#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>

Bureaucrat	b145( "b145", 145 );
Bureaucrat	b25( "b25", 25 );
Bureaucrat	b5( "b5", 5 );

void testForm( Form & f )
{
	std::cout << f
	          << std::endl;

	b145.signForm( f );
	b25.executeForm( f );
	if ( !f.isSigned() ) {
		b25.signForm( f );
		b25.executeForm( f );
	}
	b5.executeForm( f );
	std::cout << std::endl;
}
int	main()
{
	PresidentialPardonForm	ppf( "PPTarget" );
	testForm( ppf );

	RobotomyRequestForm	rrf( "RRTarget" );
	testForm( rrf );

	ShrubberyCreationForm*	pSCF = new ShrubberyCreationForm( "SCTarget" );
	testForm( *pSCF );
	delete pSCF;
}
