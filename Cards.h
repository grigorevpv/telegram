//
// Created by user on 12/6/16.
//

#ifndef TELEGRAM_CARDS_H
#define TELEGRAM_CARDS_H

#include <string>

using namespace std;

class Cards {
private:
    struct cart_info{
        string card_type;
        string card_id;
    };

public:
    cart_info read_cards();
    string get_card_id();
    string get_card_type();
};


#endif //TELEGRAM_CARDS_H
