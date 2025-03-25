#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade)
{
    if (grade < 1)
        throw std::runtime_error("Bureaucrat: Grade too high!");
    if (grade > 150)
        throw std::runtime_error("Bureaucrat: Grade too low!");
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : _name(src._name), _grade(src._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src) {
        _grade = src._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw std::runtime_error("Bureaucrat: Grade too high!");
    --_grade;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw std::runtime_error("Bureaucrat: Grade too low!");
    ++_grade;
}

void Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
