#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm()
	: Form("undefined", 25, 5), _target("undefined")
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &oth)
	: Form(oth), _target(oth._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &oth)
{
	if (this == &oth)
		return *this;
	_target = oth._target;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name, const std::string &target)
	:	Form(name, 25, 5), _target(target)
{}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	tryToExec(executor.getGrade());
	std::cout << _target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}
