#include "game.h"
#include "board.h"
#include <string>
#include "helper.h"

// Constructor for Game
Game::Game()
{
    // create new board and player
    board = new Board();
    player = new Player();
}
// Destructor for Game
Game::~Game()
{
    // delete board and player
    delete board;
    delete player;
}

void Game::start()
{
    // print commands
    std::cout << "You can use the following commands to play the game \n\n";
    std::cout << "generate <d> <p>\n";
    std::cout << " d: The dimensions of the board to be generated (between 10 and 20)\n";
    std::cout << " p: The probability of the blocks on the board to be generated randomly (between 0 and 1)\n";
    std::cout << "init <x>,<y>,<direction>\n";
    std::cout << "  x: horizontal position of the vacuum cleaner in the room (between 0 & 9) \n";
    std::cout << "  y: vertical position of the vacuum cleaner in the room (between 0 & 9) \n";
    std::cout << "  direction: direction of the vacuum cleaner's movement (north, east, south, west) \n";
    std::cout << "forward (or f) \n";
    std::cout << "turn_left (or l) \n";
    std::cout << "turn_right (or r) \n";
    std::cout << "quit \n";
    std::cout << "Press enter to continue ...";
    // wait for user to press enter - automatic invalid input
    std::cin.get();
    // add blank line
    std::cout << "\n\n";

    // load board - REQ3
    // if loadBoard is false, return to main menu
    if (!loadBoard())
    {
        return;
    }
    // initialize player - REQ4
    // if initializePlayer is false, return to main menu
    if (!initializePlayer())
    {
        return;
    }
    // play game - REQ5
    play();
    // add blank line
    std::cout << "\n\n";
}

// load board
bool Game::loadBoard()
{
    // success boolean
    bool success = false;
    // quit boolean
    bool quit = false;
    // choice: input from user
    std::string choice;
    // tokens: split choice into tokens
    std::vector<std::string> tokens;

    // main loop for function to keep asking for input
    while (!quit && !success)
    {
        // load a default empty board
        board->generateBoard(10, 0.0f);
        // print empty board
        board->displayGeneratedBoard(nullptr);
        std::cout << "\n\n";
        // print list of commands
        std::cout << "At this stage of the program, only two commands are acceptable: \n";
        std::cout << "generate <d> <p> \n";
        std::cout << "quit \n\n";

        // get input from user
        choice = Helper::readInput();
        std::cout << "\n\n";

        // if choice is EOF, exit program
        if (choice == "EOF")
        {
            // exit program
            std::cout << "End of file detected. Exiting program.\n\n";
            std::exit(EXIT_SUCCESS);
        }
        // split input into tokens
        Helper::splitString(choice, tokens, " ");
        // if choice is generate and tokens size is 3 - generate new board
        if (tokens[0] == COMMAND_GENERATE_RANDOM && tokens.size() == 3)
        {
            // load initial empty board
            int boardid = 0;
            board->load(boardid);

            // change tokens 1 and 2 to int and float
            int dimensions = std::stoi(tokens[1]);
            float probability = std::stof(tokens[2]);

            // generate board if board is not null
            if (board != nullptr)
            {
                board->generateBoard(dimensions, probability);
                // if board is generated, success is true
                success = true;
            }
            // if board is null, print error
            else
            {
                std::cout << "Error: board is null" << std::endl;
            }
        }
        // if choice is quit, exit loop and return to main menu
        else if (choice == COMMAND_QUIT)
        {
            std::cout << "\n\n";
            quit = true;
        }
        // if input is invalid, print invalid input
        else
        {
            Helper::printInvalidInput();
        }
    }
    return success;
}

