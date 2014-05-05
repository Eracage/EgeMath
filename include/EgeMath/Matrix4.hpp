#pragma once
#ifndef MATRIX4_H_EGEMATH
#define MATRIX4_H_EGEMATH

#include <EgeMath/Vector4.hpp>
#include <EgeMath/Matrix3.hpp>

namespace ege
{
	template<typename T>
	class Matrix4
	{
	public:
		static const Matrix4 Identity;
		static const unsigned int ROWS = 4;
		static const unsigned int COLUMNS = 4;
		/**
		Creates Identity Matrix
		*/
		Matrix4();
		Matrix4(const T* FirstElement);
		Matrix4(const Matrix3& mat3);
		Matrix4(const Matrix4& mat4);
		Matrix4(
			const Vector4<T>& Row1,
			const Vector4<T>& Row2,
			const Vector4<T>& Row3,
			const Vector4<T>& Row4);
		Matrix4(
			const T r1c1,const T r1c2,const T r1c3,const T r1c4,
			const T r2c1,const T r2c2,const T r2c3,const T r2c4,
			const T r3c1,const T r3c2,const T r3c3,const T r3c4,
			const T r4c1,const T r4c2,const T r4c3,const T r4c4);
		~Matrix4();

		T* ptr() const;

		const Vector4<T>& operator [](const unsigned int& index) const;
		Vector4<T>& operator [](const unsigned int& index);

	private:
		Vector4<T> r1,r2,r3,r4;

	};
	
	template<typename T> Matrix4<T> operator *(const Matrix4<T>& LeftVal, const Matrix4<T>& RightVal);

	template<typename T> Vector4<T> operator *(const Vector4<T>& LeftVal, const Matrix4<T>& RightVal);
	template<typename T> const Vector4<T> operator *=(Vector4<T>& LeftVal, const Matrix4<T>& RightVal);
	
}

#endif