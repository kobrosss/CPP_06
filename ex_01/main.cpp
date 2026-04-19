#include <iostream>
#include "Serialize.hpp"

int main()
{
	Data data;

	data.id = 228337;

	Data *og = &data;

	uintptr_t raw = Serializer::serialize(og);
	Data *restored = Serializer::deserialize(raw);

	std::cout << "Original: "<< og << std::endl;
	std::cout << "Restored: "<< restored << std::endl;
	std::cout << "Original id: "<< og->id << std::endl;
	std::cout << "Restored id: "<< restored->id << std::endl;


	if(og == restored)
		std::cout << "Yuppi"<< std::endl;
}
