#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP


#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &oth);
	Intern &operator=(const Intern &oth);
	Form *makeForm(const std::string &name, const std::string &target) const;
private:
	static Form *createPresident(const std::string &name, const std::string &target);
	static Form *createShrubbery(const std::string &name, const std::string &target);
	static Form *createRobotomy(const std::string &name, const std::string &target);
};


#endif
