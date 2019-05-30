#pragma once
#include "Character.h"
#include "PacWoman.h"

class Ghost:public Character
{
private:
	bool m_isWeak;
	Time m_weaknessDuration;
	Sprite m_visual;
	void draw(RenderTarget& target, RenderStates states) const;

public:
	Ghost(Texture& texture);
	Ghost(Texture& texture, PacWoman* pacWoman);
	enum State { Strong, Weak };
	void setWeak(Time duration);
	bool isWeak() const;
};