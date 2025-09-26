#include "../includes/Bureaucrat.hpp"
#include <iostream>

int main() {

	//TEST 1
	std::cout << std::endl;
	std::cout << "== TEST 1 ==" << std::endl;
	try
	{
		Bureaucrat b1("B1", 1);
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//TEST 2
	std::cout << std::endl;
	std::cout << "== TEST 2 ==" << std::endl;
	try
	{
		Bureaucrat b2("B2", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//TEST 3
	std::cout << std::endl;
	std::cout << "== TEST 3 ==" << std::endl;
	try
	{
		Bureaucrat b3("B3", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//TEST 3
	std::cout << std::endl;
	std::cout << "== TEST 4 ==" << std::endl;
	try
	{
		Bureaucrat b4("B4", 150);
		std::cout << b4 << std::endl;
		b4.incrementGrade();
		std::cout << b4 << std::endl;
		b4.decrementGrade();
		std::cout << b4 << std::endl;
		b4.decrementGrade();
		std::cout << b4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}