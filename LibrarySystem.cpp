#include "LibrarySystem.h"
#include <iostream>

void LibrarySystem::start() {
    // Create instances of Librarian and Patron
    static const int MAX_Patrons = 100;
    int numPatrons = 0;
    Librarian librarian;
    Patron patron[MAX_Patrons];

    int role;
    do {
        // Simulate login
        std::cout << "Enter your role (1 for Librarian, 2 for Patron, 0 to exit): ";
        std::cin >> role;

        std::cin.ignore(); // Clear input buffer

        switch (role) {
            case 1:
                // Librarian login
                librarian.getDetails();
                librarian.displayMenu(patron, numPatrons);
                break;
            case 2:
            	if(numPatrons >= MAX_Patrons){
            		cout<<"No of patrons exceeded capacity"<<endl;
            		return;
				}
                // Patron login
                patron[numPatrons].getDetails();
                patron[numPatrons].displayMenu(librarian);
                numPatrons++;
                
                break;
            case 0:
                // Exit the program
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid role selected." << std::endl;
                break;
        }
    } while (role != 0);
}

