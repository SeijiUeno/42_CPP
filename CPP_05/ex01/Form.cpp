#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &src)
    : _name(src._name), _isSigned(src._isSigned),
      _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

Form &Form::operator=(const Form &src)
{
    if (this != &src) {
        _isSigned = src._isSigned;
    }
    return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return _name; }

bool Form::isSigned() const { return _isSigned; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form: " << f.getName() 
       << ", Signed: " << (f.isSigned() ? "Yes" : "No")
       << ", Grade required to sign: " << f.getGradeToSign()
       << ", Grade required to execute: " << f.getGradeToExecute();
    return os;
}
