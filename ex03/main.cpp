#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

Bureaucrat	b72( "b72", 72 );
Bureaucrat	b25( "b25", 25 );
Bureaucrat	b5( "b5", 5 );

void testForm( Form* pf )
{
	std::cout << *pf
	          << std::endl;

	b72.signForm( *pf );
	b25.executeForm( *pf );
	if ( !pf->isSigned() )
		b25.signForm( *pf );
	b5.executeForm( *pf );
	delete pf;

	std::cout << std::endl;
}
int	main()
{
	Intern	intern;
	try {
		testForm( intern.makeForm( "PresidentialPardon",	"PPTarget" ) );
		testForm( intern.makeForm( "RobotomyRequest", "RRTarget" ) );
		testForm( intern.makeForm( "ShrubberyCreation",	"SCTarget" ) );
		testForm( intern.makeForm( "non-existent",	"some target" ) );
	}
	catch ( std::exception const & e) {
		std::cout << e.what() << std::endl << std::endl;
	}
}
