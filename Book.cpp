#include "Book.h"

void Book::getDetails() {
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    cin >> ISBN;
    cout << "Enter publication year: ";
    cin >> pub_year;
    cout << "Enter genre: ";
    cin >> genre;
    cout << "Enter quantity: ";
    cin >> quantity;
}


void Book::setDetails() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Publication Year: " << pub_year << endl;
    cout << "Genre: " << genre << endl;
    cout << "Quantity: " << quantity << endl;
}

bool Book::checkAvailability() {
    if (quantity > 0) {
        quantity--;
        return true;
    }
    else {
        return false;
    }
}

void Book::updateQuantity(int quantityChange) {
    quantity += quantityChange;
    if (quantity < 0) {
        quantity = 0;
    }
}
