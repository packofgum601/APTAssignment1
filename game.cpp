#include "game.h"
#include "board.h"
#include <string>
#include "helper.h"

Game::Game() 
{
    board = new Board();
    player = new Player();
    
    

    



}

Game::~Game()
{
    delete board;
    
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
   
    //REQ3
    loadBoard();
    //REQ4
    initializePlayer();
    //REQ5
    play();
}

bool Game::loadBoard()
{
    //TODO
    //load empty board then ask player for choice, at which point use load from Board.cpp
    //return true if board is loaded, return false if invalid input 
    //TODO: add while loop to repeat if invalid input (if returnded false: load board?)
    std::string choice;
    int boardId;
    

    while(true){
         //EMpty board options before load board
        //REQ2
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

        } else if(choice == "quit"){
            //go back to main menu;
            std::cout << "\n\n";
            return false;
            
        } else {
            std::cout << "Invalid input \n\n";
        }
    }

}

bool Game::initializePlayer()
{
    
    //initialize player on board
    //return true if player is initialized, return false if invalid input
    std::string choice;
    Direction direction = NORTH;

    while(true){
        //print board with no player
        board->display(nullptr);
        std::cout << "\n\n";
        std::cout << "At this stage of the program, only three commands are acceptable: \n";
        std::cout << "load <g> \n";
        std::cout << "init <x>,<y>,<direction>\n";
        std::cout << "quit \n\n";

        std::getline(std::cin, choice);
        std::cout << "\n\n";
        
        //load loard if choice is load
        if(choice == "load 1" || choice == "load 2"){
            //load board from Board.cpp
            //return true if board is loaded
            //create board id form choice
            int boardId;
            if(choice == "load 1"){
                boardId = 1;
            } else {
                boardId = 2;
            }
            //load board
            board->load(boardId);
            
            initializePlayer();
            return false;
        }
        

        std::vector<std::string> tokens;
        Helper::splitString(choice, tokens, " ");

        if(tokens.size() == 4 && tokens[0] == "init"){
            Position* position = new Position(std::stoi(tokens[1]), std::stoi(tokens[2]));
                if(tokens[3] == "north"){
                    direction = NORTH;
                    
                } else if(tokens[3] == "east"){
                    direction = EAST;
                    
                } else if(tokens[3] == "south"){
                    direction = SOUTH;
                    
                } else if(tokens[3] == "west"){
                    direction = WEST;
                    
                } else {
                    std::cout << "Invalid input\n\n";
                    initializePlayer();
                    return false;
                }
            
        

            player->initialisePlayer(position, direction);
            //place player on board
            board->placePlayer(*position);

            return true;
        } else if(choice == "quit"){
            //go back to main menu;
            std::cout << "\n\n";
            return false;
        } else {
            std::cout << "Invalid input\n\n";
        }
    }
        
    }

void Game::play()
{
    std::string choice;
    while(true){
        //display board with player
        board->display(player);
        std::cout << "\n\n";
        std::cout << "At this stage of the program, only four commands are acceptable: \n";
        std::cout << "forward (or f) \n";
        std::cout << "turn_left (or l)\n";
        std::cout << "turn_right (or r) \n\n";
        std::cout << "quit \n\n";

        std::getline(std::cin, choice);
        std::cout << "\n\n";
    }
}