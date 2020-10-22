#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
    cout<<"Program sprawdza czy podany tekst jest palindromem.(Program nie ignoruje wielkosci liter!)"<<endl;
    /*cout<<argv[1]<<endl;
    cout<<*argv[1]<<endl;
    cout<<argv[1][0]<<endl;   
    cout<<argv[1][1]<<endl;
    cout<<argv[1][2]<<endl;
    cout<<strlen(argv[1])<<endl;*/

    int l=0, lenght= strlen(argv[1]);

    for(int i=0; i<lenght; i++)
    {
        if(argv[1][i]!=argv[1][lenght-1-i])
        {
            l++;
        }
    }

    if(l==0) cout<<"Podany tekst jest palindromem."<<endl;
    else cout<<"Podany tekst nie jest palindromem."<<endl;

    return 0;
}