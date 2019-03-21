#pragma once
#include <iostream>
#include "alias.h"

#define EVENT_JUMP_STAGE 0

extern EventList Event_List;

class Event {
public:
	Event();
	Event(EventID set_event_type, EventParameter set_parameter_set);
	~Event();
	void set_event_type(EventID set_event_type);
	void set_event_parameter(EventParameter set_parameter_set);
	EventID GetEventType();
	EventParameter GetEventParameter();
private:
	EventID _event_type;
	EventParameter _parameter_set;
};
Event Event_JumpStage(EventParameter parameter_set);
Event Event_JumpStage(EventParameter parameter_set);
Event Event_JumpStage(EventParameter parameter_set);
Event Event_JumpStage(EventParameter parameter_set);

void InitEventList();

EventList GetEventList();
