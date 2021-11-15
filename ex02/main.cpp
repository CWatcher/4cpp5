#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

Bureaucrat	b150( "b150", 150 );
Bureaucrat	b25( "b25", 25 );
Bureaucrat	b1( "b1", 1 );

void testForm( Form & f )
{
	std::cout << f
	          << std::endl;

	b1.executeForm( f );
	b150.signForm( f );
	b25.signForm( f );
	b25.executeForm( f );
	b1.executeForm( f );
}
int	main()
{
	std::cout << b150 << b1
	          << std::endl;
	PresidentialPardonForm		ppf( "PPTarget" );
	testForm( ppf );
}
