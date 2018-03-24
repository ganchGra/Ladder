#include"Ladder.h"

///
/// Constructor
///
Ladder::Ladder(float widthLadder, float hightLadder, float footDepth, float hightStep)
	:m_widthLadder(widthLadder),
	m_footDepth(footDepth),
	m_hightStep(hightStep),
	m_hightLadder(hightLadder)
{
	if (hightLadder < hightStep)
		throw std::logic_error("You cannot build ladder with this parameters");

	setTheNumberOfSteps(hightLadder, hightStep);
}


///
/// Return hight ladder
///
float Ladder::hightLadder() const
{
	return m_hightLadder;
}

///
/// Return widht ladder
///
float Ladder::widthLadder() const
{
	return m_widthLadder;
}

///
/// Return hight step
///
float Ladder::hightStep() const
{
	return m_hightStep;
}

///
/// Return foot depth
///
float Ladder::footDepth() const
{
	return m_footDepth;
}

///
/// Return number of steps
///
unsigned Ladder::numberOfSteps() const
{
	return m_numberOfSteps;
}

///
/// Calculate the number of steps
///
void Ladder::setTheNumberOfSteps(double hightLadder, double hightStep)
{
	m_numberOfSteps = (unsigned)(hightLadder / hightStep);
}