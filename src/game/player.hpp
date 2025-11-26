#pragma once

#include "../graphics/camera.hpp"
#include "world.hpp"
#include "../window/input.hpp"

class Player
{
public:
	float posX = 0.0f;
	float posY = 0.0f;
	float posZ = 0.0f;
	float cameraHeight = 2.0f;
	
	Player();

	void update(Camera& cam, World* world);

	bool isOnFloor();

private:
};