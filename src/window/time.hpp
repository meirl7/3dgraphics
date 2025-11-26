#pragma once

class Time
{
public:
	static float deltaTime;

	void updateTime(double t);
private:
	float lastFrame = 0.0f;
};