#pragma once

#include <algorithm>
#include <cstddef>
#include <ostream>

namespace zefir::threading
{
	template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	class Matrix
	{
	public:
		Matrix() = delete;
		Matrix(const Matrix<T>&) = delete;

		Matrix(const std::size_t& rows, const std::size_t& columns) : _rows(rows), _columns(columns)
		{
			this->_data = new T[rows * columns];
			for (std::size_t i = 0; i < rows * columns; i++)
			{
				this->_data[i] = 0;
			}
		}

		~Matrix()
		{
			this->dispose();
		}

		inline const std::size_t& rows() const { return this->_rows; }
		inline const std::size_t& columns() const { return this->_columns; }

		inline T& operator()(const std::size_t& row, const std::size_t& column)
		{
			return this->_data[row * this->columns() + column];
		}

		inline T operator()(const std::size_t& row, const std::size_t& column) const
		{
			return this->_data[row * this->columns() + column];
		}

		inline Matrix<T>& operator=(const Matrix<T>& other)
		{
			this->dispose();
			std::size_t size = other.rows() * other.columns();
			this->_data = new T[size];
			//std::copy(std::begin(this->))
			for (std : size_t i = 0; i < size; i++) {
				this->_data[i] = other._data[i];
			}
		}

		Matrix<T>& operator*(const Matrix<T>& other)
		{
			Matrix<T>* ret = new Matrix<T>(this->rows(), other.columns());

			for (std::size_t i = 0; i < ret->rows(); i++)
			{
				this->calculateRow(i, *this, other, ret);
			}

			return (*ret);
		}

		friend std::ostream& operator<<(std::ostream& os, Matrix& mat)
		{
			os << "\n";
			for (std::size_t i = 0; i < mat.rows(); i++)
			{
				for (std::size_t j = 0; j < mat.columns(); j++)
				{
					os << mat(i, j) << (j + 1 == mat.columns() ? "" : "\t");
				}
				os << "\n";
			}
			os << "\n";
			return os;
		}

	private:

		void calculateRow(std::size_t row, const Matrix<T>& m1, const Matrix<T>& m2, Matrix<T>* out)
		{
			const T m1Row = row;
			for (std::size_t outCol = 0; outCol < out->columns(); outCol++)
			{
				T val = 0;
				for (std::size_t m2Row = 0; m2Row < m2.rows(); m2Row++)
				{
					val += m1(m1Row, m2Row) * m2(m2Row, outCol);
				}
				(*out)(row, outCol) = val;
			}
		}

		void dispose()
		{
			if (this->_data == nullptr) return;
			delete[] this->_data;
			this->_data = nullptr;
		}


		T* _data = nullptr;
		std::size_t _rows;
		std::size_t _columns;
	};
}