#include "Particle.h"
#include<iostream>
#include<random>

using std::endl;
using std::cout;

Particle::Particle(){

  std::random_device rd;
  std::mt19937 gen( rd() );
  std::uniform_real_distribution<> dis( 0, 1 );
  double r = dis( gen );

  this->x = r * 800;
  this->y = r * 400;
  this->friction = 1;
  this->velX = r;
  this->velY = r*20;
  this->accY = 0.98;
  this->accX = 0;
  this->w = 1;
  this->h = 1;
  this->elasticity = 0.90;
}

Particle::Particle( float x, float y ){
  this->x = x;
  this->y = y;
  this->friction = 0.155;
  this->velX = 0;
  this->velY = 0;
  this->accY = 0.98;
  this->accX = 0;
  this->w = 5;
  this->h = 5;
  this->elasticity = 0.90;
}
Particle::~Particle(){}

void Particle::update( double& dt ){
  this->updateX( dt );
  this->updateY( dt );
  this->collisionCheck();
  if( this->elasticity == 0 ){
    this->elasticity = 0.90;
    this->y = 0;
  }
}

void Particle::collisionCheck(){
  if( ( this->y + this->h ) >= 400 ) {
    this->y = this->y-1;

    this->velY = ( (-1 * this->elasticity) * this->velY );
    if( this->velY < 0 && this->velY > -2.8 ){
      this->elasticity = 0;
    }
  }
  if( (this->x + this->w ) >= 800 ||
      (this->x) <= 0 ){
      this->velX = ( -1 * this->velX );
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












