#include "Patron.h"
#include "Librarian.h" // Include the header file for the Librarian class
#include <iostream> // Include <iostream> for standard input/output

void Patron::getDetails() {
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter ID: ";
    cin >> ID;
    cin.ignore(); // Clear input buffer
    cout << "Enter contact information: ";
    getline(cin, contact_info);
}

void Patron::setDetails() {
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Contact Information: " << contact_info << endl;
}

void Patron::borrowBook(const int& index, Librarian& librarian) {
    cout << "Received index: " << index << endl; // Add this line
    // Check if the book is available in the library
    if (librarian.isBookAvailable(index)) {
        // Borrow the book
        if (getNumBorrowedBooks() < MAX_BORROWED_BOOKS) {
            borrowedBooks[getNumBorrowedBooks()] = index;
            incrementNumBorrowedBooks();
            cout << "Book borrowed successfully." << endl;
            // Update book quantity in the library
            librarian.updateBookQuantity(index, -1);
        } else {
            cout << "You have already borrowed the maximum number of books." << endl;
        }
    } else {
        cout << "The book is not available for borrowing." << endl;
    }
}

void Patron::returnBook(const int& index, Librarian& librarian) {
	    cout << "Received index: " << index << endl; // Add this line
    // Check if the index is within the range of borrowed books
    if (index >= 0 && index < getNumBorrowedBooks()) {
        // Get the index of the book in the library
        int bookIndex = borrowedBooks[index];
        
        // Return the book
        borrowedBooks[index] = borrowedBooks[getNumBorrowedBooks() - 1];
        decrementNumBorrowedBooks();
        cout << "Book returned successfully." << endl;
        
        // Update book quantity in the library
        librarian.updateBookQuantity(bookIndex, 1);
    } else {
        cout << "Invalid book index." << endl;
    }
}

void Patron::viewFine() {
    double bookPrice;
    cout << "Enter the price of the book: Rs.";
    cin >> bookPrice;

    int borrowDay, borrowMonth, borrowYear;
    cout << "Enter the borrow date (DD MM YYYY): ";
    cin >> borrowDay >> borrowMonth >> borrowYear;

    int returnDay, returnMonth, returnYear;
    cout << "Enter the return date (DD MM YYYY): ";
    cin >> returnDay >> returnMonth >> returnYear;

    double fine = 0;
    if (returnYear > borrowYear || returnMonth > borrowMonth + 1 || (returnMonth == borrowMonth + 1 && returnDay > borrowDay)) {
        fine = 500 + bookPrice;
    } else {
        fine = bookPrice;
    }

    cout << "Fine for the book: Rs." << fine << endl;
}

void Patron::displayMenu(Librarian& librarian) {
    int choice;
    do {
        cout << "Patron Menu" << endl;
    	cout << "0. Back" << endl;
        cout << "1. Browse Books" << endl;
        cout << "2. Borrow Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. View Fines" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Browsing books..." << endl;
                librarian.displayAllBooks();
                break;
            case 2:
            	int index;
                cout << "Borrowing a book...Enter index of the book" << endl;
                cin>>index;
                borrowBook(index, librarian);
                break;
            case 3:
            	int indexReturn;
                cout << "Returning a book...Enter index of the book" << endl;
                cin>>indexReturn;
                returnBook(indexReturn, librarian);
                break;
            case 4:
                viewFine();
                break;
            default:
                cout << "Moving back...." << endl;
        }
    } while (choice != 0);
}

