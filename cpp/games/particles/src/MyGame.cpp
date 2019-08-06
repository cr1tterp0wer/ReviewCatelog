#include "MyGame.h"


//Local_Stuff
#include "./Particles/ParticleStore.h"
ParticleStore *ps;

void MyGame::start(){
  isPlaying = true;

  ps = new ParticleStore( STORE_SIZE, xMouse, yMouse );

  prevTime = time(0);
  double dt;
  while( isPlaying )
  {
    currentTime = time(0);
    elapsedTime = currentTime - prevTime;
    dt = elapsedTime/DELAY;
    
    update( dt );
    render();

    // Add a 16msec delay to make our game run at ~60 fps
    SDL_Delay( DELAY );
  }
}

void MyGame::update( double& dt){

  ps->update( dt, xMouse, yMouse );
  processInput();
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

