#pragma once

#include"Ladder.h"
#include <GL/glew.h>

class SimpleLadder:public Ladder
{
public:
	SimpleLadder(float widthLadder, float footDepth, float hightStep, float hightLadder);
	
	///
	/// Return ladder type
	///
	virtual std::string type() const;

	///
	/// Draw ladder
	///
	virtual void draw(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ) const;

	///
	/// Save ladder coordinates
	///
	virtual void save(std::string &fileName, GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ) const;
	
private:
	/// 
	/// Get all vertex started from initial parametar X,Y,Z
	///
	GLfloat * getVertices(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, unsigned &totPoints) const;

private:
	
	std::string m_type;
};
