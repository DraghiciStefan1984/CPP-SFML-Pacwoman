#pragma once
#include "Character.h"

class PacWoman: public Character
{
private:
	bool m_isDead;
	Sprite m_visual;
	void draw(RenderTarget& target, RenderStates states) const;

public:
	PacWoman(Texture& texture);
	void die();
	bool isDead() const;
};