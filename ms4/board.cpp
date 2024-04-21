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
    std::vector<std::vector<Cell>> board = std::vector<std::vector<Cell>>(
        DEFAULT_BOARD_DIMENSION, std::vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY));
    // initialise board_size - default to 10
    board_size = DEFAULT_BOARD_DIMENSION;
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

// Generate a board based on the dimensions and probability - for Milestone 4
void Board::generateBoard(int dimensions, float probability)
{
    // Initialise board
    std::vector<std::vector<Cell>> *newBoard =
        new std::vector<std::vector<Cell>>(dimensions, std::vector<Cell>(dimensions, EMPTY));
    // change board size variable
    board_size = dimensions;
    // Fill board with blocks based on probability
    for (int i = 0; i < dimensions; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            // Generate a random number between 0 and 99
            int random = rand() % 100;
            // If the random number is less than the probability, set the cell to blocked
            if (random < probability * 100)
            {
                (*newBoard)[i][j] = BLOCKED;
            }
        }
    }

    // Delete the old board if it exists
    if (board != nullptr)
    {
        delete board;
    }

    // Load the new board
    board = newBoard;
}

// Place the player on the board
bool Board::placePlayer(Position position)
{
    // success boolean
    bool success = false;
    // check if position is valid
    if (position.x < 0 || position.x >= board_size || position.y < 0 || position.y >= board_size)
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

// Move the player forward
PlayerMove Board::movePlayerForward(Player *player)
{
    // the description of the next position
    PlayerMove next_position;
    // calll get forward position
    Position nextPosition = player->getNextForwardPosition();

    // check if position is inside bounds
    if (nextPosition.x < 0 || nextPosition.x >= board_size ||
        nextPosition.y < 0 || nextPosition.y >= board_size)
    {
        next_position = OUTSIDE_BOUNDS;
    }
    // check if position is blocked
    if ((*board)[nextPosition.y][nextPosition.x] == BLOCKED)
    {
        next_position = CELL_BLOCKED;
    }
    // check if position is empty
    if ((*board)[nextPosition.y][nextPosition.x] == EMPTY)
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

// Display the board - for Milestones 1,2,3
void Board::display(Player *player)
{
    // Print column numbers
    std::cout << EMPTY_OUTPUT;
    for (int j = 0; j < 10; j++)
    {
        std::cout << j << EMPTY_OUTPUT;
    }
    std::cout << std::endl;
    // Print board
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
                // Print empty cell
                std::cout << EMPTY_OUTPUT;
            }
            else if ((*board)[i][j] == BLOCKED)
            {
                // Print blocked cell
                std::cout << BLOCKED_OUTPUT;
            }
            else if ((*board)[i][j] == PLAYER)
            {
                // Print player arrow
                player->displayDirection();
            }
        }
        // Print line
        std::cout << LINE_OUTPUT << std::endl;
    }
}

// display the generated board - for Milestone 4
void Board::displayGeneratedBoard(Player *player)
{
    int board_size = board->size();

    // Print column numbers
    // Print tens digit of column numbers
    std::cout << EMPTY_OUTPUT;
    for (int j = 0; j < board_size; j++)
    {
        std::cout << LINE_OUTPUT << j / 10;
    }
    std::cout << '\n';

    // Print ones digit of column numbers
    std::cout << "  ";
    for (int j = 0; j < board_size; j++)
    {
        std::cout << "|" << j % 10;
    }
    std::cout << '\n';

    for (int i = 0; i < board_size; i++)
    {
        // Print row number
        // if i is less than 10, add a space before the number
        if (i < 10)
        {
            std::cout << EMPTY_OUTPUT;
        }
        std::cout << i;

        for (int j = 0; j < board_size; j++)
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
                // Print player direction
                player->displayDirection();
            }
        }
        std::cout << LINE_OUTPUT << std::endl;
    }
}
