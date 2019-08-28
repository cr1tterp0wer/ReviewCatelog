#include "ParticleStore.h"

bool posNegRand(){
  return ( rand() % 2 ); 
}

//Xf = Xo + (Vo * t) + 1/2(at^2)
//yf = Yo + (Vo * t) + 1/2(at^2)
ParticleStore::ParticleStore( int n, int x, int y ){

  particles = new vector<Particle>(n);

  for( int i = 0; i < n; i++){
    Particle p;
    particles->push_back( buildParticle( p, x, y ) );
  }
}

ParticleStore::~ParticleStore(){
  delete particles;
}

void ParticleStore::update( double dt, int x, int y ){

  for( int i = 0; i < particles->size(); i++ ){
    
    Particle& p = particles->at( i );
    if(p.isAlive){
      p.x = p.x + ( p.vx  );

      if( GRAVITY_ON ){
        if(GRAVITY_REVERSE){
          p.y = p.y + ( p.vy * p.TTL * dt ) + ( 0.5 * (-9.8) * ( p.TTL * dt) ); 
        }else{
          p.y = p.y + ( p.vy * p.TTL * dt ) + ( 0.5 * (9.8) * ( p.TTL * dt ) ); 
        }
      }else{
        p.y  = p.y + ( p.vy );
      }

      p.TTL++;
      if( p.TTL >=  UPPER_TTL  ){
        p.isAlive = false;
      }
    }else{
       buildParticle( p, x, y );
    }
  }
}

Particle ParticleStore::buildParticle( Particle& p ,int  x,int y ){

    p.isAlive = true;
    p.TTL = ( rand() % 
           ( UPPER_TTL - LOWER_TTL + 1) ) + LOWER_TTL;
    p.width   = P_WIDTH;

    p.color[0] = ( std::rand() % ( MAX_COLOR + 1 ) );   
    p.color[1] = ( std::rand() % ( MAX_COLOR + 1 ) );   
    p.color[2] = ( std::rand() % ( MAX_COLOR + 1 ) );

    p.x = x;
    p.y = y;
    p.vx = ( posNegRand() ) ? (-1) * ( (double) rand() / RAND_MAX ) : (double) rand()/RAND_MAX; 
    p.vy = ( posNegRand() ) ? (-1) * ( (double) rand() / RAND_MAX ) : (double) rand()/RAND_MAX; 
    p.vx = p.vx * VELOCITY_RANGE_X;
    p.vy = p.vy * VELOCITY_RANGE_Y;
    return p;
}

Particle ParticleStore::buildParticle( Particle& p ,int  x,int y, int ttl ){

    p.isAlive = true;
    p.TTL     = ttl;
    p.width   = P_WIDTH;

    p.color[0] = ( std::rand() % ( MAX_COLOR + 1 ) );   
    p.color[1] = ( std::rand() % ( MAX_COLOR + 1 ) );   
    p.color[2] = ( std::rand() % ( MAX_COLOR + 1 ) );

    p.x = x;
    p.y = y;
    p.vx = ( posNegRand() ) ? (-1) * ( (double) rand() / RAND_MAX ) : (double) rand()/RAND_MAX; 
    p.vy = ( posNegRand() ) ? (-1) * ( (double) rand() / RAND_MAX ) : (double) rand()/RAND_MAX; 
    p.vx = p.vx * VELOCITY_RANGE_X;
    p.vy = p.vy * VELOCITY_RANGE_Y;
    return p;
}

Particle& ParticleStore::at( int i ){
  return particles->at( i );
}

int ParticleStore::size(){
  return particles->size();
}
