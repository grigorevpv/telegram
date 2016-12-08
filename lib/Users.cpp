//
// Created by user on 12/5/16.
//

#include <signal.h>
#include <stdio.h>
#include <exception>
#include <tgbot/tgbot.h>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "Users.h"

using namespace std;
//using namespace boost;
using namespace TgBot;

void send_user_info(const string &id, bool friendly);

Users::Users() {
    string file_name("/home/user/ClionProjects/telegram/lib/data.txt");
    ifstream file;
    file.exceptions(ifstream::failbit | ifstream::badbit);
    file.open(file_name);

    string data_string;
    vector <string> data_array;
    int count = 0;

    if (file.is_open()){
        file >> data_string;
        number_of_users = stoi(data_string);
        while(count++ < number_of_users){
            file >> data_string;
            boost::split(data_array,data_string,boost::is_any_of(";"));
            users_name_id.insert(make_pair(data_array[0], data_array[1]));
        }
    }
    file.close();
}

void Users::show_users_data() {
    for(auto user : users_name_id){
        cout << "id = " << user.first << "   name = " << user.second << endl;
    }
}

unsigned int Users::get_number_of_users() {
    return number_of_users;
}

void Users::find_user_id(const string &id) {
    map<string, string>::iterator it;
    bool friendly = false;
    it = users_name_id.find(id);
    if (it != users_name_id.end()){
         friendly = true;
    }
    send_user_info(id, friendly);
}

void send_user_info(const string &id, bool friendly){
    Bot bot("188810782:AAE1XIyxDO2t7cIfI-aIgP2TTzwNw9LNpwM");

        bot.getApi().sendMessage(200484588, "The user with id: " + id + " is comming");
        string path;

        if (friendly){
            path = "/home/user/ClionProjects/telegram/image/sun.jpeg";
        } else {
            path = "/home/user/ClionProjects/telegram/image/prison.jpeg";
        }

        InputFile::Ptr photo (new InputFile);
        ifstream fin(path, ios::in | ios::binary);
        std::ostringstream oss;
        oss << fin.rdbuf();
        photo->data = oss.str();
        cout << photo->data.length() << endl;
        photo->mimeType = "image/jpeg";
        photo->fileName = "photo.jpeg";
        bot.getApi().sendPhoto(200484588, photo);
}