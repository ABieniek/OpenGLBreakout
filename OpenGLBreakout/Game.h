/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <tuple>

#include "GameLevel.h"
#include "GameObject.h"
#include "BallObject.h"
#include "PowerUp.h"
#include "resourceManager.h"
#include "SpriteRenderer.h"
#include "ParticleGenerator.h"
#include "PostProcessor.h"
#include <irrKlang.h>
#include <ft2build.h>
#include FT_FREETYPE_H  
#include "TextRenderer.h"

// Represents the current state of the game
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT 
};

typedef std::tuple<GLboolean, Direction, glm::vec2> Collision;

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
	// Game state
	GameState				State;
	GLboolean				Keys[1024];
	GLuint					Width, Height;
	std::vector<GameLevel>	Levels;
	GLuint					Level;
	GLuint					Lives;
	std::vector<PowerUp>	PowerUps;
	// Constructor/Destructor
	Game(GLuint width, GLuint height);
	~Game();
	// Initialize game state (load all shaders/textures/levels)
	void Init();
	// GameLoop
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
	GLboolean CheckCollision(GameObject &one, GameObject &two);
	Collision CheckCollision(BallObject &one, GameObject &two);
	Direction VectorDirection(glm::vec2 target);
	void DoCollisions();
	// powerups
	void SpawnPowerUps(GameObject &block);
	void UpdatePowerUps(GLfloat dt);
	GLboolean IsOtherPowerUpActive(std::vector<PowerUp> &powerUps, std::string type);
	void ActivatePowerUp(PowerUp &powerUp);
	// reset
	void ResetLevel();
	void ResetPlayer();
};

#endif
