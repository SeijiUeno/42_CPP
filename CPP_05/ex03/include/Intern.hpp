#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &src);
    Intern &operator=(const Intern &src);
    ~Intern();

    // Creates a new form based on the formName and target.
    // If formName is not recognized, prints an error and returns NULL.
    AForm* makeForm(const std::string &formName, const std::string &target);
};

#endif // INTERN_HPP
