#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "bcm2835.h"
#include "reader.h"


//MF522 command
#define PCD_IDLE              0x00
#define PCD_AUTHENT           0x0E
#define PCD_RECEIVE           0x08
#define PCD_TRANSMIT          0x04
#define PCD_TRANSCEIVE        0x0C
#define PCD_RESETPHASE        0x0F
#define PCD_CALCCRC           0x03

//Mifare_One
#define PICC_REQIDL           0x26
#define PICC_REQALL           0x52
#define PICC_ANTICOLL1        0x93
#define PICC_ANTICOLL2        0x95
#define PICC_ANTICOLL3        0x97
#define PICC_AUTHENT1A        0x60
#define PICC_AUTHENT1B        0x61
#define PICC_READ             0x30
#define PICC_WRITE            0xA0
#define PICC_DECREMENT        0xC0
#define PICC_INCREMENT        0xC1
#define PICC_RESTORE          0xC2
#define PICC_TRANSFER         0xB0
#define PICC_HALT             0x50

//MF522 FIFO
#define DEF_FIFO_LENGTH       64                 //FIFO size=64byte
#define MAXRLEN  18

//MF522 registers
#define     CommandReg            0x01
#define     ComIEnReg             0x02
#define     DivlEnReg             0x03
#define     ComIrqReg             0x04
#define     DivIrqReg             0x05
#define     ErrorReg              0x06
#define     Status1Reg            0x07
#define     Status2Reg            0x08
#define     FIFODataReg           0x09
#define     FIFOLevelReg          0x0A
#define     WaterLevelReg         0x0B
#define     ControlReg            0x0C
#define     BitFramingReg         0x0D
#define     CollReg               0x0E

#define     ModeReg               0x11
#define     TxModeReg             0x12
#define     RxModeReg             0x13
#define     TxControlReg          0x14
#define     TxASKReg              0x15
#define     TxSelReg              0x16
#define     RxSelReg              0x17
#define     RxThresholdReg        0x18
#define     DemodReg              0x19
#define     MifareReg             0x1C
#define     SerialSpeedReg        0x1F

#define     CRCResultRegM         0x21
#define     CRCResultRegL         0x22
#define     ModWidthReg           0x24
#define     RFCfgReg              0x26
#define     GsNReg                0x27
#define     CWGsCfgReg            0x28
#define     ModGsCfgReg           0x29
#define     TModeReg              0x2A
#define     TPrescalerReg         0x2B
#define     TReloadRegH           0x2C
#define     TReloadRegL           0x2D
#define     TCounterValueRegH     0x2E
#define     TCounterValueRegL     0x2F

#define     TestSel1Reg           0x31
#define     TestSel2Reg           0x32
#define     TestPinEnReg          0x33
#define     TestPinValueReg       0x34
#define     TestBusReg            0x35
#define     AutoTestReg           0x36
#define     VersionReg            0x37
#define     AnalogTestReg         0x38
#define     TestDAC1Reg           0x39
#define     TestDAC2Reg           0x3A
#define     TestADCReg            0x3B

/////////////////////////////////////////////////////////////////////
//MF522
/////////////////////////////////////////////////////////////////////
#define 	TAG_OK                 0
#define 	TAG_NOTAG           (1)
#define 	TAG_ERR                (2)
#define 	TAG_ERRCRC             (3)
#define 	TAG_COLLISION             (4)
typedef char tag_stat;


void ClearBitMask(uint8_t   reg,uint8_t   mask);
void WriteRawRC(uint8_t   Address, uint8_t   value);
void SetBitMask(uint8_t   reg,uint8_t   mask);
char PcdComMF522(uint8_t   Command,
                 uint8_t *pIn ,
                 uint8_t   InLenByte,
                 uint8_t *pOut ,
                 uint8_t  *pOutLenBit);
void CalulateCRC(uint8_t *pIn ,uint8_t   len,uint8_t *pOut );
uint8_t ReadRawRC(uint8_t   Address);
char PcdReset(void);
void PcdAntennaOn(void);
void PcdAntennaOff(void);
//char M500PcdConfigISOType(unsigned char type);
//char PcdSelect(uint8_t , uint8_t *);
//char PcdAuthState(unsigned char auth_mode,unsigned char addr,unsigned char *pKey,unsigned char *pSnr);
//char PcdWrite(unsigned char addr,unsigned char *pData);
//char PcdRead(unsigned char addr,unsigned char *pData);
//char PcdHalt(void);

void InitRc522(void)
{
    PcdReset();
    PcdAntennaOn();
}

