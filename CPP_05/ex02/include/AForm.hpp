#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &src);
    AForm &operator=(const AForm &src);
    virtual ~AForm();

    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &b);

    // Checks whether the form is signed and if the executor's grade is sufficient,
    // then calls the pure virtual function action().
    void execute(Bureaucrat const & executor) const;

    // Pure virtual function to be implemented by concrete forms
    virtual void action() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif // AFORM_HPP
