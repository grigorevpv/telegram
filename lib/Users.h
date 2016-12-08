//
// Created by user on 12/5/16.
//

#ifndef TELEGRAM_USERS_H
#define TELEGRAM_USERS_H

#include <map>

using namespace std;

class Users {
private:
    map<string, string> users_name_id;
    unsigned int number_of_users;
public:
    Users(char *file_name);
    void show_users_data();
    string start_read_cards();
    unsigned int get_number_of_users();

};


#endif //TELEGRAM_USERS_H