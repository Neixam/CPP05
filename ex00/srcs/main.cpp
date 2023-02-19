#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

const static std::string RED = "\033[31m";
const static std::string NEUTRAL = "\033[0m";

int main()
{
	try
	{
		Bureaucrat georges("Georges", 2);

		std::cout << georges << std::endl;
		georges.increment();
		std::cout << georges << std::endl;
		georges.increment();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << NEUTRAL << std::endl;
	}
	try
	{
		Bureaucrat john("John", 149);

		std::cout << john << std::endl;
		john.decrement();
		std::cout << john << std::endl;
		john.decrement();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << RED << e.what() << NEUTRAL << std::endl;
	}
	try
	{
		Bureaucrat patricia("Patricia", -2);

		std::cout << patricia << std::endl;
		patricia.decrement();
		std::cout << patricia << std::endl;
		patricia.decrement();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << RED << e.what() << std::endl;
	}
	return 0;
}