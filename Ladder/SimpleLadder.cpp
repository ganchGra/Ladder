#include"SimpleLadder.h"
#include<iostream>
#include<fstream>
SimpleLadder::SimpleLadder(float widthLadder, float footDepth, float hightStep, float hightLadder)
	:Ladder(widthLadder,hightLadder,footDepth,hightStep), m_type("Simple Ladder")
{}

///
/// Return ladder type
///
std::string SimpleLadder::type() const
{
	return m_type;
}


///
/// Get all vertices and their number
GLfloat * SimpleLadder::getVertices(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, unsigned &numberOfVertices) const
{
	GLfloat distFromTheFrameLeftAndRight = numberOfSteps() * footDepth() * 0.5f;

	GLfloat distFromTheFrameTopAndBottom = hightLadder() * 0.5f;
	float hight = hightLadder();
	float width = widthLadder();
	float stepHight = hightStep();
	float stepDeep = footDepth();
	unsigned totalSteps = numberOfSteps();


	/* 
	 * Base of a foot - 4 lines with 6 points for line -> 24 for step
	 * Side of the foot - 2 lines with 6 points for line -> 12 for step
	 * Base - 7 lines with 6 points for line -> 42
	 */
	numberOfVertices = 24 * numberOfSteps() + 12 * numberOfSteps() + 42;
	GLfloat * vertices = new GLfloat[numberOfVertices];

	/* 
	 * Base of a foot - 4 lines with 6 points for line -> 24 for step 
	 *       _
	 *        _
	 *         _
     *          _
     *           _
	 *
	*/
	

	unsigned pos = 0;
	for (size_t i = 0; i < totalSteps; i++)
	{
		/* Line between */
		/// left front
		vertices[pos++] = centerPosX + i * stepDeep;
		vertices[pos++] = centerPosY - i * stepHight;
		vertices[pos++] = centerPosZ;
		/// right front
		vertices[pos++] = centerPosX + (i + 1) * stepDeep;
		vertices[pos++] = centerPosY - i * stepHight;
		vertices[pos++] = centerPosZ;

		/* Line between */
		/// right front
		vertices[pos++] = centerPosX + (i + 1) * stepDeep;
		vertices[pos++] = centerPosY - i * stepHight;
		vertices[pos++] = centerPosZ;
		/// right back
		vertices[pos++] = centerPosX + (i + 1) * stepDeep;
		vertices[pos++] = centerPosY - i * stepHight;
		vertices[pos++] = centerPosZ - width;

		/* Line between */
		/// right back
		vertices[pos++] = centerPosX + (i + 1) * stepDeep;
		vertices[pos++] = centerPosY - i * stepHight;
		vertices[pos++] = centerPosZ - width;
		/// left back
		vertices[pos++] = centerPosX + i * stepDeep;
		vertices[pos++] = centerPosY - i * stepHight;
		vertices[pos++] = centerPosZ - width;

		/* Line between */
		/// left back
		vertices[pos++] = centerPosX + i * stepDeep;
		vertices[pos++] = centerPosY - i * stepHight;
		vertices[pos++] = centerPosZ - width;
		/// left front
		vertices[pos++] = centerPosX + i * stepDeep;
		vertices[pos++] = centerPosY - i * stepHight;
		vertices[pos++] = centerPosZ;
	}

	/*
	 * Side of the foot - 2 lines with 6 points for line -> 12 for step 
	 *
	 *        |
	 *          |
	 *            |
	 *        	    |
	 *        	      |
	 */

	for (size_t i = 0; i < totalSteps - 1; i++)
	{
		/* Line between */
		/// up front
		vertices[pos++] = centerPosX + (i + 1) * stepDeep;
		vertices[pos++] = centerPosY - i * stepHight;
		vertices[pos++] = centerPosZ;
		/// down front
		vertices[pos++] = centerPosX + (i + 1) * stepDeep;
		vertices[pos++] = centerPosY - (i + 1) * stepHight;
		vertices[pos++] = centerPosZ;

		/* Line between */
		/// up back
		vertices[pos++] = centerPosX + (i + 1) * stepDeep;
		vertices[pos++] = centerPosY - i * stepHight;
		vertices[pos++] = centerPosZ - width;
		/// down back
		vertices[pos++] = centerPosX + (i + 1) * stepDeep;
		vertices[pos++] = centerPosY - (i + 1) * stepHight;
		vertices[pos++] = centerPosZ - width;
	}

	/* The last step - can be more or less than hight step - 2 lines with 6 points for line -> 12 */
	/* Line between */
	/// up front
	vertices[pos++] = centerPosX + totalSteps * stepDeep;
	vertices[pos++] = centerPosY - (totalSteps - 1) * stepHight;
	vertices[pos++] = centerPosZ;
	/// down front
	vertices[pos++] = centerPosX + totalSteps * stepDeep;
	vertices[pos++] = centerPosY - hight;
	vertices[pos++] = centerPosZ;

	/* Line between */
	/// up back
	vertices[pos++] = centerPosX + totalSteps * stepDeep;
	vertices[pos++] = centerPosY - (totalSteps - 1) * stepHight;
	vertices[pos++] = centerPosZ - width;
	/// down back
	vertices[pos++] = centerPosX + totalSteps * stepDeep;
	vertices[pos++] = centerPosY - hight;
	vertices[pos++] = centerPosZ - width;
	/*
	 * Base - 7 lines with 6 points for line -> 42
	 * 
	 *   |
	 *    \
	 *     \
	 *      \
	 *   	 \_____|
	 */

	 /* Line between */
	 /// up front
	vertices[pos++] = centerPosX;
	vertices[pos++] = centerPosY;
	vertices[pos++] = centerPosZ;
	/// down front
	vertices[pos++] = centerPosX;
	vertices[pos++] = centerPosY - stepHight;
	vertices[pos++] = centerPosZ;

	/* Line between */
	/// down front
	vertices[pos++] = centerPosX;
	vertices[pos++] = centerPosY - stepHight;
	vertices[pos++] = centerPosZ;
	/// right front
	vertices[pos++] = centerPosX + (totalSteps - 1) * stepDeep;
	vertices[pos++] = centerPosY - hight;
	vertices[pos++] = centerPosZ;

	/* Line between */
	/// right front
	vertices[pos++] = centerPosX + (totalSteps - 1) * stepDeep;
	vertices[pos++] = centerPosY - hight;
	vertices[pos++] = centerPosZ;
	/// end front
	vertices[pos++] = centerPosX + totalSteps * stepDeep;
	vertices[pos++] = centerPosY - hight;
	vertices[pos++] = centerPosZ;

	/* Line between */
	/// up back
	vertices[pos++] = centerPosX;
	vertices[pos++] = centerPosY;
	vertices[pos++] = centerPosZ - width;
	/// down back
	vertices[pos++] = centerPosX;
	vertices[pos++] = centerPosY - stepHight;
	vertices[pos++] = centerPosZ - width;

	/* Line between */
	/// down back
	vertices[pos++] = centerPosX;
	vertices[pos++] = centerPosY - stepHight;
	vertices[pos++] = centerPosZ - width;
	/// right back
	vertices[pos++] = centerPosX + (totalSteps - 1) * stepDeep;
	vertices[pos++] = centerPosY - hight;
	vertices[pos++] = centerPosZ - width;

	/* Line between */
	/// right back
	vertices[pos++] = centerPosX + (totalSteps - 1) * stepDeep;
	vertices[pos++] = centerPosY - hight;
	vertices[pos++] = centerPosZ - width;
	/// end back
	vertices[pos++] = centerPosX + totalSteps * stepDeep;
	vertices[pos++] = centerPosY - hight;
	vertices[pos++] = centerPosZ - width;

	/* Line between */
	/// end front
	vertices[pos++] = centerPosX + totalSteps * stepDeep;
	vertices[pos++] = centerPosY - hight;
	vertices[pos++] = centerPosZ;
	/// end back
	vertices[pos++] = centerPosX + totalSteps * stepDeep;
	vertices[pos++] = centerPosY - hight;
	vertices[pos++] = centerPosZ - width;
	/*
	 * Final 
	 *   _
	 *  | |_
	 *   \  |_
	 *	  \   |_
	 *	   \    |_
	 *      \_____|
	 */
	
	return vertices;
}
///
///
/// Save ladder coordinates
///


