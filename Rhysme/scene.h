#pragma once
#include "alias.h"
#include <iostream>
#include <vector>
#include <string>
#include<map>
#include "RhysmE.h"
#include "stage.h"

class Scene {
public:
	Scene();
	Scene(Image* background);
	~Scene();
	void AddImage(Image * new_image, Rect dist);
	void AddButton(Button new_button);
	Image* GetRenderedImg();
	void CleanPostedImage();
	void CleanRenderedImage();
private:
	Image* _background;
	Image* _rendered_img;
	ImgRectLoadedMap posted_image;
};