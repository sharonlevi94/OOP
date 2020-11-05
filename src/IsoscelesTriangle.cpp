/* IsoscelesTriangle
 * ===========================================================================
 */
 //---------------------------- include section -------------------------------
#include "IsoscelesTriangle.h"
#include "Utilities.h"
#include "Vertex.h"
#include "Rectangle.h"
//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is building  the object using array of 3 received Vertexes.
 * input: array of 3 Vertexes.
 * output: none.
*/
IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3])
{
	if (doubleEqual(
		vertices[2].m_col,(vertices[0].m_col + vertices[1].m_col) / 2) &&
		vertices[1].isValid())
		*this =
		IsoscelesTriangle(
			vertices[0], vertices[1],
			vertices[2].m_row - vertices[0].m_row);
	else
		*this = IsoscelesTriangle();
}
/*----------------------------------------------------------------------------
 * The constractor is building the object using the bottom left vertex,
 * bottom right Vertex and the triangle height.
 * input: array of 3 Vertexes.
 * output: none.
*/
IsoscelesTriangle::IsoscelesTriangle(const Vertex& v0,
	const Vertex& v1, double height) {
	if (v0.isValid() && v1.isValid() && doubleEqual(v0.m_row, v1.m_row)
		&& v1.isToTheRightOf(v0)) {
		this->vertices[0] = v0;
		this->vertices[1] = v1;
		this->vertices[2] =
			Vertex((v1.m_col + v0.m_col) / 2, v1.m_row + height);
		return;
	}
	*this = IsoscelesTriangle();
}
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method is returning the wanted triangles Vertex,
 * usig the received index.
 * input: Index.
 * output: The wanted triangles Vertex.
*/
Vertex IsoscelesTriangle::getVertex(int index) const {
	return (this->vertices[index % 3]);
}
/*----------------------------------------------------------------------------
 * The method is calculates and return the lenght of the triangle's base edge.
 * input: None.
 * output: The lenght of the triangle base edge.
*/
double IsoscelesTriangle::getBaseLength() const {
	return(distance(this->vertices[1], this->vertices[0]));
}
/*----------------------------------------------------------------------------
  The method is calculates and return the lenght of the triangle's leg edge.
 * input: none.
 * output: The lenght of the triangle's leg edge.
*/
double IsoscelesTriangle::getLegLength() const {
	return(
		sqrt(
			pow(this->getHeight(), 2) + pow(this->getBaseLength() / 2, 2)));
}
/*----------------------------------------------------------------------------
 * The method calculates and return the triangle height.
 * input: none.
 * output: The triangle height.
*/
double IsoscelesTriangle::getHeight() const {
	double distance = this->vertices[2].m_row - this->vertices[0].m_row;
	if (distance > 0)
		return(distance);
	return(-distance);
}
/*----------------------------------------------------------------------------
 * The method drawing the triangle using the received Board.
 * input: the board wonted the triangle drawed on.
 * output: none.
*/
void IsoscelesTriangle::draw(Board& board)const {
	board.drawLine(this->vertices[0], this->vertices[1]);
	board.drawLine(this->vertices[0], this->vertices[2]);
	board.drawLine(this->vertices[1], this->vertices[2]);
}
/*----------------------------------------------------------------------------
 * The method calculates and return the triangle's bounding Rectangle.
 * input: none.
 * output: the triangle's bounding Rectangle.
*/
Rectangle IsoscelesTriangle::getBoundingRectangle() const
{
	return (Rectangle(this->getCenter(), 
		this->getBaseLength(), this->getHeight()));
}
/*----------------------------------------------------------------------------
 * The method calculates and return the trangle's area.
 * input: none.
 * output: triangle's area.
*/
double IsoscelesTriangle::getArea() const {
	return ((this->getHeight() * this->getBaseLength()) / 2);
}
/*----------------------------------------------------------------------------
 * The method calculates and return the triangle's perimeter.
 * input: none.
 * output: The triangle's perimeter.
*/
double IsoscelesTriangle::getPerimeter() const {
	return((2 * this->getLegLength()) + this->getBaseLength());
}
/*----------------------------------------------------------------------------
 * The method calculates and return the triangle's center Vertex.
 * input: none.
 * output: triangle center Vertex.
*/
Vertex IsoscelesTriangle::getCenter() const {
	double x = (this->vertices[0].m_col + this->vertices[1].m_col) / 2,
		   y = (this->vertices[0].m_row + this->vertices[2].m_row) / 2;
	return(Vertex(x, y));
}
/*----------------------------------------------------------------------------
 * The method is duplicate the triangle size, check if the new sized triangle
 * is valid, if it is its resize the triangle's values and retrun true,
 * if the new sized trinle isn't valid the function don't change the
 * triangle's values, and return false.
 * input: the wanted resize value.
 * output: if the resize succeed.
*/
bool IsoscelesTriangle::scale(double factor) {
	Vertex vercheck[3];
	for (int i = 0; i < 3; ++i) {
		vercheck[i] = this->vertices[i];
		vercheck[i].m_col -= this->getCenter().m_col;
		vercheck[i].m_row -= this->getCenter().m_row;
		vercheck[i].m_col *= factor;
		vercheck[i].m_row *= factor;
		vercheck[i].m_col += this->getCenter().m_col;
		vercheck[i].m_row += this->getCenter().m_row;
		if (!vercheck[i].isValid())
			return false;
	}
	for (int i = 0; i < 3; ++i)
		this->vertices[i] = vercheck[i];
	return true;
}
