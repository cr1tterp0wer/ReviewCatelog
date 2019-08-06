#pragma once
#include "Game.h"
#include<ctime>
#include<iostream>

using std::time_t;
using std::cout;
using std::endl;

class MyGame : public Game{

  public:
    const int STORE_SIZE = 10000;
    MyGame( int w, int h ) : Game( w, h) {}
    void start() override;

  private:
    time_t currentTime;
    time_t prevTime;
    double elapsedTime;
    SDL_Rect rect;
    bool isPlaying;
    
    void update( double& dt  ) override;
    void render() override;
    void processInput();
    void processWindowInput();

};
