#include <iostream>
#include <cmath>
#include "EquilateralTriangle.h"
#include "Board.h"
#include "Vertex.h"

Vertex    EquilateralTriangle::getVertex(int index)  const { }
double    EquilateralTriangle::getLength()           const { return Length;            }
Rectangle EquilateralTriangle::getBoundingRectangle()const { return BoundingRectangle; }
double    EquilateralTriangle::getArea()             const { return Area;              }
double    EquilateralTriangle::getPerimeter()        const { return Perimeter;         }
Vertex    EquilateralTriangle::getCenter()           const { return Center;            }
