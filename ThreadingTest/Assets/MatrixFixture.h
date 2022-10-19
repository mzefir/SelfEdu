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

		void FillWithMultiplicationTable(zefir::threading::Matrix<long double>* mat);

		zefir::threading::Matrix<long double>* m1;
		zefir::threading::Matrix<long double>* m2;
		zefir::threading::Matrix<long double>* m3;
	};

}