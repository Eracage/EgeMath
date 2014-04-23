#pragma once
#ifndef VECTOR3_H_EGEMATH
#define VECTOR3_H_EGEMATH

namespace ege
{
	template<typename T>
	class Vector3
	{
	public:
		Vector3();
		Vector3(T X, T Y, T Z);
		Vector3(T Value);
		~Vector3();

		float getLenght();
		
		union
		{
			struct
			{
				float x,y,z;
			};
			struct
			{
				float r,g,b;
			};
		};
			
		const float& operator [](const unsigned int& index) const;
		float& operator [](const unsigned int& index);
	private:

	};

	vector3 operator -(const vector3& RightVal);

	vector3 operator +(const vector3& LeftVal,const vector3& RightVal);
	vector3 operator -(const vector3& LeftVal,const vector3& RightVal);

	const vector3& operator +=(vector3& LeftVal,const vector3& RightVal);
	const vector3& operator -=(vector3& LeftVal,const vector3& RightVal);

	vector3 operator /(const vector3& LeftVal,const float& RightVal);
	const vector3& operator /=(vector3& LeftVal,const float& RightVal);

	bool operator ==(const vector3& LeftVal,const vector3& RightVal);
	bool operator !=(const vector3& LeftVal,const vector3& RightVal);

	vector3 operator *(const vector3& LeftVal, const float& RightVal);
	vector3 operator *(const float& LeftVal, const vector3& RightVal);

	const vector3& operator *=(vector3& LeftVal, const float& RightVal);
}
#endif