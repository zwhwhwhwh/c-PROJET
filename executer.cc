#include <SDL.h>        
#include <SDL_image.h>        
#include <SDL_ttf.h>        
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "color.hh"
#include "RGB.hh"
#include "HSV.hh"
#include "Plus.hh"
#include "Complementaire.hh"
#include "TriColor.hh"
#include "RandomColor.hh"
#include "ColorBoard.hh"

using namespace std;

const SDL_Color colTxt = {0,0,0};

int main(int argc, char ** argv){

  int quit = 0;
  SDL_Event event;
  int mx,my;

  RandomColor ran;
 
  //initialiser les valeurs
  char* getrgb[]={(char*)(ran.getX()),(char*)(ran.getX()),(char*)(ran.getX())};
  const char* hex = (char*)(ran.hexadecimal()).c_str();
  cout<<hex<<endl;
  stringstream s;s<<hex;
  Complementaire com(ran);
  char* comrgb[] = {(char*)(com.getX()),(char*)(com.getX()),(char*)(com.getX())};
  vector<size_t> vec = ran.toHSV();
  char* gethsv[] = {(char*)vec[0],(char*)vec[1],(char*)vec[2]};
  ColorBoard board(ran);
  vector<vector<size_t>> vb = board.tocolorBoard();
  /*
  RGB* b=new RGB[5];
  for(size_t i=0;i<5;i++){
    RGB r0(vb[i][0],vb[i][0],vb[i][0]);
    b[i] = r0;
  }
  */

  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
 
  SDL_Window * window = SDL_CreateWindow("Colorful",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  TTF_Font* Sans = TTF_OpenFont("sans.ttf", 15);  
  
  SDL_SetRenderDrawColor(renderer, 255, 230, 230, 230);
  SDL_Rect rect = {0, 0, 1024, 768}; //start_x,start_y,width,deep
  SDL_RenderFillRect(renderer, &rect);

  //afficher la couleur random
  SDL_SetRenderDrawColor(renderer, ran.getX(), ran.getY(), ran.getZ(), 230);
  rect = {510, 150, 400, 300};
  SDL_RenderFillRect(renderer, &rect);


  //afficher le boutton 'afficher'
  SDL_Rect Message_rect; //create a rect
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "afficher", colTxt);
  SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  Message_rect.x = 600;  
  Message_rect.y = 540; // controls the rect's y coordinte
  Message_rect.w = (surfaceMessage->w)*2; // controls the width of the rect
  Message_rect.h = (surfaceMessage->h)*2; // controls the height of the rect
  SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

  //afficher complementaire
  surfaceMessage = TTF_RenderText_Solid(Sans, "Complementaire:", colTxt);
  Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  Message_rect.x = 100;  
  Message_rect.y = 150; // controls the rect's y coordinte
  SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

  //afficher "ColorBoard"
  surfaceMessage = TTF_RenderText_Solid(Sans, "ColorBoard:", colTxt);
  Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  Message_rect.x = 100;
  Message_rect.y = 450;
  SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
  
  //afficher "random colors"
  surfaceMessage = TTF_RenderText_Solid(Sans, "Random Color:", colTxt);
  Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  Message_rect.x = 510;  
  Message_rect.y = 100; // controls the rect's y coordinte
  Message_rect.w = (surfaceMessage->w)*2; // controls the width of the rect
  Message_rect.h = (surfaceMessage->h)*2; // controls the height of the rect

  SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
  SDL_DestroyTexture(Message);
  SDL_FreeSurface(surfaceMessage);

  while (!quit){
    
    /* Etape 1: RECUPERER LES EVENEMENTS */
    if (SDL_PollEvent(&event)){
      //printf("un event\n");
      switch (event.type){
      case SDL_QUIT:
	quit = 1;
	break;
	   
      case  SDL_MOUSEBUTTONDOWN:
	SDL_GetMouseState( &mx, &my );
	printf("mx=%d my=%d\n",mx,my);
				
	break;
      }
    }

    //METTRE A JOUR l'ETAT DE L'APPLICATION GRAPHIQUE
    if ((mx>=600) && (mx<=700) && (my>=540) && (my<=590)){

      SDL_SetRenderDrawColor(renderer, com.getX(), com.getY(), com.getZ(), 230);
      rect = {150, 250, 200, 100}; 
      SDL_RenderFillRect(renderer, &rect);

      for(int i=0;i<5;i++){
	SDL_SetRenderDrawColor(renderer, vb[i][0], vb[i][1], vb[i][2], 230);
	rect = {150+i*100, 600, 100, 50}; 
	SDL_RenderFillRect(renderer, &rect);
      }
    }

    SDL_RenderPresent(renderer);

  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
 
  SDL_Quit();

  //delete[]b;


  return 1;

}
