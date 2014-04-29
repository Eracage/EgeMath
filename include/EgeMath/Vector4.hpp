#pragma once
#ifndef VECTOR4_H_EGEMATH
#define VECTOR4_H_EGEMATH
#include "Vector3.hpp"

namespace ege
{
	template<typename T>
	class Vector4
	{
	public:
		Vector4();
		Vector4(const T Value);
		Vector4(const T X, const T Y, const T Z, const T W);
		Vector4(const Vector2<T>& V2, const T Z, const T W);
		Vector4(const Vector3<T>& V3, const T W);
		Vector4(const Vector4<T>& V4);
		~Vector4();
		
		static double Dot(const Vector4<T>& A, const Vector4<T>& B);
		double Dot(const Vector4<T>& A) const;
		
		double LengthSquared() const;
		double Length() const;
		
		union{ T x, r;};
		union{ T y, g;};
		union{ T z, b;};
		union{ T w, a;};

		const T& operator [](const unsigned int& index) const;
		T& operator [](const unsigned int& index);
	};


	template<typename T>
	Vector4<T> operator -(const Vector4<T>& RightVal);
	
	template<typename T>
	Vector4<T> operator +(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);

	template<typename T>
	Vector4<T> operator -(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	
	template<typename T>
	Vector4<T>& operator +=(Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	template<typename T>
	Vector4<T>& operator -=(Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	
	template<typename T>
	Vector4<T> operator /(const Vector4<T>& LeftVal,const T& RightVal);
	template<typename T>
	Vector4<T>& operator /=(Vector4<T>& LeftVal,const T& RightVal);
	
	template<typename T>
	bool operator ==(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	template<typename T>
	bool operator !=(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	
	template<typename T>
	bool operator <(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	template<typename T>
	bool operator <=(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	
	template<typename T>
	bool operator >(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	template<typename T>
	bool operator >=(const Vector4<T>& LeftVal,const Vector4<T>& RightVal);
	
	template<typename T>
	Vector4<T> operator *(const Vector4<T>& LeftVal, const T& RightVal);
	template<typename T>
	Vector4<T> operator *(const T& LeftVal, const Vector4<T>& RightVal);
	
	template<typename T>
	Vector4<T>& operator *=(Vector4<T>& LeftVal, const T& RightVal);
	
	template<typename T>
	std::ostream& operator <<(std::ostream& Ostr, const Vector4<T>& RightVal);
	
	typedef Vector4<float>			Vec4;
	typedef Vector4<double>			Vec4d;
	typedef Vector4<int>			Vec4i;
	typedef Vector4<unsigned int>	Vec4u;
	typedef Vector4<unsigned char>	Color;

}
#include "inline/Vector4.inl"
#endif