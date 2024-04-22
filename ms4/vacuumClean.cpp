#include "game.h"
#include "helper.h"

//Paragraph describing process
/*
 * The main function is the entry point of the program. The main function is responsible for 
 * displaying the main menu and starting the game. Game.cpp contains the implementation of the 
 * game class. The game class is responsible for managing the game state. Board.cpp contains 
 * the implementation of the board class. The board class is responsible for loading the game 
 * board, placing the player on the board, and moving the player. Player.cpp contains the 
 * implementation of the player class. The player class is responsible for keeping track of 
 * the player's position and direction, and changing the player's direction. Helper.cpp contains 
 * the implementation of the helper class. The helper class contains several functions to help 
 * with user input and validation. Overall, the program is structured in a modular way, with 
 * each class responsible for a specific aspect of the game.
 *
 * One problem I encountered was handling the End of File (EOF) error when the user would press
 * Ctrl+D. This would cause the program to loop indefinitely, as the user could not enter another input.
 * I added a check when the program read user input to handle this case and exit the program instead of
 * looping indefinitely.
 *
 * I also had trouble at first understanding how the starter code was structured and 
 * had to spend some time reading through the code to understand how the different classes interacted 
 * with each other. Once I understood the structure, it was easier to implement the required functionality.
 * 
 * One thing that could be improved with the start-up code is making it more readable and easier to 
 * understand. I think the start-up code could use more comments to better explain how 
 * the different classes interact with each other. 
 */



using std::string;

void showStudentInformation(string name, string id, string email)
{
    // show student information
    std::cout << "------------------------------------------------\n";
    std::cout << "Name: " + name + "\n";
    std::cout << "Student ID:" + id + " \n";
    std::cout << "Email:" + email + "\n";
    std::cout << "------------------------------------------------\n";
}

int main()
{

    // create game object
    Game game;
    // quit boolean - used to exit the game
    bool quit = false;

    // main menu loop
    while (!quit)
    {
        // main menu
        std::cout << "Welcome to Vacuum CLeaning Game! \n";
        std::cout << "----------------------------------------------\n";
        std::cout << "1. Play Game\n";
        std::cout << "2. Show student's information\n";
        std::cout << "3. Quit \n\n";
        std::cout << "Please enter your choice: ";
        // use helper get input
        string choice = Helper::readInput();
        std::cout << "\n\n";
        // if choice is 1, start game
        if (choice == "1")
        {
            game.start();
        }
        // if choice is 2, show student info
        else if (choice == "2")
        {
            showStudentInformation("Joseph Packham", "s38389789", "s3838978@student.rmit.edu.au");
        }
        // if choice is 3, quit game
        else if (choice == "3")
        {
            std::cout << "Good bye!\n\n";
            quit = true;
        }
        // if readinput returns EOF, exit game
        else if (choice == "EOF")
        {
            // exit program
            std::cout << "End of file detected. Exiting program.\n\n";
            std::exit(EXIT_SUCCESS);
        }
        else
        {
            // invalid input
            std::cout << "Invalid input. Please try again.\n\n";
        }
    }
    // exit game
    return EXIT_SUCCESS;
}
