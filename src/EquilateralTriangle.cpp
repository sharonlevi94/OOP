#include "IsoscelesTriangle.h"

//----------------------------------------------------------------------------
IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3]) {
	*this = 
		IsoscelesTriangle(
			vertices[0], vertices[1], 
			vertices[3].m_row - vertices[0].m_row);
}
//----------------------------------------------------------------------------
IsoscelesTriangle::IsoscelesTriangle(const Vertex& v0, 
	const Vertex& v1, double height) {
	if (v0.isValid && v1.isValid && v0.m_row == v1.m_row 
		&& v1.isToTheRightOf(v0)) {
		this->vertices[0] = v0;
		this->vertices[1] = v1;
		this->vertices[2] = 
			Vertex((v1.m_col - v0.m_col) / 2, v1.m_row + height);
		return;
	}
	*this = IsoscelesTriangle();
}
//----------------------------------------------------------------------------
IsoscelesTriangle::getVertex(int index) const {
	return (this->vertices[index % 3]);
}
//----------------------------------------------------------------------------
IsoscelesTriangle::getBaseLength() const {
	return(this->vertices[1].m_col - this->vertices[0].m_col);
}
//----------------------------------------------------------------------------
IsoscelesTriangle::getLegLength() const {
	return(
		sqrt(
			pow(this->getHeight(), 2) + pow(this->getBaseLength() / 2, 2)));
}
//----------------------------------------------------------------------------
IsoscelesTriangle::getHeight() const {
	return(this->vertices[3].m_row - this->vertices[0].m_row);
}
//----------------------------------------------------------------------------
IsoscelesTriangle:: draw(Board& board)const {
	board.drawLine(this->vertices[0], this->vertices[1]);
	board.drawLine(this->vertices[0], this->vertices[2]);
	board.drawLine(this->vertices[1], this->vertices[2]);
}
//----------------------------------------------------------------------------
IsoscelesTriangle::getBoundingRectangle() const {
	return (
		Rectangle(this->vertices[0]), 
		Vertex(this->vertices[1].m_col, this->vertices[3].m_row));
}
//----------------------------------------------------------------------------
IsoscelesTriangle::getArea() const {
	return ((this->getHeight() * this->getBaseLength()) / 2);
}
//----------------------------------------------------------------------------
IsoscelesTriangle::getPerimeter() const {
	return((2 * this->getLegLength()) + this->getBaseLength());
}
//----------------------------------------------------------------------------
IsoscelesTriangle::getCenter() const {
	double x = 0, y = 0;
	for (int i = 0; i < 3; ++i) {
		x += this->vertices[i].m_col;
		y += this->vertices[i].m_row;
	}
	return(Vertex(x / 3, y / 3));
}
//----------------------------------------------------------------------------
IsoscelesTriangle::scale(double factor) {
	if (Vertex(this->vertices[0].m_col - factor,
		this->vertices[0].m_row - factor).isValid() &&
		Vertex(this->vertices[1].m_col + factor,
			this->vertices[1].m_row - factor).isValid() &&
		Vertex(this->vertices[2].m_col,
			this->vertices[2].m_row + factor).isValid()&&)
	{
		*this->vertices[0] = Vertex(this->vertices[0].m_col - factor,
			this->vertices[0].m_row - factor);
		*this->vertices[1] = Vertex(this->vertices[1].m_col + factor,
			this->vertices[1].m_row - factor);
		*this->vertices[2] = Vertex(this->vertices[2].m_col,
			this->vertices[2].m_row + factor);
		return true;
	}
	return false;
}
