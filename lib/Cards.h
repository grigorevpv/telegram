//
// Created by user on 08.12.16.
//

#ifndef TELEGRAM_CARDS_H
#define TELEGRAM_CARDS_H

#include <string>

using namespace std;

class Cards {
private:
    string card_id;
    string card_type;
public:
    void set_card_id(const string&);
    void set_card_type(const string&);
    string get_card_id();
    string get_card_type();
    void read_cards();
};


#endif //TELEGRAM_CARDS_H
