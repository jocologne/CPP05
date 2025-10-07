#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== TESTING EX02 - ALL FORM TYPES ===" << std::endl;
    std::cout << std::endl;

    // Initialize random seed for robotomy
    std::srand(std::time(0));

    try {
        std::cout << "--- Creating Bureaucrats ---" << std::endl;
        Bureaucrat president("President", 1);
        Bureaucrat minister("Minister", 5);
        Bureaucrat director("Director", 20);
        Bureaucrat clerk("Clerk", 70);
        Bureaucrat intern("Intern", 140);

        std::cout << president << std::endl;
        std::cout << minister << std::endl;
        std::cout << director << std::endl;
        std::cout << clerk << std::endl;
        std::cout << intern << std::endl;
        std::cout << std::endl;

        std::cout << "=== SHRUBBERY CREATION FORM TESTS ===" << std::endl;
        ShrubberyCreationForm shrubbery("Garden");
        std::cout << shrubbery << std::endl;
        std::cout << "--- Intern signs shrubbery form ---" << std::endl;
        intern.signForm(shrubbery);
        std::cout << "--- Clerk executes shrubbery form ---" << std::endl;
        clerk.executeForm(shrubbery);
        std::cout << std::endl;

        std::cout << "=== ROBOTOMY REQUEST FORM TESTS ===" << std::endl;
        RobotomyRequestForm robotomy("Bender");
        std::cout << robotomy << std::endl;
        
        std::cout << "--- Clerk signs robotomy form ---" << std::endl;
        clerk.signForm(robotomy);
        
        std::cout << "--- Director executes robotomy form (50% chance) ---" << std::endl;
        director.executeForm(robotomy);
        std::cout << std::endl;

        std::cout << "=== PRESIDENTIAL PARDON FORM TESTS ===" << std::endl;
        PresidentialPardonForm pardon("Ford Prefect");
        std::cout << pardon << std::endl;
        
        std::cout << "--- Director tries to sign pardon form (should work) ---" << std::endl;
        director.signForm(pardon);
        
        std::cout << "--- Director tries to execute pardon form (should FAIL) ---" << std::endl;
        director.executeForm(pardon);
        
        std::cout << "--- Minister executes pardon form (should work) ---" << std::endl;
        minister.executeForm(pardon);
        std::cout << std::endl;

        std::cout << "=== PRESIDENT TESTS ALL FORMS ===" << std::endl;
        std::cout << "--- President signs and executes all forms ---" << std::endl;
        
        ShrubberyCreationForm presidentialShrubbery("WhiteHouse");
        RobotomyRequestForm presidentialRobotomy("Marvin");
        PresidentialPardonForm presidentialPardon("Arthur Dent");
        
        president.signForm(presidentialShrubbery);
        president.executeForm(presidentialShrubbery);
        
        president.signForm(presidentialRobotomy);
        president.executeForm(presidentialRobotomy);
        
        president.signForm(presidentialPardon);
        president.executeForm(presidentialPardon);
        std::cout << std::endl;

        std::cout << "=== ERROR CASE TESTS ===" << std::endl;
        std::cout << "--- Intern tries presidential pardon (should fail at signing) ---" << std::endl;
        PresidentialPardonForm impossiblePardon("Trillian");
        intern.signForm(impossiblePardon);

    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "=== ALL TESTS COMPLETE ===" << std::endl;
    return 0;
}