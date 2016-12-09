#include <exception>
#include <tgbot/tgbot.h>
#include "lib/Cards.h"

using namespace std;
using namespace TgBot;

bool sigintGot = false;

int main(int argc, char* argv[]) {

    Cards cards;
    cards.read_cards();

    return 0;
}
