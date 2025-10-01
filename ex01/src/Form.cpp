#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

//Canonical
Form::Form() : _name("Default"), _signGrade(150), _execGrade(150) {
	_signed = false;
}

Form::Form(const std::string& name, int signGrade, int execGrade) 
	: _name(name), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighExcepion();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_signed = false;
}

Form::Form(const Form& other) 
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	_signed = other._signed;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

Form::~Form() {}

//Getters
std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _signGrade;
}

int Form ::getGradeToExec() const {
	return 	_execGrade;
}

//Exeptions
const char* Form::GradeTooHighExcepion::what() const throw() {
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

//Sign
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooHighExcepion();
	_signed = true;
}

//Operator <<
std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form: " << form.getName()
	   << ", Signed: " << (form.getSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeToSign()
	   << ", Grade to execute: " << form.getGradeToExec();
	return os;
}