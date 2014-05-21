namespace ege
{
	template<typename T> const Matrix3<T> Matrix3<T>::Identity = Matrix3<T>();

	template<typename T> inline Matrix3<T>::Matrix3()
		: r1(T(1),T(0),T(0)),
		r2(T(0),T(1),T(0)),
		r3(T(0),T(0),T(1))
	{}
	template<typename T> inline Matrix3<T>::Matrix3(const Matrix2<T>& mat2)
		: r1(mat2[0],T(0)),
		r2(mat2[1],T(0)),
		r3(T(0), T(0), T(1))
	{}
	template<typename T> inline Matrix3<T>::Matrix3(const Matrix3<T>& mat3)
		: r1(mat3[0]),
		r2(mat3[1]),
		r3(mat3[2])
	{}
	template<typename T>
	template<typename T2> inline Matrix3<T>::Matrix3(const Matrix3<T2>& mat3)
		: r1(mat3[0]),
		r2(mat3[1]),
		r3(mat3[2])
	{}
	template<typename T> inline Matrix3<T>::Matrix3(
		const Vector3<T>& Row1,
		const Vector3<T>& Row2,
		const Vector3<T>& Row3)
		: r1(Row1),
		r2(Row2),
		r3(Row3)
	{}
	template<typename T> inline Matrix3<T>::Matrix3(
		const T& r1c1, const T& r1c2, const T& r1c3,
		const T& r2c1, const T& r2c2, const T& r2c3,
		const T& r3c1, const T& r3c2, const T& r3c3)
		: r1(r1c1, r1c2, r1c3),
		r2(r2c1, r2c2, r2c3),
		r3(r3c1, r3c2, r3c3)
	{}
	template<typename T> inline Matrix3<T>::~Matrix3()
	{}

	template<typename T> Matrix2<T> Matrix3<T>::subMatrix2(const unsigned int RowToRemove = 3, const unsigned int ColumnToRemove = 3) const
	{
		assert(RowToRemove < ROWS && ColumnToRemove < COLUMNS);
		Matrix2<T> retVal;

		for (unsigned int row = 0; row < ROWS; ++row)
		{
			if (row != RowToRemove)
			{
				for (unsigned int col = 0; col < COLUMNS; ++col)
				{
					if (col != ColumnToRemove)
						retVal[row - (row > RowToRemove)][col - (col > ColumnToRemove)] = (*this)[row][col];
				}
			}
		}

		return retVal;
	}

	template<typename T> inline T Matrix3<T>::determinant() const
	{

		const T A[ROWS][COLUMNS] = 
		{
			(*this)[0][0],
			(*this)[0][1],
			(*this)[0][2],
			(*this)[1][0],
			(*this)[1][1],
			(*this)[1][2],
			(*this)[2][0],
			(*this)[2][1],
			(*this)[2][2]
		};
		return (
			-A[0][2] * A[1][1] * A[2][0]
			+A[0][1] * A[1][2] * A[2][0]
			+A[0][2] * A[1][0] * A[2][1]
			-A[0][0] * A[1][2] * A[2][1]
			-A[0][1] * A[1][0] * A[2][2]
			+A[0][0] * A[1][1] * A[2][2]
			);

		//return (
		//	r1[0]*(subMatrix2(0,0).determinant()) -
		//	r1[1]*(subMatrix2(0,1).determinant()) +
		//	r1[2]*(subMatrix2(0,2).determinant())
		//	);

	}

	template<typename T> inline Matrix3<T>& Matrix3<T>::Transpose()
	{
		return (*this) = transposed();
	}
	template<typename T> inline Matrix3<T> Matrix3<T>::transposed() const
	{
		return Matrix3<T>(
			(*this)[0][0], (*this)[1][0], (*this)[2][0],
			(*this)[0][1], (*this)[1][1], (*this)[2][1],
			(*this)[0][2], (*this)[1][2], (*this)[2][2]
		);
	}

	template<typename T> inline Matrix3<T> Matrix3<T>::cofactor() const
	{
		const T A[ROWS][COLUMNS] = 
		{
			(*this)[0][0],
			(*this)[0][1],
			(*this)[0][2],
			(*this)[1][0],
			(*this)[1][1],
			(*this)[1][2],
			(*this)[2][0],
			(*this)[2][1],
			(*this)[2][2]
		};
		return Matrix3<T>(
			A[1][1] * A[2][2] - A[1][2] * A[2][1],
			A[1][2] * A[2][0] - A[1][0] * A[2][2],
			A[1][0] * A[2][1] - A[1][1] * A[2][0],
			A[0][2] * A[2][1] - A[0][1] * A[2][2],
			A[0][0] * A[2][2] - A[0][2] * A[2][0],
			A[0][1] * A[2][0] - A[0][0] * A[2][1],
			A[0][1] * A[1][2] - A[0][2] * A[1][1],
			A[0][2] * A[1][0] - A[0][0] * A[1][2],
			A[0][0] * A[1][1] - A[0][1] * A[1][0]
			);

		//return Matrix3<T>(
		//	subMatrix2(0,0).determinant(),
		//	-subMatrix2(0,1).determinant(),
		//	subMatrix2(0,2).determinant(),
		//	-subMatrix2(1,0).determinant(),
		//	subMatrix2(1,1).determinant(),
		//	-subMatrix2(1,2).determinant(),
		//	subMatrix2(2,0).determinant(),
		//	-subMatrix2(2,1).determinant(),
		//	subMatrix2(2,2).determinant()
		//	);
	}

	template<typename T> inline Matrix3<T>& Matrix3<T>::Inverse()
	{
		return (*this) = inversed();
	}
	template<typename T> inline Matrix3<T> Matrix3<T>::inversed() const
	{
		assert(determinant() != 0);
		return (1.f/determinant()) * cofactor().transposed();
	}

	template<typename T> inline T* Matrix3<T>::ptr() const
	{
		return (T*)&r1.x;
	}

	template<typename T> inline const Vector3<T>& Matrix3<T>::operator [](const unsigned int& index) const
	{
		assert(index < ROWS);
		return (&r1)[index];
	}
	template<typename T> inline Vector3<T>& Matrix3<T>::operator [](const unsigned int& index)
	{
		assert(index < ROWS);
		return (&r1)[index];
	}

	template<typename T> inline bool Matrix3<T>::operator ==(const Matrix3<T>& RightVal) const
	{
		return (
			(*this)[0] == RightVal[0] &&
			(*this)[1] == RightVal[1] &&
			(*this)[2] == RightVal[2]
		);
	}
	template<typename T> inline bool Matrix3<T>::operator !=(const Matrix3<T>& RightVal) const
	{
		return !(*this == RightVal);
	}

	template<typename T> inline Matrix3<T>& Matrix3<T>::operator =(const Matrix3<T>& RightVal)
	{
		(*this)[0] = RightVal[0];
		(*this)[1] = RightVal[1];
		(*this)[2] = RightVal[2];
		return (*this);
	}

	template<typename T> inline Matrix3<T>& Matrix3<T>::operator +=(const Matrix3<T>& RightVal)
	{
		(*this)[0] += RightVal[0];
		(*this)[1] += RightVal[1];
		(*this)[2] += RightVal[2];
		return (*this);
	}
	template<typename T> inline Matrix3<T>& Matrix3<T>::operator -=(const Matrix3<T>& RightVal)
	{
		(*this)[0] -= RightVal[0];
		(*this)[1] -= RightVal[1];
		(*this)[2] -= RightVal[2];
		return (*this);
	}

	template<typename T> inline Matrix3<T>& Matrix3<T>::operator /=(const T& RightVal)
	{
		(*this)[0] /= RightVal;
		(*this)[1] /= RightVal;
		(*this)[2] /= RightVal;
	}
	template<typename T> inline Matrix3<T>& Matrix3<T>::operator *=(const T& RightVal)
	{
		(*this)[0] *= RightVal;
		(*this)[1] *= RightVal;
		(*this)[2] *= RightVal;
	}

	template<typename T> inline Matrix3<T> Matrix3<T>::operator +(const Matrix3<T>& RightVal) const
	{
		return Matrix3<T>(
		(*this)[0] + RightVal[0],
		(*this)[1] + RightVal[1],
		(*this)[2] + RightVal[2]
		);
	}
	template<typename T> inline Matrix3<T> Matrix3<T>::operator -(const Matrix3<T>& RightVal) const
	{
		return Matrix3<T>(
		(*this)[0] - RightVal[0],
		(*this)[1] - RightVal[1],
		(*this)[2] - RightVal[2]
		);
	}

	template<typename T> inline Matrix3<T> Matrix3<T>::operator /(const T& RightVal) const
	{
		return Matrix3<T>(
		r1 / RightVal,
		r2 / RightVal,
		r3 / RightVal
		);
	}
	template<typename T> inline Matrix3<T> Matrix3<T>::operator *(const T& RightVal) const
	{
		return Matrix3<T>(
		r1 * RightVal,
		r2 * RightVal,
		r3 * RightVal
		);
	}
	
	template<typename T> inline Vector2<T> Matrix3<T>::operator *(const Vector2<T>& RightVal) const
	{
		const T L[ROWS][COLUMNS] = 
		{
			(*this)[0][0],
			(*this)[0][1],
			(*this)[0][2],
			(*this)[1][0],
			(*this)[1][1],
			(*this)[1][2],
			(*this)[2][0],
			(*this)[2][1],
			(*this)[2][2]
		};
		const T R[COLUMNS] = 
		{
			RightVal[0],
			RightVal[1]
		};
		return Vector2<T>(
			L[0][0] * R[0] + L[0][1] * R[1] + L[0][2] * T(1),
			L[1][0] * R[0] + L[1][1] * R[1] + L[1][2] * T(1)
		);
	}
	template<typename T> inline Vector3<T> Matrix3<T>::operator *(const Vector3<T>& RightVal) const
	{
		const T L[ROWS][COLUMNS] = 
		{
			(*this)[0][0],
			(*this)[0][1],
			(*this)[0][2],
			(*this)[1][0],
			(*this)[1][1],
			(*this)[1][2],
			(*this)[2][0],
			(*this)[2][1],
			(*this)[2][2]
		};
		const T R[COLUMNS] = 
		{
			RightVal[0],
			RightVal[1],
			RightVal[2]
		};
		return Vector3<T>(
			L[0][0] * R[0] + L[0][1] * R[1] + L[0][2] * R[2],
			L[1][0] * R[0] + L[1][1] * R[1] + L[1][2] * R[2],
			L[2][0] * R[0] + L[2][1] * R[1] + L[2][2] * R[2]
		);
	}
	template<typename T> inline Matrix3<T> Matrix3<T>::operator *(const Matrix3<T>& RightVal) const
	{
		const T L[ROWS][COLUMNS] = 
		{
			(*this)[0][0],
			(*this)[0][1],
			(*this)[0][2],
			(*this)[1][0],
			(*this)[1][1],
			(*this)[1][2],
			(*this)[2][0],
			(*this)[2][1],
			(*this)[2][2]
		};
		const T R[ROWS][COLUMNS] = 
		{
			RightVal[0][0],
			RightVal[0][1],
			RightVal[0][2],
			RightVal[1][0],
			RightVal[1][1],
			RightVal[1][2],
			RightVal[2][0],
			RightVal[2][1],
			RightVal[2][2]
		};
		return Matrix3<T>(
			L[0][0] * R[0][0] + L[0][1] * R[1][0] + L[0][2] * R[2][0],
			L[0][0] * R[0][1] + L[0][1] * R[1][1] + L[0][2] * R[2][1],
			L[0][0] * R[0][2] + L[0][1] * R[1][2] + L[0][2] * R[2][2],
			L[1][0] * R[0][0] + L[1][1] * R[1][0] + L[1][2] * R[2][0],
			L[1][0] * R[0][1] + L[1][1] * R[1][1] + L[1][2] * R[2][1],
			L[1][0] * R[0][2] + L[1][1] * R[1][2] + L[1][2] * R[2][2],
			L[2][0] * R[0][0] + L[2][1] * R[1][0] + L[2][2] * R[2][0],
			L[2][0] * R[0][1] + L[2][1] * R[1][1] + L[2][2] * R[2][1],
			L[2][0] * R[0][2] + L[2][1] * R[1][2] + L[2][2] * R[2][2]
		);
	}
	
	template<typename T> inline Matrix3<T> operator *(const T& LeftVal, const Matrix3<T>& RightVal)
	{
		return RightVal * LeftVal;
	}
	
	template<typename T> inline Vector2<T>& operator *=(Vector2<T>& LeftVal, const Matrix3<T>& RightVal)
	{
		return LeftVal = RightVal * LeftVal;
	}
	template<typename T> inline Vector3<T>& operator *=(Vector3<T>& LeftVal, const Matrix3<T>& RightVal)
	{
		return LeftVal = RightVal * LeftVal;
	}

	template<typename T> inline std::ostream& operator <<(std::ostream& Ostr, const Matrix3<T>& RightVal)
	{
		return Ostr
			<<std::endl<<"Matrix 3x3:"
			<<std::endl<<"("<<RightVal[0][0]<<")\t("<<RightVal[0][1]<<")\t("<<RightVal[0][2]<<")"
			<<std::endl<<"("<<RightVal[1][0]<<")\t("<<RightVal[1][1]<<")\t("<<RightVal[1][2]<<")"
			<<std::endl<<"("<<RightVal[2][0]<<")\t("<<RightVal[2][1]<<")\t("<<RightVal[2][2]<<")"
			<<std::endl
			;
	}

}
