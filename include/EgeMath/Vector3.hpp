#pragma once
#ifndef VECTOR3_H_EGEMATH
#define VECTOR3_H_EGEMATH
#include "Vector2.hpp"

namespace ege
{
	template<typename T>
	class Vector3
	{
		static const unsigned int COMPONENTS = 3;
	public:
		Vector3();
		explicit Vector3(const T& Value);
		Vector3(const T& X, const T& Y, const T& Z);
		Vector3(const Vector2<T>& V2, const T& Z);
		Vector3(const Vector3<T>& V3);
		template<typename T2>
		Vector3(const Vector3<T2>& V3);
		~Vector3();
		
		/*
		Returns the dot product of 2 different vectors
		*/
		static T dot(const Vector3<T>& A, const Vector3<T>& B);
		/*
		Returns the dot product of 2 different vectors
		*/
		T dot(const Vector3<T>& A) const;
		
		/*
		Returns the cross product of 2 different vectors
		*/
		static Vector3<T> cross(const Vector3<T>& A, const Vector3<T>& B);
		/*
		Returns the cross product of 2 different vectors
		*/
		Vector3<T> cross(const Vector3<T>& A) const;
		
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
		Vector3<T>& Normalize();
		/*
		Returns normalized version of the vector, does not modify the vector
		*/
		Vector3<T> unitVector() const;

		union{ T x, r;};
		union{ T y, g;};
		union{ T z, b;};
			
		const T& operator [](const unsigned int& index) const;
		T& operator [](const unsigned int& index);
	};

	template<typename T> Vector3<T> operator -(const Vector3<T>& RightVal);
	
	template<typename T> Vector3<T> operator +(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	template<typename T> Vector3<T> operator -(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	
	template<typename T> const Vector3<T>& operator +=(Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	template<typename T> const Vector3<T>& operator -=(Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	
	template<typename T> Vector3<T> operator /(const Vector3<T>& LeftVal,const T& RightVal);
	template<typename T> const Vector3<T>& operator /=(Vector3<T>& LeftVal,const T& RightVal);
	
	template<typename T> bool operator ==(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	template<typename T> bool operator !=(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	
	template<typename T> bool operator <(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	template<typename T> bool operator <=(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	
	template<typename T> bool operator >(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	template<typename T> bool operator >=(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	
	template<typename T> Vector3<T> operator *(const Vector3<T>& LeftVal, const T& RightVal);
	template<typename T> Vector3<T> operator *(const T& LeftVal, const Vector3<T>& RightVal);
	
	template<typename T> const Vector3<T>& operator *=(Vector3<T>& LeftVal, const T& RightVal);
	
	template<typename T> std::ostream& operator <<(std::ostream& Ostr, const Vector3<T>& RightVal);
	
	typedef Vector3<float>          Vec3;
	typedef Vector3<double>         Vec3d;
	typedef Vector3<int>            Vec3i;
	typedef Vector3<unsigned int>   Vec3u;
	typedef Vector3<unsigned char>  ColorRGB;
}
#include "inline/Vector3.inl"
#endif