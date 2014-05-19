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
	
	template<typename T> inline T Vector2<T>::dot(const Vector2<T>& A, const Vector2<T>& B)
	{
		return A.x * B.x + A.y * B.y;
	}
	template<typename T> inline T Vector2<T>::dot(const Vector2<T>& A) const
	{
		return dot(*this,A);
	}
	
	template<typename T> inline T Vector2<T>::cross(const Vector2<T>& A, const Vector2<T>& B)
	{
		return A.x * B.y - A.y * B.x;
	}
	template<typename T> inline T Vector2<T>::cross(const Vector2<T>& A) const
	{
		return cross(*this,A);
	}
	
	template<typename T> inline double Vector2<T>::lengthSquared() const
	{
		const double X = static_cast<const double>(x);
		const double Y = static_cast<const double>(y);
		return X*X + Y*Y;
	}
	template<typename T> inline double Vector2<T>::length() const
	{
		return std::sqrt(lengthSquared());
	}
	
	template<typename T> inline Vector2<T>& Vector2<T>::Normalize()
	{
		return *this = unitVector();
	}
	template<typename T> inline Vector2<T> Vector2<T>::unitVector() const
	{
		const double len = length();
		return Vector2<T>(
			static_cast<T>(x / len), 
			static_cast<T>(y / len));
	}

	template<typename T> inline double Vector2<T>::angleRadians() const
	{
		return std::atan2(y,x);
	}
	template<typename T> inline double Vector2<T>::angleDegrees() const
	{
		return angleRadians()*180.0/PI;
	}
	
	template<typename T> inline Vector2<T>& Vector2<T>::Transform(const Vector2<T>& position)
	{
		return *this += position;
	}
	template<typename T> inline Vector2<T>& Vector2<T>::RotateDegrees(const float degrees)
	{
		RotateRadians(degrees/180.0f*PI);
		return *this;
	}
	template<typename T> inline Vector2<T>& Vector2<T>::RotateRadians(const float radians)
	{
		const float cosA = std::cos(radians);
		const float sinA = std::sin(radians);
		const float oldX = x;
		x = oldX*cosA-y*sinA;
		y = oldX*sinA+y*cosA;
		return *this;
	}
	template<typename T> inline Vector2<T>& Vector2<T>::Scale(const Vector2<T>& scale)
	{
		x*=scale.x;
		y*=scale.y;
		return *this;
	}

//#pragma region Operators

	template<typename T> inline const T& Vector2<T>::operator [](const unsigned int& index) const
	{
		assert(index<COMPONENTS);
		return (&x)[index];
	}
	template<typename T> inline T& Vector2<T>::operator [](const unsigned int& index)
	{
		assert(index<COMPONENTS);
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
		return (
			equals(LeftVal.x, RightVal.x) && 
			equals(LeftVal.y, RightVal.y));
	}
	template<typename T> inline bool operator !=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return !(LeftVal == RightVal);
	}
	
	template<typename T> inline bool operator <(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return LeftVal.lengthSquared() < RightVal.lengthSquared();
	}
	template<typename T> inline bool operator <=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return LeftVal.lengthSquared() <= RightVal.lengthSquared();
	}
	
	template<typename T> inline bool operator >(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return RightVal < LeftVal;
	}
	template<typename T> inline bool operator >=(const Vector2<T>& LeftVal,const Vector2<T>& RightVal)
	{
		return RightVal <= LeftVal;
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
