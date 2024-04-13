#include"game.h"

int main () {

    Game game = Game(800,600);
    game.Init();
    game.Run();
    return 0;
}