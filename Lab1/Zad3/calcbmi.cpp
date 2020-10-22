#include <iostream>
using namespace std;

int main()
{
    double masa, wzrost,BMI;
    cout<<"Program obliczy twoje BMI i poda zakresy (uzywaj .)."<<endl;
    cout<<"Podaj mase (kg): "<<endl;
    cin>>masa;
    cout<<"Podaj wzrost (m): "<<endl;
    cin>>wzrost;

    BMI = (masa/(wzrost*wzrost));
    cout<<"Twoja wartosc BMI wynosi: "<<BMI<<endl;

    if(BMI<16)
    {
        cout<<"Wyglodzenie."<<endl;
    } 
    else if((BMI>=16)&&(BMI<17))
    {
        cout<<"Wychudzenie."<<endl;
    } 
    else if((BMI>=17)&&(BMI<18.5)) 
    {
        cout<<"Niedowaga."<<endl;
    }
    else if((BMI>=18.5)&&(BMI<25)) 
    {
        cout<<"Wartosc prawidlowa."<<endl;
    }
    else if((BMI>=25)&&(BMI<30)) 
    {
        cout<<"Nadwaga."<<endl;
    }
    else if((BMI>=30)&&(BMI<35)) 
    {
        cout<<"I stopien otylosci."<<endl;
    }
    else if((BMI>=35)&&(BMI<40)) 
    {
        cout<<"II stopien otylosci."<<endl;
    }
    else if(BMI>=40) 
    {
        cout<<"Otylosc skrajna."<<endl;
    }
   
    return 0;
}