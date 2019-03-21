#include "stage.h"

extern EventList Event_List;

Stage::Stage(){
	this->_scene = new Scene;
	this->_name = std::string("void_stage");
	this->_surface_null_background = NULL;
	this->_window = NULL;

	this->_event_image.resize(GetWindowSize().h);
	for (int i = 0; i < GetWindowSize().h; i++)
		this->_event_image[i].resize(GetWindowSize().w);

	for (int i = 0; i < GetWindowSize().h; i++)
		for (int j = 0; j < GetWindowSize().w; j++)
			this->_event_image[i][j] = -1;

	//砞﹚冈灿ㄆンの把计竚﹟∕﹚
	/*****************************************/
	EventParameter insert_parameter = { 1, 2 };
	this->_event_function[0] = Event_List[0];
	this->_event_parameter[0] = insert_parameter;
	/*****************************************/
}

Stage::Stage(Window *window) {
	this->_scene = new Scene;
	this->_name = std::string("void_stage");
	this->SetWindow(window);

	this->_event_image.resize(GetWindowSize().h);
	for (int i = 0; i < GetWindowSize().h; i++)
		this->_event_image[i].resize(GetWindowSize().w);

	for (int i = 0; i < GetWindowSize().h; i++)
		for (int j = 0; j < GetWindowSize().w; j++)
			this->_event_image[i][j] = -1;

	//砞﹚冈灿ㄆンの把计竚﹟∕﹚
/*****************************************/
	EventParameter insert_parameter = { 1, 2 };
	this->_event_function[0] = Event_List[0];
	this->_event_parameter[0] = insert_parameter;
	/*****************************************/
}

Stage::~Stage(){

}

std::string Stage::GetStageName(){
	return this->_name;
}

void Stage::SetStageName(std::string set_name)
{
	this->_name = set_name;
}

void Stage::SetWindow(Window * window){
	this->_window = window;
	//Get window surface
	this->_surface_null_background = SDL_GetWindowSurface(this->_window);
	//Fill the surface
	SDL_FillRect(this->_surface_null_background, NULL, SDL_MapRGB(this->_surface_null_background->format, 0x00, 0x00, 0x00));
}

void Stage::InitNullBackground(){
	//Clear Scene
	delete this->_scene;
	this->_scene = new Scene;
	//Fill the surface
	SDL_FillRect(this->_surface_null_background, NULL, SDL_MapRGB(this->_surface_null_background->format, 0x00, 0x00, 0x00));
}

void Stage::PutAllButton(){
	/*
		Rect output_rect;
		output_rect.h = button.GetRect().h * GetWindowSize().h / STANDARD_WINDOW_HEIGHT;
		output_rect.w = button.GetRect().w * GetWindowSize().w / STANDARD_WINDOW_WIDTH;
		output_rect.x = button.GetRect().x * GetWindowSize().h / STANDARD_WINDOW_HEIGHT;
		output_rect.y = button.GetRect().y * GetWindowSize().w / STANDARD_WINDOW_WIDTH;

		for (int j = 0; j < output_rect.h && j + output_rect.y < output_rect.h; j++) {
			for (int k = 0; k < output_rect.w && k + output_rect.x < output_rect.w; k++) {
				this->_event_image[j + output_rect.y][k + output_rect.x] = button.GetEventID();
			}
		}
	*/

	//Paste button on the surface
	for (auto &button : this->_button_set) {
		//std::cout << button.GetZIndex() << "\n";
		this->_scene->AddButton(button);
		if (button.GetName() == "bg")
			continue;
		Rect output_rect;
		output_rect.h = button.GetRect().h * GetWindowSize().h / STANDARD_WINDOW_HEIGHT;
		output_rect.w = button.GetRect().w * GetWindowSize().w / STANDARD_WINDOW_WIDTH;
		output_rect.x = button.GetRect().x; //* GetWindowSize().h / STANDARD_WINDOW_HEIGHT;
		output_rect.y = button.GetRect().y; //* GetWindowSize().w / STANDARD_WINDOW_WIDTH;
		//SDL_SetAlpha();

		for (int j = 0; j < output_rect.h && j + output_rect.y < GetWindowSize().h; j++) {
			for (int k = 0; k < output_rect.w && k + output_rect.x < GetWindowSize().w; k++) {
				//std::cout << j + output_rect.y << "," << k + output_rect.x << "\n";
				this->_event_image[j + output_rect.y][k + output_rect.x] = button.GetEventID();
			}
		}
		//Old method
		//this->_scene->AddImage(button.GetImage(), button.GetRect());

		//New method
	}
}

