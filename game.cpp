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
    std::cout << "  x: horizontal position of the vacuum cleaner in the room (between 0 & 9) \n";
    std::cout << "  y: vertical position of the vacuum cleaner in the room (between 0 & 9) \n";
    std::cout << "  direction: direction of the vacuum cleaner's movement (north, east, south, west) \n";
    std::cout << "forward (or f) \n";
    std::cout << "turn_left (or l) \n";
    std::cout << "turn_right (or r) \n";
    std::cout << "quit \n";
    std::cout << "Press enter to continue ...";
    std::cin.ignore(); 
    std::cin.get();
    

    //https://stackoverflow.com/questions/27081195/trying-to-understand-stdcin-get
    

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