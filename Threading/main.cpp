#include <iostream>

#include "Assets/Matrix.h"

int main()
{
	zefir::threading::Matrix<size_t> m(10, 12);
	zefir::threading::Matrix<int> m2(10, 12);
	

	std::cout << m2(4, 4) << std::endl;
	m2(4, 4) = 11;
	std::cout << m2(4, 4) << std::endl;
	return 0;
}