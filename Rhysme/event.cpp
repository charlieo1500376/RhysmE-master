#include "event.h"

EventList Event_List;

Event::Event() {
	this->_event_type = -1;
	this->_parameter_set.resize(1);
}

Event::Event(EventID set_event_type, EventParameter set_parameter_set) {
	this->_event_type = set_event_type;
	this->_parameter_set = set_parameter_set;
}

Event::~Event() {
}

void Event::set_event_type(EventID set_event_type){
	this->_event_type = set_event_type;
}

void Event::set_event_parameter(EventParameter set_parameter_set){
	this->_parameter_set = set_parameter_set;
}

EventID Event::GetEventType(){
	return this->_event_type;
}

EventParameter Event::GetEventParameter(){
	return this->_parameter_set;
}

void InitEventList() {
	Event_List.resize(1);
	Event_List[0] = Event_JumpStage;
}

EventList GetEventList() {
	return Event_List;
}

Event Event_JumpStage(EventParameter parameter_set) {
	//from parameter_set[0]
	//jump to parameter_set[1]
	Event new_event(EVENT_JUMP_STAGE, parameter_set);
	return new_event;
}