#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &oth);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &oth);
	PresidentialPardonForm(const std::string &name, const std::string &target);
	void execute(const Bureaucrat &executor) const;
private:
	std::string _target;
};

#endif
