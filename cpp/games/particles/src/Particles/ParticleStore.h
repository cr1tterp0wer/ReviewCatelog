#pragma once
#include<vector>
#include<iostream>
#include "Particle.h"

using std::vector;
using std::cout;
using std::endl;

class ParticleStore{

  private:
    const bool GRAVITY_ON = false;
    const bool GRAVITY_REVERSE = false;
    const int UPPER_TTL = 300;
    const int LOWER_TTL = 100;
    const int P_WIDTH = 10;
    const double VELOCITY_RANGE_X = 3;
    const double VELOCITY_RANGE_Y = -4;
    const int MAX_COLOR = 256;
    vector<Particle> *particles; 

  public:
    ParticleStore( int n, int x, int y );
    virtual ~ParticleStore();

    void update( double dt, int x, int y );
    vector<Particle> getParticles();
    vector<Particle> setParticles();
    int size();
    Particle& at( int i );
    Particle buildParticle( Particle& p, int x, int y );
    Particle buildParticle( Particle& p, int x, int y, int ttl );
};
