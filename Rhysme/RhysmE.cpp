#include "RhysmE.h"

//Window size setting
int WINDOW_WIDTH = 1366;
int WINDOW_HEIGHT = 768;

//.json file list(for stages currently)
std::string setting_file_list[] = {"stage\playlist\settings.json"};

//Get window size, mainly for other .cpp space,

Rect GetWindowSize() {
	Rect window_size;
	window_size.h = WINDOW_HEIGHT;
	window_size.w = WINDOW_WIDTH;
	return window_size;
}

//Constructor of main object
//TODO : read .json or .xml files to setup stages
RhysmE::RhysmE() {
	this->_main_game_window = NULL;
	this->_main_game_stage = new Stage;
	this->_main_game_stage->SetWindow(_main_game_window);
	this->_main_game_stage->InitNullBackground();
}

//Constructor of main object, and setup window, could instantly pass actual window to stage(s)
//TODO : read .json or .xml files to setup stages
RhysmE::RhysmE(Window* window) {
	this->_main_game_window = window;
	this->_main_game_stage = new Stage;
	this->_main_game_stage->SetWindow(_main_game_window);
	this->_main_game_stage->InitNullBackground();
}

//Destructor
//TODO : check that all memory is released
RhysmE::~RhysmE(){
	return;
}

//Main loop
//TODO : clean up
void RhysmE::Run() {
	//Make sure that window is successfully binded
	if (!(this->_main_game_window))
		return;
	
	Stage stage1(this->_main_game_window);
	Stage stage2(this->_main_game_window);
	stage1.TestingSetup();
	stage2.TestingSetup2();

	Ticks time = SDL_GetTicks();

	//For testing
	int FPS = 0;
	int stage_flag = 0;

	while (1) {
		//Print FPS
		FPS++;
		if (SDL_GetTicks() - time >= 1000) {
			//system("cls");
			std::cout << "FPS : " << FPS << "\n";
			time = SDL_GetTicks();
			FPS = 0;
		}

		//Put all button in current stage on screen, then put screen(should be the final result) on window
		this->_main_game_stage->PutAllButton();
		this->_main_game_stage->PutRenderImage();

		//Refresh screen
		SDL_UpdateWindowSurface(_main_game_window);

		//Controller
		//TODO : clean up and need to be improof
		SDL_Event controller_event;
		SDL_PollEvent(&controller_event);
		if (controller_event.type == SDL_MOUSEBUTTONDOWN || controller_event.type == SDL_KEYDOWN) {
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (this->_main_game_stage->RaiseEvent(x, y).GetEventType() == EVENT_JUMP_STAGE) {
				this->_main_game_stage = stage_flag ? &stage1 : &stage2;
				stage_flag = stage_flag ? 0 : 1;
			}
		}
		if (controller_event.type == SDL_KEYDOWN) {
			if (controller_event.key.keysym.sym == SDLK_ESCAPE) {
				break;
			}
			else if (controller_event.key.keysym.sym == SDLK_b) {
				this->_main_game_stage = stage_flag ? &stage1 : &stage2;
				stage_flag = stage_flag ? 0 : 1;
			}
		}

		//If want to lock FPS
		//SDL_Delay();
	}
}

int main(int argc, char* args[]) {
	//Initialize SDL 
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Error";
		return 0;
	}

	//Initialize events, should base on .json or .xml file
	//Pre define these events with index, and use GetEventList(index) to call
	InitEventList();

	//A demo that read .json file
	
	std::ifstream in_file("song0123.json");
	json json_file;
	in_file >> json_file;
	for (int i = 0;i < 30;i++) {
		std::cout << json_file["map"][std::to_string(i)] << "\n";
	}
	
	/*
	std::ifstream in_file(setting_file_list[0]);
	json stage_playlist_setting;
	in_file >> stage_playlist_setting;
	stage_playlist_setting[""];*/

	//The window we'll be rendering to
	Window* main_window = SDL_CreateWindow("RhysmE",
		SDL_WINDOWPOS_UNDEFINED, //Window position
		SDL_WINDOWPOS_UNDEFINED, //Window position
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN  //Show  window
		);

	//Make sure that window is successfully created
	if (main_window == NULL) {
		std::cout << "Window could not be created";
		return 0;
	}

	//Create main object
	RhysmE game(main_window);

	//Setup stage information (shouldn't appear at here)
	game._main_game_stage->TestingSetup();

	//Start main game loop
	game.Run();

	//Destroy window
	SDL_DestroyWindow(main_window);

	//Quit SDL subsystems
	SDL_Quit();

	return 1;
}