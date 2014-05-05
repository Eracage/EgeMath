#pragma once

namespace ege
{
	template<typename T> inline Vector2<T>::Vector2()
			: x(T()), y(T())
	{}
	template<typename T> inline Vector2<T>::Vector2(const T& Value)
		: x(Value), y(Value)
	{}
	template<typename T> inline Vector2<T>::Vector2(const T& X, const T& Y)
		: x(X), y(Y)
	{}
	template<typename T> inline Vector2<T>::Vector2(const Vector2<T>& V2)
		: x(V2.x), y(V2.y)
	{}
	template<typename T>
	template<typename T2> inline Vector2<T>::Vector2(const Vector2<T2>& V2)
		: x(static_cast<T>(V2.x)), y(static_cast<T>(V2.y))
	{}
	template<typename T> inline Vector2<T>::~Vector2(){}
	
	template<typename T> inline static T Vector2<T>::Dot(const Vector2<T>& A, const Vector2<T>& B)
	{
		return A.x * B.x + A.y * B.y;
	}
	template<typename T> inline T Vector2<T>::Dot(const Vector2<T>& A) const
	{
		return Dot(*this,A);
	}
	
	template<typename T> inline static T Vector2<T>::Cross(const Vector2<T>& A, const Vector2<T>& B)
	{
		return A.x * B.y - A.y * B.x;
	}
	template<typename T> inline T Vector2<T>::Cross(const Vector2<T>& A) const
	{
		return Cross(*this,A);
	}
	
	template<typename T> inline double Vector2<T>::LengthSquared() const
	{	
		return Dot(*this,*this);
	}
	template<typename T> inline double Vector2<T>::Length() const
	{	
		return sqrt(LengthSquared());
	}

	template<typename T> inline float Vector2<T>::AngleRadians() const
	{
		return atan2(y,x);
	}
	template<typename T> inline float Vector2<T>::AngleDegrees() const
	{
		return AngleRadians()*180.0f/PI;
	}
	
	template<typename T> inline void Vector2<T>::Transform(const Vector2<T>& position)
	{
		x += position.x;
		y += position.y;
	}
	template<typename T> inline void Vector2<T>::RotateDegrees(const float degrees)
	{
		RotateRadians(degrees/180.0f*PI);
	}
	template<typename T> inline void Vector2<T>::RotateRadians(const float radians)
	{
		if (radians == 0)
			return;

		const float cosA = cos(radians);
		const float sinA = sin(radians);
		const float oldX = x;
		x = oldX*cosA-y*sinA;
		y = oldX*sinA+y*cosA;
	}
	template<typename T> inline void Vector2<T>::Scale(const Vector2<T>& scale)
	{
		x*=scale.x;
		y*=scale.y;
	}

//#pragma region Operators

	template<typename T> inline const T& Vector2<T>::operator [](const unsigned int& index) const
	{
		assert(index>2);
		return (&x)[index];
	}
	template<typename T> inline T& Vector2<T>::operator [](const unsigned int& index)
	{
		assert(index>2);
		return (&x)[index];
	}
	
	template<typename T> inline Vector2<T> operator -(const Vector2<T>& RightVal)
	{
		return Vector2<T>(-RightVal.x, -RightVal.y);
	}
	
	template<typename T> inline Vector2<T> operator +(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return Vector2<T>(LeftVal.x+RightVal.x,LeftVal.y+RightVal.y);
	}
	template<typename T> inline Vector2<T> operator -(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return Vector2<T>(LeftVal.x-RightVal.x,LeftVal.y-RightVal.y);
	}
	
	template<typename T> inline const Vector2<T>& operator +=(Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		LeftVal.x += RightVal.x;
		LeftVal.y += RightVal.y;
		return LeftVal;
	}
	template<typename T> inline const Vector2<T>& operator -=(Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		LeftVal.x -= RightVal.x;
		LeftVal.y -= RightVal.y;
		return LeftVal;
	}
	
	template<typename T> inline Vector2<T> operator /(const Vector2<T>& LeftVal, const float RightVal)
	{
		return Vector2<T>(LeftVal.x / RightVal,LeftVal.y / RightVal);
	}
	template<typename T> inline const Vector2<T>& operator /=(Vector2<T>& LeftVal, const float RightVal)
	{
		LeftVal.x /= RightVal;
		LeftVal.y /= RightVal;
		return LeftVal;
	}
	
	template<typename T> inline bool operator ==(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return !(LeftVal!=RightVal);
	}
	template<typename T> inline bool operator !=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return (LeftVal.x != RightVal.x || LeftVal.y != RightVal.y);
	}
	
	template<typename T> inline bool operator <(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return LeftVal.LengthSquared() < RightVal.LengthSquared();
	}
	template<typename T> inline bool operator <=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return LeftVal.LengthSquared() <= RightVal.LengthSquared();
	}
	
	template<typename T> inline bool operator >(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return LeftVal.LengthSquared() > RightVal.LengthSquared();
	}
	template<typename T> inline bool operator >=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return LeftVal.LengthSquared() >= RightVal.LengthSquared();
	}
	
	template<typename T> inline Vector2<T> operator *(const Vector2<T>& LeftVal, const float RightVal)
	{
		return Vector2<T>(LeftVal.x * RightVal,LeftVal.y * RightVal);
	}
	template<typename T> inline Vector2<T> operator *(const float LeftVal, const Vector2<T>& RightVal)
	{
		return RightVal*LeftVal;
	}
	
	template<typename T> inline const Vector2<T>& operator *=(Vector2<T>& LeftVal,const float RightVal)
	{
		LeftVal.x *= RightVal;
		LeftVal.y *= RightVal;
		return LeftVal;
	}

	template<typename T> inline std::ostream& operator <<(std::ostream& Ostr, const Vector2<T>& RightVal)
	{
		return Ostr<<"("<<RightVal.x<<","<<RightVal.y<<")";
	}
//#pragma endregion


}
