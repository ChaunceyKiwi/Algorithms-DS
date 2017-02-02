#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <float.h>
#include "Point.h"
using namespace std;
#define maximumPoints 30  //The maximum number of points

//Swap Points
void swap(Point &a,Point &b){
    Point temp;
    temp.set_values(a.getX(),a.getY());
    a.set_values(b.getX(),b.getY());
    b.set_values(temp.getX(),temp.getY());
}

//Sort Point by X value
void quickSortByX(Point* arr,int left,int right){
    int pivot;
    int wall = left; //wall is on the left of current index
    int current = left;

    if (left >= right)
        return;
    else if (left == right - 1){
        if(arr[left].getX() > arr[right].getX()){
            swap(arr[left],arr[right]);
        }
        return;
    }

    pivot = right;
    while(current < right){
        if(arr[pivot].getX() > arr[current].getX()){
            swap(arr[current],arr[wall]);
            wall++;
        }
        current++;
    }
    swap(arr[wall],arr[pivot]);
    quickSortByX(arr, left, wall - 1);
    quickSortByX(arr, wall + 1, right);
}

//Sort Point by Y value
void quickSortByY(Point* arr,int left,int right){
    int pivot;
    int wall = left; //wall is on the left of current index
    int current = left;

    if (left >= right)
        return;
    else if (left == right - 1){
        if(arr[left].getY() > arr[right].getY()){
            swap(arr[left],arr[right]);
        }
        return;
    }

    pivot = right;
    while(current < right){
        if(arr[pivot].getY() > arr[current].getY()){
            swap(arr[current],arr[wall]);
            wall++;
        }
        current++;
    }
    swap(arr[wall],arr[pivot]);
    quickSortByY(arr, left, wall - 1);
    quickSortByY(arr, wall + 1, right);
}

//Get the distance betweem Point a and Point b
float getDistance(Point a, Point b){
  float x_vary = a.getX() - b.getX();
  float y_vary = a.getY() - b.getY();
  return sqrt(x_vary * x_vary + y_vary * y_vary);
}

//Find cloestPair, the pair will return as a and b
void closetPair(int number,Point* pos,Point &a,Point &b){
  if(number == 0 || number == 1)
    cout<<"Input wrongly!"<<endl;
  else if(number == 2){
    a = pos[0];
    b = pos[1];
  }else if(number == 3){
    float distance1 = getDistance(pos[0],pos[1]);
    float distance2 = getDistance(pos[0],pos[2]);
    float distance3 = getDistance(pos[1],pos[2]);
    if(distance1 <= distance2 && distance1 <= distance3){
      a = pos[0];
      b = pos[1];
    }else if(distance2 <= distance1 && distance2 <= distance3){
      a = pos[0];
      b = pos[2];
    }else if(distance3 <= distance1 && distance3 <= distance2){
      a = pos[1];
      b = pos[2];
    }
  }else{
      int i;
      int count = 0;
      Point q0,q1,r0,r1;
      Point PointSortedByX[maximumPoints];
      Point PointSortedByY[maximumPoints];
      Point PointInRange[maximumPoints];
      for(i = 0;i < number;i++){
        PointSortedByX[i].set_values(pos[i].getX(),pos[i].getY());
        PointSortedByY[i].set_values(pos[i].getX(),pos[i].getY());
      }
      quickSortByX(PointSortedByX,0,number - 1);
      quickSortByY(PointSortedByY,0,number - 1);

      closetPair(number / 2,PointSortedByX,q0,q1);
      closetPair(number - number / 2,PointSortedByX + number / 2,r0,r1);

      float L = PointSortedByX[number/2 - 1].getX();

      float delta = min(getDistance(q0,q1),getDistance(r0,r1));

      for(i = 0;i < number;i++){
        if(pow((PointSortedByX[i].getX() - L),2) < pow(delta,2)){
        PointInRange[count].set_values(PointSortedByX[i].getX(),PointSortedByX[i].getY());
        count++;
        }
      }
      PointInRange[count].set_values(FLT_MAX,FLT_MAX);

      float min = FLT_MAX;
      float distanceTemp;
      int record_count,record_i;
      count = 0;
      while(PointInRange[count].getX() != FLT_MAX){
        for(i = 1; i <= 15;i++){
          if(PointInRange[count+i].getX() != FLT_MAX){
            distanceTemp = getDistance(PointInRange[count],PointInRange[count+i]);
            if(distanceTemp < min){
               min = distanceTemp;
               record_count = count;
               record_i = i;
            }
          }else break;
        }
       count++;
      }

    if(min < delta){
      a = PointInRange[record_count];
      b = PointInRange[record_count + record_i];
    }else if (getDistance(q0,q1) < getDistance(r0,r1)){
      a = q0;
      b = q1;
    }else{
      a = r0;
      b = r1;
    }
  }
}
