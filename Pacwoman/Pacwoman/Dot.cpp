#include "pch.h"
#include "Dot.h"

CircleShape getDot()
{
	CircleShape dot;
	dot.setRadius(4);
	dot.setFillColor(Color::White);
	dot.setOrigin(2, 2);
	return dot;
}

CircleShape getSuperDot()
{
	CircleShape superDot;
	superDot.setRadius(8);
	superDot.setFillColor(Color::White);
	superDot.setOrigin(2, 2);
	return superDot;
}
