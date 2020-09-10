#include <iostream>
#include "utilities.h"

int main()
{
	std::cout << "Enter a hexstring:\n";
	std::string hexstring;
	std::cin >> hexstring;
	std::vector<unsigned char> bytes;
	utilities::hexstringToBytes(hexstring, bytes);
	utilities::switchEndianness(bytes);
	utilities::printToHex(bytes);
	return 0;
}
