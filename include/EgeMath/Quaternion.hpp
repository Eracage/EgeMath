#pragma once
#ifndef QUATERNION_H_EGEMATH
#define QUATERNION_H_EGEMATH
#include "Vector.hpp"
#include "Matrix.hpp"

namespace ege
{
	template<typename T>
	class Quaternion
	{
		static const Quaternion Identity;
	public:
		Quaternion();
		Quaternion(const T& S, const T& X, const T& Y, const T& Z);
		Quaternion(const T& S, const Vector3<T>& V3);
		Quaternion(const Quaternion<T>& quaternion);
		template<typename T2>
		Quaternion(const Quaternion<T2>& quaternion);
		~Quaternion();

		/*
		Returns the dot product of 2 different vectors
		*/
		static T dot(const Vector4<T>& A, const Vector4<T>& B);
		/*
		Returns the dot product of 2 different vectors
		*/
		T dot(const Vector4<T>& A) const;
		
		/*
		Returns the length of the vector squared, more optimized than Length() function
		*/
		double lengthSquared() const;
		/*
		Returns the length of the vector, consider using LengthSquared() for optimization
		*/
		double length() const;

		/*
		Normalizes the vector and returns the reference
		*/
		Vector4<T>& Normalize();
		/*
		Returns normalized version of the vector, does not modify the vector
		*/
		Vector4<T> unitVector() const;
		
		union{ T x, r;};
		union{ T y, g;};
		union{ T z, b;};
		union{ T w, a;};

		const T& operator [](const unsigned int& index) const;
		T& operator [](const unsigned int& index);

		bool operator ==(const Vector4<T>& RightVal) const;
		bool operator !=(const Vector4<T>& RightVal) const;

		bool operator <(const Vector4<T>& RightVal) const;
		bool operator <=(const Vector4<T>& RightVal) const;

		bool operator >(const Vector4<T>& RightVal) const;
		bool operator >=(const Vector4<T>& RightVal) const;

		Vector4<T>& operator =(const Vector4<T>& RightVal);

		Vector4<T>& operator +=(const Vector4<T>& RightVal);
		Vector4<T>& operator -=(const Vector4<T>& RightVal);

		Vector4<T>& operator /=(const T& RightVal);
		Vector4<T>& operator *=(const T& RightVal);

		Vector4<T> operator -() const;

		Vector4<T> operator +(const Vector4<T>& RightVal) const;
		Vector4<T> operator -(const Vector4<T>& RightVal) const;

		Vector4<T> operator /(const T& RightVal) const;
		Vector4<T> operator *(const T& RightVal) const;
	};

	template<typename T> Vector4<T> operator *(const T& LeftVal, const Vector4<T>& RightVal);

	template<typename T> std::ostream& operator <<(std::ostream& Ostr, const Vector4<T>& RightVal);

	typedef Vector4<float>          Vec4;
	typedef Vector4<double>         Vec4d;
	typedef Vector4<int>            Vec4i;
	typedef Vector4<unsigned int>   Vec4u;
	typedef Vector4<unsigned char>  Color;

}
#include "inline/Quaternion.inl"
#endif