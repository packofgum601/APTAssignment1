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
    delete player;
    
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
    std::cin.get();
    //add blank line
    std::cout << "\n\n";

    //REQ3
    //loadBoard();
    if(!loadBoard()){
        return;
    }
    //REQ4
    if(!initializePlayer()){
        return;
    }
    //REQ5
    play();
    std::cout << "\n\n";
}

bool Game::loadBoard()
{
    //TODO
    //load empty board then ask player for choice, at which point use load from Board.cpp
    //return true if board is loaded, return false if invalid input 
    
    std::string choice;
    int boardId;
    char emptyboard[11][11];

    while(true){
         //EMpty board options before load board
        //REQ2
        //definie initial empy board
        
        
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
            
            return initializePlayer();
           
        }
        else if(choice == "quit"){
            //go back to main menu;
            std::cout << "\n\n";
            return false;
        }
        

        //split string by space then by commas
        std::vector<std::string> tokens;
        Helper::splitString(choice, tokens, " ");
        if (tokens[0] == "init" ){
            Helper::splitString(tokens[1], tokens, ",");
        }
        std::cout << "\n\n";
        
        if(tokens.size() == 3){
            Position* position = new Position(std::stoi(tokens[1]), std::stoi(tokens[0]));
                if(tokens[2] == "north"){
                    direction = NORTH;

                } else if(tokens[2] == "east"){
                    direction = EAST;
                    
                } else if(tokens[2] == "south"){
                    direction = SOUTH;
                    
                } else if(tokens[2] == "west"){
                    direction = WEST;
                    
                } else {
                    std::cout << "Invalid input\n\n";
                    return initializePlayer();
                    
                }

            player->initialisePlayer(position, direction);
            //place player on board
            if(!board->placePlayer(*position)){
                std::cout << "Cannot place player there\n\n";
                return initializePlayer();
            }
            //if player is placed, return true
            return true;
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
        std::cout << "turn_right (or r) \n";
        std::cout << "quit \n\n";

        choice = Helper::readInput();
        std::cout << "\n\n";

        //if choice is quit, return to main menu
        if(choice == "quit"){
            return;
        }

    
    }
}