char PcdRequest(uint8_t req_code,uint8_t *pTagType)
{
    char   status;
    uint8_t   unLen;
    uint8_t   ucComMF522Buf[MAXRLEN];

    WriteRawRC(BitFramingReg,0x07);
    ucComMF522Buf[0] = req_code;

    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,1,ucComMF522Buf,&unLen);
    if ((status == TAG_OK) && (unLen == 0x10))
    {
        *pTagType     = ucComMF522Buf[0];
        *(pTagType+1) = ucComMF522Buf[1];
    }
    else if (status == TAG_COLLISION) {
//		printf("ATQA %02x%02x\n",ucComMF522Buf[0],ucComMF522Buf[1]);
    }
    else if (status!=TAG_NOTAG) {
        status = TAG_ERR;
    }

    return status;
}

char PcdAnticoll(uint8_t cascade, uint8_t *pSnr)
{
    char   status;
    uint8_t   i,snr_check=0;
    uint8_t   unLen;
    uint8_t   ucComMF522Buf[MAXRLEN];
    uint8_t   pass=32;
    uint8_t	  collbits=0;

    i=0;
    WriteRawRC(BitFramingReg,0x00);
    do {
        ucComMF522Buf[0] = cascade;
        ucComMF522Buf[1] = 0x20+collbits;
        //	WriteRawRC(0x0e,0);
        status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,2+i,ucComMF522Buf,&unLen);
        if (status == TAG_COLLISION) {
            collbits=ReadRawRC(CollReg)&0x1f;
            if (collbits==0) collbits=32;
            i=(collbits-1)/8 +1;
//			printf ("--- %02x %02x %02x %02x %d\n",ucComMF522Buf[0],ucComMF522Buf[1],ucComMF522Buf[2],ucComMF522Buf[3],unLen);
            ucComMF522Buf[i-1]|=(1<<((collbits-1)%8));
            ucComMF522Buf[5]=ucComMF522Buf[3];
            ucComMF522Buf[4]=ucComMF522Buf[2];
            ucComMF522Buf[3]=ucComMF522Buf[1];
            ucComMF522Buf[2]=ucComMF522Buf[0];
            WriteRawRC(BitFramingReg,(collbits % 8));
//			printf (" %d %d %02x %d\n",collbits,i,ucComMF522Buf[i+1],collbits % 8);
        }
    } while (((--pass)>0)&&(status==TAG_COLLISION));

    if (status == TAG_OK)
    {
        for (i=0; i<4; i++)
        {
            *(pSnr+i)  = ucComMF522Buf[i];
            snr_check ^= ucComMF522Buf[i];
        }
        if (snr_check != ucComMF522Buf[i])
        {   status = TAG_ERR;    }
    }

    return status;
}

char PcdSelect(uint8_t cascade, uint8_t *pSnr)
{
    char   status;
    uint8_t   i;
    uint8_t   unLen;
    uint8_t   ucComMF522Buf[MAXRLEN];

    ucComMF522Buf[0] = cascade;
    ucComMF522Buf[1] = 0x70;
    ucComMF522Buf[6] = 0;
    for (i=0; i<4; i++)
    {
        ucComMF522Buf[i+2] = *(pSnr+i);
        ucComMF522Buf[6]  ^= *(pSnr+i);
    }
    CalulateCRC(ucComMF522Buf,7,&ucComMF522Buf[7]);

    ClearBitMask(Status2Reg,0x08);

    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,9,ucComMF522Buf,&unLen);

    if ((status == TAG_OK) && (unLen == 0x18))
    {   status = TAG_OK;  }
    else
    {   status = TAG_ERR;    }

    return status;
}

char PcdAuthState(uint8_t   auth_mode,uint8_t   addr,uint8_t *pKey,uint8_t *pSnr)
{
    char   status;
    uint8_t   unLen;
    uint8_t   ucComMF522Buf[MAXRLEN];

    ucComMF522Buf[0] = auth_mode;
    ucComMF522Buf[1] = addr;
    memcpy(&ucComMF522Buf[2], pKey, 6);
    memcpy(&ucComMF522Buf[8], pSnr, 4);

    status = PcdComMF522(PCD_AUTHENT,ucComMF522Buf,12,ucComMF522Buf,&unLen);
    if ((status != TAG_OK) || (!(ReadRawRC(Status2Reg) & 0x08)))
    {   status = TAG_ERR;   }

    return status;
}

