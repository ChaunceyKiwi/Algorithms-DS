#include "ClosestPair.hpp"

int main(void){
  Point pos[10];
  Point a,b;
  int i;
  pos[0].set_values(8.2,0.1);
  pos[1].set_values(3,4);
  pos[2].set_values(8,1);
  pos[3].set_values(4,5);
  pos[4].set_values(3,7);
  pos[5].set_values(1,9);
  pos[6].set_values(1,4);
  pos[7].set_values(3,6);
  pos[8].set_values(6,0);
  pos[9].set_values(8.5,0.5);

  closetPair(10,pos,a,b);

  cout<<"Cloest Pair is:"<<endl;
  cout<<"("<<a.getX()<<","<<a.getY()<<")"<<endl;
  cout<<"("<<b.getX()<<","<<b.getY()<<")"<<endl;
  cout<<"With distance: "<<getDistance(a,b)<<endl;

  return 0;
}
