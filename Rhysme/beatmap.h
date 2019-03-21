#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "alias.h"
#include <iostream>
#include <vector>
#include <string>

class Beat {
public:

private:
	Rect _rect_start;
	Rect _rect_end; //For slider
	float _start_time;
	float _lasting_time; //For slider
};

class BeatMap {
public:
	//Music music;
	std::string _map_name;
	float _beat_size;
	float _appear_speed;
	float _judge_time;
	float _map_length;
	float _map_star;
	Ticks _map_start_time;
	float _bpm;
};