#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <map>

//Forward declaration
class Button;
class Event;

//should change all into "using"
using Window = SDL_Window;
using Image = SDL_Surface;
using NullBackground = SDL_Surface;
using ButtonSet = std::vector<Button>;
using Ticks = Uint32;
using Rect = SDL_Rect;
using ImgRectLoadedMap = std::map<Image*, std::map<int, std::map<int, bool>>>;
using EventID = int;
using EventParameter = std::vector<int>;
using EventFunctionPointer = Event(*)(EventParameter);
using EventList = std::vector<EventFunctionPointer>;

using EventParameterMap = std::map<int, EventParameter>;
using EventFunctionMap = std::map<int, EventFunctionPointer>;


//using EventFunctionFull = std::map<EventFunctionPointer, ParameterSet>;
//using EventFullMap = std::map<int, EventFunctionFull>;


void SetImageOpacity(Image *image, float opacity);