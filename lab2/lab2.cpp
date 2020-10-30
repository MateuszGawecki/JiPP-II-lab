#include <iostream>
using namespace std;

void fun1(int *ptra, int *ptrb)
{
    if(*ptra>*ptrb)
    {
        int temp = *ptra;
        *ptra=*ptrb;
        *ptrb=temp;
    }
}

void fun2(int & refa, int & refb)
{
    int temp =refa;
    refa =refb;
    refb=temp;
}

void fun3(int & refa, int * ptrb)
{
    int temp = *ptrb;
    *ptrb =refa;
    refa =temp;
}

double fun4(int & refa, int &refb)
{
    int iloczyn= refa*refb;
    refa +=refb;

     return iloczyn;
}

int main()
{
    int a,b;
    int *ptra =&a , *ptrb=&b;
    cout<<"Podaj dwie liczby : "<<endl;
    cin>>a>>b;
    cout<<endl;
    cout<<a<<" "<<b<<endl;
    //fun1(ptra,ptrb);
    //fun2(a,b);
    //fun3(a,ptrb);
    cout<<"Iloczyn wynosi: "<<fun4(a,b)<<" Suma wynosi: "<<a<<endl;
    cout<<a<<" "<<b<<endl;

    return 0;
}