#include "MatrixFixture.h"

#include <iostream>
#include <random>


namespace zefir::threading::test
{


	void MatrixFixture::SetUp()
	{
		m1 = new zefir::threading::Matrix<long double>(5, 3);
		m2 = new zefir::threading::Matrix<long double>(3, 4);
		m3 = new zefir::threading::Matrix<long double>(5, 4);
		FillWithMultiplicationTable(m1);
		FillWithMultiplicationTable(m2);
		FillWithMultiplicationTable(m3);
	}

	void MatrixFixture::TearDown()
	{
		delete m1;
		delete m2;
		delete m3;
	}

	void MatrixFixture::FillWithMultiplicationTable(zefir::threading::Matrix<long double>* mat)
	{
		for (std::size_t i = 0; i < mat->rows(); i++)
			for (std::size_t j = 0; j < mat->columns(); j++)
				(*mat)(i, j) = (long double)(i + 1) * (long double)(j + 1);
	}

	TEST_F(MatrixFixture, MatrixIsMuliplicationTable) {
		long double val = (*m3)(3, 2);
		EXPECT_EQ(val, 12);
	}

	TEST_F(MatrixFixture, MatrixIsPrintableToStream)
	{
		std::cout << (*m1);
		std::cout << (*m2);
		std::cout << ((*m1)*(*m2));

		EXPECT_EQ(3, 3);
	}

	TEST_F(MatrixFixture, MatrixWithRandomValues)
	{
		long double lower_bound = -1;
		long double upper_bound = 1;
		std::uniform_real_distribution<long double> unif(lower_bound, upper_bound);
		std::random_device r;
		std::default_random_engine re(7);
		std::cout << unif(re) << "  " << unif(re) << "  " << unif(re) << "  " << unif(re) << std::endl;

		EXPECT_EQ(3, 3);
	}
}