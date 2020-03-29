#include <User.h>

User::User(std::string usr, std::string pwd, std::string fname, std::string lname, std::string eml, std::string tkn){
	this->username=usr;
	this->password=pwd;
	this->firstName=fname;
	this->lastName=lname;
	this->email=eml;
	this->token=tkn;
}

User::User(const User& other){
	this->username=other.username;
	this->password=other.password;
	this->firstName=other.firstName;
	this->lastName=other.lastName;
	this->email=other.email;
	this->token=other.token;
}

std::ostream& operator <<(std::ostream& os, const User& u){
	os << u.getUsername() << " : " << u.getPassword() <<  ":" << u.getFirstName()<<  ":" << u.getLastName()<<  ":"<< u.getPassword()<<  ":" << u.getToken()<<  ":"<<u.getUsername();
	
	return os;
}

bool User::operator ==(const User& other) const {
	return other.username == this->username && other.password==this->password && this->firstName==other.firstName && this->lastName==other.lastName && this->email==other.email && this->token==other.token;
}

bool User::operator !=(const User& other) const {
	return other.username != this->username || other.password!=this->password || this->firstName!=other.firstName || this->lastName!=other.lastName ||this->email!=other.email ||this->token!=other.token;
}

std::string User::getUsername() const {
	return username;
}

std::string User::getPassword() const {
	return password;
}

std::string User::getFirstName() const {
	return firstName;
}

std::string User::getLastName() const {
	return lastName;
}

std::string User::getEmail() const {
	return email;
}

std::string User::getToken() const {
	return token;
}
