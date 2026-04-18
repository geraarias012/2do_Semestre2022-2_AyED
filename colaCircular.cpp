#include <iostream>
#include <stdlib.h>
#define max 6

using namespace std;

class cCola
{
private:
    int arreglo[max];
    int frente=-1;
    int final=-1;
    int tamano=0;
public:
    cCola();
    bool ColaVacia();
    void insertarElemento();
    int SacarElemento();
    int getFrenteCola();
    bool colaLlena();
    void mostrar();
    ~cCola();
};

cCola::cCola(){}
cCola::~cCola(){}

void cCola::insertarElemento()
{
    int dato;
    if(colaLlena())
    {
        cout<<"\nEL ARREGLO ESTA LLENO\n"<<endl;
    }
    else
    {
        cout<<"\nINGRESE UN DATO: ";
        cin>>dato;
        cout<<"\n"<<endl;
        if(final==max-1)
        {
        	final=0;
		}
		else
		{
			final=final+1;
		}
		arreglo[final]=dato;
		if(frente==-1)
		{
			frente=0;
		}
    }
}

bool cCola::ColaVacia()
{
    if (frente==-1)
        return true;
    else
        return false;
}

bool cCola::colaLlena()
{
    if((final!=-1 && final+1==frente) || (max-1==final && frente==0))
        return true;
    else
        return false;
}

int cCola::SacarElemento()
{
    if(ColaVacia())
    {
        cout<<"\nNO HAY DATOS PARA ELIMINAR\n"<<endl;
    }
    else
        {
        cout<<"\nSE ELIMINO: "<<arreglo[frente]<<"\n"<<endl;
        if(frente==final)
        {
        	frente=-1;
        	final=-1;
		}
		else if(frente==max-1)
		{
			frente=0;
		}
		else
		{
			frente=frente+1;
		}
        }
}

void cCola::mostrar()
{
	if(frente<=final)
	{
    	for(int i=frente;i<=final;i++)
    	{
        	cout<<arreglo[i]<<endl;
    	}
	}
	else 
	{
    	for(int i=frente;i<max;i++)
    	{
        	cout<<arreglo[i]<<endl;
    	}
    	for(int i=0;i<=final;i++)
    	{
        	cout<<arreglo[i]<<endl;
    	}
	}
}

int main()
{
    int op;
    cCola obj1;
    do
    {
        cout<<"MENU:\n\n1]INSERTAR ELEMENTO\n2]SACAR ELEMENTO\n3]MOSTRAR COLA\n4]SALIR\n\nELIGA UNA OPCION: ";
        cin>>op;
    switch(op)
    {
    case 1:
    {
        obj1.insertarElemento();
        system("pause");
        system("cls");
        break;
    }
    case 2:
    {
        obj1.SacarElemento();
        system("pause");
        system("cls");
        break;
    }
    case 3:
    {
        obj1.mostrar();
        system("pause");
        system("cls");
        break;
    }
    case 4:
    {
        cout<<"\nADIOS"<<endl;
        break;
    }
    default:
    {
        cout<<"OPCION NO VALIDA"<<endl;
        system("pause");
        system("cls");
        break;
    }
    }
    }while(op!=4);
}
