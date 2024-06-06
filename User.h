	#ifndef USER_H
	#define USER_H
	
	#include <string>
	#include <iostream>
	
	using namespace std;
	
	class User {
	public:
	    string name;
	    int ID;
	
	    virtual void getDetails() = 0;
	    virtual void setDetails() = 0;
	};
	
	#endif // USER_H

