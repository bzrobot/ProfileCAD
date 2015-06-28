#include "application.h"
#include "Config.h"
#include "Engine.h"

int ActiveTool;
//Tools
#define NoTool 0
#define LineTool 1
//LineTool
int LineClickStep = 0;
float LineStart[2];
float LineEnd[2];
float TmpPos[2];
float MousePos[2];
float RealMousePos[2];
float LastMouseScrollPos[2];
float LastRealMousePos[2];
float PanDistance[2];
float VirtualOrigin[2]; //0,0 in Real Cordinant plane
char XYBuff[100];
char ResizeBuff[100];
std::string MsgBuff = "";
std::string inputText = "";
Engine *engine=NULL;
Config *config=NULL;
time_t MsgTimer=NULL;
int MsgDuration = 1500; //ms
double timer_diff_ms;

int main (int argc, char** argv)
{
    if (TTF_Init() != 0)
    {
      printf("SDL_ttf Error!\n");
      SDL_Quit();
      return 1;
    }
    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        WindowTitle, SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        DefaultWindowWidth,
        DefaultWindowHeight,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    SDL_Renderer* renderer = NULL;
    SDL_Renderer* screen = NULL;
    renderer =  SDL_CreateRenderer( window, 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

		config = new Config(window, renderer);
		engine = new Engine(window, renderer, config);

    SDL_Event e;
		bool quit = false;
		while (!quit)
		{
      engine->GetMousePos(MousePos);
      engine->GetRealXY(RealMousePos, MousePos);
      sprintf(XYBuff, "X: %lf, Y: %lf, rX: %lf, rY: %lf", MousePos[0], MousePos[1], RealMousePos[0], RealMousePos[1]);

      SDL_StartTextInput();
      //SDL_StopTextInput();
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				if (e.type == SDL_WINDOWEVENT)
				{
					if (e.window.event == SDL_WINDOWEVENT_RESIZED)
					{
						engine->UpdateWindowSize(e.window.data1, e.window.data2);
            //sprintf(ResizeBuff, "H: %d, W: %d", e.window.data1, e.window.data2);
            //engine->PutTexture(engine->MakeText(ResizeBuff, 8), 10, 10);
					}
				}
        if (e.type == SDL_TEXTINPUT)
        {
          if( !( ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' ) && ( e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )
          {
                if (inputText == "")
                {
                  inputText = ":";
                }
                inputText += e.text.text;
          }
        }
				if (e.type == SDL_KEYDOWN)
				{
          if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
          {
            //lop off character]
            if (inputText != ":")
            {
              inputText.pop_back();
            }
            if (inputText == ":")
            {
              inputText = "";
            }
          }
          else if( e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
          {
            SDL_SetClipboardText( inputText.c_str() );
          }
          //Handle paste
          else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
          {
            inputText = SDL_GetClipboardText();
          }
          if (e.key.keysym.scancode == SDL_SCANCODE_UP)
					{
							engine->PanIncY(-10);

					}
					if (e.key.keysym.scancode == SDL_SCANCODE_DOWN)
					{
							engine->PanIncY(+10);

					}
					if (e.key.keysym.scancode == SDL_SCANCODE_LEFT)
					{
							engine->PanIncX(-10);

					}
					if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					{
							engine->PanIncX(+10);

					}
          if (e.key.keysym.scancode == SDL_SCANCODE_RETURN)
					{
							//printf("Input: %s\n", inputText.c_str());
							if (inputText.find(":file") != std::string::npos)
							{
								std::string file = trim(inputText.substr(5, inputText.length()));
								config->Filename = strdup(file.c_str());
								//engine->Open();
								//MsgBuff = ">Opened " + file;
							}
              if (inputText.find(":ac") != std::string::npos)
							{
                MsgTimer = time(0);
								std::size_t cXp = inputText.find("x");
								std::size_t cYp = inputText.find("y");
                std::size_t Rp  = inputText.find("r");

								std::string cX = inputText.substr(cXp+1, (cYp - cXp) -1);
								std::string cY = inputText.substr(cYp+1, (Rp - cYp)-1);
								std::string R = inputText.substr(Rp+1, (inputText.length() - Rp)-1);
                MsgBuff = ">Drew Arc cX: " + cX + " cY: " + cY + " R: " + R;
                engine->ArcByCenter(atof((char *)cX.c_str()), atof((char *)cY.c_str()), atof((char *)R.c_str()));
              }
							if (inputText.find(":l") != std::string::npos)
							{
								MsgTimer = time(0);
								std::size_t FirstX = inputText.find("x");
								std::size_t FirstY = inputText.find("y");
								std::size_t LastX = inputText.find("x", FirstX+1);
								std::size_t LastY = inputText.find("y", FirstY+1);
								std::string X1 = inputText.substr(FirstX+1, (FirstY-FirstX)-1);
								std::string Y1 = inputText.substr(FirstY+1, (LastX - FirstY) -1);
								std::string X2 = inputText.substr(LastX+1, (LastY - LastX)-1);
								std::string Y2 = inputText.substr(LastY+1, (inputText.length() - LastY)-1);


								if (X1 != inputText && X2 != inputText && Y1 != inputText && Y2 != inputText)
								{
									LineStart[0] = atof((char*)X1.c_str());
									LineStart[1] = atof((char*)Y1.c_str());
									LineEnd[0] = atof((char*)X2.c_str());
									LineEnd[1] = atof((char*)Y2.c_str());
									engine->Line(LineStart, LineEnd);
									MsgBuff = ">Drew Line X1: " + X1 + " Y1: " + Y1 + " X2: " + X2 + " Y2: " + Y2;
								}
								else if (X2 == inputText && Y2 == inputText)
								{
									LineStart[0] = atof((char*)X1.c_str());
									LineStart[1] = atof((char*)Y1.c_str());
									LineClickStep = 1;
									ActiveTool = LineTool;
									MsgBuff = ">Added Line X1: " + X1 + " Y1: " + Y1 + " => Click at Endpoint";
								}
								else if (ActiveTool == NoTool)
								{
										MsgBuff = ">Line Tool Active";
										ActiveTool = LineTool;
								}
								else
								{
									MsgBuff = ">Line Tool Inctive";
									ActiveTool = NoTool;
								}

							}
              inputText="";
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_S && SDL_GetModState() & KMOD_CTRL)
					{
							//engine->Save();
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_O && SDL_GetModState() & KMOD_CTRL)
					{
							//engine->Open();
					}
					if (e.key.keysym.sym == SDLK_n && SDL_GetModState() & KMOD_CTRL)
					{
						//config->Color((char *)"Black");
						//SDL_RenderClear(renderer);
						//engine->Trash();
						//printf("====> Deleted current changes!\n");
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						printf("====> Bye!\n");
						quit = true;
					}
				}
				if (e.type == SDL_MOUSEWHEEL)
				{

          if (e.wheel.y > 0)
          {
              //printf("> ZoomIn ++ %f\n", engine->ZoomIn());
              engine->ZoomIn();
          }
          else
          {
              //printf("> ZoomOut ++ %f\n", engine->ZoomOut());
              engine->ZoomOut();
          }
					//printf("\rX: %lf, Y: %lf |||||| rX: %lf, rY: %lf\0", MousePos[0], MousePos[1], RealMousePos[0], RealMousePos[1]);
				}
				if (e.type == SDL_MOUSEBUTTONUP)
				{
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						printf("=====> Left Click!\n");
            int id = engine->GetCurserOverId(); //Remember that this resets the id buffer!
            if (id != -1)
            {
              printf("Clicked on Entity with ID: %d\n", id);
            }
						if (ActiveTool == LineTool)
						{
							if (LineClickStep == 1)
							{
								engine->GetMousePos(LineEnd);
								engine->Line(LineStart, LineEnd);
								printf("\t> Line End ==== x: %lf y: %lf\n", engine->GetX(LineStart), engine->GetY(LineEnd));
								LineClickStep = 0;
							}
							else if (LineClickStep == 0)
							{
								engine->GetMousePos(LineStart);
								LineClickStep = 1;
								printf("\t> Line Start ==== x: %lf y: %lf\n", (float) engine->GetX(LineStart), (float) engine->GetY(LineEnd));
							}
						}
					}
				}
			//printf("Physical %s key acting as %s key\n", SDL_GetScancodeName(e.key.keysym.scancode), SDL_GetKeyName(e.key.keysym.sym));
		}
    //Begin Render -- quick in, quick out!
    config->Color(config->BackgroundColor); //Background color
    SDL_RenderClear(renderer);
    engine->PutTexture(engine->MakeText(XYBuff, 8), 10, 10);
    timer_diff_ms = difftime(time(0), MsgTimer) * 1000.;
    //if (timer_diff_ms < MsgDuration)
    if (MsgBuff != "")
    {
      engine->PutTexture(engine->MakeColorText(config->ColorGreen, (char *)MsgBuff.c_str(), 8), 10, (engine->WindowHeight - 25));
    }
    if (inputText != "")
    {
      engine->PutTexture(engine->MakeText((char *)inputText.c_str(), 12), 10, (engine->WindowHeight - 50));
    }
    engine->UpdateScreen();
    SDL_RenderPresent( renderer );
    //usleep(10);
    //End Render
      //SDL_RenderPresent( renderer );
			//fflush(stdout);
		}
    config->SaveConfig();
    engine->UnInit();
		delete engine;
		SDL_RenderClear(renderer);
		SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
