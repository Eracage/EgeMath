namespace ege
{
	template<typename T> inline Vector4<T>::Vector4()
		: x(T()), y(T()), z(T()), w(T())
	{}
	template<typename T> inline Vector4<T>::Vector4(const T& Value)
		: x(Value), y(Value), z(Value), w(Value)
	{}
	template<typename T> inline Vector4<T>::Vector4(const T& X, const T& Y, const T& Z, const T& W)
		: x(X), y(Y), z(Z), w(W)
	{}
	template<typename T> inline Vector4<T>::Vector4(const Vector2<T>& V2, const T& Z, const T& W)
		: x(V2.x), y(V2.y), z(Z), w(W)
	{}
	template<typename T> inline Vector4<T>::Vector4(const Vector3<T>& V3, const T& W)
		: x(V3.x), y(V3.y), z(V3.z), w(W)
	{}
	template<typename T> inline Vector4<T>::Vector4(const Vector4<T>& V4)
		: x(V4.x), y(V4.y), z(V4.z), w(V4.w)
	{}
	template<typename T>
	template<typename T2> inline Vector4<T>::Vector4(const Vector4<T2>& V4)
		: x(static_cast<T>(V4.x)), y(static_cast<T>(V4.y)), z(static_cast<T>(V4.z)), w(static_cast<T>(V4.w))
	{}
	template<typename T> inline Vector4<T>::~Vector4(){}


	template<typename T> inline Vector2<T> Vector4<T>::xy() const
	{
		return Vector2<T>(x,y);
	}
	template<typename T> inline Vector3<T> Vector4<T>::xyz() const
	{
		return Vector3<T>(x,y,z);
	}

	template<typename T> inline T Vector4<T>::dot(const Vector4<T>& A, const Vector4<T>& B)
	{
		return A.x * B.x + A.y * B.y + A.z * B.z + A.w * B.w;
	}
	template<typename T> inline T Vector4<T>::dot(const Vector4<T>& A) const
	{
		return dot(*this,A);
	}

	template<typename T> inline double Vector4<T>::lengthSquared() const
	{	
		const double X = static_cast<const double>(x);
		const double Y = static_cast<const double>(y);
		const double Z = static_cast<const double>(z);
		const double W = static_cast<const double>(w);
		return X*X + Y*Y + Z*Z + W*W;
	}
	template<typename T> inline double Vector4<T>::length() const
	{	
		return std::sqrt(lengthSquared());
	}
	
	template<typename T> inline Vector4<T>& Vector4<T>::Normalize()
	{
		return *this = unitVector();
	}
	template<typename T> inline Vector4<T> Vector4<T>::unitVector() const
	{
		const double len = length();
		return Vector4<T>(
			static_cast<T>(x / len), 
			static_cast<T>(y / len), 
			static_cast<T>(z / len), 
			static_cast<T>(w / len));
	}

//#pragma region Operators

	template<typename T> inline const T& Vector4<T>::operator [](const unsigned int& index) const
	{
		assert(index<COMPONENTS);
		return (&x)[index];
	}
	template<typename T> inline T& Vector4<T>::operator [](const unsigned int& index)
	{
		assert(index<COMPONENTS);
		return (&x)[index];
	}
	
	template<typename T> inline bool Vector4<T>::operator ==(const Vector4<T>& RightVal) const
	{
		return (
			equals(x, RightVal.x) && 
			equals(y, RightVal.y) && 
			equals(z, RightVal.z) && 
			equals(w, RightVal.w));
	}
	template<typename T> inline bool Vector4<T>::operator !=(const Vector4<T>& RightVal) const
	{
		return !((*this) == RightVal);
	}
	
	template<typename T> inline bool Vector4<T>::operator <(const Vector4<T>& RightVal) const
	{
		return lengthSquared() < RightVal.lengthSquared();
	}
	template<typename T> inline bool Vector4<T>::operator <=(const Vector4<T>& RightVal) const
	{
		return lengthSquared() <= RightVal.lengthSquared();
	}
	
	template<typename T> inline bool Vector4<T>::operator >(const Vector4<T>& RightVal) const
	{
		return RightVal < (*this);
	}
	template<typename T> inline bool Vector4<T>::operator >=(const Vector4<T>& RightVal) const
	{
		return RightVal <= (*this);
	}
	
	template<typename T> inline Vector4<T>& Vector4<T>::operator =(const Vector4<T>& RightVal)
	{
		x = RightVal.x;
		y = RightVal.y;
		z = RightVal.z;
		w = RightVal.w;
		return (*this);
	}

	template<typename T> inline Vector4<T>& Vector4<T>::operator +=(const Vector4<T>& RightVal)
	{
		x += RightVal.x;
		y += RightVal.y;
		z += RightVal.z;
		w += RightVal.w;
		return (*this);
	}
	template<typename T> inline Vector4<T>& Vector4<T>::operator -=(const Vector4<T>& RightVal)
	{
		x -= RightVal.x;
		y -= RightVal.y;
		z -= RightVal.z;
		w -= RightVal.w;
		return (*this);
	}
	
	template<typename T> inline Vector4<T>& Vector4<T>::operator /=( const T& RightVal)
	{
		x /= RightVal;
		y /= RightVal;
		z /= RightVal;
		w /= RightVal;
		return (*this);
	}
	template<typename T> inline Vector4<T>& Vector4<T>::operator *=(const T& RightVal)
	{
		x *= RightVal;
		y *= RightVal;
		z *= RightVal;
		w *= RightVal;
		return (*this);
	}

	template<typename T> inline Vector4<T> Vector4<T>::operator -() const
	{
		return Vector4<T>(-x, -y, -z, -w);
	}
	
	template<typename T> inline Vector4<T> Vector4<T>::operator +(const Vector4<T>& RightVal) const
	{
		return Vector4<T>(x+RightVal.x,y+RightVal.y,z+RightVal.z,w+RightVal.w);
	}
	template<typename T> inline Vector4<T> Vector4<T>::operator -(const Vector4<T>& RightVal) const
	{
		return Vector4<T>(x-RightVal.x,y-RightVal.y,z-RightVal.z,w-RightVal.w);
	}
	
	template<typename T> inline Vector4<T> Vector4<T>::operator /( const T& RightVal) const
	{
		return Vector4<T>(x / RightVal,y / RightVal,z / RightVal,w / RightVal);
	}
	template<typename T> inline Vector4<T> Vector4<T>::operator *( const T& RightVal) const
	{
		return Vector4<T>(x * RightVal,y * RightVal,z * RightVal,w * RightVal);
	}

	template<typename T> inline Vector4<T> operator *(const T& LeftVal, const Vector4<T>& RightVal)
	{
		return RightVal*LeftVal;
	}

	template<typename T> inline std::ostream& operator <<(std::ostream& Ostr, const Vector4<T>& RightVal)
	{
		return Ostr<<"("<<RightVal.x<<","<<RightVal.y<<","<<RightVal.z<<","<<RightVal.w<<")";
	}

//#pragma endregion

}
