#pragma once
#include "Game.h"
#include<iostream>

using std::cout;
using std::endl;

class MyGame : public Game{

  public:
    const int STORE_SIZE = 100;
    MyGame( int w, int h ) : Game( w, h) {}
    void start() override;

  private:
    Uint64 currentTime;
    Uint64 prevTime;
    double dt;
    SDL_Rect rect;
    bool isPlaying;
    
    void update( double& dt  ) override;
    void render() override;
    void processInput();
    void processWindowInput();

};
