#pragma once
#ifndef MATRIX3_H_EGEMATH
#define MATRIX3_H_EGEMATH

#include <EgeMath/Vector3.hpp>


namespace ege
{
	template<typename T>
	class Matrix3
	{
	public:
		/**
		Creates Identity Matrix
		*/
		Matrix3()
			:
			r1(vector3(T(1),T(0),T(0))),
			r2(vector3(T(0),T(1),T(0))),
			r3(vector3(T(0),T(0),T(1)))
		{}
		Matrix3(const T* FirstElement)
			:
			r1(FirstElement[0],FirstElement[1],FirstElement[2]),
			r2(FirstElement[3],FirstElement[4],FirstElement[5]),
			r3(FirstElement[6],FirstElement[7],FirstElement[8])
		{}
		Matrix3(
			const Vector3<T>& Row1,
			const Vector3<T>& Row2,
			const Vector3<T>& Row3)
			: 
			r1(Row1),
			r2(Row2),
			r3(Row3)
		{}
		Matrix3(
			const T& r1c1, const T& r1c2, const T& r1c3,
			const T& r2c1, const T& r2c2, const T& r2c3,
			const T& r3c1, const T& r3c2, const T& r3c3)
			:
			r1(r1c1,r1c2,r1c3),
			r2(r2c1,r2c2,r2c3),
			r3(r3c1,r3c2,r3c3)
		{}

		T* FirstElement()
		{
			return (T*)&r1.x;
		}

		const Vector3<T>& operator [](const unsigned int& index) const
		{
			return (&r1)[index];
		}
		Vector3<T>& operator [](const unsigned int& index)
		{
			return (&r1)[index];
		}

	private:
		Vector3 r1,r2,r3;

	};

	template<typename T>
	Matrix3<T> operator *(const Matrix3<T>& LeftVal, const Matrix3<T>& RightVal);
	
	template<typename T>
	Vector3<T> operator *(const Vector3<T>& LeftVal, const Matrix3<T>& RightVal);
	template<typename T>
	const Vector3<T> operator *=(Vector3<T>& LeftVal, const Matrix3<T>& RightVal);
}

#endif