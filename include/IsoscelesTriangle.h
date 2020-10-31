#pragma once
#include "Vertex.h"
#include "Rectangle.h"

class IsoscelesTriangle
{
public:
	IsoscelesTriangle(const Vertex vertices[3]);
	IsoscelesTriangle(
		const Vertex& v0 = Vertex(20,20), 
		const Vertex& v1 = Vertex(30,20), 
		double height = sqrt(75));

	Vertex getVertex(int index) const;
	double getBaseLength() const;
	double getLegLength() const;
	double getHeight() const;

	void draw(Board& board)const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	Vertex vertices[3];
};
