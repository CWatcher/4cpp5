#include "Bureaucrat.hpp"
void	Bureaucrat::checkGrade() throw ( GradeTooHighException, GradeTooLowException )
{
	if ( _grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	if ( _grade > 150 )
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( std::string const & name, int grade )
:	_name( name ), _grade( grade )
{
	checkGrade();
}
Bureaucrat::Bureaucrat( const Bureaucrat & src )
:	Bureaucrat( src._name, src._grade )
{
	checkGrade();
}
Bureaucrat::~Bureaucrat()
{}

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	*this = { rhs._name, rhs._grade };
	checkGrade();
	return *this;
}
std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}

char const *	Bureaucrat::GradeTooHighException::what() const throw()
{	return "Grade is too high";
}
char const *	Bureaucrat::GradeTooLowException::what() const throw()
{	return "Grade is too low";
}
