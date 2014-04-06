#pragma once
#ifndef RECTANGLE_H_EGEMATH
#define RECTANGLE_H_EGEMATH

#include "Vector2.hpp"

namespace ege
{
	class rectangle
	{
	public:
		rectangle();
		rectangle(float Left, float Top, float Width, float Height);
		rectangle(Vector2 Position, float Width, float Height);
		rectangle(Vector2 Position, Vector2 Size);

		~rectangle();

		union
		{
			struct 
			{
				float left, top, width, height;
			};
			struct
			{
				float x, y;
			};
		};

		float getRight() const;
		float getBottom() const;

		bool Intersects(rectangle otherRectangle) const;
		bool Contains(Vector2 Position) const;
	private:

	};
}
#endif