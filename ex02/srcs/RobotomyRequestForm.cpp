#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm()
		: Form("undefined", 72, 45), _target("undefined")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &oth)
		: Form(oth), _target(oth._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &oth)
{
	if (this == &oth)
		return *this;
	_target = oth._target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, const std::string &target)
		:	Form(name, 72, 45), _target(target)
{}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	tryToExec(executor.getGrade());
	std::cout << "brrrrrrrrrrrzt !" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "Operation has missed !" << std::endl;
}