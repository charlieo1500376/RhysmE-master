#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "RhysmE.h"
#include "alias.h"

class Button {
public:
	Button();
	~Button();

	//Set
	void SetImage(Image* set_image);
	void SetPosition(float set_rect_x, float set_rect_y);
	void SetPosition(Rect set_rect);
	void SetEventID(EventID set_event_id);
	void SetEventParameter(EventParameter set_event_parameter);
	void SetName(std::string set_name);
	void SetZIndex(int set_z_index);
	void SetTranslate(Rect set_translate);
	void SetTranslate(float set_translate_x, float set_translate_y);

	//Get
	Image* GetImage();
	Rect GetRect();
	Rect GetRawRect();
	EventID GetEventID();
	std::string GetName();
	EventParameter GetEventParameter();
	int GetZIndex();

private:
	int _z_index;
	std::string _name;
	Image* _button_image;
	Rect _rect;
	Rect _translate;
	EventID _event_id;
	EventParameter _event_parameter;
};