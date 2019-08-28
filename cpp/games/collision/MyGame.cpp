#include "MyGame.h"

//Local_Stuff
void MyGame::start(){

  isPlaying = true;
  p = new Particle( 0, 0 );
  p->setAccx( 0 );
  p->setAccy( 0.98 );
  p->setVelX( 0 );
  p->setVelY( 0 );
  p->setW( 50 );
  p->setH( 50 );

  processWindowInput();

  Uint64 currentTime = SDL_GetPerformanceCounter();
  Uint64 prevTime = currentTime;
  dt = 0; //in ms
  
  double lag = 0.0;
  
  while( isPlaying )
  {
    currentTime = SDL_GetPerformanceCounter();
    dt = (double)( ( ( currentTime - prevTime ) * 1000 ) / ( (double)SDL_GetPerformanceFrequency() ) );
    prevTime = currentTime;
    lag += dt;
    
    //Looped render cycle to combat lag
    while( lag >= MS_UPDATE_TIME ){
      double deltaLag = ( lag / MS_UPDATE_TIME ); //good enough
      update( deltaLag );
      lag -= MS_UPDATE_TIME;
    }
    
    render();
  }
}

void MyGame::update( double& dt){
  p->update( dt );
  processInput();
}

void MyGame::render(){

  // Change color to black
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );

  // Clear the window
  SDL_RenderClear( renderer );

  //Create a square
  SDL_Rect r;
  r.x = p->getX();
  r.y = p->getY();
  r.w = 50.0;
  r.h = 50.0;
  SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
  SDL_RenderFillRect( renderer, &r );

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

