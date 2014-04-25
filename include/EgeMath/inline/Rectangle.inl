#include <cassert>

namespace ege
{
	template<typename T> inline Rectangle<T>::Rectangle()
		: left(T()), top(T()), width(T()), height(T())
	{}
	template<typename T> inline Rectangle<T>::Rectangle(const T Left, const T Top, const T Width, const T Height)
		: left(Left), top(Top), width(Width), height(Height)
	{}
	template<typename T> inline Rectangle<T>::Rectangle(const Vector2<T>& Position, const T Width, const T Height)
		: left(Position.x), top(Position.y), width(Width), height(Height)
	{}
	template<typename T> inline Rectangle<T>::Rectangle(const Vector2<T>& Position, const Vector2<T>& Size)
		: left(Position.x), top(Position.y), width(Size.x), top(Size.y)
	{}
	template<typename T> inline Rectangle<T>::Rectangle(const Rectangle<T>& rectangle)
		: left(rectangle.left), top(rectangle.top), width(rectangle.width), height(rectangle.height)
	{}
	template<typename T> inline Rectangle<T>::~Rectangle()
	{}

	template<typename T> inline T Rectangle<T>::getRight() const
	{
		return left + width;
	}
	template<typename T> inline T Rectangle<T>::getBottom() const
	{
		return top + height;
	}

	template<typename T> inline bool Rectangle<T>::Intersects(const Rectangle<T>& otherRectangle) const
	{
		return !
			(otherRectangle.getRight() < left &&
			getRight() < otherRectangle.left &&
			otherRectangle.getBottom() > top &&
			getBottom() > otherRectangle.top);
	}
	template<typename T> inline bool Rectangle<T>::Contains(const Vector2<T>& Position) const
	{
		return Intersects(Rectangle(Position,0,0));
	}
	template<typename T> inline bool Rectangle<T>::Contains(const Rectangle<T>& otherRectangle) const
	{
		return 
			(otherRectangle.getRight() < getRight() &&
			left < otherRectangle.left &&
			otherRectangle.top < top &&
			getBottom() < otherRectangle.getBottom());
	}
}