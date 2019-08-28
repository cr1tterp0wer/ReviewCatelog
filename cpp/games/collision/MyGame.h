#pragma once
#include "Game.h"
#include "Particle.h"
#include<iostream>
#include<vector>

using std::cout;
using std::endl;

class MyGame : public Game{

  public:
    MyGame( int w, int h ) : Game( w, h) {}
    void start() override;

  private:
    const double MS_UPDATE_TIME = 16;
    Uint64 currentTime;
    Uint64 prevTime;
    double dt;
    SDL_Rect rect;
    bool isPlaying;
    std::vector<Particle> particles;

    void update( double& dt  ) override;
    void render() override;
    void processInput();
    void processWindowInput();

};
