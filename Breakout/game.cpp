#include "Game.h"

Game::Game(unsigned int width, unsigned int height) 
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
}

Game::~Game()
{
}

void Game::Init()
{
}

void Game::ProcessInput()
{
}

void Game::Update(float dt)
{
}

void Game::Render()
{
}
