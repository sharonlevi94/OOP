#pragma once
#include "Vertex.h"
#include "IsoscelesTriangle.h"

class EquilateralTriangle
{
public:
	EquilateralTriangle();
	EquilateralTriangle(Vertex vertices[3]);
	
	Vertex getVertex(int index) const;
	double getLength();

	void draw(Board& board)const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	IsoscelesTriangle triangle;
};
#endif //_EquilateralTriangle_H
