#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &src);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    // Attempts to sign a form
    void signForm(AForm &form);
    // Attempts to execute a form
    void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif // BUREAUCRAT_HPP
