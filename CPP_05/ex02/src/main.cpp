#include "Bureaucrat.hpp"
#include "concrete/ShrubberyCreationForm.hpp"
#include "concrete/RobotomyRequestForm.hpp"
#include "concrete/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    // Create Bureaucrats with varying grades.
    Bureaucrat boss("Boss", 1);
    Bureaucrat average("Average", 50);
    Bureaucrat clerk("Clerk", 150);

    // Create concrete forms.
    ShrubberyCreationForm shrubbery("Home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Fry");

    std::cout << "\n-- Signing Forms --" << std::endl;
    try {
        boss.signForm(shrubbery);
        boss.signForm(robotomy);
        boss.signForm(pardon);
    }
    catch (std::exception &e) {
        std::cerr << "Error signing form: " << e.what() << std::endl;
    }

    std::cout << "\n-- Executing Forms --" << std::endl;
    // Boss (grade 1) should be able to execute all forms.
    boss.executeForm(shrubbery);
    boss.executeForm(robotomy);
    boss.executeForm(pardon);

    std::cout << "\n-- Testing with Insufficient Grade --" << std::endl;
    // Clerk (grade 150) has too low a grade and should fail.
    clerk.executeForm(shrubbery);

    std::cout << "\n-- Testing Execution on Unsigned Form --" << std::endl;
    // Create a form that is not signed.
    ShrubberyCreationForm unsignedForm("Office");
    boss.executeForm(unsignedForm);

    return 0;
}
