#include "board.h"

using std::vector;

const vector<vector<Cell>> Board::BOARD_1 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

const vector<vector<Cell>> Board::BOARD_2 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

Board::Board()
{
    // TODO
    //initailise board
    std::vector<std::vector<Cell>> board = std::vector<std::vector<Cell>>(DEFAULT_BOARD_DIMENSION, std::vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY));



    
    
    
}

Board::~Board()
{
   
    delete board;
}

void Board::load(int boardId)
{
    
    //load boa

        if(board != nullptr) {
        delete board;
        board = nullptr;
    }   

    // Create a new board
    if(boardId == 1) {
        board = new std::vector<std::vector<Cell>>(BOARD_1);
    } else if(boardId == 2) {
        board = new std::vector<std::vector<Cell>>(BOARD_2);
    }



    
    
    
    
}

bool Board::placePlayer(Position position)
{
    // TODO
    //place player on board
    //return true if player is placed, return false if invalid input
    if(position.x < 0 || position.x >= DEFAULT_BOARD_DIMENSION || position.y < 0 || position.y >= DEFAULT_BOARD_DIMENSION){
        return false;
    }
    if((*board)[position.x][position.y] == BLOCKED){
        return false;
    }
    (*board)[position.x][position.y] = PLAYER;
    return true;
}

PlayerMove Board::movePlayerForward(Player* player)
{
    // TODO
    return PLAYER_MOVED;
}

void Board::display(Player* player)
{

    // TODO
    std::cout << "  ";
    for (int j = 0; j < 10; j++) {
        std::cout << j << ' ';
    }
    std::cout << std::endl;
    // Print board
    for (int i = 0; i < 10; i++) {
        // Print row number
        std::cout << i;

        // Print cells
        for (int j = 0; j < 10; j++) {
            std::cout << '|';
            if ((*board)[i][j] == EMPTY) {
                std::cout << EMPTY_OUTPUT;
            } else if ((*board)[i][j] == BLOCKED) {
                std::cout << BLOCKED_OUTPUT;
            } else if ((*board)[i][j] == PLAYER) {
                // Print player direction
                player->displayDirection();
            }
        }
        std::cout << '|' << std::endl;

    
}





}


