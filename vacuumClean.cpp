#include "game.h"
#include "helper.h"

using std::string;

void showStudentInformation(string name, string id, string email){
    std::cout << "------------------------------------------------\n";
    std::cout << "Name: " + name + "\n";
    std::cout << "Student ID:" + id + " \n";
    std::cout << "Email:" + email +  "\n";
    std::cout << "------------------------------------------------\n";
}

int main()
{
    /**
     * TODO: here's the main function. You can write the "main menu" loop/code
     * here or you can make separate functions - up to you.
     */
    int n = 0;
    int choice;
    Game game;

    while(n == 0) {
        std::cout << "Welcome to Vacuum CLeaning Game! \n";
        std::cout << "----------------------------------------------\n";
        std::cout << "1. Play Game\n";
        std::cout << "2. Show student's information\n";
        std::cout << "3. Quit \n\n";
        std::cout << "Please enter your choice: ";
        std::cin >> choice;
        std::cout << "\n\n";      

        if(choice == 1){
            game.start();
        } else if (choice == 2) {
            showStudentInformation("Joseph Packham", "s38389789", "s3838978@student.rmit.edu.au");
        } else if (choice == 3) {
            n++; 
        }


    }

    
    

    std::cout << "Good bye!\n\n";

    return EXIT_SUCCESS;
}

