#ifndef AUTHENTICATOR
#define AUTHENTICATOR

#include <string>
#include <server.h>
#include <User.h>
#include <Database.h>

/*

The Authenticator object is the part of the application that manages everything related to users. For now there is only user creation, authentication, and retrieving of user data, so it does these three things. 

In order for it to do its work, it needs a database, so we give it a pointer to one. Again, a pointer, not a copy. We don't want to copy the data unnecessarily.

Notice the trick of declaring a default constructor as private. This means that it can not be called, so an authenticator object can not be constructed without giving it a pointer to a database. Neat. Speaking of constructors, there is also a copy constructor. From now on, *always* define a copy constructor. Very bad things can happen if you don't, and the problem will not be obvious at all. 

----

In addition to being able to create itself, we have the 3 tasks, namely authenticate, which takes in a username and a password and performs authentication. It returns a JSON object formatted as follows:

If the authentication attempt is successful:
{"success": true, "token": 123456}

If authentication attempt is unsuccessful:
{"success": false}

This allows the user interface to act accordingly when users attetmpt to login. If the "success" part of the response is true, then it can store the token and use it for future interactions with the server. If the "success" part is false, then no token is sent, so the appropriate error message can be displayed on the interface.

----

The signup method takes in 5 strings, namely username, password, first name, last name, and email address. That is all that is needed to build a User object, and store it in the database. The signup method returns a JSON object that is formatted as follows:

If creation of the user was successful:
{"success": true}

If creation of the user failed (due to the fact that username already exists in database):
{"success": false, "message": "the appropriate error message, eg. Username already taken..."}

Once again, looking at the "success" field, the user interface can handle situations appropriately. It is very important to know if stuff we requested actually succeeded. Many times we simply assume that whatever we programmed will succeed, but that is never guaranteed, so it's a good idea to always check. Here we make that easier, by sending a "success" flag as part of the response.

----

The details method is an example of something that can only be executed by a user who has the token, and passes it along with their request. The idea is that I can only retrieve my own information, and not the information of anyone else, and since I only have my own token, the only successful request I will be able to make, is a request for my data. The details method takes in a username, and a token, and returns a JSON object formatted in the following way:

If the token provided is valid for that username:
{"success": true, "firstName": "John", "lastName": "Smith"}

If the token provided is not valid for that username:
{"success:" false}

*/

class Authenticator {
	Authenticator();
	Database* db;

public:
	Authenticator(Database* db);
	Authenticator(const Authenticator&);

	ucm::json authenticate(std::string, std::string);
	
	ucm::json signup(std::string, std::string, std::string, std::string, std::string);

	ucm::json details(std::string, std::string);

	friend struct AuthenticatorTest;
};


#endif
