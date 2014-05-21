#pragma once
#ifndef MATRIX2_H_EGEMATH
#define MATRIX2_H_EGEMATH

#include "Vector2.hpp"


namespace ege
{
	template<typename T>
	class Matrix2
	{
	public:
		static const Matrix2<T> Identity;
		static const unsigned int ROWS = 2;
		static const unsigned int COLUMNS = 2;
		/**
		Creates Identity Matrix
		*/
		Matrix2<T>();
		Matrix2<T>(const Matrix2<T>& mat2);
		template<typename T2>
		Matrix2<T>(const Matrix2<T2>& mat2);
		Matrix2<T>(
			const Vector2<T>& Row1,
			const Vector2<T>& Row2);
		Matrix2<T>(
			const T& r1c1, const T& r1c2,
			const T& r2c1, const T& r2c2);
		~Matrix2<T>();

		T determinant() const;

		Matrix2<T>& Transpose();
		Matrix2<T> transposed() const;

		Matrix2<T> cofactor() const;

		Matrix2<T>& Inverse();
		Matrix2<T> inversed() const;

		T* ptr() const;

		const Vector2<T>& operator [](const unsigned int& index) const;
		Vector2<T>& operator [](const unsigned int& index);

		bool operator ==(const Matrix2<T>& RightVal) const;
		bool operator !=(const Matrix2<T>& RightVal) const;

		Matrix2<T>& operator =(const Matrix2<T>& RightVal);

		Matrix2<T>& operator +=(const Matrix2<T>& RightVal);
		Matrix2<T>& operator -=(const Matrix2<T>& RightVal);

		Matrix2<T>& operator /=(const T& RightVal);
		Matrix2<T>& operator *=(const T& RightVal);

		Matrix2<T> operator +(const Matrix2<T>& RightVal) const;
		Matrix2<T> operator -(const Matrix2<T>& RightVal) const;

		Matrix2<T> operator /(const T& RightVal) const;
		Matrix2<T> operator *(const T& RightVal) const;

		Vector2<T> operator *(const Vector2<T>& RightVal) const;
		Matrix2<T> operator *(const Matrix2<T>& RightVal) const;

	private:
		Vector2<T> r1,r2;
	};

	template<typename T> Matrix2<T> operator *(const T& LeftVal, const Matrix2<T>& RightVal);

	template<typename T> Vector2<T>& operator *=(Vector2<T>& LeftVal, const Matrix2<T>& RightVal);

	template<typename T> std::ostream& operator <<(std::ostream& Ostr, const Matrix2<T>& RightVal);

	typedef Matrix2<float> Mat2;
}
#include "inline/Matrix2.inl"
#endif