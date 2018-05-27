// Copyright 2018 Batanina Liubov

#include <iostream>
#include "include/matrix_operation.hpp"

int main(int argc, const char** argv)
{
	MatrixOperation app;
	MatrixCalculator output = app(argc, argv);
	std::cout << output << std::endl;
	return 0;

}
