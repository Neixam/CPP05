#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &oth)
{
	(void)oth;
}

Intern &Intern::operator=(const Intern &oth)
{
	(void)oth;
	return *this;
}

Form *Intern::makeForm(const std::string &name, const std::string &target) const
{
	static const struct
	{
		std::string name;
		Form *(*create)(const std::string&, const std::string&);
	} formsConstruct[3] =
	{
			{"robotomy request", createRobotomy },
			{"presidential request", createPresident },
			{"shrubbery request", createShrubbery }
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formsConstruct[i].name == name)
			return formsConstruct[i].create(name, target);
	}
	std::cerr << "no form for name " << name << std::endl;
	return NULL;
}

Form *Intern::createPresident(const std::string &name, const std::string &target)
{
	return new PresidentialPardonForm(name, target);
}

Form *Intern::createShrubbery(const std::string &name, const std::string &target)
{
	return new ShrubberyCreationForm(name, target);
}

Form *Intern::createRobotomy(const std::string &name, const std::string &target)
{
	return new RobotomyRequestForm(name, target);
}
