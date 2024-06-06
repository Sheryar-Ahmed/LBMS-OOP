#include "Librarian.h"

void Librarian::getDetails() {
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter ID: ";
    cin >> ID;
    cin.ignore(); 
}

void Librarian::setDetails() {
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
}

void Librarian::addBook() {
	cout<<getNumBooks()<<endl;
    if (getNumBooks() >= MAX_BOOKS) {
        cout << "Library is full. Cannot add more books." << endl;
        return;
    }

    Book newBook;
    newBook.getDetails();
    books[getNumBooks()] = newBook;
    incrementNumBooks(); 
    cout << "Book added successfully." << endl;
}

bool Librarian::isBookAvailable(int index) {
        if (books[index].quantity > 0) {
            cout << "Book '" << index << "' is available." << endl;
            return true;
        }
    cout << "Book '" << "' is not available." << endl;
    return false;
}


void Librarian::removeBook() {
        if (getNumBooks() == 0) {
            cout << "No books available to remove." << endl;
            return;
        }

        int bookToRemove;
        cout << "Enter the number of the book to remove (1-" << numBooks << "): ";
        cin >> bookToRemove;

        if (bookToRemove < 1 || bookToRemove > getNumBooks()) {
            cout << "Invalid book number." << endl;
            return;
        }

        for (int i = bookToRemove - 1; i < getNumBooks() - 1; ++i) {
            books[i] = books[i + 1];
        }
        decrementNumBooks();

        cout << "Book removed successfully." << endl;
    }

void Librarian::displayBookDetails(int index) {
        if (index >= 0 && index < getNumBooks()) {
            books[index].setDetails();
        } else {
            cout << "Invalid book index." << endl;
        }
}
void Librarian::displayAllBooks() {
        cout << "Books in the library:" << endl;
        for (int i = 0; i < getNumBooks(); ++i) {
            cout << "Book " << (i + 1) << ":" << endl;
            displayBookDetails(i);
            cout << endl;
        }
}

void Librarian::updateBookQuantity(int index, int quantityChange) {
    if (index >= 0 && index < MAX_BOOKS) {
        books[index].updateQuantity(quantityChange);
    } else {
        cout << "Invalid book index." << endl;
    }
}



void Librarian::issueBook(Patron patron[], int numPatrons) {
    int patronID;
    cout << "Enter patron ID: ";
    cin >> patronID;

    // Search for the patron
    int patronIndex = -1;
    for (int i = 0; i < numPatrons; ++i) {
        if (patron[i].ID == patronID) {
            patronIndex = i;
            break;
        }
    }

    if (patronIndex == -1) {
        cout << "Patron not found." << endl;
        return;
    }

    int bookIndex;
    cout << "Enter index of the book to issue: ";
    cin >> bookIndex;

    if (isBookAvailable(bookIndex)) {
        patron[patronIndex].borrowBook(bookIndex, *this);
    } else {
        cout << "Book not available for issuing." << endl;
    }
}

void Librarian::receiveBook(Patron patron[], int numPatrons) {
    int patronID;
    cout << "Enter patron ID: ";
    cin >> patronID;

    int patronIndex = -1;
    for (int i = 0; i < numPatrons; ++i) {
        if (patron[i].ID == patronID) {
            patronIndex = i;
            break;
        }
    }

    if (patronIndex == -1) {
        cout << "Patron not found." << endl;
        return;
    }

    int bookIndex;
    cout << "Enter index of the book to receive: ";
    cin >> bookIndex;

    if (bookIndex >= 0 && bookIndex < patron[patronIndex].getNumBorrowedBooks()) {
        patron[patronIndex].returnBook(bookIndex, *this); // Pass the Librarian object
    } else {
        cout << "Invalid book index." << endl;
    }
}


void Librarian::displayFine() {
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





void Librarian::displayMenu(Patron patron[], int numPatrons) {
	int choice;
	do{
    cout << "Librarian Menu" << endl;
   	cout << "0. Back" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Remove Book" << endl;
    cout << "3. Issue Book" << endl;
    cout << "4. Receive Book" << endl;
    cout << "5. Search Book" << endl;
    cout << "6. Display All Books" << endl;
    cout << "7. Display Fines" << endl;

    cout << "Enter your choice: ";
    cin >> choice;
        cin.ignore();
    switch (choice) {
        case 1:
            // Add Book
            cout << "Adding a book..." << endl;
            addBook();
            break;
        case 2:
            // Remove Book
            cout << "Removing a book..." << endl;
            removeBook();
            break;
        case 3:
            // Issue Book
            cout << "Issuing a book..." << endl;
            issueBook(patron, numPatrons);
            break;
        case 4:
            // Receive Book
            cout << "Receiving a book..." << endl;
            receiveBook(patron, numPatrons);
            break;
        case 5:
            // Search Book
            int index;
            cout << "Searching for a book...Enter index" << endl;
            cin>>index;
            displayBookDetails(index);
            break;
        case 6:
            // Display Fines
            cout << "Displaying All Books..." << endl;
            displayAllBooks();
            break;
         case 7:
            // Display Fines
            cout << "Displaying fines..." << endl;
            displayFine();
            break;
        default:
            cout << "Moving back...." << endl;
    }
}while(choice != 0);
}
