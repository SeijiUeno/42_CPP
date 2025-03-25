#include "Bureaucrat.hpp"

void testValidCreation() {
    std::cout << "=== Test: Valid Bureaucrat Creation ===" << std::endl;
    try {
        Bureaucrat b("John", 100);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testGradeTooHighOnCreation() {
    std::cout << "=== Test: Grade Too High on Creation ===" << std::endl;
    try {
        Bureaucrat b("High", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testGradeTooLowOnCreation() {
    std::cout << "=== Test: Grade Too Low on Creation ===" << std::endl;
    try {
        Bureaucrat b("Low", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testIncrementException() {
    std::cout << "=== Test: Increment Exception ===" << std::endl;
    try {
        Bureaucrat b("Alice", 1);
        std::cout << "Before increment: " << b << std::endl;
        b.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testDecrementException() {
    std::cout << "=== Test: Decrement Exception ===" << std::endl;
    try {
        Bureaucrat b("Bob", 150);
        std::cout << "Before decrement: " << b << std::endl;
        b.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void testCopyAndAssignment() {
    std::cout << "=== Test: Copy Constructor and Assignment Operator ===" << std::endl;
    try {
        Bureaucrat original("Original", 50);
        std::cout << "Original: " << original << std::endl;
        
        Bureaucrat copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        Bureaucrat assigned("Assigned", 100);
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    testValidCreation();
    testGradeTooHighOnCreation();
    testGradeTooLowOnCreation();
    testIncrementException();
    testDecrementException();
    testCopyAndAssignment();
    return (0);
}
