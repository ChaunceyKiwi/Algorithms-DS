#include <iostream>
#include <math.h>
using namespace std;

bool IsPrime(int number)
{
  int i;
  
  for (i=2; i<number; i++)
  {
    if (number % i == 0)
    {
      return false;
    }
  }
  
  return true;	
}

/* calculates (a^b) % mod */
int pow(int a, int b, int mod)
{
  int x = 1, y = a;
  
  while (b > 0)
  {
    // if b is odd
    if (b % 2 == 1){
      x *= y;
      if (x > mod) {
        x %= mod;
      }
    }
    
    y *= y;
    
    if (y > mod)
      y %= mod;
    
    b /= 2;
  }
  
  return x;
}

int main() {
  int testRange = 100;
  for (int p = 2; p < testRange; p++) {
    int flag = 1;
    
    for (int a = 1; a < p; a++) {
      if (pow(a, p-1, p) != 1) {
        flag = 0;
        break;
      }
    }
    
    if (flag == 1) {
      cout << p << endl;
    }
  }
}
