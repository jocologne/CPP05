
#include "../includes/Intern.hpp"

Intern::FormCreator Intern::_formCreators[3] = {
	{"shrubbery creation", &Intern::createShrubbery},
	{"robotomy request", &Intern::createRobotomy},
	{"presidential pardon", &Intern::createPresidential}
};

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void) other;
}

Intern& Intern::operator=(const Intern& other) {
	(void) other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	for (int i = 0; i < 3; i++) {
		if (_formCreators[i].formName == formName) {
			AForm* form = _formCreators[i].createFunction(target);
			std::cout << "Intern created " << formName << std::endl;
			return form;
		}
	}
	std::cout << "This forms doesn't exist." << std::endl;
	return NULL;
}