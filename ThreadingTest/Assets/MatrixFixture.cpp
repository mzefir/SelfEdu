#include "MatrixFixture.h"



namespace zefir::threading::test
{


	void MatrixFixture::SetUp()
	{
		m1 = new zefir::threading::Matrix<long double>(10, 10);
	}

	void MatrixFixture::TearDown() 
	{
		delete m1;
	}

	TEST_F(MatrixFixture, MethodBarDoesAbc) {
		long double val = ( * m1)(3, 3);
		EXPECT_EQ(val, 9);
	}
}