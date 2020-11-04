#include "Board.h"
#include "Vertex.h"
#include "Window.h"
#include "Rectangle.h"
//---------------------------Constructors------------------------------------
Window::Window(const Rectangle& outer, const Rectangle& inner) 
	:Outer(outer),Inner(inner)
{
	if (!(outer.getCenter().isEqual(inner.getCenter())            &&
		outer.getTopRight().isHigherThan(inner.getTopRight())     &&
		outer.getTopRight().isToTheRightOf(inner.getTopRight())   &&
		inner.getBottomLeft().isHigherThan(outer.getBottomLeft()) &&
		inner.getBottomLeft().isToTheRightOf(outer.getBottomLeft())))
	{
		this->Inner = Rectangle(Vertex(20, 10), Vertex(30, 20));
		this->Outer = Rectangle(Vertex(20, 10), Vertex(30, 20));
	}
	this->Inner = Rectangle(inner.getBottomLeft(),inner.getTopRight());
	this->Outer = Rectangle(outer.getBottomLeft(), outer.getTopRight());
}
//---------------------------
Window::Window(const Rectangle& outer, double verticalThickness, double horizontalThickness)
	: Outer(outer), Inner(outer)
{
 //missed
}
//--------------------------Other  Functions-----------------------------------
Vertex Window::getBottomLeft()           const  
{ return Outer.getBottomLeft(); }
//----------------------------------------------------------------------------
Vertex Window::getTopRight()             const  
{ return Outer.getTopRight();   }
//----------------------------------------------------------------------------
double Window::getVerticalThickness()    const 
{ return Outer.getTopRight().m_row - Inner.getTopRight().m_row; }
//----------------------------------------------------------------------------
double Window::getHorizontalThickness()  const 
{ return Outer.getTopRight().m_col - Inner.getTopRight().m_col; }
//----------------------------------------------------------------------------
Rectangle Window::getBoundingRectangle() const
{ return Outer.getBoundingRectangle(); }
//----------------------------------------------------------------------------
double Window::getArea()                 const 
{ return Outer.getArea() - Inner.getArea(); }
//----------------------------------------------------------------------------
double Window::getPerimeter()            const 
{ return Inner.getPerimeter() + Outer.getPerimeter(); }
//----------------------------------------------------------------------------
Vertex Window::getCenter()               const 
{ return Inner.getCenter(); }
//----------------------------------------------------------------------------
bool Window::scale(double factor) 
{
	if (Inner.scale(factor) && Outer.scale(factor))
		return true;
	return false;
}
//----------------------------------------------------------------------------
void Window::draw(Board& board)const
{
	Inner.draw(board);
	Outer.draw(board);
}





