#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cctype>

void ScalarConverter::convert(const std::string &literal)
{
	LiteralType type = detect(literal);

	if (type == INVALID)
	{
		std::cout << "Error\n";
		return;
	}

	double value = parseLiteral(literal, type);
	printChar(value);
	printInt(value);
	printDouble(value);
	printFloat(value);
}

ScalarConverter::LiteralType ScalarConverter::detect(const std::string &s)
{
	if (isPseudo(s))
		return PSEUDO;
	if (s.length() == 3 && s[0] == '\'' && s[3] == '\'')
		return CHAR;

	bool dot = false;
	bool fState = false;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
			dot = true;
		else if (s[i] == 'f' && i == s.length() - 1)
			fState = true;
		else if (!std::isdigit(s[i]) && s[i] != '-' && s[i] != '+')
			return (INVALID);
	}

	if (dot && fState)
		return FLOAT;
	if (dot)
		return DOUBLE;
	return(INT);
}

bool ScalarConverter::isPseudo(const std::string &s)
{
	if (s == "nan" || s == "nanf")
		return true;
	if (s == "+inf" || s == "-inf")
		return true;
	if (s == "+inff" || s == "-inff")
		return true;
	return false;
}

double ScalarConverter::parseLiteral(const std::string &s, LiteralType type)
{
	if (type == CHAR && !s.empty())
		return static_cast<double>(s[1]);
	if (type == FLOAT && !s.empty())
		return std::strtod(s.substr(0, s.length() - 1).c_str(), NULL);
	return std::strtod(s.c_str(), NULL);
}

void ScalarConverter::printChar(double i)
{
	std::cout << "char: ";

	if (std::isnan(i) || i < 0 || i > 127)
		std::cout << "imposible\n";
	else if (!std::isprint(static_cast<char>(i)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(i) << "'" << "\n";
}

void ScalarConverter::printFloat(double i)
{
	std::cout << "float: ";
	if (std::isnan(i))
		std::cout << "nanf\n";
	else if (std::isinf(i))
		if (i < 0)
			std::cout << "-inff\n";
		else
			std::cout << "+inff\n";
	else
		std::cout << std::fixed << std::setprecision(1)
				  << static_cast<float>(i) << "f\n";
}

void ScalarConverter::printInt(double i)
{
	std::cout << "int: ";

	if(std::isnan(i) || i > std::numeric_limits<int>::max()
	|| i < std::numeric_limits<int>::min() )
		std::cout << "imposible\n";
	else
		std::cout << static_cast<int>(i) << "\n";
}

void ScalarConverter::printDouble(double i)
{
	std::cout << "double: ";

	if(std::isnan(i))
		std::cout << "nanf\n";
	else if (std::isinf(i))
		if(i > 0)
			std::cout << "+inff\n";
		else
			std::cout << "-inff\n";
	else
		std::cout << std::fixed << std::setprecision(1)
		<< i << "\n";
}
