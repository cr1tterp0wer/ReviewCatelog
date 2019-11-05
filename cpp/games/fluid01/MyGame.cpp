#include "MyGame.h"
#include<vector>

//#define IX(i,j) ((i)+(N+2)*(j))

struct Grid{
  int size;
  int color;
  int width;
  int area;
  float delta = 0.10;
  double diffuseAlpha = 0.05;
  std::vector<float> *values;
};

Grid grid;
Grid gridSecond;

//Local_Stuff
void MyGame::start(){
  gameInit();
  processWindowInput();

  double lag = 0.0;
  dt = 0; //in ms

  Uint64 currentTime = SDL_GetPerformanceCounter();
  Uint64 prevTime = currentTime;
  
  isPlaying = true;
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
  processInput();
  updateGrid( dt );
}

void MyGame::render(){

  // Change color to black
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );

  // Clear the window
  SDL_RenderClear( renderer );

  //render grid
  renderGrid();

  // Render the changes above
  SDL_RenderPresent( renderer );
}

void MyGame::gameInit(){

  gridSecond.width = grid.width = 8;
  gridSecond.area =  grid.area  = grid.width * grid.width;
  gridSecond.size = grid.size = ( SCRN_SIZE*SCRN_SIZE ) / grid.area; 
  gridSecond.color = grid.color = 100;
  gridSecond.values = grid.values = new std::vector<float>();
  gridSecond.delta =  grid.delta = 0.001;

  for( int i = 0; i < grid.size; i++ ){
    grid.values->push_back( i * grid.delta );
    gridSecond.values->push_back( i * grid.delta );
  }
}

void MyGame::updateGrid( double dt){
  diffuse( dt );
}

void MyGame::diffuse( double dt ){

  float alpha = dt * grid.diffuseAlpha * grid.size;

  for ( int i = 0; i < grid.size; i++ ){

  }

}

void MyGame::renderGrid(){

   for( int i =0; i< grid.size; i++ ){

    SDL_Rect r;
    r.x = ( grid.width * i ) % SCRN_SIZE; 
    r.y = grid.width * ( i / ( SCRN_SIZE/grid.width ) );
    r.w = grid.width;
    r.h = grid.width;
    grid.color += i;

    // Render rect
    SDL_SetRenderDrawColor( renderer, grid.color, grid.color * grid.delta, grid.color * grid.delta * i, 255 );
//    SDL_SetRenderDrawColor( renderer, grid.color, grid.color, grid.color, 255 );

    SDL_RenderFillRect( renderer, &r );
  }
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

