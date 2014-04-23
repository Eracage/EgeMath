#pragma once

namespace ege
{
	template<typename T>
	inline Vector2<T>::Vector2()
			: x(T()), y(T())
	{}
	template<typename T>
	inline Vector2<T>::Vector2(T X, T Y)
		: x(X), y(Y)
	{}
	template<typename T>
	inline Vector2<T>::Vector2(T Value)
		: x(Value), y(Value)
	{}
	template<typename T>
	inline Vector2<T>::~Vector2(){}
	
	template<typename T>
	inline float Vector2<T>::LenghtSquared() const
	{	
		return Dot(*this,*this);
	}
	
	template<typename T>
	inline float Vector2<T>::Lenght() const
	{	
		return sqrt(pow(x,2) + pow(y,2));
	}
	template<typename T>
	inline float Vector2<T>::AngleRadians() const
	{
		return atan2(y,x);
	}
	template<typename T>
	inline float Vector2<T>::AngleDegrees() const
	{
		return AngleRadians()*180.0f/PI;
	}
	
	template<typename T>
	inline void Vector2<T>::Transform(const Vector2<T> position)
	{
		x += position.x;
		y += position.y;
	}
	template<typename T>
	inline void Vector2<T>::RotateDegrees(const float degrees)
	{
		RotateRadians(degrees/180.0f*PI);
	}
	template<typename T>
	inline void Vector2<T>::RotateRadians(const float radians)
	{
		if (radians == 0)
			return;

		const float cosA = cos(radians);
		const float sinA = sin(radians);
		const float oldX = x;
		x = oldX*cosA-y*sinA;
		y = oldX*sinA+y*cosA;
	}
	template<typename T>
	inline void Vector2<T>::Scale(const Vector2<T> scale)
	{
		x*=scale.x;
		y*=scale.y;
	}

#pragma region Operators
	
	template<typename T>
	inline Vector2<T> operator -(const Vector2<T>& RightVal)
	{
		return Vector2<T>(-RightVal.x, -RightVal.y);
	}
	
	template<typename T>
	inline Vector2<T> operator +(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return Vector2<T>(LeftVal.x+RightVal.x,LeftVal.y+RightVal.y);
	}
	template<typename T>
	inline Vector2<T> operator -(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return Vector2<T>(LeftVal.x-RightVal.x,LeftVal.y-RightVal.y);
	}
	
	template<typename T>
	inline const Vector2<T>& operator +=(Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		LeftVal.x += RightVal.x;
		LeftVal.y += RightVal.y;
		return LeftVal;
	}
	template<typename T>
	inline const Vector2<T>& operator -=(Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		LeftVal.x -= RightVal.x;
		LeftVal.y -= RightVal.y;
		return LeftVal;
	}
	
	template<typename T>
	inline Vector2<T> operator /(const Vector2<T>& LeftVal, const float& RightVal)
	{
		return Vector2<T>(LeftVal.x / RightVal,LeftVal.y / RightVal);
	}
	template<typename T>
	inline const Vector2<T>& operator /=(Vector2<T>& LeftVal, const float& RightVal)
	{
		LeftVal.x /= RightVal;
		LeftVal.y /= RightVal;
		return LeftVal;
	}
	
	template<typename T>
	inline bool operator ==(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		if (LeftVal.x == RightVal.x && LeftVal.y == RightVal.y)
			return true;
		return false;
	}
	template<typename T>
	inline bool operator !=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return !(LeftVal==RightVal);
	}
	
	template<typename T>
	inline bool operator <(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return LeftVal.LenghtSquared() < RightVal.LenghtSquared();
	}
	template<typename T>
	inline bool operator <=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return LeftVal.LenghtSquared() <= RightVal.LenghtSquared();
	}
	
	template<typename T>
	inline bool operator >(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return LeftVal.LenghtSquared() > RightVal.LenghtSquared();
	}
	template<typename T>
	inline bool operator >=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return LeftVal.LenghtSquared() >= RightVal.LenghtSquared();
	}
	
	template<typename T>
	inline Vector2<T> operator *(const Vector2<T>& LeftVal, const float& RightVal)
	{
		return Vector2<T>(LeftVal.x * RightVal,LeftVal.y * RightVal);
	}
	template<typename T>
	inline Vector2<T> operator *(const float& LeftVal, const Vector2<T>& RightVal)
	{
		return Vector2<T>(LeftVal * RightVal.x,LeftVal * RightVal.y);
	}
	
	template<typename T>
	inline const Vector2<T>& operator *=(Vector2<T>& LeftVal,const float& RightVal)
	{
		LeftVal.x *= RightVal;
		LeftVal.y *= RightVal;
		return LeftVal;
	}

#pragma endregion

	template<typename T>
	inline float Dot(Vector2<T> A, Vector2<T> B)
	{
		return A.x * B.x + A.y * B.y;
	}

	template<typename T>
	inline std::ostream& operator <<(std::ostream& Ostr, const Vector2<T>& RightVal)
	{
		Ostr<<"("<<RightVal.x<<","<<RightVal.y<<")";
	}
}
