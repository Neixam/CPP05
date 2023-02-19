#include <exception>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const static std::string RED = "\033[31m";
const static std::string NEUTRAL = "\033[0m";

int main()
{
	srand(time(NULL));
	{
		PresidentialPardonForm a38("A38", "John1");
		RobotomyRequestForm b12("B12", "Patrice1");
		ShrubberyCreationForm c443("C443", "garden1");
		Bureaucrat patricia("Patricia", 1);
		Bureaucrat joe("Joe", 150);

		std::cout << "-------------------- TEST 1 -----------------------" << std::endl;
		std::cout << a38 << std::endl;
		std::cout << b12 << std::endl;
		std::cout << c443 << std::endl;
		std::cout << patricia << std::endl;
		std::cout << joe << std::endl;

		patricia.signForm(a38);
		patricia.signForm(b12);
		patricia.signForm(c443);
		std::cout << a38 << std::endl;
		std::cout << b12 << std::endl;
		std::cout << c443 << std::endl;
		joe.executeForm(a38);
		joe.executeForm(b12);
		joe.executeForm(c443);
	}
	{
		PresidentialPardonForm a38("A39", "John2");
		RobotomyRequestForm b12("B13", "Patrice2");
		ShrubberyCreationForm c443("C444", "garden2");
		Bureaucrat patricia("Patricia", 150);
		Bureaucrat joe("Joe", 1);

		std::cout << "-------------------- TEST 2 -----------------------" << std::endl;
		std::cout << a38 << std::endl;
		std::cout << b12 << std::endl;
		std::cout << c443 << std::endl;
		std::cout << patricia << std::endl;
		std::cout << joe << std::endl;

		patricia.signForm(a38);
		patricia.signForm(b12);
		patricia.signForm(c443);
		std::cout << a38 << std::endl;
		std::cout << b12 << std::endl;
		std::cout << c443 << std::endl;
		joe.executeForm(a38);
		joe.executeForm(b12);
		joe.executeForm(c443);
	}
	{
		PresidentialPardonForm a38("A40", "John3");
		RobotomyRequestForm b12("B14", "Patrice3");
		ShrubberyCreationForm c443("C445", "garden3");
		Bureaucrat patricia("Patricia", 1);
		Bureaucrat joe("Joe", 1);

		std::cout << "-------------------- TEST 3 -----------------------" << std::endl;
		std::cout << a38 << std::endl;
		std::cout << b12 << std::endl;
		std::cout << c443 << std::endl;
		std::cout << patricia << std::endl;
		std::cout << joe << std::endl;

		patricia.signForm(a38);
		patricia.signForm(b12);
		patricia.signForm(c443);
		std::cout << a38 << std::endl;
		std::cout << b12 << std::endl;
		std::cout << c443 << std::endl;
		joe.executeForm(a38);
		joe.executeForm(b12);
		joe.executeForm(c443);
	}
	return 0;
}