#include "pch.h"
#include "Ghost.h"


Ghost::Ghost(Texture & texture):m_visual(texture), m_isWeak(false), m_weaknessDuration(Time::Zero)
{
	setOrigin(20, 20);
}

Ghost::Ghost(Texture & texture, PacWoman * pacWoman)
{
}

void Ghost::setWeak(Time duration)
{
	m_isWeak = true;
	m_weaknessDuration = duration;
}

bool Ghost::isWeak() const
{
	return m_isWeak;
}

void Ghost::draw(RenderTarget & target, RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_visual, states);
}