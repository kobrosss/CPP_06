#pragma once
#include <iostream>
#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);

public:
	static void convert(const std::string &literal);

	// Type detection

	static bool isChar(const std::string &);
	static bool isFloat(const std::string &);
	static bool isInt(const std::string &);
	static bool isDouble(const std::string &);

	// detection

	enum LiteralType
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDO,
		INVALID
	};

	static LiteralType detect(const std::string &s);
	static bool isPseudo(const std::string &s);

	// parsing
	static double parseLiteral(const std::string &s, LiteralType type);

	// printing
	static void printChar(double i);
	static void printFloat(double i);
	static void printInt(double i);
	static void printDouble(double i);


};
