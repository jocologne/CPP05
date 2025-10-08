#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

//Canonical
AForm::AForm() : _name("Default"), _signGrade(150), _execGrade(150) {
	_signed = false;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade) 
	: _name(name), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_signed = false;
}

AForm::AForm(const AForm& other) 
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	_signed = other._signed;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm() {}

//Getters
std::string AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _signGrade;
}

int AForm::getGradeToExec() const {
	return 	_execGrade;
}

//Exeptions
const char* AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

//Sign
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooHighException();
	_signed = true;
}

void AForm::checkExecutionRequirements(const Bureaucrat& executor) const {
	if (!_signed)
		throw std::runtime_error("Form is not signed");
	if ( executor.getGrade() > _execGrade)
		throw AForm::GradeTooLowException();
}

//Operator <<
std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form: " << form.getName()
	   << ", Signed: " << (form.getSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeToSign()
	   << ", Grade to execute: " << form.getGradeToExec();
	return os;
}