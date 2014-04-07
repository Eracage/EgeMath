#include <cmath>
#include <Math.hpp>

namespace ege
{
	Vector2::Vector2()
			: x(0), y(0)
	{}
	Vector2::Vector2(float X, float Y)
		: x(X), y(Y)
	{}
	Vector2::~Vector2(){}
	
	float Vector2::LenghtSquared() const
	{	
		return Dot(*this,*this);
	}

	float Vector2::Lenght() const
	{	
		return sqrt(pow(x,2) + pow(y,2));
	}
	float Vector2::AngleRadians() const
	{
		return atan2(y,x);
	}
	float Vector2::AngleDegrees() const
	{
		return AngleRadians()*180.0f/PI;
	}

	void Vector2::Transform(const Vector2 position)
	{
		x += position.x;
		y += position.y;
	}
	void Vector2::RotateDegrees(const float degrees)
	{
		RotateRadians(degrees/180.0f*PI);
	}
	void Vector2::RotateRadians(const float radians)
	{
		if (radians == 0)
			return;

		const float cosA = cos(radians);
		const float sinA = sin(radians);
		const float oldX = x;
		x = oldX*cosA-y*sinA;
		y = oldX*sinA+y*cosA;
	}
	void Vector2::Scale(const Vector2 scale)
	{
		x*=scale.x;
		y*=scale.y;
	}

	Vector2 operator -(const Vector2& RightVal)
	{
		return Vector2(-RightVal.x, -RightVal.y);
	}

	Vector2 operator +(const Vector2& LeftVal,const Vector2& RightVal)
	{
		return Vector2(LeftVal.x+RightVal.x,LeftVal.y+RightVal.y);
	}
	Vector2 operator -(const Vector2& LeftVal,const Vector2& RightVal)
	{
		return Vector2(LeftVal.x-RightVal.x,LeftVal.y-RightVal.y);
	}

	const Vector2& operator +=(Vector2& LeftVal,const Vector2& RightVal)
	{
		LeftVal.x += RightVal.x;
		LeftVal.y += RightVal.y;
		return LeftVal;
	}
	const Vector2& operator -=(Vector2& LeftVal,const Vector2& RightVal)
	{
		LeftVal.x -= RightVal.x;
		LeftVal.y -= RightVal.y;
		return LeftVal;
	}

	Vector2 operator /(const Vector2& LeftVal, const float& RightVal)
	{
		return Vector2(LeftVal.x / RightVal,LeftVal.y / RightVal);
	}
	const Vector2& operator /=(Vector2& LeftVal, const float& RightVal)
	{
		LeftVal.x /= RightVal;
		LeftVal.y /= RightVal;
		return LeftVal;
	}

	bool operator ==(const Vector2& LeftVal,const Vector2& RightVal)
	{
		if (LeftVal.x == RightVal.x && LeftVal.y == RightVal.y)
			return true;
		return false;
	}
	bool operator !=(const Vector2& LeftVal,const Vector2& RightVal)
	{
		return !(LeftVal==RightVal);
	}

	

	bool operator <(const Vector2& LeftVal,const Vector2& RightVal)
	{
		return LeftVal.LenghtSquared() < RightVal.LenghtSquared();
	}
	bool operator <=(const Vector2& LeftVal,const Vector2& RightVal)
	{
		return LeftVal.LenghtSquared() <= RightVal.LenghtSquared();
	}

	bool operator >(const Vector2& LeftVal,const Vector2& RightVal)
	{
		return LeftVal.LenghtSquared() > RightVal.LenghtSquared();
	}
	bool operator >=(const Vector2& LeftVal,const Vector2& RightVal)
	{
		return LeftVal.LenghtSquared() >= RightVal.LenghtSquared();
	}

	Vector2 operator *(const Vector2& LeftVal, const float& RightVal)
	{
		return Vector2(LeftVal.x * RightVal,LeftVal.y * RightVal);
	}
	Vector2 operator *(const float& LeftVal, const Vector2& RightVal)
	{
		return Vector2(LeftVal * RightVal.x,LeftVal * RightVal.y);
	}

	const Vector2& operator *=(Vector2& LeftVal,const float& RightVal)
	{
		LeftVal.x *= RightVal;
		LeftVal.y *= RightVal;
		return LeftVal;
	}


	float Dot(Vector2 A, Vector2 B)
	{
		return A.x * B.x + A.y * B.y;
	}
}
