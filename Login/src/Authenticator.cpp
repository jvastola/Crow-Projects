#include <fstream>
#include <iostream>
#include <boost/uuid/uuid.hpp>            
#include <boost/uuid/uuid_generators.hpp> 
#include <boost/uuid/uuid_io.hpp>         
#include <Authenticator.h>

Authenticator::Authenticator(Database* db){
	this->db=db;
}

Authenticator::Authenticator(const Authenticator& other){
	this->db=other.db;
}

ucm::json Authenticator::authenticate(std::string username, std::string password){
	ucm::json response;

	response["success"] = false;
	if(db->hasKey(username)){
		User* temp = db->get(username);
		if(temp->getPassword()==password){
		response["success"] = true;
		response["token"] = temp->getToken();
		}
	}
	
	return response;
}
	
ucm::json Authenticator::signup(std::string usr, std::string pwd, std::string fname, std::string lname, std::string email){

	ucm::json response;
	if(db->hasKey(usr)){
		response["success"] = false;
		response["message"] = "Username already taken";
		return response;
	}
	boost::uuids::uuid uuid = boost::uuids::random_generator()();
	std::stringstream s;
	s << uuid;
	std::string token = s.str();

	User* temp= new User(usr,pwd,fname,lname,email,token);
	db->write(usr,temp);
	response["success"] = true;
	response["message"] = {"firstName :"+ temp->getFirstName(),"lastName :" +temp->getLastName()};
	return response;
}

ucm::json Authenticator::details(std::string username, std::string token){
	
	ucm::json response;
	ucm::json details;


	if(db->hasKey(username)){
		User* temp = db->get(username);
		details["firstName"]=temp->getFirstName();
		details["lastName"]=temp->getLastName();
		response["details"]= details;
		response["success"] = true;
	}
	else {
		response["success"] = false;
	}

	return response;
}
