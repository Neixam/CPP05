#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &oth);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &oth);
	ShrubberyCreationForm(const std::string &name, const std::string &target);
	void execute(const Bureaucrat &executor) const;
private:
	std::string _target;
	static const std::string _tree;
};

#endif
