#include "game.h"

Game::Game() 
{
    



}

Game::~Game()
{
    // TODO
}


void Game::start()
{
    std::cout << "You can use the following commands to play the game \n\n";
    std::cout << "load <g>\n";
    std::cout << "  g: number of the game board to load\n";
    std::cout << "init <x>,<y>,<direction>\n";
    std::cout << "  x: horizontal position of the vacuum cleaner in the room (between 0 & 9)";
    std::cout << "  y: vertical position of the vacuum cleaner in the room (between 0 & 9)";

}

bool Game::loadBoard()
{
    //TODO
    return false; // feel free to revise this line, depending on your implementation.
}

bool Game::initializePlayer()
{
    //TODO
    return false; // feel free to revise this line.
}

void Game::play()
{
    //TODO
}