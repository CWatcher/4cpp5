#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target )
	throw ( GradeTooHighException, GradeTooLowException )
:	  Form( "ShrubberyCreation", target, 72, 45 )
{
	srand( time( NULL ) );
}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
 	throw ( GradeTooHighException, GradeTooLowException )
:	  Form( src )
{}

void	ShrubberyCreationForm::executeSpecifically() const
		throw ( GradeTooLowException, IsNotSignedException )
{
	std::string	const result[2] = {
		" has been robotomized successfully",
		" has been failed to be robotomized"
	};
	std::cout << "Z-z-Z-z... Z-z-Z-z-Z... " << _target << result[ rand() % 2 ]
	          << std::endl;
}
