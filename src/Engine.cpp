#include "Engine.h"

Engine::Engine(SDL_Window* w, SDL_Renderer* _r, Config *c, int _WindowWidth, int _WindowHeight)
{
	//memcpy(config->Filename, File, sizeof(*File));
	EntityArraySize = 0;
	EntityArray = (SDL_Texture	**)malloc(sizeof(SDL_Texture	*));

	ViewRatio = 0.05;
	r = _r;
	window = w;
	WindowWidth = _WindowWidth;
	WindowHeight = _WindowHeight-150;
	OriginOffsetX = (_WindowWidth/2); //Center Origin
	OriginOffsetY = (_WindowHeight/2); //Center Origin
	config = c;
	config->UpdateWindowSize(WindowWidth, WindowHeight);
	//printf("==> Writing to %s\n", config->Filename);
}
void Engine::UpdateWindowSize(int w, int h)
{
	WindowWidth = w;
	WindowHeight = h;
	config->UpdateWindowSize(w, h);
}
void Engine::GetWindowSize(int w, int h)
{
	w = WindowWidth;
	w = WindowHeight;
}
void Engine::GetMousePos(float out[2])
{
	int x, y;
	SDL_GetMouseState(&x, &y);
 	//out[0] = (x - OriginOffsetX);
	//out[1] = ((y - OriginOffsetY)/-1);
	float in[2];
	in[0] = x;
	in[1] = y;
	GetXY(out, in);
}
void Engine::PanXY(float pos[2])
{
	OriginOffsetX = (WindowWidth - pos[0]) / 2; //Center Origin
	OriginOffsetY = (WindowHeight - pos[1]) / 2; //Center Origin
}
void Engine::PanIncX(float p)
{
	OriginOffsetX = OriginOffsetX + p;
}
void Engine::PanIncY(float p)
{
	OriginOffsetY = OriginOffsetY + p;
}
float Engine::ZoomIn()
{
	ViewRatio = ViewRatio - .001;
	return ViewRatio;
}
float Engine::ZoomOut()
{
	ViewRatio = ViewRatio + .001;
	return ViewRatio;
}
void Engine::GetDistance(float out, float p1[2], float p2[2])
{
	out = sqrt(pow((p2[0] - p1[0]), 2) + pow((p2[1] - p1[1]), 2));
}
void Engine::GetRealXY(float out[2], float in[2])
{
	out[0] = ((in[0] / ViewRatio) + OriginOffsetX);
	out[1] = (-1*((in[1] / ViewRatio) - OriginOffsetY));
}
void Engine::GetXY(float out[2], float in[2])
{
	out[0] = ((in[0] - OriginOffsetX) * ViewRatio);
	out[1] = (((in[1] - OriginOffsetY)/-1) * ViewRatio);
}
float Engine::GetX(float in[2])
{
	float out[2];
	GetXY(out, in);
	return out[0];
}
float Engine::GetY(float in[2])
{
	float out[2];
	GetXY(out, in);
	return out[1];
}
void Engine::Line(float Start[2], float End[2])
{
	float screen_point1[2];
	float screen_point2[2];

	GetRealXY(screen_point1, Start);
	GetRealXY(screen_point2, End);

	SDL_Texture *texture = SDL_CreateTexture(r, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WindowWidth, WindowHeight);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(texture, 255); //Make texture clear
	SDL_SetRenderTarget( r, texture );
	SDL_SetRenderDrawColor( r, 0, 0, 0, 0 ); //Make texture clear
	SDL_RenderClear(r);
	config->Color((char*)config->LineColor);
	SDL_RenderDrawLine(r, screen_point1[0], screen_point1[1], screen_point2[0], screen_point2[1]);
	SDL_RenderPresent( r );
	SDL_SetRenderTarget( r, NULL );
	//EntityArray[EntityArraySize] = (SDL_Texture	*)malloc(sizeof(SDL_Texture	*));
	if (EntityArraySize > 0)
	{
			EntityArray = (SDL_Texture	**)realloc(EntityArray, sizeof(SDL_Texture	*)*(EntityArraySize+1));
	}
	EntityArray[EntityArraySize] = texture;
	EntityArraySize++;
}
const char* Engine::GetField(char* line, int num)
{
    const char* tok;
		char *str = strdup(line);
    for (tok = strtok(str, ":"); tok && *tok; tok = strtok(NULL, ":\n"))
    {
        if (!--num)
				{
					free(str);
					return tok;
				}
    }
		free(str);
    return "";
}
SDL_Texture* Engine::MakeText(char *Text, int Size)
{
	return MakeColorText(config->ColorWhite, Text, Size);
}
SDL_Texture* Engine::MakeColorText(SDL_Color Color, char *Text, int Size)
{

	TTF_Font *font = TTF_OpenFont(config->Font, Size);
	if (font == nullptr){
		printf("Cant open font %s\n", config->Font);
		return nullptr;
	}
	//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Surface *surf = TTF_RenderText_Blended(font, Text, Color);
	if (surf == nullptr){
		TTF_CloseFont(font);
		printf("Error rendering text\n");
		return nullptr;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(r, surf);
	if (texture == nullptr){
		printf("Error creating surface\n");
	}
	//Clean up the surface and font
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}
void Engine::PutTexture(SDL_Texture *t, float x, float y)
{
	SDL_Rect texture_rect;
	int w, h;
	SDL_QueryTexture(t, NULL, NULL, &w, &h);
	texture_rect.x = x;  //the x coordinate
	texture_rect.y = y; // the y coordinate
	texture_rect.w = w; //the width of the texture
	texture_rect.h = h; //the height of the texture
	SDL_RenderCopy(r, t, NULL, &texture_rect);

}
void Engine::UpdateScreen()
{
	printf("EntityCount: %d\r", EntityArraySize);
	int x;
	for(x = 0; x < EntityArraySize; x++)
	{
			if (EntityArray[x] != NULL)
			{
				SDL_Texture *t = EntityArray[x];
				PutTexture(t, 0, 0);
			}
			else
			{
				printf("\t====> Entity %d is corrupt\n", x);
			}
			//printf("Puting Texture: %d\n", x);
	}
}
void Engine::UnInit()
{
	//g_slist_free(Entitys);
	//g_slist_free(SelectedEntitys);
	int i;
	/*for(i=0;i<EntityArraySize; i++)
  	free(EntityArray[i]);
	free(EntityArray);*/
	delete config;
}
