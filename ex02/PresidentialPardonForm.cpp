#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string const & target )
	throw ( GradeTooHighException, GradeTooLowException )
:	  Form( "PresidentialPardon", target, 25, 5 )
{}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
 	throw ( GradeTooHighException, GradeTooLowException )
:	  Form( src )
{}

void	PresidentialPardonForm::executeSpecifically() const
		throw ( GradeTooLowException, IsNotSignedException )
{
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox"
	          << std::endl;
}
