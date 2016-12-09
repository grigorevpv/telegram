//
// Created by user on 08.12.16.
//

#include "Cards.h"
#include "Users.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>
#include <sys/wait.h>
#include <signal.h>
#include "rfid.h"
#include "bcm2835.h"
#include "config.h"
#include "rc522.h"


char *reader();
uint8_t HW_init(uint32_t spi_speed, uint8_t gpio);
void usage(char *);
uint8_t debug = 0;

void Cards::set_card_id(const string &id) {
    card_id = id;
}

void Cards::set_card_type(const string &type) {
    card_type = type;
}

string Cards::get_card_id() {
    return card_id;
}

string Cards::get_card_type() {
    return card_type;
}

void Cards::read_cards() {
    string id;
    Users users;
    int i = 20;
    while (i--) {
        card_id = reader();
        users.find_user_id(card_id);
    }
}




