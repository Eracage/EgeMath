#pragma once
#ifndef VECTOR4_H_EGEMATH
#define VECTOR4_H_EGEMATH
#include "Vector3.hpp"

namespace ege
{
	template<typename T>
	class Vector4
	{
		static const unsigned int COMPONENTS = 4;
	public:
		Vector4();
		explicit Vector4(const T& Value);
		Vector4(const T& X, const T& Y, const T& Z, const T& W);
		Vector4(const Vector2<T>& V2, const T& Z, const T& W);
		Vector4(const Vector3<T>& V3, const T& W);
		Vector4(const Vector4<T>& V4);
		template<typename T2>
		Vector4(const Vector4<T2>& V4);
		~Vector4();
		
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
	};

	template<typename T> Vector4<T> operator -(const Vector4<T>& RightVal);
	
	template<typename T> Vector4<T> operator +(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	template<typename T> Vector4<T> operator -(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	
	template<typename T> const Vector4<T>& operator +=(Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	template<typename T> const Vector4<T>& operator -=(Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	
	template<typename T> Vector4<T> operator /(const Vector4<T>& LeftVal,const T& RightVal);
	template<typename T> const Vector4<T>& operator /=(Vector4<T>& LeftVal,const T& RightVal);
	
	template<typename T> bool operator ==(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	template<typename T> bool operator !=(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	
	template<typename T> bool operator <(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	template<typename T> bool operator <=(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	
	template<typename T> bool operator >(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	template<typename T> bool operator >=(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	
	template<typename T> Vector4<T> operator *(const Vector4<T>& LeftVal, const T& RightVal);
	template<typename T> Vector4<T> operator *(const T& LeftVal, const Vector4<T>& RightVal);
	
	template<typename T> const Vector4<T>& operator *=(Vector4<T>& LeftVal, const T& RightVal);
	
	template<typename T> std::ostream& operator <<(std::ostream& Ostr, const Vector4<T>& RightVal);
	
	typedef Vector4<float>          Vec4;
	typedef Vector4<double>         Vec4d;
	typedef Vector4<int>            Vec4i;
	typedef Vector4<unsigned int>   Vec4u;
	typedef Vector4<unsigned char>  Color;

}
#include "inline/Vector4.inl"
#endif