#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define BOLD(text) "\033[1m" text "\033[0m"

void testFormCreation() {
    std::cout << BOLD("========== FORM TESTS ==========") << std::endl;

    std::cout << BOLD("Test 1: Creating 'Standard' form (76 to sign, 76 to execute)") << std::endl;
    try {
        Form standard("Standard", 76, 76);
        std::cout << "SUCCESS: " << standard << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Invalid signing grade (-1)
    std::cout << BOLD("Test 2: Creating 'Pope Can Sign' form (-1 to sign, 76 to execute)") << std::endl;
    try {
        Form pope("Pope Can Sign", -1, 76);
        std::cout << "SUCCESS: " << pope << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Invalid execution grade (0)
    std::cout << BOLD("Test 3: Creating 'You Better Call Batman' form (76 to sign, 0 to execute)") << std::endl;
    try {
        Form batman("You Better Call Batman", 76, 0);
        std::cout << "SUCCESS: " << batman << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Invalid signing grade (151)
    std::cout << BOLD("Test 4: Creating Error form (151 to sign(error), 76 to execute)") << std::endl;
    try {
        Form amoeba("Amoeba Can Sign", 151, 76);
        std::cout << "SUCCESS: " << amoeba << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Invalid execution grade (200)
    std::cout << BOLD("Test 5: Creating form (76 to sign, 200 to execute)") << std::endl;
    try {
        Form dog("Creating Form", 76, 200);
        std::cout << "SUCCESS: " << dog << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}


void testSignature() {
    std::cout << BOLD("========== SIGNATURE TESTS ==========") << std::endl;


    Bureaucrat junior("Junior Bureaucrat", 150);
    Bureaucrat average;
    Bureaucrat boss("Boss", 1);

    // Create a form that requires a grade of 75 to sign and 20 to execute
    Form form("form_75_20", 75, 20);
    std::cout << "Form details: " << form << std::endl;
    std::cout << std::endl;

    std::cout << BOLD("Test A: Junior attempts to sign the form:") << std::endl;
    std::cout << junior << std::endl;
    junior.signForm(form);
    std::cout << std::endl;

    // Average Bureaucrat's signing attempt: may initially fail
    std::cout << BOLD("Test B: Average Bureaucrat attempts to sign the form:") << std::endl;
    std::cout << average << std::endl;
    average.signForm(form);
    std::cout << std::endl;

    // Improve Average Bureaucrat's grade and try again
    std::cout << BOLD("Test C: Average Bureaucrat improves his grade and tries again:") << std::endl;
    average.incrementGrade();
    average.signForm(form);
    std::cout << std::endl;

    // succeed regardless of form status
    std::cout << BOLD("Test D: Boss attempts to sign the form:") << std::endl;
    std::cout << boss << std::endl;
    boss.signForm(form);
    std::cout << std::endl;
}

int main() {
    testFormCreation();
    testSignature();
    return 0;
}
