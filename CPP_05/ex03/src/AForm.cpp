#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false),
      _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &src)
    : _name(src._name), _isSigned(src._isSigned),
      _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &src)
{
    if (this != &src)
    {
        // Only _isSigned is mutable.
        _isSigned = src._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    action();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: Grade too high!";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: Grade too low!";
}
const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm: Form not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form: " << form.getName() 
       << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Grade required to sign: " << form.getGradeToSign()
       << ", Grade required to execute: " << form.getGradeToExecute();
    return os;
}
