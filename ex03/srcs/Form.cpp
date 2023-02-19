#include "Form.hpp"

Form::~Form()
{

}

Form::Form() : _name("A38"), _signed(false), _gradeMinToSign(150), _gradeMinToExec(150)
{}

Form::Form(const Form &oth) : _name(oth._name), _signed(oth._signed),
	_gradeMinToSign(oth._gradeMinToSign), _gradeMinToExec(oth._gradeMinToExec)
{

}

Form &Form::operator=(const Form &oth)
{
	if (this == &oth)
		return *this;
	_signed = oth._signed;
	_gradeMinToSign = oth._gradeMinToSign;
	_gradeMinToExec = oth._gradeMinToExec;
	return *this;
}

Form::Form(const std::string &name, int gradeMinToSign, int gradeMinToExec)
	: _name(name), _signed(false), _gradeMinToSign(gradeMinToSign), _gradeMinToExec(gradeMinToExec)
{
	if (_gradeMinToSign < 1 || _gradeMinToExec < 1)
		throw GradeTooHighException();
	if (_gradeMinToSign > 150 || _gradeMinToExec > 150)
		throw GradeTooLowException();
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeMinToSign;
}

int Form::getGradeToExec() const
{
	return _gradeMinToExec;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeMinToSign)
		throw GradeTooLowException();
	_signed = true;
}

void Form::tryToExec(int grade) const
{
	if (!_signed)
		throw NotSignedException();
	if (grade > _gradeMinToExec)
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade can't be higher than 1";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade can't be lower than 150";
}

const char *Form::NotSignedException::what() const throw()
{
	return "The form hasn't signed yet";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	std::string sign(" hasn't signed, ");
	if (form.isSigned())
		sign = " has signed, ";
	return os << form.getName() << ", form" << sign << "grade to sign " << form.getGradeToSign()
		<< ", grade to execute " << form.getGradeToExec();
}
