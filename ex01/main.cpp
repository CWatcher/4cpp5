#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int	main()
{
	try
	{	Bureaucrat bLow ("bLow", 151);
		std::cout << bLow << std::endl;
	}
	catch ( std::exception const & e )
	{	std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	Bureaucrat b2( "b2", 2 );
	std::cout << b2;
	try
	{	b2.incrementGrade();
		b2.incrementGrade();
	}
	catch ( Bureaucrat::GradeTooHighException const & e )
	{	std::cout << e.what() << ": " << e.grade << std::endl;
	}
	std::cout << b2;
}
