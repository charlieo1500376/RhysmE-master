#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "alias.h"
#include "button.h"
#include "checker.h"
#include "event.h"

//Forward declaration
class Scene;

class Stage {
public:
	Stage();
	Stage(Window* window);
	~Stage();
	std::string GetStageName();
	void SetStageName(std::string set_name);
	void SetWindow(Window* window);
	void InitNullBackground();
	void PutAllButton();
	void PutRenderImage();
	void TestingSetup();
	void TestingSetup2();
	Event RaiseEvent(int x, int y);
	void CleanPostImage();
	void CleanEventMap();
	void SortButtonSetByZIndex();
	//void CleanButtonSet();
private:
	std::string _name;
	Scene* _scene;
	NullBackground* _surface_null_background;
	ButtonSet _button_set;
	Window* _window;
	std::vector<std::vector<EventID>> _event_image;
	EventFunctionMap _event_function;
	EventParameterMap _event_parameter;
};

bool ZindexSmaller(Button & left_button, Button & right_button);