#include "EquilateralTriangle.h"
//----------------------------------------------------------------------------
EquilateralTriangle::EquilateralTriangle() {
	this->triangle = IsoscelesTriangle();
}
//----------------------------------------------------------------------------
EquilateralTriangle::EquilateralTriangle(Vertex vertices[3]) {
	this->triangle = IsoscelesTriangle(vertices);
}
//----------------------------------------------------------------------------
EquilateralTriangle::getVertex(int index) const {
	return(this->triangle.getVertex(index));
}
//----------------------------------------------------------------------------
EquilateralTriangle::getLength() {
	return(this->triangle.getLegLength());
}
//----------------------------------------------------------------------------
EquilateralTriangle::draw(Board& board)const {
	this->triangle.draw(board);
}
//----------------------------------------------------------------------------
EquilateralTriangle::getBoundingRectangle() const {
	return(this->triangle.getBoundingRectangle());
}
//----------------------------------------------------------------------------
EquilateralTriangle::getArea() const {
	return(this->triangle.getArea());
}
//----------------------------------------------------------------------------
EquilateralTriangle::getPerimeter() const {
	return(this->triangle.getPerimeter());
}
//----------------------------------------------------------------------------
EquilateralTriangle::getCenter() const {
	return(this->triangle.getCenter);
}
//----------------------------------------------------------------------------
EquilateralTriangle::scale(double factor) {
	return(this->triangle.scale(factor));
}
