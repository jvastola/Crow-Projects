#include <igloo/igloo.h>
#include <Authenticator.h>
#include <Database.h>
#include <User.h>
#include <stdio.h>

using namespace igloo;

Context(UserTest){
	User user = User("jsoap", "abc123", "Joe", "Soap", "joe@yahoo.com", "123456");
	Spec(CanGetUsername){
		Assert::That(user.getUsername(), Equals("jsoap"));
	}

	Spec(CanGetPassword){
		Assert::That(user.getPassword(), Equals("abc123"));
	}

	Spec(CanGetFirstName){
		Assert::That(user.getFirstName(), Equals("Joe"));
	}

	Spec(CanGetLastName){
		Assert::That(user.getLastName(), Equals("Soap"));
	}

	Spec(CanGetEmail){
		Assert::That(user.getEmail(), Equals("joe@yahoo.com"));
	}

	Spec(CanGetToken){
		Assert::That(user.getToken(), Equals("123456"));
	}

};

Context(DatabaseTest){
	Spec(fileExists){
		std::string path = "misc/test_db.txt";
		std::string wrong = "misc/something.txt";
		Database db(path);
		Assert::That(db.checkFile(path), IsTrue());
		Assert::That(db.checkFile(wrong), IsFalse());
	}

	Spec(CreateDBFileIfNotExist){
		remove("misc/newlyCreated.txt");
		std::string wrong = "misc/newlyCreated.txt";
		Database db(wrong);
		Assert::That(db.checkFile(wrong), IsTrue());
	}

	Spec(ReadDB){
		Database db("misc/test_db.txt");
		Database expected;
		expected.storage.insert({"angelo", new User("angelo", "abc123", "Angelo", "Kyrilov", "akyrilov@ucmerced.edu", "1a692274-c2c7-4571-8720-286b3ab2cbfe")});
		expected.storage.insert({"john", new User("john", "abc123", "John", "Smith", "jsmith@ucmerced.edu", "529bd0bd-06d5-46d8-a465-2e2e166039ee")});

		Assert::That(db, Equals(expected));
	}

	Spec(DatabaseHasKey){
		Database db("misc/test_db.txt");
		Assert::That(db.hasKey("angelo"), IsTrue());
		Assert::That(db.hasKey("trudy"), IsFalse());
	}

	Spec(DatabaseCanWriteRecords){
		Database db;
		db.write("angelo", new User("angelo", "abc123", "Angelo", "Kyrilov", "akyrilov@ucmerced.edu", "1a692274-c2c7-4571-8720-286b3ab2cbfe"));
		db.write("john", new User("john", "abc123", "John", "Smith", "jsmith@ucmerced.edu", "529bd0bd-06d5-46d8-a465-2e2e166039ee"));

		Database expected;
		expected.storage.insert({"angelo", new User("angelo", "abc123", "Angelo", "Kyrilov", "akyrilov@ucmerced.edu", "1a692274-c2c7-4571-8720-286b3ab2cbfe")});
		expected.storage.insert({"john", new User("john", "abc123", "John", "Smith", "jsmith@ucmerced.edu", "529bd0bd-06d5-46d8-a465-2e2e166039ee")});

		Assert::That(db, Equals(expected));
	}

	Spec(DatabaseGetRecord){
		Database db("misc/test_db.txt");
		User* expected = new User("angelo", "abc123", "Angelo", "Kyrilov", "akyrilov@ucmerced.edu", "1a692274-c2c7-4571-8720-286b3ab2cbfe");

		User* actual = db.get("angelo");

		Assert::That(*actual, Equals(*expected));

		delete expected; 
	}


};


Context (AuthenticatorTest){

	Spec(AuthenticateRealUser){
		Database db("misc/test_db.txt");
		Authenticator auth(&db);
		ucm::json actual = auth.authenticate("angelo", "abc123");
		ucm::json expected;
		expected["success"] = true;
		expected["token"] = "1a692274-c2c7-4571-8720-286b3ab2cbfe";
		Assert::That(actual, Equals(expected));
	}

	Spec(DenyFakeUser){
		Database db("misc/test_db.txt");
		Authenticator auth(&db);
		ucm::json attempt = auth.authenticate("trudy", "stolen_password");
	
		Assert::That(attempt["success"], IsFalse());
	}

	Spec(SignupNewUser){
		remove("misc/empty.txt");
		Database db("misc/empty.txt");
		Authenticator auth(&db);
		ucm::json response = auth.signup("jane", "abc123", "Jane", "Smith", "jsmith2@ucmerced.edu");
		Assert::That(response["success"], IsTrue());

	}

	Spec(TryToSignupExistingUser){
		Database db("misc/empty.txt");
		Authenticator auth(&db);
		ucm::json response = auth.signup("jane", "abc123", "Jane", "Smith", "jsmith2@ucmerced.edu");
		Assert::That(response["success"], IsFalse());

	}
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
