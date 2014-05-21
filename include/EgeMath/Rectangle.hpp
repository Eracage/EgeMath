#pragma once
#ifndef RECTANGLE_H_EGEMATH
#define RECTANGLE_H_EGEMATH

#include "Vector2.hpp"

namespace ege
{
	template<typename T>
	class Rectangle
	{
	public:
		Rectangle();
		Rectangle(const T Left, const T Top, const T Width, const T Height);
		Rectangle(const Vector2<T>& Position, const T Width, const T Height);
		Rectangle(const Vector2<T>& Position, const Vector2<T>& Size);
		Rectangle(const Rectangle<T>& rectangle);
		~Rectangle();
		
		union{T left, x;};
		union{T top, y;};
		union{T width;};
		union{T height;};

		T getRight() const;
		T getBottom() const;

		bool Intersects(const Rectangle<T>& otherRectangle) const;
		bool Contains(const Vector2<T>& Position) const;
		bool Contains(const Rectangle<T>& otherRectangle) const;

	};
}
#include "inline/Rectangle.inl"
#endif