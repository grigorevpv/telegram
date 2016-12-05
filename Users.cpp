//
// Created by user on 12/5/16.
//


#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "Users.h"

using namespace std;
//using namespace boost;

Users::Users(char *file_name) {
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
        cout << "name = " << user.first << "   id = " << user.second << endl;
    }
}
