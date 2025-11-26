#include "time.hpp"

float Time::deltaTime = 1.0f / 60.0f;

void Time::updateTime(double t)
{
	deltaTime = (float)t - lastFrame;
	lastFrame = (float)t;
}
