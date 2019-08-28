#include "MyGame.h"

//Local_Stuff
void MyGame::start(){

  isPlaying = true;
  
  for( int i = 0; i < 100; i++ ){
    Particle p;
    this->particles.push_back( p );
  }

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
//  p->update( dt );
  for( int i = 0; i < particles.size(); i++ ){
    particles.at( i ).update( dt );
  }

  processInput();
}

void MyGame::render(){

  // Change color to black
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );

  // Clear the window
  SDL_RenderClear( renderer );

  //Create particles
  for( int i = 0; i < particles.size(); i++ ){
    SDL_Rect r;
    r.x = particles.at( i ).getX();
    r.y = particles.at( i ).getY();
    r.w = particles.at( i ).getW();
    r.h = particles.at( i ).getH();
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
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

