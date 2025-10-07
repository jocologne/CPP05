#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== TESTING EX02 - ROBOTOMY REQUEST FORM ===" << std::endl;
    std::cout << std::endl;

    // Initialize random seed for robotomy
    std::srand(std::time(0));

    try {
        std::cout << "--- Creating Bureaucrats ---" << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat doctor("Doctor", 40);
        Bureaucrat intern("Intern", 70);
        Bureaucrat newbie("Newbie", 150);

        std::cout << boss << std::endl;
        std::cout << doctor << std::endl;
        std::cout << intern << std::endl;
        std::cout << newbie << std::endl;
        std::cout << std::endl;

        std::cout << "--- Creating Robotomy Request Form ---" << std::endl;
        RobotomyRequestForm robotomyForm("Bender");
        std::cout << robotomyForm << std::endl;
        std::cout << std::endl;

        std::cout << "--- TEST 1: Intern tries to sign form (should work) ---" << std::endl;
        intern.signForm(robotomyForm);
        std::cout << robotomyForm << std::endl;
        std::cout << std::endl;

        std::cout << "--- TEST 2: Intern tries to execute form (should FAIL - grade too low) ---" << std::endl;
        intern.executeForm(robotomyForm);
        std::cout << std::endl;

        std::cout << "--- TEST 3: Doctor executes form (should work - 50% chance) ---" << std::endl;
        doctor.executeForm(robotomyForm);
        std::cout << std::endl;

        std::cout << "--- TEST 4: Newbie tries to sign form (should FAIL - grade too low) ---" << std::endl;
        RobotomyRequestForm robotomyForm2("R2D2");
        newbie.signForm(robotomyForm2);
        std::cout << std::endl;

        std::cout << "--- TEST 5: Boss signs and executes multiple times (see 50% chance) ---" << std::endl;
        RobotomyRequestForm robotomyForm3("C3PO");
        boss.signForm(robotomyForm3);
        
        for (int i = 0; i < 3; i++) {
            std::cout << "Attempt " << (i + 1) << ": ";
            boss.executeForm(robotomyForm3);
        }
        std::cout << std::endl;

        std::cout << "--- TEST 6: Try to execute unsigned form ---" << std::endl;
        RobotomyRequestForm unsignedForm("Terminator");
        doctor.executeForm(unsignedForm);
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "=== TEST COMPLETE ===" << std::endl;
    return 0;
}