char PcdRead(uint8_t addr,uint8_t *p )
{
    char   status;
    uint8_t   unLen;
    uint8_t   i,ucComMF522Buf[MAXRLEN];
    uint8_t   CRC_buff[2];

    memset(ucComMF522Buf,0,sizeof(ucComMF522Buf));
    ucComMF522Buf[0] = PICC_READ;
    ucComMF522Buf[1] = addr;
    CalulateCRC(ucComMF522Buf,2,&ucComMF522Buf[2]);

    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,4,ucComMF522Buf,&unLen);
    CalulateCRC(ucComMF522Buf,16,CRC_buff);
    //	printf("debug %02x%02x %02x%02x   ",ucComMF522Buf[16],ucComMF522Buf[17],CRC_buff[0],CRC_buff[1]);

    if ((status == TAG_OK) && (unLen == 0x90))
    {
        if ((CRC_buff[0]!=ucComMF522Buf[16])||(CRC_buff[1]!=ucComMF522Buf[17])) { status = TAG_ERRCRC; }
        for (i=0; i<16; i++)
        {    *(p +i) = ucComMF522Buf[i];   }
    }
    else
    {   status = TAG_ERR;   }

    return status;
}

char PcdWrite(uint8_t   addr,uint8_t *p )
{
    char   status;
    uint8_t   unLen;
    uint8_t   i,ucComMF522Buf[MAXRLEN];

    ucComMF522Buf[0] = PICC_WRITE;
    ucComMF522Buf[1] = addr;
    CalulateCRC(ucComMF522Buf,2,&ucComMF522Buf[2]);

    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,4,ucComMF522Buf,&unLen);

    if ((status != TAG_OK) || (unLen != 4) || ((ucComMF522Buf[0] & 0x0F) != 0x0A))
    {   status = TAG_ERR;   }

    if (status == TAG_OK)
    {
        for (i=0; i<16; i++)
        {
            ucComMF522Buf[i] = *(p +i);
        }
        CalulateCRC(ucComMF522Buf,16,&ucComMF522Buf[16]);

        status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,18,ucComMF522Buf,&unLen);
        if ((status != TAG_OK) || (unLen != 4) || ((ucComMF522Buf[0] & 0x0F) != 0x0A))
        {   status = TAG_ERR;   }
    }

    return status;
}

char PcdHalt(void)
{
    uint8_t status;
    uint8_t unLen;
    uint8_t ucComMF522Buf[MAXRLEN];

    ucComMF522Buf[0] = PICC_HALT;
    ucComMF522Buf[1] = 0;
    CalulateCRC(ucComMF522Buf,2,&ucComMF522Buf[2]);

    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,4,ucComMF522Buf,&unLen);

    return status;
}

void CalulateCRC(uint8_t *pIn ,uint8_t   len,uint8_t *pOut )
{
    uint8_t   i,n;
    ClearBitMask(DivIrqReg,0x04);
    WriteRawRC(CommandReg,PCD_IDLE);
    SetBitMask(FIFOLevelReg,0x80);
    for (i=0; i<len; i++)
    {   WriteRawRC(FIFODataReg, *(pIn +i));   }
    WriteRawRC(CommandReg, PCD_CALCCRC);
    i = 0xFF;
    do
    {
        n = ReadRawRC(DivIrqReg);
        i--;
    }
    while ((i!=0) && !(n&0x04));
    pOut [0] = ReadRawRC(CRCResultRegL);
    pOut [1] = ReadRawRC(CRCResultRegM);
}

char PcdReset(void)
{
    WriteRawRC(CommandReg,PCD_RESETPHASE);
    usleep(10000);
    ClearBitMask(TxControlReg,0x03);
    usleep(10000);
    SetBitMask(TxControlReg,0x03);
    WriteRawRC(TModeReg,0x8D);
    WriteRawRC(TPrescalerReg,0x3E);
    WriteRawRC(TReloadRegL,30);
    WriteRawRC(TReloadRegH,0);
    WriteRawRC(TxASKReg,0x40);
    WriteRawRC(ModeReg,0x3D);            //6363
    //	WriteRawRC(DivlEnReg,0x90);
    WriteRawRC(RxThresholdReg,0x84);
    WriteRawRC(RFCfgReg,0x68);
    WriteRawRC(GsNReg,0xff);
    WriteRawRC(CWGsCfgReg,0x2f);
    //	WriteRawRC(ModWidthReg,0x2f);

    return TAG_OK;
}

/*
char M500PcdConfigISOType(uint8_t   type)
{
	if (type == 'A')
	{
		ClearBitMask(Status2Reg,0x08);
		WriteRawRC(ModeReg,0x3D);
		WriteRawRC(RxSelReg,0x86);
		WriteRawRC(RFCfgReg,0x7F);
		WriteRawRC(TReloadRegL,30);
		WriteRawRC(TReloadRegH,0);
		WriteRawRC(TModeReg,0x8D);
		WriteRawRC(TPrescalerReg,0x3E);
		PcdAntennaOn();
	}
	else{ return 1; }

	return TAG_OK;
}
 */

