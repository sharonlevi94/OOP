#ifndef _Rectangle_H
#define _Rectangle_H
#pragma         once

#include "Vertex.h"
#include  "Board.h"
class     Rectangle
{
private:
	Vertex BottomLeft, TopRight,BottomRight,TopLeft, Center;
	double                   Width, Height, Area, Perimeter;

	void      setBottomLeft (double, double);
	void      setTopRight   (double, double);
	void      setBottomRight(double, double);
	void      setTopLeft    (double, double);
	void      SetCenter     (double, double);

public:
	//Constructors:
	Rectangle (const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle                         (const Vertex vertices[2]);
	Rectangle       (double x0, double y0, double x1, double y2);
	Rectangle(const Vertex& center, double width, double height);

	Vertex    getBottomLeft()        const;
	Vertex    getTopRight()          const;
	double    getWidth()             const;
	double    getHeight()            const;

	Rectangle getBoundingRectangle() const;
	Vertex    getCenter()            const;
	void      draw(Board& board)     const;  
	double    getArea()              const;
	double    getPerimeter()         const;   
	bool      scale        (double factor);
};
#endif // _Rectangle_H
