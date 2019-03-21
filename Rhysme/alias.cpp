#include "alias.h"

void SetImageOpacity(Image * image, float opacity){
	if (opacity > 1)
		opacity = 1;
	else if (opacity < 0)
		opacity = 0;
	SDL_SetSurfaceAlphaMod(image, opacity * 255);
}
