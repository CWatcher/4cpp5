#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException( int grade )
:	grade( grade )
{}
Bureaucrat::GradeTooLowException::GradeTooLowException( int grade )
:	grade( grade )
{}

char const *	Bureaucrat::GradeTooHighException::what() const throw()
{	return "Grade is too high";
}
char const *	Bureaucrat::GradeTooLowException::what() const throw()
{	return "Grade is too low";
}

void	Bureaucrat::checkGrade( int grade )
	throw ( GradeTooHighException, GradeTooLowException )
{
	if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException( grade );
	if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException( grade );
}

Bureaucrat::Bureaucrat( std::string const & name, int grade )
	throw ( GradeTooHighException, GradeTooLowException )
:	_name( name ), _grade( grade )
{
	checkGrade( _grade );
}
Bureaucrat::Bureaucrat( const Bureaucrat & src )
	throw ( GradeTooHighException, GradeTooLowException )
:	_name( src._name ), _grade( src._grade )
{
	checkGrade( _grade );
}
Bureaucrat::~Bureaucrat()
{}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs )
		throw ( GradeTooHighException, GradeTooLowException )
{
	checkGrade( rhs._grade );
	_grade = rhs._grade;
	return *this;
}
std::ostream &	operator<<( std::ostream & o, Bureaucrat const & i ) throw()
{
	o << "name = " << i.getName() << ", ";
	o << "grade = " << i.getGrade() << std::endl;
	return o;
}

std::string		Bureaucrat::getName() const throw()
{	return _name;
}
int				Bureaucrat::getGrade() const throw()
{	return _grade;
}

int				Bureaucrat::incrementGrade() throw ( GradeTooHighException )
{
	checkGrade( _grade - 1 );
	return --_grade;
}
int				Bureaucrat::decrementGrade() throw ( GradeTooLowException )
{
	checkGrade( _grade + 1 );
	return ++_grade;
}
