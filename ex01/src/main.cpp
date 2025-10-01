#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat highGrade("A", 1);
		Bureaucrat lowGrade("B", 150);

		Form form1("Form 1", 50, 50);
		Form form2("Form 2", 1, 1);

		highGrade.signForm(form1);
		lowGrade.signForm(form2);

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}