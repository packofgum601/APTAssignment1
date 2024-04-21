#include "game.h"
#include "board.h"
#include <string>
#include "helper.h"

// TODO: implement moves - games, player, board
//  Game constructor
Game::Game()
{
    // create board and player
    board = new Board();
    player = new Player();
}

// Game destructor
Game::~Game()
{
    // delete board and player
    delete board;
    delete player;
}

// start game
void Game::start()
{
    // print commands
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
    // wait for user to press enter
    std::cin.get();
    // add blank line
    std::cout << "\n\n";

    // load board - REQ3
    // if board is not loaded, return to main menu
    if (!loadBoard())
    {
        return;
    }
    // initialize player - REQ4
    // if player is not initialized, return to main menu
    if (!initializePlayer())
    {
        return;
    }
    // play game - REQ5
    play();
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
    // board id: number of the game board to load
    int boardId = 0;
    // main loop for function to keep asking for input
    while (!quit && !success)
    {
        // print board with no player
        board->load(boardId);
        board->display(nullptr);

        // add blank line
        std::cout << "\n\n";

        // list options
        std::cout << "At this stage of the program, only two commands are acceptable: \n";
        std::cout << "load <g> \n";
        std::cout << "quit \n\n";
        // read input
        choice = Helper::readInput();
        // if choice is EOF, exit program
        if (choice == "EOF")
        {
            // exit program
            std::cout << "End of file detected. Exiting program.\n\n";
            std::exit(EXIT_SUCCESS);
        }
        // split input by into tokens
        std::vector<std::string> tokens;
        Helper::splitString(choice, tokens, " ");
        // if choice is load
        if (tokens[0] == COMMAND_LOAD)
        {
            // load board based on board id
            if (tokens[1] == "1")
            {
                boardId = 1;
            }
            else if (tokens[1] == "2")
            {
                boardId = 2;
            }

            // load board
            board->load(boardId);

            success = true;
        }
        // if choice is quit, exit loop and return to main menu
        else if (choice == COMMAND_QUIT)
        {
            std::cout << "\n\n";
            quit = true;
        }
        else
        {
            // invalid input
            Helper::printInvalidInput();
        }
    }
    return success;
}

// initialize player
bool Game::initializePlayer()
{
    // quit boolean
    bool quit = false;
    // success boolean
    bool success = false;
    // choice: input from user
    std::string choice;
    // direction: direction of the player
    Direction direction = NORTH;
    // board id: number of the game board to load
    int boardId = 0;
    // main loop for function to keep asking for input
    while (!quit && !success)
    {
        // print board with no player
        board->display(nullptr);
        // add blank line and list options
        std::cout << "\n\n";
        std::cout << "At this stage of the program, only three commands are acceptable: \n";
        std::cout << "load <g> \n";
        std::cout << "init <x>,<y>,<direction>\n";
        std::cout << "quit \n\n";
        // read input
        choice = Helper::readInput();
        // if choice is EOF - exit program
        if (choice == "EOF")
        {
            // exit program
            std::cout << "End of file detected. Exiting program.\n\n";
            std::exit(EXIT_SUCCESS);
        }

        // split choice into tokens
        std::vector<std::string> load_tokens;
        Helper::splitString(choice, load_tokens, " ");
        // if choice is load - load new board
        if (load_tokens[0] == COMMAND_LOAD)
        {
            // load board based on board id
            if (load_tokens[1] == "1")
            {
                boardId = 1;
            }
            else if (load_tokens[1] == "2")
            {
                boardId = 2;
            }
            else
            {
                // invalid input
                Helper::printInvalidInput();
            }
            // load board
            board->load(boardId);
        }
        // if choice is quit, exit loop and return to main menu
        else if (choice == COMMAND_QUIT)
        {
            std::cout << "\n\n";
            quit = true;
        }

        // split choice into tokens
        std::vector<std::string> tokens;
        Helper::splitString(choice, tokens, " ");
        // if choice is init - initialize player and place on board
        if (tokens[0] == COMMAND_INIT)
        {
            // split tokens into position and direction
            Helper::splitString(tokens[1], tokens, ",");
        }
        std::cout << "\n\n";
        // if tokens size is 3
        if (tokens.size() == 3)
        {
            // create new position
            Position *position = new Position(std::stoi(tokens[0]), std::stoi(tokens[1]));
            // set direction based on input
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
                // invalid input
                Helper::printInvalidInput();
            }
            // initialize player
            player->initialisePlayer(position, direction);
            // if player cannot be placed on board, print error message
            // else set success to true as player has been placed on board
            if (!board->placePlayer(*position))
            {
                std::cout << "Unable to place player at that position\n\n";
            }
            else
            {
                success = true;
            }
        }
        else
        {
            // invalid input
            Helper::printInvalidInput();
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
        board->display(player);
        std::cout << "\n\n";
        // list options
        std::cout << "At this stage of the program, only four commands are acceptable: \n";
        std::cout << "forward (or f) \n";
        std::cout << "turn_left (or l)\n";
        std::cout << "turn_right (or r) \n";
        std::cout << "quit \n\n";
        // read input
        choice = Helper::readInput();
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
            // if player is outside bounds, print error message
            if (playerMove == OUTSIDE_BOUNDS)
            {
                // print error - split into two lines for readability
                std::cout << "The vacuum cleaner is at the edge of the board";
                std::cout << "and cannot move further in that direction \n\n";
            }
            // if player is blocked, print error message
            else if (playerMove == CELL_BLOCKED)
            {
                std::cout << "Unable to move - cell is blocked\n\n";
            }
            // if player moved, print player moved
            else if (playerMove == PLAYER_MOVED)
            {
                // print player moved
                std::cout << "Player Moved\n\n";
            }
        }

        // if choice is quit, display total number of moves, exit loop and return to main menu
        else if (choice == COMMAND_QUIT)
        {
            quit = true;
            // print total number of moves
            std::cout << "Total number of moves: " << player->moves << "\n\n";
            //reset player moves
            player->moves = 0;
        }
        // invalid input
        else
        {
            Helper::printInvalidInput();
        }
    }
}