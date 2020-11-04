#pragma once
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
class Window
{
private:
	Rectangle Outer, Inner;
public:
	Window(const Rectangle& outer, const Rectangle& inner);
	Window(const Rectangle& outer, double verticalThickness, double horizontalThickness);
	
	Vertex getBottomLeft() const;
	Vertex getTopRight()const;

	double getVerticalThickness()const;
	double getHorizontalThickness() const;

	void draw(Board& board)const;
	Rectangle getBoundingRectangle() const;
	double getArea()const;
	double getPerimeter()const;
	Vertex getCenter()const;
	bool scale(double factor);
};

