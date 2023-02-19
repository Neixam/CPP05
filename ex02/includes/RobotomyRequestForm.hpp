#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &oth);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &oth);
	RobotomyRequestForm(const std::string &name, const std::string &target);
	void execute(const Bureaucrat &executor) const;
private:
	std::string _target;
};


#endif
