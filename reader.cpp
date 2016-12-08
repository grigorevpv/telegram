#include <signal.h>
#include <stdio.h>
#include <exception>
#include <tgbot/tgbot.h>
#include "lib/Users.h"

using namespace std;
using namespace TgBot;

bool sigintGot = false;

int main(int argc, char* argv[]) {

    Users one(argv[1]);
    one.show_users_data();

//    signal(SIGINT, [](int s) {
//        printf("SIGINT got");
//        sigintGot = true;
//    });
//
//    Bot bot("188810782:AAE1XIyxDO2t7cIfI-aIgP2TTzwNw9LNpwM");
//    bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {
//        bot.getApi().sendMessage(message->chat->id, "Hi!");
//    });
//
//    bot.getEvents().onCommand("photo", [&bot](Message::Ptr message) {
//        InputFile::Ptr photo (new InputFile);
//        string path = "/home/user/ClionProjects/telegram/sun.jpeg";
//        ifstream fin(path, ios::in | ios::binary);
//        std::ostringstream oss;
//        oss << fin.rdbuf();
//        photo->data = oss.str();
//        cout << photo->data.length() << endl;
//        photo->mimeType = "image/jpeg";
//        photo->fileName = "sun.jpeg";
//        bot.getApi().sendPhoto(message->chat->id, photo);
//    });
//
//    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
//        printf("User wrote %s\n", message->text.c_str());
//        if (StringTools::startsWith(message->text, "/start")) {
//            return;
//        }
//        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
//    });
//
//    try {
//        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
//
//        TgLongPoll longPoll(bot);
//        while (!sigintGot) {
//            printf("Long poll started\n");
//            longPoll.start();
//        }
//    } catch (exception& e) {
//        printf("error: %s\n", e.what());
//    }

    return 0;
}
