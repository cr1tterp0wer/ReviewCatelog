#include "Game.h"

class TriangleGame : public Game{

  public:
    TriangleGame( int w, int h ) : Game( w, h) {}

  private:
    SDL_Rect rect;
    
    void update(){
    
    }

    void render(){

        // Change color to black
        SDL_SetRenderDrawColor( renderer, 31, 31, 54, 0 );

        // Clear the window
        SDL_RenderClear( renderer );

        // Change color to green + draw rect
        SDL_SetRenderDrawColor( renderer, 240, 240, 101, 255 );
        SDL_RenderFillRect( renderer, &rect );

        // Render the changes above
        SDL_RenderPresent( renderer );
    }
};
