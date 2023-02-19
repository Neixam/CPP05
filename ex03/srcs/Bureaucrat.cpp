#include "Bureaucrat.hpp"
#include "Form.hpp"

const static std::string RED = "\033[31m";
const static std::string GREEN = "\033[32m";
const static std::string NEUTRAL = "\033[0m";

Bureaucrat::Bureaucrat() : _name("Joe"), _grade(150)
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &oth) : _name(oth._name), _grade(oth._grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &oth)
{
	if (this == &oth)
	{
		return *this;
	}
	_grade = oth._grade;
	return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::increment()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << _name << " signed " << form.getName() << NEUTRAL << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << RED << _name << " couldn’t sign " << form.getName()
			<< " because: Bureaucrat's grade is too low" << NEUTRAL << std::endl;
	}
}

void Bureaucrat::executeForm(const Form &form) const
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << _name << " executed " << form.getName() << NEUTRAL << std::endl;
	}
	catch (Form::NotSignedException &notSignedException)
	{
		std::cout << RED << _name << " couldn’t execute " << form.getName() << " because: "
				  << notSignedException.what() << NEUTRAL << std::endl;
	}
	catch (Form::GradeTooLowException &gradeTooLowException)
	{
		std::cout << RED << _name << " couldn’t execute " << form.getName()
				  << " because: Bureaucrat's grade is too low" << NEUTRAL << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade can't be higher than 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade can't be lower than 150";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
