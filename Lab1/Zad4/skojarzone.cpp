#include <iostream>
using namespace std;

int main()
{
    int A,B, sumA=0, sumB=0;
    cout<<"Program sprawdza czy dwie liczby, obie wieksze od 1, sa skojarzone.\nPodaj pierwsza liczbe: "<<endl;
    cin>>A;
    cout<<endl<<"Podaj druga liczbe: "<<endl;
    cin>>B;
    cout<<endl;

    for(int i=1; i<A; i++)
    {
        if((A%i)==0)
        {
            sumA +=i;
            //cout<<i<<endl;
        }
    }

    //cout<<endl;

    for(int j=1; j<B; j++)
    {
        if((B%j)==0)
        {
            sumB +=j;
            //cout<<j<<endl;
        }
    }

    if((sumA==(B+1))&&(sumB==(A+1))) 
    {
        cout<<"Liczby sa skojarzone."<<endl;
    }
    else
    {
        cout<<"Liczby nie sa skojarzone."<<endl;
    }

    return 0;
}