void SimpleLadder::save(std::string &fileName, GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ) const
{
	std::ofstream file(fileName.c_str());
	file
		<< "Width ladder in cm: " << widthLadder() << "\n"
		<< "Hight ladder in cm: " << hightLadder() << "\n"
		<< "Hight step in cm: " << hightStep() << "\n"
		<< "Foot depth in cm: " << footDepth() << "\n"
		<< "Number of steps: " << numberOfSteps() << "\n"
		<< "Type: " << m_type << "\n";

	unsigned totalVertices;

	GLfloat * vertices = getVertices(centerPosX, centerPosY, centerPosZ, totalVertices);
	
	file << "Number of vertex: " << totalVertices << "\n\n";
	size_t i = 0;
	while (i < totalVertices)
	{
		file << vertices[i++] << " " << vertices[i++] << " " << vertices[i++] << "\n";
	}
	
	file.close();
	delete[] vertices;
	std::cout << "Succsesfull saved Simple ladder\nFile name: " << fileName << std::endl;
}


///
/// Draw ladder
///
void SimpleLadder::draw(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ) const
{
	
	unsigned totalVertex;
	GLfloat * vertices = getVertices(centerPosX, centerPosY, centerPosZ, totalVertex);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColor3f(0, 1, 2);
	glVertexPointer(3, GL_FLOAT, 0, vertices);

	glDrawArrays(GL_LINES, 0, totalVertex);

	glDisableClientState(GL_VERTEX_ARRAY);
	delete[] vertices;
}