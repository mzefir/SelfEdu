#pragma once

#include "gtest/gtest.h"

#include "../../Threading/Assets/Matrix.h"


namespace zefir::threading::test
{

	class MatrixFixture : public ::testing::Test
	{
	protected:
		void SetUp() override;
		void TearDown() override;

	
		zefir::threading::Matrix<long double> *m1;
	};

}