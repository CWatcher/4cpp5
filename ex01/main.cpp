#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int	main()
{
	Bureaucrat	b150( "b150", 150 );
	Bureaucrat	b1( "b1", 1 );
	Form		f1( "f1", 1, 1 );

	std::cout << b150 << b1 << f1
	          << std::endl;

	b150.signForm( f1 );
	b1.signForm( f1 );
	std::cout << f1;
}
