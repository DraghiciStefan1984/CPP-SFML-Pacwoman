#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"
#include <array>

using namespace sf;
using namespace std;

class Game

{
public:
	Game();
	~Game();

	void run();

	Font& getFont();
	Texture& getLogo();
	Texture& getTexture();

	void changeGameState(GameState::State gameState);

private:
	RenderWindow m_window;
	GameState* m_currentState;
	//array<GameState*, GameState::Count> m_gameStates;

	Font m_font;
	Texture m_logo;
	Texture m_texture;
};