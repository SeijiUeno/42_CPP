#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serialization {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serialization();
	Serialization(const Serialization& src);
	Serialization& operator=(const Serialization&);
	~Serialization();
};

#endif
