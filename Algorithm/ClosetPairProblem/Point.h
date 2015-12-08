#include <math.h>

class Point{
  float x, y;
public:
  void set_values (float,float);
  float distanceFromOrigin();
  float getX() {return x;}
  float getY() {return y;}

};

void Point::set_values(float set_x,float set_y){
  x = set_x;
  y = set_y;
}

float Point::distanceFromOrigin(){
  return sqrt(x*x + y*y);
}
