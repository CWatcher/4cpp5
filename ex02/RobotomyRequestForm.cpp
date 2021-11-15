#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string const & target )
	throw ( GradeTooHighException, GradeTooLowException )
:	  Form( "RobotomyRequest", target, 25, 5 )
{}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
 	throw ( GradeTooHighException, GradeTooLowException )
:	  Form( src )
{}

void	RobotomyRequestForm::executeSpecifically() const
		throw ( GradeTooLowException, IsNotSignedException )
{
	std::cout << _target << " has been pardoned by Zafod Beeblebrox"
	          << std::endl;
}
