#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Bonus: public Drawable, public Transformable
{
private:
	Sprite m_visual;
	void draw(RenderTarget& target, RenderStates& states) const;

public:
	Bonus(Texture& texture);
	enum Fruit { Banana, Apple, Cherry };
	void setFruit(Fruit fruit);
};