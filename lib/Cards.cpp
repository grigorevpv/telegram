//
// Created by user on 08.12.16.
//

#include "Cards.h"
#include "reader.c"
#include "Users.h"

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


