#include "board.h"

using std::vector;

const vector<vector<Cell>> Board::BOARD_1 =
    {
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}};

const vector<vector<Cell>> Board::BOARD_2 =
    {
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}};

// Constructor for Board
Board::Board()
{
    // initailise board
    std::vector<std::vector<Cell>> board =
        std::vector<std::vector<Cell>>(DEFAULT_BOARD_DIMENSION,
                                       std::vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY));
}

// Destructor for Board
Board::~Board()
{
    delete board;
}

// Load a board based on the boardId - for Milestones 1,2,3
void Board::load(int boardId)
{
    // if board is not null, delete it and set it to null
    if (board != nullptr)
    {
        delete board;
        board = nullptr;
    }

    // Create a new board based on the boardId
    if (boardId == 1)
    {
        board = new std::vector<std::vector<Cell>>(BOARD_1);
    }
    else if (boardId == 2)
    {
        board = new std::vector<std::vector<Cell>>(BOARD_2);
    }
    // load empty board if board id is 0
    else
    {
        board = new std::vector<std::vector<Cell>>(DEFAULT_BOARD_DIMENSION,
                                                   std::vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY));
    }
}

// Place a player on the board
bool Board::placePlayer(Position position)
{
    // success bool
    bool success = false;

    // check if position is inside the board
    if (position.x < 0 || position.x >= DEFAULT_BOARD_DIMENSION || position.y < 0 ||
        position.y >= DEFAULT_BOARD_DIMENSION)
    {
        success = false;
    }
    // check if position is blocked
    if ((*board)[position.y][position.x] == BLOCKED)
    {
        success = false;
    }
    // place player on board if empty
    if ((*board)[position.y][position.x] == EMPTY)
    {
        (*board)[position.y][position.x] = PLAYER;
        success = true;
    }

    return success;
}

// Move a player forward
PlayerMove Board::movePlayerForward(Player *player)
{
    // description of the next position
    PlayerMove next_position;
    // calll get forward position
    Position nextPosition = player->getNextForwardPosition();

    // check if position is inside bounds
    if (nextPosition.x < 0 || nextPosition.x >= DEFAULT_BOARD_DIMENSION || nextPosition.y < 0 ||
        nextPosition.y >= DEFAULT_BOARD_DIMENSION)
    {
        next_position = OUTSIDE_BOUNDS;
    }
    // check if position is blocked
    else if ((*board)[nextPosition.y][nextPosition.x] == BLOCKED)
    {
        next_position = CELL_BLOCKED;
    }
    // check if position is empty
    else if ((*board)[nextPosition.y][nextPosition.x] == EMPTY)
    {
        // remove player from current position
        (*board)[player->position.y][player->position.x] = EMPTY;
        // set new position to player
        (*board)[nextPosition.y][nextPosition.x] = PLAYER;
        // update player position
        player->updatePosition(nextPosition);
        next_position = PLAYER_MOVED;
    }
    else
    {
        // if position is invalid
        next_position = OUTSIDE_BOUNDS;
    }
    return next_position;
}

// Display the board
void Board::display(Player *player)
{
    // Print column numbers
    std::cout << EMPTY_OUTPUT;
    for (int j = 0; j < 10; j++)
    {
        std::cout << j << EMPTY_OUTPUT;
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
    {
        // Print row number
        std::cout << i;

        // Print cells
        for (int j = 0; j < 10; j++)
        {
            std::cout << LINE_OUTPUT;
            if ((*board)[i][j] == EMPTY)
            {
                std::cout << EMPTY_OUTPUT;
            }
            else if ((*board)[i][j] == BLOCKED)
            {
                std::cout << BLOCKED_OUTPUT;
            }
            else if ((*board)[i][j] == PLAYER)
            {
                // Print player arrow
                player->displayDirection();
            }
        }
        std::cout << LINE_OUTPUT << std::endl;
    }
}
