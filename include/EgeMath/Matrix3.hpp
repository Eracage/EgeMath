#pragma once
#ifndef MATRIX3_H_EGEMATH
#define MATRIX3_H_EGEMATH

#include <EgeMath/Vector3.hpp>


namespace ege
{
	class matrix3
	{
	public:
		/**
		Creates Identity Matrix
		*/
		matrix3()
			:
			r1(vector3(1.f,0.f,0.f)),
			r2(vector3(0.f,1.f,0.f)),
			r3(vector3(0.f,0.f,1.f))
		{}
		matrix3(const float* FirstElement)
			:
			r1(FirstElement[0],FirstElement[1],FirstElement[2]),
			r2(FirstElement[3],FirstElement[4],FirstElement[5]),
			r3(FirstElement[6],FirstElement[7],FirstElement[8])
		{}
		matrix3(
			const vector3& Row1,
			const vector3& Row2,
			const vector3& Row3)
			: 
			r1(Row1),
			r2(Row2),
			r3(Row3)
		{}
		matrix3(
			const float r1c1,const float r1c2,const float r1c3,
			const float r2c1,const float r2c2,const float r2c3,
			const float r3c1,const float r3c2,const float r3c3)
			:
			r1(r1c1,r1c2,r1c3),
			r2(r2c1,r2c2,r2c3),
			r3(r3c1,r3c2,r3c3)
		{}

		float* FirstElement()
		{
			return (float*)&r1.x;
		}

		const vector3& operator [](const unsigned int& index) const
		{
			return (&r1)[index];
		}
		vector3& operator [](const unsigned int& index)
		{
			return (&r1)[index];
		}

	private:
		vector3 r1,r2,r3;

	};

	matrix3 operator *(const matrix3& LeftVal, const matrix3& RightVal);
	const matrix3 operator *=(matrix3& LeftVal, const matrix3& RightVal);
	
	vector3 operator *(const vector3& LeftVal, const matrix3& RightVal);
	const vector3 operator *=(vector3& LeftVal, const matrix3& RightVal);
}

#endif