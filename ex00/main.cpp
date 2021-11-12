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
	Bureaucrat b1( "b1", 1 ), b150( "b150", 150 );
	std::cout << b1 << b150 << std::endl;
	try
	{	b1.incrementGrade();
	}
	catch ( Bureaucrat::GradeTooHighException const & e )
	{	std::cout << e.what() << ": " << e.grade << std::endl;
	}
}
