#include <iostream>
#include <sstream>
#include <boost/uuid/uuid.hpp>            
#include <boost/uuid/uuid_generators.hpp> 
#include <boost/uuid/uuid_io.hpp>  

int main(){

	boost::uuids::uuid uuid = boost::uuids::random_generator()();
	std::stringstream s;
	s << uuid;
	std::string token = s.str();

	std::cout << token << std::endl;

	return 0;
}
