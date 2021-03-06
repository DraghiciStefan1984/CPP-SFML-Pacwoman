#include "pch.h"
#include "PacWoman.h"

PacWoman::PacWoman(Texture& texture) :m_visual(texture), m_isDead(false) 
{
	setOrigin(20, 20);
}

void PacWoman::draw(RenderTarget & target, RenderStates states) const
{
	states.transform *= getTransform();
	if (!m_isDead) target.draw(m_visual);
}

void PacWoman::die() { m_isDead = true; }

bool PacWoman::isDead() const { return m_isDead; }