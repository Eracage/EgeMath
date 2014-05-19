#pragma once
#ifndef UTILS_H_EGEMATH
#define UTILS_H_EGEMATH

#include <cmath>

namespace ege
{
	const float PI = 3.14159265358979323846264f;

	const double ACCEPTABLE_TOLERANCE = 0.0001;
	template<typename T> 
	bool equals(const T A, const T B, const T Tolerance = T(ACCEPTABLE_TOLERANCE))
	{
		return static_cast<T>(std::abs(A - B)) <= Tolerance;
	}
}

#endif