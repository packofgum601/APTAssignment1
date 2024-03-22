#include "game.h"
#include "board.h"
#include <string>

Game::Game() 
{
    
    

    



}

Game::~Game()
{
    
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
    //add blank line
    std::cout << "\n\n";
    loadBoard();
    
    




    //initializePlayer();
    //play();

    //https://stackoverflow.com/questions/27081195/trying-to-understand-stdcin-get
    

}

bool Game::loadBoard()
{
    //TODO
    //load empty board then ask player for choice, at which point use load from Board.cpp
    //return true if board is loaded, return false if invalid input 
    //TODO: add while loop to repeat if invalid input (if returnded false: load board?)
    std::string choice;
    int boardId;
    int loop = 0;
    while(loop == 0){
        //definie initial empy board
        char emptyboard[11][11];
        //create initial rows and columns
        for(int i=1; i < 11; i++){
            for(int j = 1; j < 11; j++) {
                emptyboard[i][j] = ' ';
            }
        }
        //add row and column numbers
        for (int i = 0; i< 10; i++){
            emptyboard[i+1][0] = '0' + i;
            emptyboard[0][i+1] = '0' + i;
        }
        // add space for top left
        emptyboard[0][0] = ' ';
        //print the board
        for(int i=0; i < 11; i++){
            for(int j = 0; j < 11; j++) {
                std::cout << "|" << emptyboard[i][j];
            }
            std::cout << "|\n";

        }

    
        //add blank line 
        std::cout << "\n\n";
        //list options 
        std::cout << "At this stage of the program, only two commands are acceptable: \n";
        std::cout << "load <g> \n";
        std::cout << "quit \n\n";
        std::getline(std::cin, choice);
        std::cout << "\n\n";
        
        if(choice == "load 1" || choice == "load 2"){
            //load board from Board.cpp
            //return true if board is loaded
            //create board id form choice
            if(choice == "load 1"){
                boardId = 1;
            } else {
                boardId = 2;
            }
            //load board
            board->load(boardId);
            return true;
            loop++;

            
        } else if(choice == "quit"){
            //go back to main menu;
            std::cout << "\n\n";
            return false;
            
        } else {
            std::cout << "Invalid input \n\n";
        }
    }

    std::cout << "\n\n";
    std::cout << "At this stage of the program, only three commands are acceptable: \n";
    std::cout << "load <g> \n";
    std::cout << "init <x>,<y>,<direction>\n";
    std::cout << "quit \n\n";

    
    
    
    return false;  

    
    //return false; // feel free to revise this line, depending on your implementation.
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