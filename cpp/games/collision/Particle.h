
class Particle{

  private:
    float x;
    float y;
    float velX;
    float velY;
    float accX;
    float accY;
    float elasticity;
    float friction;
    int w;
    int h;
    
    void updateX( double &dt );
    void updateY( double &dt );
    
  public:
    Particle();
    Particle( float x, float y );
    virtual ~Particle();

    void update( double &dt );
    void collisionCheck();

    float getX() const;
    float getY() const;

    void setAccy( float a );
    void setAccx( float a );
    void setVelX( float x );
    void setVelY( float y );
    void setH( int h );
    void setW( int w );
    int getW();
    int getH();

};
