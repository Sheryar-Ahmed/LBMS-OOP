	#include "User.h"
	#include "Book.h"
	#include "Patron.h"
	class Librarian : public User {
		private:
	    static const int MAX_BOOKS = 100;
	    Book books[MAX_BOOKS];
	    int numBooks = 0;
	public:
		int getNumBooks() const {
        	return numBooks;
    	}
    	void incrementNumBooks() {
        	numBooks++;
    	}
		void decrementNumBooks() {
        	numBooks--;
    	}		
	    void getDetails() override;
	    void setDetails() override;
	    void displayMenu(Patron patron[], int numPatrons);
	    void addBook();
	    void removeBook();
	    void displayBookDetails(int index);
	    void issueBook(Patron patron[], int numPatrons);
	    void displayFine();
	    void receiveBook(Patron patron[], int numPatrons);
	    void displayAllBooks();
	    bool isBookAvailable(int index);
	    void updateBookQuantity(int index, int quantityChange);
	};
