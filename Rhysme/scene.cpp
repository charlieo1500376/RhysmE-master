#include "scene.h"


Scene::Scene(){
	_rendered_img = SDL_CreateRGBSurface(0, GetWindowSize().w, GetWindowSize().h, 32, 0x00, 0x00, 0x00, 0x00);
}

Scene::Scene(Image * background){
	this->_background = background;
	SDL_BlitSurface(this->_background, NULL, this->_rendered_img, NULL);
}

Scene::~Scene() {
}

void Scene::AddImage(Image * new_image, Rect dist) {
	//Easy scale
	/*dist.h *= 0.5;
	dist.w *= 0.5;*/
	if (posted_image[new_image][dist.x][dist.y] == true) {
		return;
	}
	else {
		//SDL_BlitSurface(new_image, NULL, this->_rendered_img, &dist);
		SDL_BlitScaled(new_image, NULL, this->_rendered_img, &dist);
		posted_image[new_image][dist.x][dist.y] = true;
	}
}

void Scene::AddButton(Button new_button) {
	Rect output_rect;
	output_rect.x = new_button.GetRect().x;
	output_rect.y = new_button.GetRect().y;
	SetImageOpacity(new_button.GetImage(), 0.5);
	
	if (posted_image[new_button.GetImage()][output_rect.x][output_rect.y] == true) {
		return;
	}

	float window_h = GetWindowSize().h;
	float window_w = GetWindowSize().w;

	if (new_button.GetName() == "bg") {
		output_rect.h = new_button.GetRect().h;
		output_rect.w = new_button.GetRect().w;

		if (output_rect.h > window_h && output_rect.w > window_w) {
			output_rect.h = window_h;
			output_rect.w = window_w;
		}
		else {
			if (output_rect.h < window_h) {
				output_rect.w *= window_h / output_rect.h;
				output_rect.h = window_h;
			}
			if (output_rect.w < window_w) {
				output_rect.h *= window_w / output_rect.w;
				output_rect.w = window_w;
			}
		}
		
	}
	else {
		output_rect.h = new_button.GetRect().h * GetWindowSize().h / STANDARD_WINDOW_HEIGHT;
		output_rect.w = new_button.GetRect().w * GetWindowSize().w / STANDARD_WINDOW_WIDTH;
	}
	//SDL_BlitSurface(new_image, NULL, this->_rendered_img, &dist);
	SDL_BlitScaled(new_button.GetImage(), NULL, this->_rendered_img, &output_rect);
	posted_image[new_button.GetImage()][output_rect.x][output_rect.y] = true;

}

Image * Scene::GetRenderedImg()
{
	return this->_rendered_img;
}

void Scene::CleanPostedImage(){
	this->posted_image.clear();
	//SDL_FreeSurface(_rendered_img);
	//_rendered_img = SDL_CreateRGBSurface(0, GetWindowSize().w, GetWindowSize().h, 32, 0x00, 0x00, 0x00, 0x00);
}

void Scene::CleanRenderedImage(){
	SDL_FreeSurface(_rendered_img);
	_rendered_img = SDL_CreateRGBSurface(0, GetWindowSize().w, GetWindowSize().h, 32, 0x00, 0x00, 0x00, 0x00);
}
