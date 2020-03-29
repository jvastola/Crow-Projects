#ifndef USER
#define USER

#include <string>
#include <iostream>

/* 

This class represents a user of the system

A user has a username, password, firstName, lastName, email, and a token, all represented as strings

The first 5 fields are self explanatory, and they are passed into the constructor of User

The token field is a unique string generated for the user at the time of creation. It is used to verify the identity of a user making a request to the system. When a user logs in successfully, we send them their token. They then need to use that token for every request they make on the system. When responding to the request, we check to see if they have sent along the correct token. If so, we can fulfill the request, if not, we do not.


There must be a constructor that can build a user object, from the 5 strings, namely username, password, firstName, lastName, and email. A token is generated in the constructor and is saved.

There must also be a copy constructor.

There must be getters for each one of the 6 instance variables.

We also need to be able to compare two User objects with the == operator. They are the same if they have the same values for each of their fields.

We also need an operator for !=, between two User objects. 

Finally, we must be able to cout a User object, so we need to overload the << operator.

*/

class User {
	std::string username;
	std::string password;
	std::string firstName;
	std::string lastName;
	std::string email;
	std::string token;

public:
	User(std::string, std::string, std::string, std::string, std::string, std::string);
	User(const User&);

	std::string getUsername() const;
	std::string getPassword() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getEmail() const;
	std::string getToken() const;

	bool operator ==(const User& other) const;
	bool operator !=(const User& other) const;
	friend std::ostream& operator <<(std::ostream&, const User&);
};


#endif
