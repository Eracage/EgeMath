#pragma once
#ifndef MATRIX4_H_EGEMATH
#define MATRIX4_H_EGEMATH

#include "Vector4.hpp"
#include "Matrix3.hpp"

namespace ege
{
	template<typename T>
	class Matrix4
	{
	public:
		static const Matrix4<T> Identity;
		static const unsigned int ROWS = 4;
		static const unsigned int COLUMNS = 4;
		/**
		Creates Identity Matrix
		*/
		Matrix4();
		explicit Matrix4(const Matrix2<T>& mat2);
		explicit Matrix4(const Matrix3<T>& mat3);
		Matrix4(const Matrix4<T>& mat4);
		template<typename T2>
		Matrix4(const Matrix4<T2>& mat4);
		Matrix4(
			const Vector4<T>& Row1,
			const Vector4<T>& Row2,
			const Vector4<T>& Row3,
			const Vector4<T>& Row4);
		Matrix4(
			const T& r1c1,const T& r1c2,const T& r1c3,const T& r1c4,
			const T& r2c1,const T& r2c2,const T& r2c3,const T& r2c4,
			const T& r3c1,const T& r3c2,const T& r3c3,const T& r3c4,
			const T& r4c1,const T& r4c2,const T& r4c3,const T& r4c4);
		~Matrix4();

		Matrix3<T> subMatrix3(const unsigned int RowToRemove = 3, const unsigned int ColumnToRemove = 3) const;

		T determinant() const;

		Matrix4<T>& Transpose();
		Matrix4<T> transposed() const;

		Matrix4<T> cofactor() const;

		Matrix4<T>& Inverse();
		Matrix4<T> inversed() const;

		T* ptr() const;

		const Vector4<T>& operator [](const unsigned int& index) const;
		Vector4<T>& operator [](const unsigned int& index);

		bool operator ==(const Matrix4<T>& RightVal) const;
		bool operator !=(const Matrix4<T>& RightVal) const;

		Matrix4<T>& operator =(const Matrix4<T>& RightVal);

		Matrix4<T>& operator +=(const Matrix4<T>& RightVal);
		Matrix4<T>& operator -=(const Matrix4<T>& RightVal);

		Matrix4<T>& operator /=(const T& RightVal);
		Matrix4<T>& operator *=(const T& RightVal);

		Matrix4<T> operator +(const Matrix4<T>& RightVal) const;
		Matrix4<T> operator -(const Matrix4<T>& RightVal) const;

		Matrix4<T> operator /(const T& RightVal) const;
		Matrix4<T> operator *(const T& RightVal) const;

		Vector2<T> operator *(const Vector2<T>& RightVal) const;
		Vector3<T> operator *(const Vector3<T>& RightVal) const;
		Vector4<T> operator *(const Vector4<T>& RightVal) const;

		Matrix4<T> operator *(const Matrix4<T>& RightVal) const;

	private:
		Vector4<T> r1,r2,r3,r4;

	};

	template<typename T> Matrix4<T> operator *(const T& LeftVal, const Matrix4<T>& RightVal);

	template<typename T> Vector2<T>& operator *=(Vector2<T>& LeftVal, const Matrix4<T>& RightVal);
	template<typename T> Vector3<T>& operator *=(Vector3<T>& LeftVal, const Matrix4<T>& RightVal);
	template<typename T> Vector4<T>& operator *=(Vector4<T>& LeftVal, const Matrix4<T>& RightVal);

	template<typename T> std::ostream& operator <<(std::ostream& Ostr, const Matrix3<T>& RightVal);

	typedef Matrix4<float> Mat4;
}
#include "inline/Matrix4.inl"
#endif