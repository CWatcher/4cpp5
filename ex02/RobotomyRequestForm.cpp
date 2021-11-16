#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm( std::string const & target )
	throw ( GradeTooHighException, GradeTooLowException )
:	  Form( "RobotomyRequest", target, 72, 45 )
{
	srand( time( NULL ) );
}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
 	throw ( GradeTooHighException, GradeTooLowException )
:	  Form( src )
{}

void	RobotomyRequestForm::executeSpecifically() const
		throw ( GradeTooLowException, IsNotSignedException )
{
	std::string	const result[2] = {
		" has been robotomized successfully",
		" has been failed to be robotomized"
	};
	std::cout << "Z-z-Z-z... Z-z-Z-z-Z... " << getTarget() << result[ rand() % 2 ]
	          << std::endl;
}
