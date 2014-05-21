namespace ege
{
	template<typename T> const Matrix4<T> Matrix4<T>::Identity = Matrix4<T>();

	template<typename T> inline Matrix4<T>::Matrix4()
		:
		r1(T(1),T(0),T(0),T(0)),
		r2(T(0),T(1),T(0),T(0)),
		r3(T(0),T(0),T(1),T(0)),
		r4(T(0),T(0),T(0),T(1))
	{}
	template<typename T> inline Matrix4<T>::Matrix4(const Matrix2<T>& mat2)
		:
		r1(mat2[0],T(0),T(0)),
		r2(mat2[1],T(0),T(0)),
		r3(T(0),T(0),T(1),T(0)),
		r4(T(0),T(0),T(0),T(1))
	{}
	template<typename T> inline Matrix4<T>::Matrix4(const Matrix3<T>& mat3)
		:
		r1(mat3[0],T(0)),
		r2(mat3[1],T(0)),
		r3(mat3[2],T(0)),
		r4(T(0),T(0),T(0),T(1))
	{}
	template<typename T> inline Matrix4<T>::Matrix4(const Matrix4<T>& mat4)
		: r1(mat4[0]),
		r2(mat4[1]),
		r3(mat4[2]),
		r3(mat4[3])
	{}
	template<typename T>
	template<typename T2> inline Matrix4<T>::Matrix4(const Matrix4<T2>& mat4)
		: r1(mat4[0]),
		r2(mat4[1]),
		r3(mat4[2]),
		r4(mat4[3])
	{}
	template<typename T> inline Matrix4<T>::Matrix4(
		const Vector4<T>& Row1,
		const Vector4<T>& Row2,
		const Vector4<T>& Row3,
		const Vector4<T>& Row4)
		: 
		r1(Row1),
		r2(Row2),
		r3(Row3),
		r4(Row4)
	{}
	template<typename T> inline Matrix4<T>::Matrix4(
		const T& r1c1,const T& r1c2,const T& r1c3,const T& r1c4,
		const T& r2c1,const T& r2c2,const T& r2c3,const T& r2c4,
		const T& r3c1,const T& r3c2,const T& r3c3,const T& r3c4,
		const T& r4c1,const T& r4c2,const T& r4c3,const T& r4c4)
		:
		r1(r1c1,r1c2,r1c3,r1c4),
		r2(r2c1,r2c2,r2c3,r2c4),
		r3(r3c1,r3c2,r3c3,r3c4),
		r4(r4c1,r4c2,r4c3,r4c4)
	{}
	template<typename T> inline Matrix4<T>::~Matrix4()
	{}
	
	template<typename T> inline Matrix3<T> Matrix4<T>::subMatrix3(const unsigned int RowToRemove = 3, const unsigned int ColumnToRemove = 3) const
	{
		assert(RowToRemove < ROWS && ColumnToRemove < COLUMNS);
		Matrix3<T> retVal;

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

	template<typename T> inline T Matrix4<T>::determinant() const
	{
		return (
			r1[0]*(subMatrix3(0,0).determinant()) -
			r1[1]*(subMatrix3(0,1).determinant()) +
			r1[2]*(subMatrix3(0,2).determinant()) -
			r1[3]*(subMatrix3(0,3).determinant())
			);
	}

	template<typename T> inline Matrix4<T>& Matrix4<T>::Transpose()
	{
		return (*this) = transposed();
	}
	template<typename T> inline Matrix4<T> Matrix4<T>::transposed() const
	{
		return Matrix4<T>(
			(*this)[0][0], (*this)[1][0], (*this)[2][0], (*this)[3][0],
			(*this)[0][1], (*this)[1][1], (*this)[2][1], (*this)[3][1],
			(*this)[0][2], (*this)[1][2], (*this)[2][2], (*this)[3][2],
			(*this)[0][3], (*this)[1][3], (*this)[2][3], (*this)[3][3]
		);
	}

	template<typename T> inline Matrix4<T> Matrix4<T>::cofactor() const
	{
		return Matrix4<T>(
			subMatrix3(0,0).determinant(),
			-subMatrix3(0,1).determinant(),
			subMatrix3(0,2).determinant(),
			-subMatrix3(0,3).determinant(),
			-subMatrix3(1,0).determinant(),
			subMatrix3(1,1).determinant(),
			-subMatrix3(1,2).determinant(),
			subMatrix3(1,3).determinant(),
			subMatrix3(2,0).determinant(),
			-subMatrix3(2,1).determinant(),
			subMatrix3(2,2).determinant(),
			-subMatrix3(2,3).determinant(),
			-subMatrix3(3,0).determinant(),
			subMatrix3(3,1).determinant(),
			-subMatrix3(3,2).determinant(),
			subMatrix3(3,3).determinant()
			);
	}

	template<typename T> inline Matrix4<T>& Matrix4<T>::Inverse()
	{
		return (*this) = inversed();
	}
	template<typename T> inline Matrix4<T> Matrix4<T>::inversed() const
	{
		T det = determinant();
		Matrix4<T> cof = cofactor();
		Matrix4<T> adj = cof.transposed();
		float Idet = 1.f/det;
		assert(determinant() != 0);
		return (1.f/determinant()) * cofactor().transposed();
	}

	template<typename T> inline T* Matrix4<T>::ptr() const
	{
		return (T*)&r1.x;
	}

	template<typename T> inline const Vector4<T>& Matrix4<T>::operator [](const unsigned int& index) const
	{
		assert(index < ROWS);
		return (&r1)[index];
	}
	template<typename T> inline Vector4<T>& Matrix4<T>::operator [](const unsigned int& index)
	{
		assert(index < ROWS);
		return (&r1)[index];
	}

	template<typename T> inline bool Matrix4<T>::operator ==(const Matrix4<T>& RightVal) const
	{
		return (
			(*this)[0] == RightVal[0] &&
			(*this)[1] == RightVal[1] &&
			(*this)[2] == RightVal[2] &&
			(*this)[3] == RightVal[3]
		);
	}
	template<typename T> inline bool Matrix4<T>::operator !=(const Matrix4<T>& RightVal) const
	{
		return !(*this == RightVal);
	}

	template<typename T> inline Matrix4<T>& Matrix4<T>::operator =(const Matrix4<T>& RightVal)
	{
		(*this)[0] = RightVal[0];
		(*this)[1] = RightVal[1];
		(*this)[2] = RightVal[2];
		(*this)[3] = RightVal[3];
		return (*this);
	}

	template<typename T> inline Matrix4<T>& Matrix4<T>::operator +=(const Matrix4<T>& RightVal)
	{
		(*this)[0] += RightVal[0];
		(*this)[1] += RightVal[1];
		(*this)[2] += RightVal[2];
		(*this)[3] += RightVal[3];
		return (*this);
	}
	template<typename T> inline Matrix4<T>& Matrix4<T>::operator -=(const Matrix4<T>& RightVal)
	{
		(*this)[0] -= RightVal[0];
		(*this)[1] -= RightVal[1];
		(*this)[2] -= RightVal[2];
		(*this)[3] -= RightVal[3];
		return (*this);
	}

	template<typename T> inline Matrix4<T>& Matrix4<T>::operator /=(const T& RightVal)
	{
		(*this)[0] /= RightVal;
		(*this)[1] /= RightVal;
		(*this)[2] /= RightVal;
		(*this)[3] /= RightVal;
	}
	template<typename T> inline Matrix4<T>& Matrix4<T>::operator *=(const T& RightVal)
	{
		(*this)[0] *= RightVal;
		(*this)[1] *= RightVal;
		(*this)[2] *= RightVal;
		(*this)[3] *= RightVal;
	}

	template<typename T> inline Matrix4<T> Matrix4<T>::operator +(const Matrix4<T>& RightVal) const
	{
		return Matrix4<T>(
		(*this)[0] + RightVal[0],
		(*this)[1] + RightVal[1],
		(*this)[2] + RightVal[2],
		(*this)[3] + RightVal[3]
		);
	}
	template<typename T> inline Matrix4<T> Matrix4<T>::operator -(const Matrix4<T>& RightVal) const
	{
		return Matrix4<T>(
		(*this)[0] - RightVal[0],
		(*this)[1] - RightVal[1],
		(*this)[2] - RightVal[2],
		(*this)[3] - RightVal[3]
		);
	}

	template<typename T> inline Matrix4<T> Matrix4<T>::operator /(const T& RightVal) const
	{
		return Matrix4<T>(
		r1 / RightVal,
		r2 / RightVal,
		r3 / RightVal,
		r4 / RightVal
		);}
	template<typename T> inline Matrix4<T> Matrix4<T>::operator *(const T& RightVal) const
	{
		return Matrix4<T>(
		r1 * RightVal,
		r2 * RightVal,
		r3 * RightVal,
		r4 * RightVal
		);
	}
	
	template<typename T> inline Vector2<T> Matrix4<T>::operator *(const Vector2<T>& RightVal) const
	{
		const T L[ROWS-2][COLUMNS-1] = 
		{
			(*this)[0][0],
			(*this)[0][1],
			(*this)[0][3],
			(*this)[1][0],
			(*this)[1][1],
			(*this)[1][3]
		};
		const T R[COLUMNS-1] = 
		{
			RightVal[0],
			RightVal[1],
			T(1)
		};

		return Vector2<T>(
			L[0][0] * R[0] + L[0][1] * R[1] + L[0][2] * R[2],
			L[1][0] * R[0] + L[1][1] * R[1] + L[1][2] * R[2]
			);
	}
	template<typename T> inline Vector3<T> Matrix4<T>::operator *(const Vector3<T>& RightVal) const
	{
		const T L[ROWS-1][COLUMNS] = 
		{
			(*this)[0][0],
			(*this)[0][1],
			(*this)[0][2],
			(*this)[0][3],
			(*this)[1][0],
			(*this)[1][1],
			(*this)[1][2],
			(*this)[1][3],
			(*this)[2][0],
			(*this)[2][1],
			(*this)[2][2],
			(*this)[2][3]
		};
		const T R[COLUMNS] = 
		{
			RightVal[0],
			RightVal[1],
			RightVal[2],
			T(1)
		};

		return Vector3<T>(
			L[0][0] * R[0] + L[0][1] * R[1] + L[0][2] * R[2] + L[0][3] * R[3],
			L[1][0] * R[0] + L[1][1] * R[1] + L[1][2] * R[2] + L[1][3] * R[3],
			L[2][0] * R[0] + L[2][1] * R[1] + L[2][2] * R[2] + L[2][3] * R[3]
			);
	}
	template<typename T> inline Vector4<T> Matrix4<T>::operator *(const Vector4<T>& RightVal) const
	{
		const T L[ROWS][COLUMNS] = 
		{
			(*this)[0][0],
			(*this)[0][1],
			(*this)[0][2],
			(*this)[0][3],
			(*this)[1][0],
			(*this)[1][1],
			(*this)[1][2],
			(*this)[1][3],
			(*this)[2][0],
			(*this)[2][1],
			(*this)[2][2],
			(*this)[2][3],
			(*this)[3][0],
			(*this)[3][1],
			(*this)[3][2],
			(*this)[3][3]
		};
		const T R[COLUMNS] = 
		{
			RightVal[0],
			RightVal[1],
			RightVal[2],
			RightVal[3]
		};

		return Vector4<T>(
			L[0][0] * R[0] + L[0][1] * R[1] + L[0][2] * R[2] + L[0][3] * R[3],
			L[1][0] * R[0] + L[1][1] * R[1] + L[1][2] * R[2] + L[1][3] * R[3],
			L[2][0] * R[0] + L[2][1] * R[1] + L[2][2] * R[2] + L[2][3] * R[3],
			L[3][0] * R[0] + L[3][1] * R[1] + L[3][2] * R[2] + L[3][3] * R[3]
			);
	}

	template<typename T> inline Matrix4<T> Matrix4<T>::operator *(const Matrix4<T>& RightVal) const
	{
		const T L[ROWS][COLUMNS] = 
		{
			(*this)[0][0],
			(*this)[0][1],
			(*this)[0][2],
			(*this)[0][3],
			(*this)[1][0],
			(*this)[1][1],
			(*this)[1][2],
			(*this)[1][3],
			(*this)[2][0],
			(*this)[2][1],
			(*this)[2][2],
			(*this)[2][3],
			(*this)[3][0],
			(*this)[3][1],
			(*this)[3][2],
			(*this)[3][3]
		};
		const T R[ROWS][COLUMNS] = 
		{
			RightVal[0][0],
			RightVal[0][1],
			RightVal[0][2],
			RightVal[0][3],
			RightVal[1][0],
			RightVal[1][1],
			RightVal[1][2],
			RightVal[1][3],
			RightVal[2][0],
			RightVal[2][1],
			RightVal[2][2],
			RightVal[2][3],
			RightVal[3][0],
			RightVal[3][1],
			RightVal[3][2],
			RightVal[3][3]
		};


		return Matrix4<T>(
			L[0][0] * R[0][0] + L[0][1] * R[1][0] + L[0][2] * R[2][0] + L[0][3] * R[3][0],
			L[0][0] * R[0][1] + L[0][1] * R[1][1] + L[0][2] * R[2][1] + L[0][3] * R[3][1],
			L[0][0] * R[0][2] + L[0][1] * R[1][2] + L[0][2] * R[2][2] + L[0][3] * R[3][2],
			L[0][0] * R[0][3] + L[0][1] * R[1][3] + L[0][2] * R[2][3] + L[0][3] * R[3][3],
			L[1][0] * R[0][0] + L[1][1] * R[1][0] + L[1][2] * R[2][0] + L[1][3] * R[3][0],
			L[1][0] * R[0][1] + L[1][1] * R[1][1] + L[1][2] * R[2][1] + L[1][3] * R[3][1],
			L[1][0] * R[0][2] + L[1][1] * R[1][2] + L[1][2] * R[2][2] + L[1][3] * R[3][2],
			L[1][0] * R[0][3] + L[1][1] * R[1][3] + L[1][2] * R[2][3] + L[1][3] * R[3][3],
			L[2][0] * R[0][0] + L[2][1] * R[1][0] + L[2][2] * R[2][0] + L[2][3] * R[3][0],
			L[2][0] * R[0][1] + L[2][1] * R[1][1] + L[2][2] * R[2][1] + L[2][3] * R[3][1],
			L[2][0] * R[0][2] + L[2][1] * R[1][2] + L[2][2] * R[2][2] + L[2][3] * R[3][2],
			L[2][0] * R[0][3] + L[2][1] * R[1][3] + L[2][2] * R[2][3] + L[2][3] * R[3][3],
			L[3][0] * R[0][0] + L[3][1] * R[1][0] + L[3][2] * R[2][0] + L[3][3] * R[3][0],
			L[3][0] * R[0][1] + L[3][1] * R[1][1] + L[3][2] * R[2][1] + L[3][3] * R[3][1],
			L[3][0] * R[0][2] + L[3][1] * R[1][2] + L[3][2] * R[2][2] + L[3][3] * R[3][2],
			L[3][0] * R[0][3] + L[3][1] * R[1][3] + L[3][2] * R[2][3] + L[3][3] * R[3][3]
			);
	}
	
	
	template<typename T> inline Matrix4<T> operator *(const T& LeftVal, const Matrix4<T>& RightVal)
	{
		return RightVal * LeftVal;
	}
	
	template<typename T> inline Vector2<T>& operator *=(Vector2<T>& LeftVal, const Matrix4<T>& RightVal)
	{
		return LeftVal = RightVal * LeftVal;
	}
	template<typename T> inline Vector3<T>& operator *=(Vector3<T>& LeftVal, const Matrix4<T>& RightVal)
	{
		return LeftVal = RightVal * LeftVal;
	}
	template<typename T> inline Vector4<T>& operator *=(Vector4<T>& LeftVal, const Matrix4<T>& RightVal)
	{
		return LeftVal = RightVal * LeftVal;
	}

	template<typename T> inline std::ostream& operator <<(std::ostream& Ostr, const Matrix4<T>& RightVal)
	{
		return Ostr
			<<std::endl<<"Matrix 4x4:"
			<<std::endl<<"("<<RightVal[0][0]<<")\t\t("<<RightVal[0][1]<<")\t\t("<<RightVal[0][2]<<")\t\t("<<RightVal[0][3]<<")"
			<<std::endl<<"("<<RightVal[1][0]<<")\t\t("<<RightVal[1][1]<<")\t\t("<<RightVal[1][2]<<")\t\t("<<RightVal[1][3]<<")"
			<<std::endl<<"("<<RightVal[2][0]<<")\t\t("<<RightVal[2][1]<<")\t\t("<<RightVal[2][2]<<")\t\t("<<RightVal[2][3]<<")"
			<<std::endl<<"("<<RightVal[3][0]<<")\t\t("<<RightVal[3][1]<<")\t\t("<<RightVal[3][2]<<")\t\t("<<RightVal[3][3]<<")"
			<<std::endl
			;
	}
}