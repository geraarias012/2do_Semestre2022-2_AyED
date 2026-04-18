#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>

using namespace std;


class fhas
{
private:
    struct nodo
    {
      char rfc[14];
      int estado = 0;
    }arreglo[11][11];
    int cont=0;
public:

   void resgistro();
    bool buscar();
    int fhash(char []);

    fhas();
    ~fhas();
};


fhas::fhas(){}
fhas::~fhas(){}


void fhas::resgistro()
{
    int a=-1,b=1;
    char rfcaux[14];
    cout<<endl<<"Ingresa el RFC: ";
    cin.getline(rfcaux,14,'\n');
    fflush(stdin);

    a = fhash(rfcaux);



        while(arreglo[a][b].estado==1)
        {
        	if(strcoll(arreglo[a][b].rfc,rfcaux)==0)
        	{
        		cout<<endl<<"Ya esta registrado ese RFC"<<endl;
        		arreglo[a][b].estado=0;
			}
			else
			{
           		b++;
           	}	
        }
		strcpy(arreglo[a][b].rfc,rfcaux);
    	arreglo[a][b].estado = 1;

    cout<<endl<<"Se coloco en la posicion: "<<a<<", arreglo numero: "<<b<<endl<<endl;
}

int fhas::fhash(char r[])
{
    int pos,suma=0,a=0;
    for(int i=1;i<11;i++)
    {
        a = r[i];
        suma=suma+a;
    }
   pos = suma%11+1;
   return pos;
}

bool fhas::buscar()
{
    int a,b=0;
    bool bus;
    char rfcaux[13];
    cout<<endl<<"Ingresa RFC a buscar: ";
    cin.getline(rfcaux,14,'\n');
    fflush(stdin);
    a = fhash(rfcaux);
    for(b;b<11;b++)
	{
    	if(strcoll(arreglo[a][b].rfc,rfcaux)==0)
    	{
       	bus=true;
    	}
    	else
    	{
      	  bus=false;
    	}
    	if(bus==true)
    	{
    		b=11;
		}
	}
       return bus;
}

int main()

{
    int op;
    fhas obj1;
do
	{
		cout<<"METODO HASH"<<endl<<endl<<"1)Insertar"<<endl<<"2)Buscar"<<endl<<"3)Salir"<<endl<<"Ingrese una opcion: ";
		cin>>op;
        fflush(stdin);
		switch(op)
		{
		case 1:
			obj1.resgistro();
			system("pause");
			system("cls");

			break;
		case 2:
		    if(obj1.buscar())
            {
                cout<<endl<<"Si esta"<<endl<<endl;
            }
            else{
                cout<<endl<<"No esta"<<endl<<endl;
            }
            system("pause");
			system("cls");

			break;
		case 3:
			cout<<endl<<"Fin del programa"<<endl<<endl<<"Adios"<<endl;

			break;
		default:
			cout<<"Opcion no valida"<<endl;
            system("pause");
			system("cls");
			break;
		}
	}while(op!=3);
    return 0;
}
