#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
public:
	Form();
	~Form();
	Form(const Form &oth);
	Form &operator=(const Form &oth);
	Form(const std::string &name, int gradeMinToSign, int gradeMinToExec);

	const std::string &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	void beSigned(const Bureaucrat &bureaucrat);
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
private:
	const std::string _name;
	bool _signed;
	int _gradeMinToSign;
	int _gradeMinToExec;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
