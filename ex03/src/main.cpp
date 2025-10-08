#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	std::cout << "=== TESTING EX03 - INTERN ===" << std::endl;
	std::cout << std::endl;

	// Initialize random seed for robotomy
	std::srand(std::time(0));

	try {
		std::cout << "--- Creating Bureaucrats and Intern ---" << std::endl;
		Bureaucrat boss("Boss", 1);
		Intern someRandomIntern;
		
		std::cout << boss << std::endl;
		std::cout << std::endl;

		std::cout << "=== TEST 1: Create Shrubbery Creation Form ===" << std::endl;
		AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Home");
		if (shrubberyForm) {
			boss.signForm(*shrubberyForm);
			boss.executeForm(*shrubberyForm);
			delete shrubberyForm;
		}
		std::cout << std::endl;

		std::cout << "=== TEST 2: Create Robotomy Request Form ===" << std::endl;
		AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "Bender");
		if (robotomyForm) {
			boss.signForm(*robotomyForm);
			boss.executeForm(*robotomyForm);
			delete robotomyForm;
		}
		std::cout << std::endl;

		std::cout << "=== TEST 3: Create Presidential Pardon Form ===" << std::endl;
		AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
		if (pardonForm) {
			boss.signForm(*pardonForm);
			boss.executeForm(*pardonForm);
			delete pardonForm;
		}
		std::cout << std::endl;

		std::cout << "=== TEST 4: Try to create invalid form ===" << std::endl;
		AForm* invalidForm = someRandomIntern.makeForm("invalid form", "Nobody");
		if (invalidForm) {
			boss.signForm(*invalidForm);
			boss.executeForm(*invalidForm);
			delete invalidForm;
		}
		std::cout << std::endl;

		std::cout << "=== TEST 5: Case sensitivity test ===" << std::endl;
		AForm* wrongCaseForm = someRandomIntern.makeForm("SHRUBBERY CREATION", "Garden");
		if (wrongCaseForm) {
			boss.signForm(*wrongCaseForm);
			boss.executeForm(*wrongCaseForm);
			delete wrongCaseForm;
		}
		std::cout << std::endl;

		std::cout << "=== TEST 6: Multiple forms quickly ===" << std::endl;
		AForm* forms[3];
		std::string formNames[3] = {
			"shrubbery creation",
			"robotomy request", 
			"presidential pardon"
		};
		std::string targets[3] = {"Park", "R2D2", "Arthur"};
		
		for (int i = 0; i < 3; i++) {
			forms[i] = someRandomIntern.makeForm(formNames[i], targets[i]);
			if (forms[i]) {
				boss.signForm(*forms[i]);
				boss.executeForm(*forms[i]);
				delete forms[i];
			}
			std::cout << std::endl;
		}

	} catch (const std::exception& e) {
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "=== ALL TESTS COMPLETE ===" << std::endl;
	return 0;
}