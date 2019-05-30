#include "pch.h"
#include "Bonus.h"


Bonus::Bonus(Texture & texture):m_visual(texture)
{
	m_visual.setOrigin(15, 15);
	setFruit(Banana);
}

void Bonus::setFruit(Fruit fruit)
{
	if (fruit == Banana) m_visual.setTextureRect(IntRect(32, 0, 30, 30));
	else if (fruit == Apple) m_visual.setTextureRect(IntRect(32+30, 0, 30, 30));
	else if (fruit == Cherry) m_visual.setTextureRect(IntRect(32+60, 0, 30, 30));
}

void Bonus::draw(RenderTarget & target, RenderStates & states) const
{
	states.transform *= getTransform();
	target.draw(m_visual, states);
}