#pragma once
#ifndef VECTOR2_H_EGEMATH
#define VECTOR2_H_EGEMATH
#include <ostream>

namespace ege
{
	template<typename T>
	class Vector2
	{
	public:

		Vector2();
		Vector2(T X, T Y);
		Vector2(T Value);
		~Vector2();

		static float Dot(const Vector2<T> A, const Vector2<T> B);

		float LenghtSquared() const;

		float Lenght() const;
		/*
		Returns the angle of the vector in radians ranging from -PI to PI
		*/
		float AngleRadians() const;
		/*
		Returns the angle of the vector in degrees ranging from -180 to 180
		*/
		float AngleDegrees() const;

		/*
		Transforms the current vector by given position vector.
		*/
		void Transform(const Vector2 Position);
		/*
		Rotates the current vector by given amount of degrees.
		*/
		void RotateDegrees(const float Degrees);
		/*
		Rotates the current vector by given amount of radians.
		*/
		void RotateRadians(const float Radians);
		/*
		Scales the current vector by given scale vector.
		*/
		void Scale(const Vector2 Scale);

		union{ T x, w;};
		union{ T y, h;};

		const T& operator [](const unsigned int& index) const;
		T& operator [](const unsigned int& index);
	};

	template<typename T>
	Vector2<T> operator -(const Vector2<T>& RightVal);
	
	template<typename T>
	Vector2<T> operator +(const Vector2<T>& LeftVal,const Vector2<T>& RightVal);

	template<typename T>
	Vector2<T> operator -(const Vector2<T>& LeftVal,const Vector2<T>& RightVal);
	
	template<typename T>
	Vector2<T>& operator +=(Vector2<T>& LeftVal,const Vector2<T>& RightVal);
	template<typename T>
	Vector2<T>& operator -=(Vector2<T>& LeftVal,const Vector2<T>& RightVal);
	
	template<typename T>
	Vector2<T> operator /(const Vector2<T>& LeftVal,const float& RightVal);
	template<typename T>
	Vector2<T>& operator /=(Vector2<T>& LeftVal,const float& RightVal);
	
	template<typename T>
	bool operator ==(const Vector2<T>& LeftVal,const Vector2<T>& RightVal);
	template<typename T>
	bool operator !=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal);
	
	template<typename T>
	bool operator <(const Vector2<T>& LeftVal,const Vector2<T>& RightVal);
	template<typename T>
	bool operator <=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal);
	
	template<typename T>
	bool operator >(const Vector2<T>& LeftVal,const Vector2<T>& RightVal);
	template<typename T>
	bool operator >=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal);
	
	template<typename T>
	Vector2<T> operator *(const Vector2<T>& LeftVal, const float& RightVal);
	template<typename T>
	Vector2<T> operator *(const float& LeftVal, const Vector2<T>& RightVal);
	
	template<typename T>
	Vector2<T>& operator *=(Vector2<T>& LeftVal, const float& RightVal);
	
	template<typename T>
	float Dot(const Vector2<T> A, const Vector2<T> B);
	
	template<typename T>
	std::ostream& operator <<(std::ostream& Ostr, const Vector2<T>& RightVal);

	typedef Vector2<float>			Vec2;
	typedef Vector2<double>			Vec2d;
	typedef Vector2<int>			Vec2i;
	typedef Vector2<unsigned int>	Vec2u;
}
#include <EgeMath/Vector2.inl>
#endif