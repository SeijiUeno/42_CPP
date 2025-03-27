#include <cassert>
#include <iostream>
#include "Data.hpp"
#include "Serialization.hpp"

#define BOLD(text) "\033[1m" text "\033[0m"
#define GREEN(text) "\033[1;32m" text "\033[0m"

void testMultipleData() {
	Data data1, data2;
	data1.value = 20;
	data1.name = "Beta";

	data2.value = 30;
	data2.name = "Gamma";

	std::cout << BOLD("===== Manual confirmation & Visualisation of Serialize and Deserialize! =====") << std::endl;

	std::cout << BOLD("Serialize!! : \n") << "&data1 = [ " << &data1 
			  << " ] \n &data2 = [ " << &data2 << " ]" << std::endl;
	uintptr_t raw1 = Serialization::serialize(&data1);
	uintptr_t raw2 = Serialization::serialize(&data2);
	std::cout << BOLD("After it!! : \n ") << "Raw1 = [ " << raw1 
			  << " ] \n Raw2 = [ " << raw2 << " ]" << std::endl;
	
	Data* deserialized1 = Serialization::deserialize(raw1);
	Data* deserialized2 = Serialization::deserialize(raw2);
	std::cout << BOLD("Undone!! : \n ") << "deserialized1 = [ " << deserialized1 
			  << " ] \n deserialized2 = [ " << deserialized2 << " ]" << std::endl;
	
	std::cout << BOLD("===== Assert confirmation =====") << std::endl;
	assert(deserialized1 == &data1);
	assert(deserialized2 == &data2);

	std::cout << BOLD("MultipleData PASSED Assertion!!! :\n") 
			  << deserialized1 << " == " << &data1 << "\n"
			  << deserialized2 << " == " << &data2 << std::endl;
}

int main() {
	testMultipleData();
	std::cout << GREEN("All tests passed.") << std::endl;
	return 0;
}
