#pragma once

#include "Mascot.cpp"
#include "ObstacleHandler.cpp"

class MainGame : public Game
{
public:
	//First frame after initializing SDL 2
	MainGame()
	{
	}

	//When the program is shuting down
	~MainGame()
	{
		mascot.~Mascot();
	}

	//Every Frame ( Manage Logic )
	void Update()
	{
		mascot.Update(input, time);
		handler.Update(time);
	}

	//Process SDL2 Events (Extra input related code...)
	void ProcessEvents(const SDL_Event& e)
	{
	}

	//Every Frame ( Draw Images )
	void Render()
	{
		if(!handler.isColliding(mascot.collider))
			mascot.Render();

		handler.Render();
	}
public:
	Mascot mascot;
	ObstacleHandler handler;
};