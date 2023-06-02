#include "Classes.h"

const char* MyException::what() const throw()
{
	return errorMessage.c_str();
}
