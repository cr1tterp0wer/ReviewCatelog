#include "MyGame.h"


//Local_Stuff
#include "./Particles/ParticleStore.h"
ParticleStore *ps;

void MyGame::start(){
  isPlaying = true;

  processWindowInput();
  ps = new ParticleStore( STORE_SIZE, xMouse, yMouse );

  Uint64 currentTime = SDL_GetPerformanceCounter();
  Uint64 prevTime = 0;
  dt = 0;
  
  while( isPlaying )
  {
    currentTime = prevTime;
    currentTime = SDL_GetPerformanceCounter();
    dt = (double)((currentTime - prevTime ) * 1000 / (double)SDL_GetPerformanceFrequency() );
    dt = dt/1000;
    update( dt );
    render();

    SDL_Delay( DELAY );
    prevTime = currentTime;
  }
}

void MyGame::update( double& dt){

  processInput();
  ps->update( dt, xMouse, yMouse );
}

void MyGame::render(){

  // Change color to black
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );

  // Clear the window
  SDL_RenderClear( renderer );

  // Change color to green + draw rect
  
  for( int i =0; i< ps->size(); i++ ){
    SDL_Rect r;
    r.x = ps->at( i ).x;
    r.y = ps->at( i ).y;
    r.w = ps->at( i ).width;
    r.h = r.w;

    // Render rect
    SDL_SetRenderDrawColor( renderer, ps->at( i ).color[0], ps->at( i ).color[1], ps->at( i ).color[2], 255 );
    SDL_RenderFillRect( renderer, &r );
  }

  // Render the changes above
  SDL_RenderPresent( renderer );
}

void MyGame::processInput(){

  processWindowInput();
}

void MyGame::processWindowInput(){
  SDL_Event e;
  while( SDL_PollEvent( &e ) > 0 ){
    switch(e.type){
      case SDL_QUIT:
        isPlaying = false;
        break;
      case SDL_MOUSEMOTION:
        SDL_GetMouseState(&xMouse,&yMouse);
        break;
    }
  }
}

