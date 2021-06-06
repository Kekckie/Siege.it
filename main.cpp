#include "game.h"
#include "tower.h"
#include "block.h"

using namespace std;

int main()
{
    //new game "engine"
    Game game;

    //game loop
    while(game.running())
    {
        //update
        game.update();

        //render
        game.render();
    }

    return 0;
}
