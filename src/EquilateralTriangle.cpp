/* EquilateralTriangle
 * ===========================================================================
 */
 //---------------------------- include section -------------------------------
#include "EquilateralTriangle.h"
//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is check if the vertices received building an equilateral
 * triangle, if it is the constractor build the equilateral triangle due the
 * received vertices, if not, the constractor bulid the triangle by the
 * demanded default values.
 * input: array of 3 Vertexes.
 * output: none.
*/
EquilateralTriangle::EquilateralTriangle(const Vertex vertices[3])
{
	IsoscelesTriangle temp = IsoscelesTriangle(vertices);
	if (temp.getLegLength() == temp.getBaseLength())
		this->triangle = temp;
	else
		this->triangle = IsoscelesTriangle();
}

//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method is returning the wanted triangles Vertex,
 * usig the received index.
 * input: Index.
 * output: The wanted triangles Vertex.
*/
Vertex EquilateralTriangle::getVertex(int index) const {
	return(this->triangle.getVertex(index));
}
/*----------------------------------------------------------------------------
 * The method is calculates and return the lenght of the triangle's edges.
 * input: None.
 * output: The lenght of the triangle base edge.
*/
double EquilateralTriangle::getLength() const{
	return(this->triangle.getLegLength());
}
/*----------------------------------------------------------------------------
 * The method drawing the triangle using the received Board.
 * input: the board wonted the triangle drawed on.
 * output: none.
*/
void EquilateralTriangle::draw(Board& board)const {
	this->triangle.draw(board);
}
/*----------------------------------------------------------------------------
 * The method calculates and return the triangle's bounding Rectangle.
 * input: none.
 * output: the triangle's bounding Rectangle.
*/
Rectangle EquilateralTriangle::getBoundingRectangle() const {
	return(this->triangle.getBoundingRectangle());
}
/*----------------------------------------------------------------------------
 * The method calculates and return the trangle's area.
 * input: none.
 * output: triangle's area.
*/
double EquilateralTriangle::getArea() const {
	return(this->triangle.getArea());
}
/*----------------------------------------------------------------------------
 * The method calculates and return the triangle's perimeter.
 * input: none.
 * output: The triangle's perimeter.
*/
double EquilateralTriangle::getPerimeter() const {
	return(this->triangle.getPerimeter());
}
/*----------------------------------------------------------------------------
 * The method calculates and return the triangle's center Vertex.
 * input: none.
 * output: triangle center Vertex.
*/
Vertex EquilateralTriangle::getCenter() const {
	return (this->triangle.getCenter());
}
/*----------------------------------------------------------------------------
 * The method is duplicate the triangle size, check if the new sized triangle
 * is valid, if it is its resize the triangle's values and retrun true,
 * if the new sized trinle isn't valid the function don't change the
 * triangle's values, and return false.
 * input: the wanted resize value.
 * output: if the resize succeed.
*/
bool EquilateralTriangle::scale(double factor) {
	return(this->triangle.scale(factor));
}
