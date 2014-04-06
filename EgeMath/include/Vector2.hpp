#pragma once
#ifndef VECTOR2_H_EGEMATH
#define VECTOR2_H_EGEMATH

namespace ege
{
	class Vector2
		{
		public:
			Vector2();
			Vector2(float X, float Y);
			~Vector2();

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

			union
			{
				struct
				{
					float x,y;
				};
				struct
				{
					float w,h;
				};
			};

		private:

		};

	Vector2 operator -(const Vector2& RightVal);

	Vector2 operator +(const Vector2& LeftVal,const Vector2& RightVal);
	Vector2 operator -(const Vector2& LeftVal,const Vector2& RightVal);

	const Vector2& operator +=(Vector2& LeftVal,const Vector2& RightVal);
	const Vector2& operator -=(Vector2& LeftVal,const Vector2& RightVal);

	Vector2 operator /(const Vector2& LeftVal,const float& RightVal);
	const Vector2& operator /=(Vector2& LeftVal,const float& RightVal);

	bool operator ==(const Vector2& LeftVal,const Vector2& RightVal);
	bool operator !=(const Vector2& LeftVal,const Vector2& RightVal);

	bool operator <(const Vector2& LeftVal,const Vector2& RightVal);
	bool operator <=(const Vector2& LeftVal,const Vector2& RightVal);

	bool operator >(const Vector2& LeftVal,const Vector2& RightVal);
	bool operator >=(const Vector2& LeftVal,const Vector2& RightVal);

	Vector2 operator *(const Vector2& LeftVal, const float& RightVal);
	Vector2 operator *(const float& LeftVal, const Vector2& RightVal);

	const Vector2& operator *=(Vector2& LeftVal, const float& RightVal);

	float Dot(const Vector2 A, const Vector2 B);
		/*std::ostream& operator <<(std::ostream& Ostr, const vector& RightVal);*/
}
#endif