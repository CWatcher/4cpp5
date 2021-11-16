#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>

Bureaucrat	b145( "b145", 145 );
Bureaucrat	b25( "b25", 25 );
Bureaucrat	b1( "b1", 1 );

void testForm( Form & f )
{
	std::cout << f
	          << std::endl;

	b1.executeForm( f );
	b145.signForm( f );
	if ( !f.getIsSigned() )
		b25.signForm( f );
	b25.executeForm( f );
	b1.executeForm( f );
}
int	main()
{
	PresidentialPardonForm	ppf( "PPTarget" );
	testForm( ppf );
	std::cout << std::endl;

	RobotomyRequestForm	rrf( "RRTarget" );
	testForm( rrf );
	std::cout << std::endl;

	ShrubberyCreationForm*	pSCF = new ShrubberyCreationForm( "SCTarget" );
	testForm( *pSCF );
	delete pSCF;
}
