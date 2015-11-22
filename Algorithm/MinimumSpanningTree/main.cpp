#include <iostream>
using namespace std;

class City{
private:
  string* citys;
  int size;

public:
  City(int n){
    citys = new string[n];
    size = n;
  }

  ~City(){
    delete[] citys;
  }

  void setName(int index,string name){
    citys[index] = name;
  }

  string getName(int index){
    return citys[index];
  }

  int getIndex(string name){
    for(int i = 0;i < size;i++){
      if(citys[i] == name){
        return i;
      }
    }
    return -1;
  }
};

int main(void){
  int m,n,i;

  cout<<"Input n and m:"<<endl;
  cin>>n>>m;
  cout<<"M:"<<m<<" N:"<<n<<endl;

  // for(i = 0;i < m,i++)
  // scanf("%s\n", );


}