uint8_t ReadRawRC(uint8_t Address)
{
    char buff[2];
    buff[0] = ((Address<<1)&0x7E)|0x80;
    bcm2835_spi_transfern(buff,2);
    return (uint8_t)buff[1];
}

void WriteRawRC(uint8_t Address, uint8_t value)
{
    char buff[2];

    buff[0] = (char)((Address<<1)&0x7E);
    buff[1] = (char)value;
    bcm2835_spi_transfern(buff,2);
}

void SetBitMask(uint8_t   reg,uint8_t   mask)
{
    char   tmp = 0x0;
    tmp = ReadRawRC(reg);
    WriteRawRC(reg,tmp | mask);  // set bit mask
}

void ClearBitMask(uint8_t   reg,uint8_t   mask)
{
    char   tmp = 0x0;
    tmp = ReadRawRC(reg);
    WriteRawRC(reg, tmp & ~mask);  // clear bit mask
}

char PcdComMF522(uint8_t   Command,
                 uint8_t *pIn ,
                 uint8_t   InLenByte,
                 uint8_t *pOut ,
                 uint8_t *pOutLenBit)
{
    char   status = TAG_ERR;
    uint8_t   irqEn   = 0x00;
    uint8_t   waitFor = 0x00;
    uint8_t   lastBits;
    uint8_t   n;
    uint32_t   i;
    uint8_t PcdErr;

    //	printf("CMD %02x\n",pIn[0]);
    switch (Command)
    {
        case PCD_AUTHENT:
            irqEn   = 0x12;
            waitFor = 0x10;
            break;
        case PCD_TRANSCEIVE:
            irqEn   = 0x77;
            waitFor = 0x30;
            break;
        default:
            break;
    }

    WriteRawRC(ComIEnReg,irqEn|0x80);
    //	WriteRawRC(ComIEnReg,irqEn);
    ClearBitMask(ComIrqReg,0x80);
    SetBitMask(FIFOLevelReg,0x80);
    WriteRawRC(CommandReg,PCD_IDLE);

    for (i=0; i<InLenByte; i++) {
        WriteRawRC(FIFODataReg, pIn [i]);
    }

    WriteRawRC(CommandReg, Command);

    if (Command == PCD_TRANSCEIVE) {
        SetBitMask(BitFramingReg,0x80);
    }

    //i = 600;//���ʱ��Ƶ�ʵ������M1�����ȴ�ʱ��25ms
    i = 150;
    do
    {
        usleep(200);
        //		bcm2835_delayMicroseconds(200);
        n = ReadRawRC(ComIrqReg);
        i--;
    }
    while ((i!=0) && (!(n&0x01)) && (!(n&waitFor)));

    ClearBitMask(BitFramingReg,0x80);

    if (i!=0)
    {
        PcdErr=ReadRawRC(ErrorReg);
        if (!(PcdErr & 0x11))
        {
            status = TAG_OK;
            if (n & irqEn & 0x01) {status = TAG_NOTAG;}
            if (Command == PCD_TRANSCEIVE) {
                n = ReadRawRC(FIFOLevelReg);
                lastBits = ReadRawRC(ControlReg) & 0x07;
                if (lastBits) {*pOutLenBit = (n-1)*8 + lastBits;}
                else {*pOutLenBit = n*8;}

                if (n == 0) {n = 1;}
                if (n > MAXRLEN) {n = MAXRLEN;}

                for (i=0; i<n; i++) {
                    pOut [i] = ReadRawRC(FIFODataReg);
//					printf (".%02X ",pOut[i]);
                }
            }
        }
        else {
            //			fprintf (stderr,"Err %02x\n",PcdErr);
            status = TAG_ERR;}

        if (PcdErr&0x08) {
            if (debug) fprintf (stderr,"COllision \n");
            status = TAG_COLLISION;

        }

    }


    //    SetBitMask(ControlReg,0x80);           // stop timer now
    //    WriteRawRC(CommandReg,PCD_IDLE); ???????
//	printf ("PCD Err %02x\n",PcdErr);
    return status;
}

void PcdAntennaOn(void)
{
    uint8_t   i;
    i = ReadRawRC(TxControlReg);
    if (!(i & 0x03))
    {
        SetBitMask(TxControlReg, 0x03);
    }
}

void PcdAntennaOff(void)
{
    ClearBitMask(TxControlReg, 0x03);
}
