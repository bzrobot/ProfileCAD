#ifndef _Engine_
#define _Engine_
#include "application.h"


#ifndef _Config_
#include "Config.h"
#endif

class Engine                // begin declaration of the class
{
	public:                    // begin public section
	float OriginOffsetX;
	float OriginOffsetY;
	float ViewRatio;
	int WindowWidth;
	int WindowHeight;
	SDL_Window* window;
	SDL_Renderer* r;
	GSList *Entitys;
	GSList *SelectedEntitys;
	Config *config;

	Engine(SDL_Window* w, SDL_Renderer* _r, Config *c, int _WindowWidth, int _WindowHeight);     // constructor
	const char* GetField(char* line, int num);
	void UpdateWindowSize(int w, int h);
	void GetWindowSize(int w, int h);
	void GetRealXY(float out[2], float in[2]); //Get Screen Cordinant plane fron Virtual Cordinant plane
	void GetXY(float out[2], float in[2]); //Get Virtual Cordinant plane from Screen Cordinant plane
	float GetX(float in[2]); //GetXY Wrapper Function
	float GetY(float in[2]); //GetXY Wrapper Function
	void GetMousePos(float out[2]); //Returns Virtual Cordinant plane
	void Line(float Start[2], float End[2]);
	void Push(char *line); //Pushes Entitys to memmory
	void Pull(); //Pulls entitys from memory
	void Save(); //Copys entitys from memory to file
	void Open(); //Copys entitys from file to memory and updates screen
	void Trash();
	float ZoomIn();
	float ZoomOut();
	void PanIncX(float p);
	void PanIncY(float p);
	void PanXY(float pos[2]);
	void GetDistance(float out, float p1[2], float p2[2]);
	SDL_Texture* MakeText(char *Text, int Size);
	SDL_Texture* MakeColorText(SDL_Color Color, char *Text, int Size);
	void PutTexture(SDL_Texture* t, float x, float y);
	void UpdateScreen();
	void UnInit();
};



#endif /* _Engine_ */