// initialize player on board
bool Game::initializePlayer()
{
    // quit boolean
    bool quit = false;
    // success boolean
    bool success = false;
    // choice: input from user
    std::string choice;
    // direction: direction of player
    Direction direction = NORTH;
    // main loop for function to keep asking for input
    while (!quit && !success)
    {
        // print generated board with no player
        board->displayGeneratedBoard(nullptr);
        // print list of commands
        std::cout << "\n\n";
        std::cout << "At this stage of the program, only three commands are acceptable: \n";
        std::cout << "generate <d> <p> \n";
        std::cout << "init <x>,<y>,<direction>\n";
        std::cout << "quit \n\n";
        // get input from user
        choice = Helper::readInput();

        // if choice is quit, exit loop and return to main menu
        if (choice == COMMAND_QUIT)
        {
            std::cout << "\n\n";
            quit = true;
        }
        // if choice is EOF, exit program
        else if (choice == "EOF")
        {
            // exit program
            std::cout << "End of file detected. Exiting program.\n\n";
            std::exit(EXIT_SUCCESS);
        }

        // split input into tokens
        std::vector<std::string> tokens;
        Helper::splitString(choice, tokens, " ");

        // if choice is generate - generate new board
        if (tokens[0] == COMMAND_GENERATE_RANDOM)
        {
            // change tokens 1 and 2 to int and float
            int dimensions = std::stoi(tokens[1]);
            float probability = std::stof(tokens[2]);
            // generate board
            board->generateBoard(dimensions, probability);
        }
        // if choice is init - initialize player and place on board
        else if (tokens[0] == COMMAND_INIT)
        {
            // split tokens into position and direction
            Helper::splitString(tokens[1], tokens, ",");

            std::cout << "\n\n";
            // if tokens size is 3
            if (tokens.size() == 3)
            {
                // create new position
                Position *position = new Position(std::stoi(tokens[0]), std::stoi(tokens[1]));
                // check direction
                if (tokens[2] == DIRECTION_NORTH)
                {
                    direction = NORTH;
                }
                else if (tokens[2] == DIRECTION_EAST)
                {
                    direction = EAST;
                }
                else if (tokens[2] == DIRECTION_SOUTH)
                {
                    direction = SOUTH;
                }
                else if (tokens[2] == DIRECTION_WEST)
                {
                    direction = WEST;
                }
                else
                {
                    // print invalid input
                    Helper::printInvalidInput();
                }
                // initialize player
                player->initialisePlayer(position, direction);
                // place player on board
                if (!board->placePlayer(*position))
                {
                    //print position
                    std::cout << "Player position: " << position->x << "," << position->y << "\n\n";
    
                    
                    // if player cannot be placed due to block or out of bounds
                    std::cout << "Unable to place player at that position\n\n";
                }
                else
                {
                    // if player is placed, return true
                    success = true;
                }
            }
            else
            {
                // print invalid input
                Helper::printInvalidInput();
            }
        }
    }
    return success;
}
// play game
void Game::play()
{
    // quit boolean
    bool quit = false;
    // choice: input from user
    std::string choice;
    // main loop for function to keep asking for input
    while (!quit)
    {
        // display board with player
        board->displayGeneratedBoard(player);
        // print list of commands
        std::cout << "\n\n";
        std::cout << "At this stage of the program, only four commands are acceptable: \n";
        std::cout << "forward (or f) \n";
        std::cout << "turn_left (or l)\n";
        std::cout << "turn_right (or r) \n";
        std::cout << "quit \n\n";

        // get input from user
        choice = Helper::readInput();
        std::cout << "\n\n";

        // if choice is EOF, exit program
        if (choice == "EOF")
        {
            // exit program
            std::cout << "End of file detected. Exiting program.\n\n";
            std::exit(EXIT_SUCCESS);
        }

        // if choice is turn left or l - turn player left and display new direction
        if (choice == COMMAND_TURN_LEFT ||
            choice == COMMAND_TURN_LEFT_SHORTCUT)
        {
            player->turnDirection(TURN_LEFT);
        }

        // if choice is turn right or r - turn player right and display new direction
        else if (choice == COMMAND_TURN_RIGHT ||
                 choice == COMMAND_TURN_RIGHT_SHORTCUT)
        {
            player->turnDirection(TURN_RIGHT);
        }

        // if choice is forward or f - move player forward and display new position
        else if (choice == COMMAND_FORWARD ||
                 choice == COMMAND_FORWARD_SHORTCUT)
        {
            // call move player forward
            PlayerMove playerMove = board->movePlayerForward(player);
            // if player move is outside bounds, print error
            if (playerMove == OUTSIDE_BOUNDS)
            {
                // print error - split into two lines for readability
                std::cout << "The vacuum cleaner is at the edge of the board";
                std::cout << "and cannot move further in that direction \n\n";
            }
            // if player move is blocked, print error
            else if (playerMove == CELL_BLOCKED)
            {
                std::cout << "Unable to move - cell is blocked\n\n";
            }
            // if player moved
            else if (playerMove == PLAYER_MOVED)
            {
                // print player moved
                std::cout << "Player Moved\n\n";
            }
        }
        // if choice is quit, display total player moves, exit loop and return to main menu
        else if (choice == COMMAND_QUIT)
        {
            quit = true;
            // display moves made
            std::cout << "Total player moves: " << player->moves << "\n\n";
            // reset player moves
            player->moves = 0;
        }
        // invalid input
        else
        {
            Helper::printInvalidInput();
        }
    }
}