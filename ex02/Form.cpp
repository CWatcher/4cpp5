#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::GradeTooHighException::GradeTooHighException( int grade )
:	grade( grade )
{}
Form::GradeTooLowException::GradeTooLowException( int grade )
:	grade( grade )
{}

char const *	Form::GradeTooHighException::what() const throw()
{	return "Grade is too high";
}
char const *	Form::GradeTooLowException::what() const throw()
{	return "Grade is too low";
}
char const *	Form::IsNotSignedException::what() const throw()
{	return "The form is not signed";
}

void	Form::checkGrade( int grade ) const
	throw ( GradeTooHighException, GradeTooLowException )
{
	if ( grade < 1 )
		throw Form::GradeTooHighException( grade );
	if ( grade > 150 )
		throw Form::GradeTooLowException( grade );
}

Form::Form(   std::string const & name, std::string const & target
		    , int gradeToSign, int gradeToExecute )
	throw ( GradeTooHighException, GradeTooLowException )
:	  _name( name ), _target( target )
	, _gradeToSign( gradeToSign ), _gradeToExecute( gradeToExecute )
	, _isSigned( false )
{
	checkGrade( _gradeToSign );
	checkGrade( _gradeToExecute );
}
Form::Form( Form const & src )
	throw ( GradeTooHighException, GradeTooLowException )
:	  _name( src._name )
	, _gradeToSign( src._gradeToSign ), _gradeToExecute( src._gradeToExecute )
{
	checkGrade( _gradeToSign );
	checkGrade( _gradeToExecute );
}
Form::~Form()
{}

Form &			Form::operator=( Form const & rhs )
{
	_isSigned = rhs._isSigned;
	return *this;
}
std::ostream &	operator<<( std::ostream & o, Form const & i ) throw()
{
	o << "Form { "
	  << "name = "           << i.getName()           << ", "
	  << "target = "         << i.getTarget()         << ", "
	  << "gradeToSign = "    << i.getGradeToSign()    << ", "
	  << "gradeToExecute = " << i.getGradeToExecute() << ", "
	  << "isSigned = "       << i.isSigned()
	  << " }" << std::endl;
	return o;
}

std::string		Form::getName() const throw()
{	return _name;
}
std::string		Form::getTarget() const throw()
{	return _target;
}
int				Form::getGradeToSign() const throw()
{	return _gradeToSign;
}
int				Form::getGradeToExecute() const throw()
{	return _gradeToExecute;
}
bool			Form::isSigned() const throw()
{	return _isSigned;
}

void			Form::beSigned( Bureaucrat const & signer )
	throw ( GradeTooLowException )
{
	if ( signer.getGrade() > _gradeToSign )
		throw GradeTooLowException( signer.getGrade() );
	_isSigned = true;
}
void			Form::execute( Bureaucrat const & executor ) const
		throw ( GradeTooLowException, IsNotSignedException )
{
	if ( executor.getGrade() > _gradeToExecute )
		throw GradeTooLowException( executor.getGrade() );
	if ( !_isSigned )
		throw IsNotSignedException();
	executeSpecifically();
}
