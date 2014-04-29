namespace ege
{
	template<typename T> inline Matrix4<T>::Matrix4<T>()
		:
		r1(Vector4<T>(T(1),T(0),T(0),T(0))),
		r2(Vector4<T>(T(0),T(1),T(0),T(0))),
		r3(Vector4<T>(T(0),T(0),T(1),T(0))),
		r4(Vector4<T>(T(0),T(0),T(0),T(1)))
	{}
	template<typename T> inline Matrix4<T>::Matrix4<T>(const T* fe)
		:
		r1(fe[0],fe[1],fe[2],fe[3]),
		r2(fe[4],fe[5],fe[6],fe[7]),
		r3(fe[8],fe[9],fe[10],fe[11]),
		r4(fe[12],fe[13],fe[14],fe[15])
	{}
	template<typename T> inline Matrix4<T>::Matrix4<T>(const matrix3 mat3)
		:
		r1(mat3[0],T(0)),
		r2(mat3[1],T(0)),
		r3(mat3[2],T(0)),
		r4(T(0),T(0),T(0),T(1))
	{}
	template<typename T> inline Matrix4<T>::Matrix4<T>(
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
	template<typename T> inline Matrix4<T>::Matrix4<T>(
		const T r1c1,const T r1c2,const T r1c3,const T r1c4,
		const T r2c1,const T r2c2,const T r2c3,const T r2c4,
		const T r3c1,const T r3c2,const T r3c3,const T r3c4,
		const T r4c1,const T r4c2,const T r4c3,const T r4c4)
		:
		r1(r1c1,r1c2,r1c3,r1c4),
		r2(r2c1,r2c2,r2c3,r2c4),
		r3(r3c1,r3c2,r3c3,r3c4),
		r4(r4c1,r4c2,r4c3,r4c4)
	{}
	template<typename T> inline Matrix4<T>::~Matrix4<T>()
	{}
	
	template<typename T> inline T* Matrix4<T>::FirstElement() const
	{
		return (T*)&r1.x;
	}
	
	template<typename T> inline const Vector4<T>& Matrix4<T>::operator [](const unsigned int& index) const
	{
		return (&r1)[index];
	}
	template<typename T> inline Vector4<T>& Matrix4<T>::operator [](const unsigned int& index)
	{
		return (&r1)[index];
	}
	
	template<typename T> inline Matrix4<T> operator *(const Matrix4<T>& RM, const Matrix4<T>& LM)
	{
		const T L[4][4] = 
		{
			LM[0][0],
			LM[0][1],
			LM[0][2],
			LM[0][3],
			LM[1][0],
			LM[1][1],
			LM[1][2],
			LM[1][3],
			LM[2][0],
			LM[2][1],
			LM[2][2],
			LM[2][3],
			LM[3][0],
			LM[3][1],
			LM[3][2],
			LM[3][3]
		};
		const T R[4][4] = 
		{
			RM[0][0],
			RM[0][1],
			RM[0][2],
			RM[0][3],
			RM[1][0],
			RM[1][1],
			RM[1][2],
			RM[1][3],
			RM[2][0],
			RM[2][1],
			RM[2][2],
			RM[2][3],
			RM[3][0],
			RM[3][1],
			RM[3][2],
			RM[3][3]
		};


		return Matrix4<T>(
			L[0][0] * R[0][0] + L[1][0] * R[0][1] + L[2][0] * R[0][2] + L[3][0] * R[0][3],
			L[0][1] * R[0][0] + L[1][1] * R[0][1] + L[2][1] * R[0][2] + L[3][1] * R[0][3],
			L[0][2] * R[0][0] + L[1][2] * R[0][1] + L[2][2] * R[0][2] + L[3][2] * R[0][3],
			L[0][3] * R[0][0] + L[1][3] * R[0][1] + L[2][3] * R[0][2] + L[3][3] * R[0][3],
			L[0][0] * R[1][0] + L[1][0] * R[1][1] + L[2][0] * R[1][2] + L[3][0] * R[1][3],
			L[0][1] * R[1][0] + L[1][1] * R[1][1] + L[2][1] * R[1][2] + L[3][1] * R[1][3],
			L[0][2] * R[1][0] + L[1][2] * R[1][1] + L[2][2] * R[1][2] + L[3][2] * R[1][3],
			L[0][3] * R[1][0] + L[1][3] * R[1][1] + L[2][3] * R[1][2] + L[3][3] * R[1][3],
			L[0][0] * R[2][0] + L[1][0] * R[2][1] + L[2][0] * R[2][2] + L[3][0] * R[2][3],
			L[0][1] * R[2][0] + L[1][1] * R[2][1] + L[2][1] * R[2][2] + L[3][1] * R[2][3],
			L[0][2] * R[2][0] + L[1][2] * R[2][1] + L[2][2] * R[2][2] + L[3][2] * R[2][3],
			L[0][3] * R[2][0] + L[1][3] * R[2][1] + L[2][3] * R[2][2] + L[3][3] * R[2][3],
			L[0][0] * R[3][0] + L[1][0] * R[3][1] + L[2][0] * R[3][2] + L[3][0] * R[3][3],
			L[0][1] * R[3][0] + L[1][1] * R[3][1] + L[2][1] * R[3][2] + L[3][1] * R[3][3],
			L[0][2] * R[3][0] + L[1][2] * R[3][1] + L[2][2] * R[3][2] + L[3][2] * R[3][3],
			L[0][3] * R[3][0] + L[1][3] * R[3][1] + L[2][3] * R[3][2] + L[3][3] * R[3][3]
			);
	}
	template<typename T> inline const Matrix4<T> operator *=(Matrix4<T>& LeftVal, const Matrix4<T>& RightVal)
	{
		LeftVal = LeftVal * RightVal;
		return LeftVal;
	}

	
	template<typename T> inline Vector4<T> operator *(const Vector4<T>& RV, const Matrix4<T>& LM)
	{
		const T L[4][4] = 
		{
			LM[0][0],
			LM[0][1],
			LM[0][2],
			LM[0][3],
			LM[1][0],
			LM[1][1],
			LM[1][2],
			LM[1][3],
			LM[2][0],
			LM[2][1],
			LM[2][2],
			LM[2][3],
			LM[3][0],
			LM[3][1],
			LM[3][2],
			LM[3][3]
		};
		const T R[4] = 
		{
			RV[0],
			RV[1],
			RV[2],
			RV[3]
		};

		return Vector4<T>(
			L[0][0] * R[0] + L[0][1] * R[1] + L[0][2] * R[2] + L[0][3] * R[3],
			L[1][0] * R[0] + L[1][1] * R[1] + L[1][2] * R[2] + L[1][3] * R[3],
			L[2][0] * R[0] + L[2][1] * R[1] + L[2][2] * R[2] + L[2][3] * R[3],
			L[3][0] * R[0] + L[3][1] * R[1] + L[3][2] * R[2] + L[3][3] * R[3]
			);
	}
	template<typename T> inline const Vector4<T> operator *=(Vector4<T>& LeftVal, const Matrix4<T>& RightVal)
	{
		LeftVal = LeftVal * RightVal;
		return LeftVal;
	}

}