#pragma once

#include <cstddef>

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
			for (std::size_t i = 0; i < rows; i++)
			{
				for (std::size_t j = 0; j < columns; j++)
				{
					this->_data[i * columns + j] = T(i * j);
				}
			}
		}

		~Matrix()
		{
			if (this->_data == nullptr) return;
			delete[] this->_data;
			this->_data = nullptr;
		}

		inline const std::size_t& rows() const { return this->_rows; }
		inline const std::size_t& columns() const { return this->_columns; }

		inline T& operator()(const std::size_t& row, const std::size_t& column)
		{
			return this->_data[row * this->columns() + column];
		}

	private:
		T* _data = nullptr;
		std::size_t _rows;
		std::size_t _columns;
	};
}