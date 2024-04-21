#include "game.h"
#include "helper.h"

//Paragraph describing process
/* In this assignment, I have 
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
