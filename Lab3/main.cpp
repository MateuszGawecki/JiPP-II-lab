#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Matrix
{
    private:
        int n,m;
        double **tab;
    
    public:
        Matrix(int a); //konstruktor
        Matrix(int a, int b); //konstruktor
        Matrix(string path); //konstruktor czytajacy z pliku
        ~Matrix(); //destruktor
        void set(int a, int b, double c); //ustawia element (n,m) na wartość c
        double get(int a, int b); //zwraca wartość z miejsca (n,m) w tablicy
        void print();//wypisuje macierz
        int cols();//zwraca liczbę kolumn 
        int rows();//zwraca liczbę wierszy
        Matrix add(Matrix&); //metoda dodawania macierzy
        Matrix subtract(Matrix&); //metoda odejmowania macierzy
        Matrix multiply(Matrix&); //metoda mnożenia macierzy
        Matrix& operator+(Matrix&);//definicja operatora dodawania macierzy
        Matrix& operator-(Matrix&);//definicja operatora odejmowania macierzy
        Matrix& operator*(Matrix&);//definicja operatora mnożenia macierzy
        void store(string filename,string path);//zapis do pliku
};

Matrix::Matrix(string path)
{
    fstream plik;
    plik.open(path, ios::in);

    if(!plik.good())
    {
        exit (2);
    }
    else
    {
        cout<<"Otwarto na odczyt"<<endl;
    }
    

    plik>>n;
    plik>>m;
    
     tab=new double*[n];
    for(int i=0; i<n; i++)
      tab[i]=new double[m];

    for(int j=0; j<n; j++)
      for(int k=0;k<m; k++)
        plik>>tab[j][k];
}

void Matrix::store(string filename, string path)
{
  string droga=path+filename;
  fstream plik;
  plik.open(droga, ios::out);

  if(!plik.good())
  {
      exit (1);
  }
  else
  {
    cout<<"Otwarto"<<endl;
  }

  plik<<n;
  plik<<" ";
  plik<<m;
  plik<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            plik<<tab[i][j];
            plik<<" ";
        }
        plik<<endl;
    }

    plik.close();
}

Matrix::Matrix(int a)
{
    n=a;
    m=a;

    tab=new double*[n];
    for(int i=0; i<n; i++)
      tab[i]=new double[m];

    for(int j=0; j<n; j++)
      for(int k=0;k<m; k++)
        tab[j][k]=0;
}

Matrix::Matrix(int a, int b)
{
    n=a;
    m=b;

    tab=new double*[n];
    for(int i=0; i<n; i++)
      tab[i]=new double[m];

    for(int j=0; j<n; j++)
      for(int k=0;k<m; k++)
        tab[j][k]=0;
}

Matrix::~Matrix()
{
    if(tab)
    {
        for(int i=0; i<n; i++)
        {
            if(tab[i]) delete []tab[i];
        }
        delete []tab;
    }
    cout<<"Destruktor"<<endl;
}

void Matrix::set(int a, int b, double c)
{
    tab[a][b]=c;
}

double Matrix::get(int a, int b)
{
    return tab[a][b];
}

void Matrix::print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}

int Matrix::cols()
{
    return m;
}

int Matrix::rows()
{
    return n;
}

Matrix Matrix::add(Matrix& a)
{
    if(n!=a.n || m!=a.m)
    {
        exit(1);
    }
        Matrix w(n,m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                w.tab[i][j]=tab[i][j]+a.tab[i][j];;
            }
        }

    return w;
}

Matrix Matrix::subtract(Matrix& a)
{
   if(n!=a.n || m!=a.m)
    {
        exit(1);
    }
        Matrix w(n,m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                w.tab[i][j]=tab[i][j]-a.tab[i][j];
            }
        }
    
    return w;
}

Matrix Matrix::multiply(Matrix& a)
{
    if(m!=a.n)
    {
        exit(1);
    }
        Matrix w(n,a.m);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a.m;j++)
            {
                for(int k=0;k<m;k++)
                    w.tab[i][j] +=tab[i][k]*a.tab[k][j];
            }
        }
    
    return w;
}


Matrix& Matrix::operator+(Matrix& a)
{
    if(n!=a.n || m!=a.m)
    {
        exit(1);
    }
        Matrix w(n,m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                w.tab[i][j]=tab[i][j]+a.tab[i][j];;
            }
        }

    return w;
}

Matrix& Matrix::operator-(Matrix& a)
{
     if(n!=a.n || m!=a.m)
    {
        exit(1);
    }
        Matrix w(n,m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                w.tab[i][j]=tab[i][j]-a.tab[i][j];
            }
        }
    
    return w;
}

Matrix& Matrix::operator*(Matrix& a)
{
     if(m!=a.n)
    {
        exit(1);
    }
        Matrix w(n,a.m);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a.m;j++)
            {
                for(int k=0;k<m;k++)
                    w.tab[i][j] +=tab[i][k]*a.tab[k][j];
            }
        }
    
    return w;
}

int main()
{
    Matrix m1(4);
    Matrix m2(4);
    cout<<"Po wywolaniu konstruktora"<<endl;
    m1.print();
    cout<<endl;
    m2.print();
    cout<<endl;

    for(int i=0; i<4;i++)
    {
        int l=1;
        for(int j=0;j<4;j++)
        {
            m1.set(i,j,l);
            l++;
        }
    }

    for(int i=0; i<4;i++)
    {
        int l=10;
        for(int j=0;j<4;j++)
        {
            m2.set(i,j,l);
            l--;
        }
    }

    cout<<"Po ustawieniu wartosci metoda set"<<endl;
    m1.print();
    cout<<endl;
    m2.print();
    cout<<endl;

    cout<<endl<<"Metoda get "<<endl;
    for(int i=0; i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<m1.get(i,j);
            cout<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i=0; i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<m2.get(i,j);
            cout<<" ";
        }
        cout<<endl;
    }

    cout<<"Metoda add subtract multiply"<<endl;


    (m1.add(m2)).print();
    cout<<endl;
    (m1.subtract(m2)).print();
    cout<<endl;
    (m1.multiply(m2)).print();
    cout<<endl;
    
    cout<<"Kostruktor dla macierzy prostokatnej"<<endl;
    Matrix m3(4,5);
    m3.print();

    cout<<"metoda cols i rows dla macierzy prostokatnej"<<endl;
    cout<<m3.cols()<<" "<<m3.rows()<<endl;

    for(int i=0; i<4;i++)
    {
        int l=20;
        for(int j=0;j<5;j++)
        {
            m3.set(i,j,l);
            l++;
        }
    }
    cout<<"Metoda set dla prostokatnej"<<endl;
    m3.print();

    cout<<"Zapis macierzy prostokatnej w plik"<<endl;
    m3.store("macierz.txt","C:\\Users\\gmate\\projects\\lab3\\");
    

    cout<<"Nowa macierz na podstawie zapisanej do pliku"<<endl;
    Matrix m4("C:\\Users\\gmate\\projects\\lab3\\macierz.txt");
    cout<<endl;
    m4.print();
    cout<<endl;

    return 0;
}