#pragma once
#ifndef VECTOR2_H_EGEMATH
#define VECTOR2_H_EGEMATH
#include <ostream>
#include "Utils.h"
#include <cassert>

namespace ege
{
	template<typename T>
	class Vector2
	{
		static const unsigned int COMPONENTS = 2;
	public:
		Vector2();
		explicit Vector2(const T& Value);
		Vector2(const T& X, const T& Y);
		Vector2(const Vector2<T>& V2);
		template<typename T2>
		Vector2(const Vector2<T2>& V2);
		~Vector2();

		/*
		Returns the dot product of 2 different vectors
		*/
		static T dot(const Vector2<T>& A, const Vector2<T>& B);
		/*
		Returns the dot product of 2 different vectors
		*/
		T dot(const Vector2<T>& A) const;
		
		/*
		Returns the cross product of 2 different vectors
		*/
		static T cross(const Vector2<T>& A, const Vector2<T>& B);
		/*
		Returns the cross product of 2 different vectors
		*/
		T cross(const Vector2<T>& A) const;

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
		Vector2<T>& Normalize();
		/*
		Returns normalized version of the vector, does not modify the vector
		*/
		Vector2<T> unitVector() const;

		/*
		Returns the angle of the vector in radians ranging from -PI to PI
		*/
		double angleRadians() const;
		/*
		Returns the angle of the vector in degrees ranging from -180 to 180
		*/
		double angleDegrees() const;

		/*
		Transforms the current vector by given position vector.
		*/
		Vector2<T>& Transform(const Vector2<T>& Position);
		/*
		Rotates the current vector by given amount of degrees.
		*/
		Vector2<T>& RotateDegrees(const float Degrees);
		/*
		Rotates the current vector by given amount of radians.
		*/
		Vector2<T>& RotateRadians(const float Radians);
		/*
		Scales the current vector by given scale vector.
		*/
		Vector2<T>& Scale(const Vector2<T>& Scale);

		union{ T x, w;};
		union{ T y, h;};

		const T& operator [](const unsigned int& index) const;
		T& operator [](const unsigned int& index);

		bool operator ==(const Vector2<T>& RightVal) const;
		bool operator !=(const Vector2<T>& RightVal) const;

		bool operator <(const Vector2<T>& RightVal) const;
		bool operator <=(const Vector2<T>& RightVal) const;

		bool operator >(const Vector2<T>& RightVal) const;
		bool operator >=(const Vector2<T>& RightVal) const;

		Vector2<T>& operator =(const Vector2<T>& RightVal);

		Vector2<T>& operator +=(const Vector2<T>& RightVal);
		Vector2<T>& operator -=(const Vector2<T>& RightVal);

		Vector2<T>& operator /=(const T& RightVal);
		Vector2<T>& operator *=(const T& RightVal);

		Vector2<T> operator -() const;

		Vector2<T> operator +(const Vector2<T>& RightVal) const;
		Vector2<T> operator -(const Vector2<T>& RightVal) const;

		Vector2<T> operator /(const T& RightVal) const;
		Vector2<T> operator *(const T& RightVal) const;

	};

	template<typename T> Vector2<T> operator *(const T& LeftVal, const Vector2<T>& RightVal);

	template<typename T> std::ostream& operator <<(std::ostream& Ostr, const Vector2<T>& RightVal);

	typedef Vector2<float>          Vec2;
	typedef Vector2<double>         Vec2d;
	typedef Vector2<int>            Vec2i;
	typedef Vector2<unsigned int>   Vec2u;
}
#include "inline/Vector2.inl"


#endif