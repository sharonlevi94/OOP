#include "EquilateralTriangle.h"
//----------------------------------------------------------------------------
EquilateralTriangle::EquilateralTriangle() {
	this->triangle = IsoscelesTriangle();
}
//----------------------------------------------------------------------------
EquilateralTriangle::EquilateralTriangle(Vertex vertices[3])
{
	this->triangle = IsoscelesTriangle(vertices);
}
//----------------------------------------------------------------------------
Vertex EquilateralTriangle::getVertex(int index) const {
	return(this->triangle.getVertex(index));
}
//----------------------------------------------------------------------------
double EquilateralTriangle::getLength() {
	return(this->triangle.getLegLength());
}
//----------------------------------------------------------------------------
void EquilateralTriangle::draw(Board& board)const {
	this->triangle.draw(board);
}
//----------------------------------------------------------------------------
Rectangle EquilateralTriangle::getBoundingRectangle() const {
	return(this->triangle.getBoundingRectangle());
}
//----------------------------------------------------------------------------
double EquilateralTriangle::getArea() const {
	return(this->triangle.getArea());
}
//----------------------------------------------------------------------------
double EquilateralTriangle::getPerimeter() const {
	return(this->triangle.getPerimeter());
}
//----------------------------------------------------------------------------
Vertex EquilateralTriangle::getCenter() const {
	return (this->triangle.getCenter());
}
//----------------------------------------------------------------------------
bool EquilateralTriangle::scale(double factor) {
	return(this->triangle.scale(factor));
}
