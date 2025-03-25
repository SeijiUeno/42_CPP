#include "Intern.hpp"
#include "concrete/ShrubberyCreationForm.hpp"
#include "concrete/RobotomyRequestForm.hpp"
#include "concrete/PresidentialPardonForm.hpp"

typedef AForm* (*FormCreator)(const std::string &target);

AForm* createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* createPardon(const std::string &target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {
    // Nothing to initialize
}

Intern::Intern(const Intern &src) {
    (void)src;
}

Intern &Intern::operator=(const Intern &src) {
    (void)src;
    return *this;
}

Intern::~Intern() {
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    struct FormEntry {
        const char* name;
        FormCreator creator;
    };
    const FormEntry forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPardon}
    };

    const int n = sizeof(forms) / sizeof(FormEntry);
    for (int i = 0; i < n; i++) {
        if (formName == forms[i].name) {
            AForm* form = forms[i].creator(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cout << "Intern: Unknown form " << formName << std::endl;
    return NULL;
}
