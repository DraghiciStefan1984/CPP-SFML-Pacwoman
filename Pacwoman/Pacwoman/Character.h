#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class Character: public Drawable, public Transformable
{
private:
	float m_speed;

public:
	Character();
	void setSpeed(float speed);
	float getSpeed() const;
};

