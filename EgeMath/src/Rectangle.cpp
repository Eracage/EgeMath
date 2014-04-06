#include <cmath>
#include <cassert>
#include <Math.hpp>

namespace ege
{
	rectangle::rectangle(){}
	rectangle::rectangle(float Left, float Top, float Width, float Height)
		: left(Left),
		  top(Top),
		  width(Width),
		  height(Height)
	{
		assert(!(width<0||height<0));
	}
	rectangle::rectangle(Vector2 Position, float Width, float Height)
		: left(Position.x),
		  top(Position.y),
		  width(Width),
		  height(Height)
	{
		assert(!(width<0||height<0));
	}
	rectangle::rectangle(Vector2 Position, Vector2 Size)
		: left(Position.x),
		  top(Position.y),
		  width(Size.x),
		  height(Size.y)
	{
		assert(!(width<0||height<0));
	}

	rectangle::~rectangle()
	{}
	
	float rectangle::getRight() const
	{
		return left + width;
	}
	float rectangle::getBottom() const
	{
		return top + height;
	}
	
	bool rectangle::Intersects(rectangle otherRectangle) const
	{
		if (otherRectangle.getRight() < left)
			return false;
		if (getRight() < otherRectangle.left)
			return false;
		if (otherRectangle.getBottom() < top)
			return false;
		if (getBottom() < otherRectangle.top)
			return false;
		return true;
	}
	bool rectangle::Contains(Vector2 Position) const
	{
		return Intersects(rectangle(Position,0,0));
	}
}