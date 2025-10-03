#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== TESTING EX01 - FORMS ===" << std::endl;
    std::cout << std::endl;

    try {
        std::cout << "--- Creating Bureaucrats ---" << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 50);
        Bureaucrat intern("Intern", 140);
        Bureaucrat newbie("Newbie", 150);

        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << intern << std::endl;
        std::cout << newbie << std::endl;
        std::cout << std::endl;

        std::cout << "--- Creating Shrubbery Form ---" << std::endl;
        ShrubberyCreationForm gardenForm("Garden");
        std::cout << gardenForm << std::endl;
        std::cout << std::endl;

        std::cout << "--- TEST 1: Intern tries to sign form (should work) ---" << std::endl;
        intern.signForm(gardenForm);
        std::cout << gardenForm << std::endl;
        std::cout << std::endl;

        std::cout << "--- TEST 2: Intern tries to execute form (should FAIL - grade too low) ---" << std::endl;
        intern.executeForm(gardenForm);
        std::cout << std::endl;

        std::cout << "--- TEST 3: Manager executes form (should work) ---" << std::endl;
        manager.executeForm(gardenForm);
        std::cout << std::endl;

        std::cout << "--- TEST 4: Newbie tries to sign form (should FAIL - grade too low) ---" << std::endl;
        ShrubberyCreationForm backyardForm("Backyard");
        newbie.signForm(backyardForm);
        std::cout << std::endl;

        std::cout << "--- TEST 5: Boss signs and executes new form ---" << std::endl;
        ShrubberyCreationForm parkForm("CentralPark");
        boss.signForm(parkForm);
        boss.executeForm(parkForm);
        std::cout << std::endl;

        std::cout << "--- TEST 6: Try to execute unsigned form ---" << std::endl;
        ShrubberyCreationForm unsignedForm("Forest");
        manager.executeForm(unsignedForm);
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "=== TEST COMPLETE ===" << std::endl;
    return 0;
}