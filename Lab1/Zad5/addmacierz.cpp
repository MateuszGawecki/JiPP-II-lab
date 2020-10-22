#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int tab1[2][3], tab2[2][3];
    cout<<"Program dodaje dwie macierze o wym 2x3."<<endl;

    srand(time(NULL));

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            tab1[i][j]=(rand()%100)+0;
            tab2[i][j]=(rand()%100)+0;
        }
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<tab1[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<tab2[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            tab1[i][j]+=tab2[i][j];
            cout<<tab1[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}