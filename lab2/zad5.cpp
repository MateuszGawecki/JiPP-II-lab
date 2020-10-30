#include <iostream>
//#include <algorithm>
using namespace std;

template <typename T>
void swap2(T & a, T & b)
{
  T tmp = a;
  a = b;
  b = tmp;
}

int main()
{
    int a =100, b= 200;
    float c = 3.14, d=1.222;
    char e='a' , f='b' ;
    cout<<a<<" "<<b<<endl;
    cout<<c<<" "<<d<<endl;
    cout<<e<<" "<<f<<endl;

    swap2(a,b);
    swap2(c,d);
    swap2(e,f);

    cout<<a<<" "<<b<<endl;
    cout<<c<<" "<<d<<endl;
    cout<<e<<" "<<f<<endl;

    return 0;
}