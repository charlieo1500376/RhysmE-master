#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <fstream>
#include <string>
#include "alias.h"
#include "stage.h"
#include "scene.h"
#include "event.h"
#include "json.hpp"

//Window size, standard
#define STANDARD_WINDOW_WIDTH 1920
#define STANDARD_WINDOW_HEIGHT 1080

using json = nlohmann::json;

//forward declaration
class Stage;

class RhysmE {
public:
	RhysmE();
	RhysmE(Window* window);
	~RhysmE();
	Window *_main_game_window;
	Stage* _main_game_stage;
	void Run();
private:

};

Rect GetWindowSize();