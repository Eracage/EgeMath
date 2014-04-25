#pragma once
#ifndef VECTOR3_H_EGEMATH
#define VECTOR3_H_EGEMATH
#include "Vector2.hpp"

namespace ege
{
	template<typename T>
	class Vector3
	{
	public:
		Vector3();
		Vector3(const T Value);
		Vector3(const T X, const T Y, const T Z);
		Vector3(const Vector2<T>& V2, const T Z);
		Vector3(const Vector3<T>& V3);
		~Vector3();
		
		static float Dot(const Vector3<T>& A, const Vector3<T>& B);
		float Dot(const Vector3<T>& A) const;
		
		static Vector3<T> Cross(const Vector3<T>& A, const Vector3<T>& B);
		Vector3<T> Cross(const Vector3<T>& A) const;

		float LengthSquared() const;
		float Length() const;
		

		union{ T x, r;};
		union{ T y, g;};
		union{ T z, b;};
			
		const T& operator [](const unsigned int& index) const;
		T& operator [](const unsigned int& index);
	};


	template<typename T>
	Vector3<T> operator -(const Vector3<T>& RightVal);
	
	template<typename T>
	Vector3<T> operator +(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);

	template<typename T>
	Vector3<T> operator -(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	
	template<typename T>
	Vector3<T>& operator +=(Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	template<typename T>
	Vector3<T>& operator -=(Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	
	template<typename T>
	Vector3<T> operator /(const Vector3<T>& LeftVal,const float RightVal);
	template<typename T>
	Vector3<T>& operator /=(Vector3<T>& LeftVal,const float RightVal);
	
	template<typename T>
	bool operator ==(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	template<typename T>
	bool operator !=(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	
	template<typename T>
	bool operator <(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	template<typename T>
	bool operator <=(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	
	template<typename T>
	bool operator >(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	template<typename T>
	bool operator >=(const Vector3<T>& LeftVal,const Vector3<T>& RightVal);
	
	template<typename T>
	Vector3<T> operator *(const Vector3<T>& LeftVal, const float RightVal);
	template<typename T>
	Vector3<T> operator *(const float LeftVal, const Vector3<T>& RightVal);
	
	template<typename T>
	Vector3<T>& operator *=(Vector3<T>& LeftVal, const float RightVal);
	
	template<typename T>
	std::ostream& operator <<(std::ostream& Ostr, const Vector3<T>& RightVal);
	
	typedef Vector3<float>			Vec3;
	typedef Vector3<double>			Vec3d;
	typedef Vector3<int>			Vec3i;
	typedef Vector3<unsigned int>	Vec3u;
	typedef Vector3<unsigned char>	ColorRGB;
}
#include "inline/Vector3.inl"
#endif