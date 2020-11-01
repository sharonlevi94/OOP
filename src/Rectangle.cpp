#include <iostream>
#include <cmath>
#include "Rectangle.h"
#include "Board.h"
#include "Vertex.h"

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
{
	if (bottomLeft.isValid()                &&
		topRight.  isValid()                &&
		topRight.  isHigherThan(bottomLeft) &&
		topRight.  isToTheRightOf(bottomLeft))
	{
		this->BottomLeft.m_col = bottomLeft.m_col;
		this->BottomLeft.m_row = bottomLeft.m_row;
		this->TopRight.m_col =     topRight.m_col;
		this->TopRight.m_row =     topRight.m_row;
	}
	else
	{
		setBottomLeft(20,10);
		setTopRight(30, 20);
	}
	setBottomRight (TopRight.m_col,BottomLeft.m_row);
	setTopLeft    (BottomLeft.m_col, TopRight.m_row);
	SetCenter((BottomLeft.m_col+BottomRight.m_col)/2,
		         (TopLeft.m_row+BottomLeft.m_row)/2);
	Area = (TopLeft.m_row - BottomLeft.m_row) *
		   (BottomRight.m_col-BottomLeft.m_col);
	Perimeter = ((TopLeft.m_row - BottomLeft.m_row)*2)+
		        ((BottomRight.m_col - BottomLeft.m_col)*2);
	Height = TopLeft.m_row - BottomLeft.m_row;
	Width = BottomRight.m_col - BottomLeft.m_col;
}
//Rectangle::Rectangle(const Vertex vertices[2])
	//: Rectangle (vertices[0],vertices[1]) {}
//Rectangle::Rectangle(const double x0,const double y0,const double x1,const double y1)
	//: Rectangle(setBottomLeft(x0, y0), setTopRight(x1, y1)){}
//Rectangle::Rectangle(const Vertex& center,const double width,const double height)
	//: Rectangle(center.m_col - (width\2), center.m_row - (height\2),
	  //center.m_col + (width\2), center.m_row + (height\2)) {}

Vertex    Rectangle::getBottomLeft()        const { return BottomLeft; }
Vertex    Rectangle::getTopRight()          const { return TopRight;   }
Vertex    Rectangle::getCenter()            const { return Center;     }
double    Rectangle::getWidth()             const { return Width;      }
double    Rectangle::getHeight()            const { return Height;     }
double    Rectangle::getArea()              const { return Area;       }
double    Rectangle::getPerimeter()         const { return Perimeter;  }

void      Rectangle::draw(Board& board)     const 
{
	board.drawLine(TopLeft,TopRight);
	board.drawLine(TopLeft, BottomLeft);
	board.drawLine(BottomLeft, BottomRight);
	board.drawLine(TopRight, BottomRight);
}
Rectangle Rectangle::getBoundingRectangle() const 
{
	Rectangle BoundRec(this->BottomLeft, this->TopRight);
	return BoundRec;
}
/*
*we have to do the following actions each vertex:
1.we need the center
2.sub the center from each vertex
3.mul every coordinate by factor
4.add the center to every vertex.
*/
bool Rectangle::scale(double factor)         
{
	if (factor <= 0)
		return false;
	Rectangle New(this->BottomLeft,this->TopRight);
	//sub the center from each vertex:
	New.setBottomLeft(BottomLeft.m_col - Center.m_col, BottomLeft.m_row - Center.m_row);
	New.setTopRight(TopRight.m_col - Center.m_col, TopRight.m_row - Center.m_row);
	//mul every coordinate by factor:
	New.BottomLeft.m_col *= factor;
	New.BottomLeft.m_row *= factor;
	New.TopRight.m_col *= factor;
	New.TopRight.m_row *= factor;
	//add the center to every coordinate:
	New.setBottomLeft(BottomLeft.m_col + Center.m_col, BottomLeft.m_row + Center.m_row);
	New.setTopRight(TopRight.m_col + Center.m_col, TopRight.m_row + Center.m_row);
	//check valid:
	if (!New.BottomLeft.isValid() || !New.TopRight.isValid())
		return false;
	//update shape members:
	this->setBottomLeft(New.BottomLeft.m_col, New.BottomLeft.m_row);
	this->setTopRight(New.TopRight.m_col, New.TopRight.m_row);
	this->setBottomRight(this->TopRight.m_col,this->BottomLeft.m_row);
	this->setTopLeft(this->BottomLeft.m_col, this->TopRight.m_row);
	Area = (TopLeft.m_row - BottomLeft.m_row) *
		(BottomRight.m_col - BottomLeft.m_col);
	Perimeter = ((TopLeft.m_row - BottomLeft.m_row) * 2) +
		((BottomRight.m_col - BottomLeft.m_col) * 2);
	Height = TopLeft.m_row - BottomLeft.m_row;
	Width = BottomRight.m_col - BottomLeft.m_col;
	return true;
}

void Rectangle::setBottomLeft  (double x, double y)
{
	BottomLeft.m_col = x;
	BottomLeft.m_row = y;
}
void Rectangle::setTopRight    (double x, double y)
{
	TopRight.m_col = x;
	TopRight.m_row = y;
}
void Rectangle::setBottomRight (double x, double y)
{
	BottomRight.m_col = x;
	BottomRight.m_row = y;
}
void Rectangle::setTopLeft     (double x, double y)
{
	TopLeft.m_col = x;
	TopLeft.m_row = y;
}
void Rectangle::SetCenter      (double x, double y)
{
	Center.m_col = x;
	Center.m_row = y;
}
