#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <string>
#include "stage.h"
#include "alias.h"
#include "beatmap.h"

//Forward declaration
class Beat;
class BeatPoint;
class BeatSlider;
class BeatSlash;

class Game : public Stage {
public:
	Game();
	~Game();
	void run();
private:
	BeatMap _map;
};