#pragma once

#include<string>
#define GLEW_STATIC
#include <GL/glew.h>

class Ladder
{
public:

	///
	/// Constructor
	///
	Ladder(float widthLadder, float hightLadder, float footDepth, float hightStep);

	///
	/// Return hight ladder
	///
	float hightLadder() const;

	///
	/// Return widht ladder
	///
	float widthLadder() const;

	///
	/// Return hight step
	///
	float hightStep() const;

	///
	/// Return foot depth
	///
	float footDepth() const;

	///
	/// Return number of steps
	///
	unsigned numberOfSteps() const;

	///
	/// Return ladder type
	///
	virtual std::string type() const = 0;

	///
	/// Draw ladder
	///
	virtual void draw(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ) const = 0;
	
	///
	/// Save ladder data to file
	///
	virtual void save(std::string & fileName, GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ) const = 0;

private:
	///
	/// Calculate the number of steps
	///
	void setTheNumberOfSteps(float hightLadder, float hightStep);
private:

	float m_widthLadder;
	float m_footDepth;
	float m_hightStep;
	float m_hightLadder;

	unsigned m_numberOfSteps;
};

