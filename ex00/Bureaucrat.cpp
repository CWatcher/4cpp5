#include "Bureaucrat.hpp"
void	Bureaucrat::checkGrade()
	throw ( GradeTooHighException, GradeTooLowException )
{
	if ( _grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	if ( _grade > 150 )
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( std::string const & name, int grade )
	throw ( GradeTooHighException, GradeTooLowException )
:	_name( name ), _grade( grade )
{
	checkGrade();
}
Bureaucrat::Bureaucrat( const Bureaucrat & src )
	throw ( GradeTooHighException, GradeTooLowException )
:	_name( src._name ), _grade( src._grade )
{
	checkGrade();
}
Bureaucrat::~Bureaucrat()
{}

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	checkGrade();
	_grade = rhs._grade;
	return *this;
}
std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << "name = " << i.getName() << ", ";
	o << "grade = " << i.getGrade() << std::endl;
	return o;
}

std::string			Bureaucrat::getName() const
{	return _name;
}
int					Bureaucrat::getGrade() const
{	return _grade;
}


char const *	Bureaucrat::GradeTooHighException::what() const throw()
{	return "Grade is too high";
}
char const *	Bureaucrat::GradeTooLowException::what() const throw()
{	return "Grade is too low";
}
