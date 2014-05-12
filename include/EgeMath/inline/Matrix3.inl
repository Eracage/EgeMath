#include <EgeMath/Matrix3.hpp>


namespace ege
{
		Matrix3 operator *(const Matrix3& LM, const Matrix3& RM)
		{
			const float L[3][3] = 
			{
				LM[0][0],
				LM[0][1],
				LM[0][2],
				LM[1][0],
				LM[1][1],
				LM[1][2],
				LM[2][0],
				LM[2][1],
				LM[2][2]
			};
			const float R[3][3] = 
			{
				RM[0][0],
				RM[0][1],
				RM[0][2],
				RM[1][0],
				RM[1][1],
				RM[1][2],
				RM[2][0],
				RM[2][1],
				RM[2][2]
			};


			return Matrix3(
				L[0][0] * R[0][0] + L[1][0] * R[0][1] + L[2][0] * R[0][2],
				L[0][1] * R[0][0] + L[1][1] * R[0][1] + L[2][1] * R[0][2],
				L[0][2] * R[0][0] + L[1][2] * R[0][1] + L[2][2] * R[0][2],
				L[0][0] * R[1][0] + L[1][0] * R[1][1] + L[2][0] * R[1][2],
				L[0][1] * R[1][0] + L[1][1] * R[1][1] + L[2][1] * R[1][2],
				L[0][2] * R[1][0] + L[1][2] * R[1][1] + L[2][2] * R[1][2],
				L[0][0] * R[2][0] + L[1][0] * R[2][1] + L[2][0] * R[2][2],
				L[0][1] * R[2][0] + L[1][1] * R[2][1] + L[2][1] * R[2][2],
				L[0][2] * R[2][0] + L[1][2] * R[2][1] + L[2][2] * R[2][2]
				);
		}
		const Matrix3 operator *=(Matrix3& LeftVal, const Matrix3& RightVal)
		{
			LeftVal = LeftVal * RightVal;
			return LeftVal;
		}
	
		vector3 operator *(const vector3& RV, const Matrix3& LM)
		{
			const float L[3][3] = 
			{
				LM[0][0],
				LM[0][1],
				LM[0][2],
				LM[1][0],
				LM[1][1],
				LM[1][2],
				LM[2][0],
				LM[2][1],
				LM[2][2]
			};
			const float R[4] = 
			{
				RV[0],
				RV[1],
				RV[2]
			};

			return vector3(
				L[0][0] * R[0] + L[0][1] * R[1] + L[0][2] * R[2],
				L[1][0] * R[0] + L[1][1] * R[1] + L[1][2] * R[2],
				L[2][0] * R[0] + L[2][1] * R[1] + L[2][2] * R[2]
				);
		}
		const vector3 operator *=(vector3& LeftVal, const Matrix3& RightVal)
		{
			LeftVal = LeftVal * RightVal;
			return LeftVal;
		}
}