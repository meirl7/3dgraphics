#include "player.hpp"

Player::Player()
{
	
}

void Player::update(Camera& camera, World* world)
{
	if (Input::isKeyJustPressed(GLFW_KEY_SPACE))
	{

	}

	camera.position.y = posY;
}

bool Player::isOnFloor()
{

	return false;
}
