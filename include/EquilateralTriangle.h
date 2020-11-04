#pragma once
#include "Vertex.h"
#include "IsoscelesTriangle.h"
#include "Rectangle.h"

class EquilateralTriangle
{
public:
	EquilateralTriangle(const Vertex vertices[3]);

	Vertex getVertex(int index) const;
	double getLength()const;

	void draw(Board& board)const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	IsoscelesTriangle triangle;
};
