#ifndef PATRON_H
#define PATRON_H

#include "User.h"
#include <string>

using namespace std;

class Librarian;

class Patron : public User {
private:
    static const int MAX_BORROWED_BOOKS = 10;
    string contact_info;
    int borrowedBooks[MAX_BORROWED_BOOKS];
    int numBorrowedBooks = 0;

public:
    int getNumBorrowedBooks() {
        return numBorrowedBooks;
    }

    void incrementNumBorrowedBooks() {
        if (numBorrowedBooks < MAX_BORROWED_BOOKS) {
            numBorrowedBooks++;
        }
    }

    void decrementNumBorrowedBooks() {
        if (numBorrowedBooks > 0) {
            numBorrowedBooks--;
        }
    }
	void findPatronByid(const int& id);
    void getDetails() override;
    void setDetails() override;
    void displayMenu(Librarian& librarian);
    void viewFine();
    void borrowBook(const int& index, Librarian& librarian); // Corrected indentation
    void returnBook(const int& index, Librarian& librarian); // Corrected indentation
};

#endif // PATRON_H

