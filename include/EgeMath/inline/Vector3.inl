#pragma once

namespace ege
{
	template<typename T> inline Vector3<T>::Vector3()
			: x(T()), y(T()), z(T())
	{}
	template<typename T> inline Vector3<T>::Vector3(const T& Value)
		: x(Value), y(Value), z(Value)
	{}
	template<typename T> inline Vector3<T>::Vector3(const T& X,const T& Y,const T& Z)
		: x(X), y(Y), z(Z)
	{}
	template<typename T> inline Vector3<T>::Vector3(const Vector2<T>& V2, const T& Z)
		: x(V2.x), y(V2.y), z(Z)
	{}
	template<typename T> inline Vector3<T>::Vector3(const Vector3<T>& V3)
		: x(V3.x), y(V3.y), z(V3.z)
	{}
	template<typename T>
	template<typename T2> inline Vector3<T>::Vector3(const Vector3<T2>& V3)
		: x(static_cast<T>(V3.x)), y(static_cast<T>(V3.y)), z(static_cast<T>(V3.z))
	{}
	template<typename T> inline Vector3<T>::~Vector3(){}
	
	template<typename T> inline T Vector3<T>::dot(const Vector3<T>& A, const Vector3<T>& B)
	{
		return A.x * B.x + A.y * B.y + A.z * B.z;
	}
	template<typename T> inline T Vector3<T>::dot(const Vector3<T>& A) const
	{
		return dot(*this,A);
	}
	
	template<typename T> inline Vector3<T> Vector3<T>::cross(const Vector3<T>& A, const Vector3<T>& B)
	{
		return Vector3<T>(
			A.y * B.z - A.z * B.y,
			A.z * B.x - A.x * B.z,
			A.x * B.y - A.y * B.x);
	}
	template<typename T> inline Vector3<T> Vector3<T>::cross(const Vector3<T>& A) const
	{
		return cross(*this,A);
	}

	template<typename T> inline double Vector3<T>::lengthSquared() const
	{
		const double X = static_cast<const double>(x);
		const double Y = static_cast<const double>(y);
		const double Z = static_cast<const double>(z);
		return X*X + Y*Y + Z*Z;
	}
	template<typename T> inline double Vector3<T>::length() const
	{
		return std::sqrt(lengthSquared());
	}
	
	template<typename T> inline Vector3<T>& Vector3<T>::Normalize()
	{
		return *this = unitVector();
	}
	template<typename T> inline Vector3<T> Vector3<T>::unitVector() const
	{
		const double len = length();
		return Vector3<T>(
			static_cast<T>(x / len), 
			static_cast<T>(y / len), 
			static_cast<T>(z / len));
	}

//#pragma region Operators

	template<typename T> inline const T& Vector3<T>::operator [](const unsigned int& index) const
	{
		assert(index<COMPONENTS);
		return (&x)[index];
	}
	template<typename T> inline T& Vector3<T>::operator [](const unsigned int& index)
	{
		assert(index<COMPONENTS);
		return (&x)[index];
	}
	
	template<typename T> inline Vector3<T> operator -(const Vector3<T>& RightVal)
	{
		return Vector3<T>(-RightVal.x, -RightVal.y, -RightVal.z);
	}
	
	template<typename T> inline Vector3<T> operator +(const Vector3<T>& LeftVal,const Vector3<T>& RightVal)
	{
		return Vector3<T>(LeftVal.x+RightVal.x,LeftVal.y+RightVal.y,LeftVal.z+RightVal.z);
	}
	template<typename T> inline Vector3<T> operator -(const Vector3<T>& LeftVal,const Vector3<T>& RightVal)
	{
		return Vector3<T>(LeftVal.x-RightVal.x,LeftVal.y-RightVal.y,LeftVal.z-RightVal.z);
	}
	
	template<typename T> inline const Vector3<T>& operator +=(Vector3<T>& LeftVal,const Vector3<T>& RightVal)
	{
		LeftVal.x += RightVal.x;
		LeftVal.y += RightVal.y;
		LeftVal.z += RightVal.z;
		return LeftVal;
	}
	template<typename T> inline const Vector3<T>& operator -=(Vector3<T>& LeftVal,const Vector3<T>& RightVal)
	{
		LeftVal.x -= RightVal.x;
		LeftVal.y -= RightVal.y;
		LeftVal.z -= RightVal.z;
		return LeftVal;
	}
	
	template<typename T> inline Vector3<T> operator /(const Vector3<T>& LeftVal, const float RightVal)
	{
		return Vector3<T>(LeftVal.x / RightVal,LeftVal.y / RightVal,LeftVal.z / RightVal);
	}
	template<typename T> inline const Vector3<T>& operator /=(Vector3<T>& LeftVal, const float RightVal)
	{
		LeftVal.x /= RightVal;
		LeftVal.y /= RightVal;
		LeftVal.z /= RightVal;
		return LeftVal;
	}
	
	template<typename T> inline bool operator ==(const Vector3<T>& LeftVal,const Vector3<T>& RightVal)
	{
		return (
			equals(LeftVal.x, RightVal.x) && 
			equals(LeftVal.y, RightVal.y) && 
			equals(LeftVal.z, RightVal.z));
	}
	template<typename T> inline bool operator !=(const Vector3<T>& LeftVal,const Vector3<T>& RightVal)
	{
		return !(LeftVal == RightVal);
	}
	
	template<typename T> inline bool operator <(const Vector3<T>& LeftVal,const Vector3<T>& RightVal)
	{
		return LeftVal.lengthSquared() < RightVal.lengthSquared();
	}
	template<typename T> inline bool operator <=(const Vector3<T>& LeftVal,const Vector3<T>& RightVal)
	{
		return LeftVal.lengthSquared() <= RightVal.lengthSquared();
	}
	
	template<typename T> inline bool operator >(const Vector3<T>& LeftVal,const Vector3<T>& RightVal)
	{
		return RightVal < LeftVal;
	}
	template<typename T> inline bool operator >=(const Vector3<T>& LeftVal,const Vector3<T>& RightVal)
	{
		return RightVal <= LeftVal;
	}
	
	template<typename T> inline Vector3<T> operator *(const Vector3<T>& LeftVal, const float RightVal)
	{
		return Vector3<T>(LeftVal.x * RightVal,LeftVal.y * RightVal,LeftVal.z * RightVal);
	}
	template<typename T> inline Vector3<T> operator *(const float LeftVal, const Vector3<T>& RightVal)
	{
		return RightVal*LeftVal;
	}

	template<typename T> inline const Vector3<T>& operator *=(Vector3<T>& LeftVal,const float RightVal)
	{
		LeftVal.x *= RightVal;
		LeftVal.y *= RightVal;
		LeftVal.z *= RightVal;
		return LeftVal;
	}

	template<typename T> inline std::ostream& operator <<(std::ostream& Ostr, const Vector3<T>& RightVal)
	{
		return Ostr<<"("<<RightVal.x<<","<<RightVal.y<<","<<RightVal.z<<")";
	}

//#pragma endregion

}
