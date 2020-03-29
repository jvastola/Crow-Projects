#ifndef DATABASE
#define DATABASE

#include <unordered_map>
#include <string>
#include <User.h>

/*

This Database object stores information about users. It is not as much a database in real life as much as it is just a table, but whatever.

There are two versions of this data storage object. Persistent and in-memory only. When constructing the object, if we specify a file, then the data will be stored in that file, and so the storage is persistent, meaning that even if we quit the application or restart our computer, the data will be preserved because it is in a file on the hard drive.

If we use the default constructor, this creates an in-memory only storage, meaning that when we quit the application or restart our computer, the data is lost. Each of those versions is useful for different things. Think about unit tests. Some of them can be performed with only in-memory storage.

The Database object (whether it is persistent or not) stores data in a hash map, where username is the key, and a pointer to a User object is the value. The reason we store a pointer, and not a copy of the user object is precisely because we do not want to make copies of all the user data every time we want to use it.

An example of what a database file might look like is:

----------------------------------------------------------------------
| Key	|	Value                                                    |
----------------------------------------------------------------------
| jack	|	{jack, abc123, Jack, Roberts, jack@yahoo.com, 1233456}   |
| jill	|	{jill, password, Jill, Richards, jill@yahoo.com, 654321} |
----------------------------------------------------------------------

The idea is that we can quickly (O(1) time) get all the data of a user if we only know their username. In order for this to work, all usernames must be unique (hashmap keys must be unique), which works out great as usernames are unique. In Database terms, we call the username a primary key.

So the methods that our database needs to support are, a hasKey method that takes in a string, and returns true if the database contains a key matching the string. In other words, we are checking if a given username exists.

There should also be a get method that takes in a key (username), and returns the User object assosiated to that key. Of course it returns it as a pointer because we do not want to make copies of all the data all the time.

Finally, there is a write method, that takes a username as a string, as well as everything that's needed to build a User object, and creates it in the database. If we are on a persistent database, then this change must also be written to the file.

We overload == and != operators, so that we can compare two databases (this is for unit testing purposes).
We also overload the << operator, also for debugging and unit testing purposes.

While on the topic of unit testing, we notice that there are some private functions in the Database object, and if we wanted to unit test them, we wouldn't have access to them. We therefore declare the class (or struct) DatabaseTest to be a friend of the class. The DatabaseTest struct is the Context for the Database unit tests, defined in test.cpp. Since it is now declared as a friend, it will have access to all the private stuff.
*/

class Database {
	std::string db_path;
	std::unordered_map<std::string, User*> storage;
	
	bool checkFile(std::string);
	void readDb();

	bool persistent;

public:
	Database();
	Database(std::string);
	Database(const Database&);

	bool hasKey(std::string);
	User* get(std::string);
	void write(std::string, User*);

	bool operator == (const Database&) const;
	bool operator != (const Database&) const;
	friend std::ostream& operator <<(std::ostream& os, const Database& db);

	friend struct DatabaseTest;

	~Database();
};



#endif
