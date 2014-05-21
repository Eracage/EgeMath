#pragma once
#ifndef MATRIX3_H_EGEMATH
#define MATRIX3_H_EGEMATH

#include "Vector3.hpp"
#include "Matrix2.hpp"


namespace ege
{
	template<typename T>
	class Matrix3
	{
	public:
		static const Matrix3<T> Identity;
		static const unsigned int ROWS = 3;
		static const unsigned int COLUMNS = 3;
		/**
		Creates Identity Matrix
		*/
		Matrix3();
		explicit Matrix3(const Matrix2<T>& mat2);
		Matrix3(const Matrix3<T>& mat3);
		template<typename T2>
		Matrix3(const Matrix3<T2>& mat3);
		Matrix3(
			const Vector3<T>& Row1,
			const Vector3<T>& Row2,
			const Vector3<T>& Row3);
		Matrix3(
			const T& r1c1, const T& r1c2, const T& r1c3,
			const T& r2c1, const T& r2c2, const T& r2c3,
			const T& r3c1, const T& r3c2, const T& r3c3);
		~Matrix3<T>();

		Matrix2<T> subMatrix2(const unsigned int RowToRemove = 2, const unsigned int ColumnToRemove = 2) const;

		T determinant() const;

		Matrix3<T>& Transpose();
		Matrix3<T> transposed() const;

		Matrix3<T> cofactor() const;

		Matrix3<T>& Inverse();
		Matrix3<T> inversed() const;

		T* ptr() const;
		
		const Vector3<T>& operator [](const unsigned int& index) const;
		Vector3<T>& operator [](const unsigned int& index);

		bool operator ==(const Matrix3<T>& RightVal) const;
		bool operator !=(const Matrix3<T>& RightVal) const;

		Matrix3<T>& operator =(const Matrix3<T>& RightVal);

		Matrix3<T>& operator +=(const Matrix3<T>& RightVal);
		Matrix3<T>& operator -=(const Matrix3<T>& RightVal);

		Matrix3<T>& operator /=(const T& RightVal);
		Matrix3<T>& operator *=(const T& RightVal);

		Matrix3<T> operator +(const Matrix3<T>& RightVal) const;
		Matrix3<T> operator -(const Matrix3<T>& RightVal) const;

		Matrix3<T> operator /(const T& RightVal) const;
		Matrix3<T> operator *(const T& RightVal) const;

		Vector2<T> operator *(const Vector2<T>& RightVal) const;
		Vector3<T> operator *(const Vector3<T>& RightVal) const;

		Matrix3<T> operator *(const Matrix3<T>& RightVal) const;

	private:
		Vector3<T> r1,r2,r3;

	};

	template<typename T> Matrix3<T> operator *(const T& LeftVal, const Matrix3<T>& RightVal);

	template<typename T> Vector2<T>& operator *=(Vector2<T>& LeftVal, const Matrix3<T>& RightVal);
	template<typename T> Vector3<T>& operator *=(Vector3<T>& LeftVal, const Matrix3<T>& RightVal);

	template<typename T> std::ostream& operator <<(std::ostream& Ostr, const Matrix3<T>& RightVal);

	typedef Matrix3<float> Mat3;
}
#include "inline/Matrix3.inl"
#endif