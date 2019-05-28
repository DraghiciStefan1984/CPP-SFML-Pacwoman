#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;
using namespace std;

class GameState
{
public:
	enum State { NoCoin, GetReady, Playing, Won, Lost, Count };

	GameState(Game* game);
	Game* getGame() const;

	virtual void insertCoin() = 0;
	virtual void pressButton() = 0;
	virtual void moveStick(Vector2i direction) = 0;
	virtual void update(Time delta) = 0;
	virtual void draw(RenderWindow& window) = 0;

private:
	Game* m_game;
};


class NoCoinState : public GameState
{
public:

	NoCoinState(Game* game);

	void insertCoin();
	void pressButton();
	void moveStick(Vector2i direction);
	void update(Time Delta);
	void draw(RenderWindow& window);

private:
	Text m_text;
	Sprite m_sprite;

	bool m_displayText;
};

class GetReadyState : public GameState
{
public:
	GetReadyState(Game* game);

	void insertCoin();
	void pressButton();
	void moveStick(Vector2i direction);
	void update(Time Delta);
	void draw(RenderWindow& window);

private:
	Text m_text;
};

class PlayingState : public GameState
{
public:
	PlayingState(Game* game);

	void insertCoin();
	void pressButton();
	void moveStick(Vector2i direction);
	void update(Time Delta);
	void draw(RenderWindow& window);

private:
	//PacWoman m_pacWoman;
	//Ghost m_ghost;
};

class LostState : public GameState
{
public:
	LostState(Game* game);

	void insertCoin();
	void pressButton();
	void moveStick(Vector2i direction);
	void update(Time Delta);
	void draw(RenderWindow& window);

private:
	Text m_text;
	Time m_countDown;
	Text m_countDownText;
};

class WonState : public GameState
{
public:
	WonState(Game* game);

	void insertCoin();
	void pressButton();
	void moveStick(Vector2i direction);
	void update(Time Delta);
	void draw(RenderWindow& window);

private:
	Text m_text;
};