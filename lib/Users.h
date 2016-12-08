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
    Users();
    void show_users_data();
    unsigned int get_number_of_users();
    void find_user_id(const string &);
};


#endif //TELEGRAM_USERS_H
