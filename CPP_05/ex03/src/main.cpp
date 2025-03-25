#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* form;

    // Test known forms.
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
        delete form;

    form = someRandomIntern.makeForm("presidential pardon", "Fry");
    if (form)
        delete form;

    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form)
        delete form;

    // Test an unknown form.
    form = someRandomIntern.makeForm("unknown form", "Target");
    if (form)
        delete form;

    return 0;
}
