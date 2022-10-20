#include<iostream>

using namespace std;

inline float Area(float radius)
{
    return 3.14 * radius * radius;
}
int main()
{

  
  float radius;
  cout<<"Enter Radius of circle=";
  cin>>radius;
  cout<<"Area of circle : "<<Area(radius);
  return 0;

}
