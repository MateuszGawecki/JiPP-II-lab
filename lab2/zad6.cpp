#include <iostream>
#include <algorithm>
using namespace std;

template <typename T, size_t N>
void swap2(T (&a)[N],T (&b)[N])
{
  for(size_t i=0; i<N; ++i)
     swap(a[i],b[i]);
}

int main()
{
    int tab1[2]={1,2}, tab2[2]={3,4};
    double tab3[2]= {2.3,1.5}, tab4[2]={5.3,6.1};

    for(int i=0;i<2;i++)
        cout<<tab1[i]<<" ";
    cout<<endl;

    for(int i=0;i<2;i++)
        cout<<tab2[i]<<" ";
    cout<<endl;

    for(int i=0;i<2;i++)
        cout<<tab3[i]<<" ";
    cout<<endl;

    for(int i=0;i<2;i++)
        cout<<tab4[i]<<" ";
    cout<<endl;

    swap2(tab1,tab2);
    swap2(tab3,tab4);

    for(int i=0;i<2;i++)
        cout<<tab1[i]<<" ";
    cout<<endl;

    for(int i=0;i<2;i++)
        cout<<tab2[i]<<" ";
    cout<<endl;

    for(int i=0;i<2;i++)
        cout<<tab3[i]<<" ";
    cout<<endl;

    for(int i=0;i<2;i++)
        cout<<tab4[i]<<" ";
    cout<<endl;

    return 0;
}