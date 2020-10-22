#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
  cout<<"Program sortuje dane przekazane do programu."<<endl;

  cout<<"Dane do posortowania: ";
  
  for(int b=1;b<argc;b++)
  {
      cout<<argv[b]<<" ";
  }
  cout<<endl;

  int l;
  char *x=NULL;

  do
  {
      l=0;

      for(int i=1; i<argc-1; i++)
      {
          if(atof(argv[i])>atof(argv[i+1]))
          {
              x=argv[i];
              argv[i]=argv[i+1];
              argv[i+1]=x;

              l++;
          }
      }

  } while (l!=0);

  cout<<"Dane posortowane: ";

  for(int c=1;c<argc;c++)
  {
      cout<<argv[c]<<" ";
  }
  cout<<endl;


  return 0;
}

/*

  int *tab = (int*) malloc((argc-1)*sizeof(int));
 
  for(int q=0;q<argc-1;++q)
  {
      tab[q] = atof(argv[q+1]);
  }

  for(int i=0; i<argc-1; i++)
  {
      for(int j=i+1; j<argc-1; j++)
      {
          if(tab[j]<tab[i])
          {
              swap(tab[j],tab[i]);
          }
      }
  }

  cout<<"Dane posortowane: ";
  for(int c=0;c<argc-1;c++)
  {
      cout<<tab[c]<<" ";
  }

  free(tab);
*/