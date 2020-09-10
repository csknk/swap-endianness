#ifndef UTILITIES_H
#define UTILITIES_H
#endif

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <typeinfo>

namespace utilities {

int hexDigitToInt(char digit)
{
	digit = tolower(digit);
	if (digit >= '0' && digit <='9')
	       return (int)(digit - '0');
	else if (digit >= 'a' && digit <= 'f') {
		return (int)(digit - '1' - '0') + 10; 
	}	
	return -1;
}

int hexstringToBytes(std::string const&	hexstring, std::vector<unsigned char>& result)
{
	if (hexstring.size() % 2) {
		std::cerr << "The hexstring is not an even number of characters.\n";
		exit(EXIT_FAILURE);
	}
	
	size_t resultLength = hexstring.size() / 2;
	size_t i = 0;
	for (auto it = hexstring.begin(); it != hexstring.end(); it = it + 2) {
		int sixteens = hexDigitToInt(*it);
		int units = hexDigitToInt(*std::next(it));
		if (sixteens == -1 || units == -1) {
			std::cerr << "Invalid character.\n";
			exit(EXIT_FAILURE);
		}
		result.push_back((sixteens << 4) | units);
		i++;
	}
	return resultLength;
}
	
	
/**
 * Print a string as hexadecimal values.
 *
 * */ 
template <typename T>
void printToHex(T s)
{
	for(size_t i = 0; i < s.size(); i++) {
		std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)s[i];
	}
	std::cout << '\n';
}

/**
 *
 * return a hex string representation of the value of an integer
 *
 * */ 
std::string intToHexString1(int num)
{
	std::stringstream ss;
	ss << std::hex << num;
	return ss.str();
}

/**
 * Convert an int to a hexadecimal string, using arithmetic.
 *
 * */
std::string intToHexString2(int num)
{
	const char hexChars[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	std::string result;
	while (num) {
		char tmp = hexChars[num % 16];
		result.insert(result.begin(), tmp);
		num /= 16;
	}
	return result;
}

/**
 * Build a hex string representation of bytes.
 * 
 * */
void charToHexString(const char& c, std::string& s)
{
	std::stringstream ss;
	ss << std::setfill('0') << std::setw(2) << std::hex << (0xff & (int)c);
	s.append(ss.str());
}

template <typename T>
void switchEndianness(T& collection)
{
	size_t i = 0, j = collection.size() - 1;
	while (i < collection.size() / 2) {
		auto tmp = collection[i];
		collection[i++] = collection[j];
		collection[j--] = tmp;
	}	
}
} // utilities
