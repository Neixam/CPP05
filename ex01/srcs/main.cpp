#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

const static std::string RED = "\033[31m";
const static std::string NEUTRAL = "\033[0m";

int main()
{
	try
	{
		Form a38("A38", 0, 0);

		std::cout << a38 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << NEUTRAL << std::endl;
	}
	try
	{
		Form a38("A38", 1, 151);

		std::cout << a38 << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << RED << e.what() << NEUTRAL << std::endl;
	}
	try
	{
		Form a38("A38", -1, 150);

		std::cout << a38 << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << RED << e.what() << NEUTRAL << std::endl;
	}
	try
	{
		Form a38("A38", 41, 20);
		Bureaucrat john("John", 49);
		Bureaucrat patricia("Patricia", 39);

		std::cout << a38 << std::endl;
		std::cout << john << std::endl;
		std::cout << patricia << std::endl;
		john.signForm(a38);
		std::cout << a38 << std::endl;
		patricia.signForm(a38);
		std::cout << a38 << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << RED << e.what() << std::endl;
	}
	return 0;
}