void Stage::PutRenderImage(){
	//Put final scene on the surface a.k.a. background
	SDL_BlitSurface(this->_scene->GetRenderedImg(), NULL, this->_surface_null_background, NULL);
}

void Stage::TestingSetup(){

	this->_button_set.resize(2);
	Image *background_img = Checker_LoadImage("img\\test\\stage0\\background.png");
	Image *button_img = Checker_LoadImage("img\\test\\stage0\\button.png");
	this->_button_set[0].SetImage(background_img);
	this->_button_set[0].SetPosition(0.0, 0.0);
	this->_button_set[1].SetImage(button_img);
	this->_button_set[1].SetPosition(0.5, 0.5);
	//_scene. = _surface_background

	//ㄆン砞﹚
	/**************/
	_button_set[0].SetName("bg");
	_button_set[0].SetEventID(-1);
	_button_set[0].SetZIndex(0);
	_button_set[1].SetEventID(0);
	_button_set[1].SetZIndex(1);
	/**************/
}

void Stage::TestingSetup2() {
	this->_button_set.resize(10);

	//std::string background_image_source = "img\\test\\stage1\\background.jpg";
	std::string background_image_source = "stage\\playlist\\img\\bg.jpg";
	Image* background_image = Checker_LoadImage(background_image_source);

	this->_button_set[0].SetImage(background_image);
	this->_button_set[0].SetPosition(0, 0);
	this->_button_set[0].SetName("bg");
	/*
	for (int i = 1; i < 10; i++) {
		std::string button_image_source = "img\\test\\stage0\\button.png";
		Image *button_img = Checker_LoadImage(button_image_source);
		this->_button_set[i].SetImage(button_img);
		this->_button_set[i].SetPosition(0.1, 0.1);
		this->_button_set[i].SetZIndex(i);
		//
		_button_set[i].SetEventID(0);
	}*/
	/*
	int i = 1;
	std::string button_image_source = "stage\\playlist\\img\\banner-bg.png";
	Image *button_img = Checker_LoadImage(button_image_source);
	this->_button_set[i].SetImage(button_img);
	this->_button_set[i].SetPosition(0, 0);
	this->_button_set[i].SetZIndex(i);
	i++;*/

	//ㄆン砞﹚
	/**************/
	/*
	_button_set[0].SetName("bg");
	_button_set[0].SetEventID(-1);
	_button_set[1].SetEventID(0);
	*/
	/**************/
	//_scene. = _surface_background
}

Event Stage::RaiseEvent(int x, int y){
	EventID event_id = this->_event_image[y][x];
	EventParameter event_parameter = this->_event_parameter[event_id];
	if(event_id >= 0)
	//std::cout << "event " << event_id << ":" << event_parameter[0] << event_parameter[1] << "\n";
	if(event_id >= 0)
		return this->_event_function[event_id](this->_event_parameter[event_id]);
	Event no_event;
	return no_event;
}

void Stage::CleanPostImage(){
	this->_scene->CleanPostedImage();
}

void Stage::CleanEventMap(){
	for (int i = 0; i < this->_event_image.size(); i++)
		this->_event_image[i].clear();
	this->_event_image.clear();

	this->_event_image.resize(GetWindowSize().h);
	for (int i = 0; i < GetWindowSize().h; i++)
		this->_event_image[i].resize(GetWindowSize().w);

	for (int i = 0; i < GetWindowSize().h; i++)
		for (int j = 0; j < GetWindowSize().w; j++)
			this->_event_image[i][j] = -1;
}

bool ZindexSmaller(Button &left_button, Button &right_button) {	
	return left_button.GetZIndex() < right_button.GetZIndex();
}

void Stage::SortButtonSetByZIndex() {
	std::sort(this->_button_set.begin(), this->_button_set.end(), ZindexSmaller);
}