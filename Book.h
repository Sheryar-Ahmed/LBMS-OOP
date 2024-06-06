#include <string>
#include <iostream>

using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    int pub_year;
    string genre;
    int quantity;

    void getDetails();
    void setDetails();
    void updateQuantity(int quantityChange);
    bool checkAvailability();
};
