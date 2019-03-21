#include "button.h"

Button::Button(){
	this->_event_parameter.resize(1);
	this->_z_index = 0;
}

Button::~Button() {
}

//rect should split
void Button::SetImage(Image* set_image) {
	this->_button_image = set_image;
	this->_rect.w = set_image->w;
	this->_rect.h = set_image->h;
}

void Button::SetPosition(float set_rect_x, float set_rect_y) {
	if (set_rect_x >= 1.0 || set_rect_y >=  1.0) {
		this->_rect.x = set_rect_x;
		this->_rect.y = set_rect_y;
	}
	this->_rect.x = set_rect_x * GetWindowSize().w;
	this->_rect.y = set_rect_y * GetWindowSize().h;
}

void Button::SetPosition(Rect set_rect) {
	this->_rect.x = set_rect.x;
	this->_rect.y = set_rect.y;
}

void Button::SetEventID(EventID set_event_id){
	this->_event_id = set_event_id;
}

void Button::SetEventParameter(EventParameter set_event_parameter){
	int new_size = set_event_parameter.size();
	this->_event_parameter.resize(new_size);
	this->_event_parameter = set_event_parameter;
}

void Button::SetName(std::string set_name){
	this->_name = set_name;
}

void Button::SetZIndex(int set_z_index){
	this->_z_index = set_z_index;
}

void Button::SetTranslate(Rect set_translate){
	this->_translate = set_translate;
}

void Button::SetTranslate(float set_translate_x, float set_translate_y){
	if (set_translate_x > 1.0 || set_translate_y > 1.0) {
		this->_translate.x = set_translate_x;
		this->_translate.y = set_translate_y;
		return;
	}
	this->_translate.x = set_translate_x * GetWindowSize().w;
	this->_translate.y = set_translate_y * GetWindowSize().h;
}

Image* Button::GetImage() {
	return this->_button_image;
}

Rect Button::GetRect() {
	Rect translated_rect;
	translated_rect.h = this->_rect.h;
	translated_rect.w = this->_rect.w;
	translated_rect.x = this->_rect.x + this->_translate.x;
	translated_rect.y= this->_rect.y + this->_translate.y;
	return this->_rect;
}

Rect Button::GetRawRect(){
	return this->_rect;
}

EventID Button::GetEventID() {
	return this->_event_id;
}

std::string Button::GetName(){
	return this->_name;
}

EventParameter Button::GetEventParameter(){
	return this->_event_parameter;
}

int Button::GetZIndex(){
	return this->_z_index;
}
