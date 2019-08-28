#include "Particle.h"
#include<iostream>

using std::endl;
using std::cout;

Particle::Particle( float x, float y ){
  this->x = x;
  this->y = y;
}
Particle::~Particle(){}

void Particle::update( double& dt ){
  this->updateX( dt );
  this->updateY( dt );
  this->collisionCheck();
}

void Particle::collisionCheck(){

  if( ( this->y + this->h ) >= 400 ) {
    this->y = this->y - 1;
    this->velY = ( -1 * this->velY ) * 0.90;
  }
}

void Particle::updateX( double &dt ){
   this->x = this->x + ( this->velX * dt ) + 
             (0.5 * this->accX * dt * dt );
   this->velX = ( this->velX + ( this->accX * dt ) );
}

void Particle::updateY( double &dt ){
   this->y = this->y + ( this->velY * dt ) +
             (0.5 * this->accY * dt * dt );
   this->velY = ( this->velY + ( this->accY * dt ) );
}
void Particle::setAccy( float a ){
  this->accY = a;
}
void Particle::setAccx( float a ){
  this->accX = a;
}
void Particle::setVelX( float x ){
  this->velX = x;
} 
void Particle::setVelY( float y ){
  this->velY = y;
} 

void Particle::setH( int h ){ this->h = h;}
void Particle::setW( int w ){ this->w = w;}

int Particle::getW(){ return this->w; }
int Particle::getH(){ return this->h; }

float Particle::getX() const { return x; }
float Particle::getY() const { return y; }












