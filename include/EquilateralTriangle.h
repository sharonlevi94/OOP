#ifndef _EquilateralTriangle_H
#define _EquilateralTriangle_H
#pragma once
#include "Board.h"
#include "Vertex.h"
#include "Rectangle.h"
class EquilateralTriangle
{
private:
	Vertex Top, BottomLeft, BottomRight;
	double Area, Center, Perimeter,Length;
	Rectangle BoundingRectangle;

	void setTop();
	void setBottomLeft();
	void SetBottomRight();
	void setArea();
	void setCenter();
	void setBoundingRectangle();
public:
	EquilateralTriangle(const Vertex vertices[3]); //c'tor
	void draw(Board& board)const; 
	bool scale(double factor);

	Vertex    getVertex(int index)  const;
	double    getLength()           const;         //return the length of one line
	Rectangle getBoundingRectangle()const;
	double    getArea()             const;
	double    getPerimeter()        const;
	Vertex    getCenter()           const;
};
#endif //_EquilateralTriangle_H
