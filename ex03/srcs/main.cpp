#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

const static std::string RED = "\033[31m";
const static std::string NEUTRAL = "\033[0m";

int main()
{
	srand(time(NULL));
	{
		Intern someRandomIntern;
		Bureaucrat toto("Thomas", 7);
		Form* rrf;
		Form* rpf;
		Form* rsf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rsf = someRandomIntern.makeForm("shrubbery request", "plop");
		rpf = someRandomIntern.makeForm("presidential request", "Joe");
		std::cout << *rrf << std::endl;
		std::cout << *rpf << std::endl;
		std::cout << *rsf << std::endl;
		toto.signForm(*rrf);
		toto.signForm(*rpf);
		toto.signForm(*rsf);
		toto.executeForm(*rrf);
		toto.executeForm(*rpf);
		toto.executeForm(*rsf);
	}
	{
		Intern someRandomIntern;
		Form *rrf = someRandomIntern.makeForm("choco request", "Bender");

		if (rrf == NULL)
			std::cout << "some disaster" << std::endl;
	}
	return 0;
}