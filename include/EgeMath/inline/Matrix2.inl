namespace ege
{
	template<typename T> const Matrix2<T> Matrix2<T>::Identity = Matrix2<T>();

	template<typename T> inline Matrix2<T>::Matrix2()
		: r1(T(1),T(0)),
		r2(T(0),T(1))
	{}
	template<typename T> inline Matrix2<T>::Matrix2(const Matrix2<T>& mat2)
		: r1(mat2[0]),
		r2(mat2[1])
	{}
	template<typename T>
	template<typename T2> inline Matrix2<T>::Matrix2(const Matrix2<T2>& mat2)
		: r1(mat2[0]),
		r2(mat2[1])
	{}
	template<typename T> inline Matrix2<T>::Matrix2(
		const Vector2<T>& Row1,
		const Vector2<T>& Row2)
		: r1(Row1),
		r2(Row2)
	{}
	template<typename T> inline Matrix2<T>::Matrix2(
		const T& r1c1, const T& r1c2,
		const T& r2c1, const T& r2c2)
		: r1(r1c1, r1c2),
		r2(r2c1, r2c2)
	{}
	template<typename T> inline Matrix2<T>::~Matrix2()
	{}

	template<typename T> inline T Matrix2<T>::determinant() const
	{
		return r1.cross(r2);
	}

	template<typename T> inline Matrix2<T>& Matrix2<T>::Transpose()
	{
		return (*this) = transposed();
	}
	template<typename T> inline Matrix2<T> Matrix2<T>::transposed() const
	{
		return Matrix2<T>(
			(*this)[0][0], (*this)[1][0],
			(*this)[0][1], (*this)[1][1]
		);
	}

	template<typename T> inline Matrix2<T> Matrix2<T>::cofactor() const
	{
		return Matrix2<T>(
			(*this)[1][1], -(*this)[1][0],
			-(*this)[0][1], (*this)[0][0]
		);
	}

	template<typename T> inline Matrix2<T>& Matrix2<T>::Inverse()
	{
		return (*this) = inversed();
	}
	template<typename T> inline Matrix2<T> Matrix2<T>::inversed() const
	{
		assert(determinant() != 0);
		return (1.f/determinant()) * cofactor().transposed();
	}

	template<typename T> inline T* Matrix2<T>::ptr() const
	{
		return (T*)&r1.x;
	}

	template<typename T> inline const Vector2<T>& Matrix2<T>::operator [](const unsigned int& index) const
	{
		assert(index < ROWS);
		return (&r1)[index];
	}
	template<typename T> inline Vector2<T>& Matrix2<T>::operator [](const unsigned int& index)
	{
		assert(index < ROWS);
		return (&r1)[index];
	}

	template<typename T> inline bool Matrix2<T>::operator ==(const Matrix2<T>& RightVal) const
	{
		return (
			(*this)[0] == RightVal[0] &&
			(*this)[1] == RightVal[1]
		);
	}
	template<typename T> inline bool Matrix2<T>::operator !=(const Matrix2<T>& RightVal) const
	{
		return !(*this == RightVal);
	}

	template<typename T> inline Matrix2<T>& Matrix2<T>::operator =(const Matrix2<T>& RightVal)
	{
		(*this)[0] = RightVal[0];
		(*this)[1] = RightVal[1];
		return (*this);
	}

	template<typename T> inline Matrix2<T>& Matrix2<T>::operator +=(const Matrix2<T>& RightVal)
	{
		(*this)[0] += RightVal[0];
		(*this)[1] += RightVal[1];
		return (*this);
	}
	template<typename T> inline Matrix2<T>& Matrix2<T>::operator -=(const Matrix2<T>& RightVal)
	{
		(*this)[0] -= RightVal[0];
		(*this)[1] -= RightVal[1];
		return (*this);
	}

	template<typename T> inline Matrix2<T>& Matrix2<T>::operator /=(const T& RightVal)
	{
		(*this)[0] /= RightVal;
		(*this)[1] /= RightVal;
	}
	template<typename T> inline Matrix2<T>& Matrix2<T>::operator *=(const T& RightVal)
	{
		(*this)[0] *= RightVal;
		(*this)[1] *= RightVal;
	}

	template<typename T> inline Matrix2<T> Matrix2<T>::operator +(const Matrix2<T>& RightVal) const
	{
		return Matrix2<T>(
		(*this)[0] + RightVal[0],
		(*this)[1] + RightVal[1]
		);
	}
	template<typename T> inline Matrix2<T> Matrix2<T>::operator -(const Matrix2<T>& RightVal) const
	{
		return Matrix2<T>(
		(*this)[0] - RightVal[0],
		(*this)[1] - RightVal[1]
		);
	}

	template<typename T> inline Matrix2<T> Matrix2<T>::operator /(const T& RightVal) const
	{
		return Matrix2<T>(
		r1 / RightVal,
		r2 / RightVal
		);
	}
	template<typename T> inline Matrix2<T> Matrix2<T>::operator *(const T& RightVal) const
	{
		return Matrix2<T>(
		r1 * RightVal,
		r2 * RightVal
		);
	}

	template<typename T> inline Vector2<T> Matrix2<T>::operator *(const Vector2<T>& RightVal) const
	{
		const T L[ROWS][COLUMNS] = 
		{
			(*this)[0][0],
			(*this)[0][1],
			(*this)[1][0],
			(*this)[1][1]
		};
		const T R[COLUMNS] = 
		{
			RightVal[0],
			RightVal[1]
		};
		return Vector2<T>(
			L[0][0]*R[0] + L[0][1]*R[1],
			L[1][0]*R[0] + L[1][1]*R[1]
			);
	}
	template<typename T> inline Matrix2<T> Matrix2<T>::operator *(const Matrix2<T>& RightVal) const
	{
		const T L[ROWS][COLUMNS] = 
		{
			(*this)[0][0],
			(*this)[0][1],
			(*this)[1][0],
			(*this)[1][1]
		};
		const T R[ROWS][COLUMNS] = 
		{
			RightVal[0][0],
			RightVal[0][1],
			RightVal[1][0],
			RightVal[1][1]
		};
		return Matrix2<T>(
			L[0][0] * R[0][0] + L[0][1] * R[1][0],
			L[0][0] * R[0][1] + L[0][1] * R[1][1],
			L[1][0] * R[0][0] + L[1][1] * R[1][0],
			L[1][0] * R[0][1] + L[1][1] * R[1][1]
			);
	}

	template<typename T> inline Matrix2<T> operator *(const T& LeftVal, const Matrix2<T>& RightVal)
	{
		return RightVal * LeftVal;
	}

	template<typename T> inline Vector2<T>& operator *=(Vector2<T>& LeftVal, const Matrix2<T>& RightVal)
	{
		return LeftVal = RightVal * LeftVal;
	}

	template<typename T> inline std::ostream& operator <<(std::ostream& Ostr, const Matrix2<T>& RightVal)
	{
		return Ostr
			<<std::endl<<"Matrix 2x2:"
			<<std::endl<<"("<<RightVal[0][0]<<")\t("<<RightVal[0][1]<<")"
			<<std::endl<<"("<<RightVal[1][0]<<")\t("<<RightVal[1][1]<<")"
			<<std::endl;
	}

}