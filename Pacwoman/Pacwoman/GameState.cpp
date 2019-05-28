#include "pch.h"
#include "GameState.h"

template <typename T>
void centerOrigin(T& drawable)
{
	FloatRect bound = drawable.getLocalBounds();
	drawable.setOrigin(bound.width / 2, bound.height / 2);
}

GameState::GameState(Game* game) : m_game(game) {}

NoCoinState::NoCoinState(Game* game) : GameState(game)
{
	m_sprite.setTexture(game->getLogo());
	m_sprite.setPosition(20, 50);
	m_text.setFont(game->getFont());
	m_text.setString("Insert coin!");
	centerOrigin(m_text);
	m_text.setPosition(240, 150);
	m_displayText = true;
}

GetReadyState::GetReadyState(Game* game) : GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("Press Start when you're ready...");
	m_text.setCharacterSize(14);
	centerOrigin(m_text);
	m_text.setPosition(240, 240);
}

PlayingState::PlayingState(Game* game) : GameState(game), m_pacWoman(game->getTexture()), m_ghost(game->getTexture())
{
	m_pacWoman.move(100, 100);
	m_ghost.move(200, 200);
}

WonState::WonState(Game* game) : GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("You Won!");
	m_text.setCharacterSize(42);
	centerOrigin(m_text);
	m_text.setPosition(240, 120);
}

LostState::LostState(Game* game) : GameState(game)
{
	m_text.setFont(game->getFont());
	m_text.setString("You lost!");
	m_text.setCharacterSize(42);
	centerOrigin(m_text);
	m_text.setPosition(240, 120);
	m_countDownText.setFont(game->getFont());
	m_countDownText.setCharacterSize(12);
	centerOrigin(m_countDownText);
	m_countDownText.setPosition(240, 240);
}

Game* GameState::getGame() const { return m_game; }

void NoCoinState::insertCoin() { getGame()->changeGameState(GameState::GetReady); }

void NoCoinState::pressButton() {}

void NoCoinState::moveStick(Vector2i direction) {}

void NoCoinState::update(Time delta)
{
	static Time timeBuffer = Time::Zero;
	timeBuffer += delta;

	while (timeBuffer >= seconds(0.5))
	{
		m_displayText = !m_displayText;
		timeBuffer -= seconds(1);
	}
}

void NoCoinState::draw(RenderWindow& window)
{
	window.draw(m_sprite);
	if (m_displayText) window.draw(m_text);
}

void GetReadyState::insertCoin() {}

void GetReadyState::pressButton() { getGame()->changeGameState(GameState::Playing); }

void GetReadyState::moveStick(Vector2i direction) 
{
	if (direction.x == -1) getGame()->changeGameState(GameState::Lost);
	else if (direction.x == 1) getGame()->changeGameState(GameState::Won);
}

void GetReadyState::update(Time delta) {}

void GetReadyState::draw(RenderWindow& window) { window.draw(m_text); }

void PlayingState::insertCoin() { m_pacWoman.die(); }

void PlayingState::pressButton() { m_ghost.setWeak(seconds(3)); }

void PlayingState::moveStick(Vector2i direction) {}

void PlayingState::update(Time delta)
{
	m_pacWoman.update(delta);
	m_ghost.update(delta);
}

void PlayingState::draw(RenderWindow& window)
{
	window.draw(m_pacWoman);
	window.draw(m_ghost);
}

void WonState::insertCoin() {}

void WonState::pressButton() {}

void WonState::moveStick(Vector2i direction) {}

void WonState::update(Time delta)
{
	static Time timeBuffer = Time::Zero;
	timeBuffer += delta;
	if (timeBuffer.asSeconds() > 5) getGame()->changeGameState(GameState::GetReady);
}

void WonState::draw(RenderWindow& window) { window.draw(m_text); }

void LostState::insertCoin() {}

void LostState::pressButton() {}

void LostState::moveStick(Vector2i direction) {}

void LostState::update(Time delta)
{
	m_countDown += delta;
	if (m_countDown.asSeconds() >= 10) getGame()->changeGameState(GameState::GetReady);
	m_countDownText.setString("Insert a coin to continue... " + to_string(10 - static_cast<int>(m_countDown.asSeconds())));
}

void LostState::draw(RenderWindow& window)
{
	window.draw(m_text);
	window.draw(m_countDownText);
}
