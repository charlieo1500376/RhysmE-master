#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "alias.h"

Image* Checker_LoadImage(std::string image_source);
Image* Checker_LoadImage(const char* image_source);