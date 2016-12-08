//
// Created by user on 08.12.16.
//

#include "Cards.h"
#include "reader.h"

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
    string *id(new string) = nullptr;
    string *type(new string) = nullptr;
    string old_id = *id;
    string old_type = *type;
    reader(id, type);

}


