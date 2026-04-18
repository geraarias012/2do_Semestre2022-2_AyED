#include <iostream>
#include <stdlib.h>
#define max 6

using namespace std;

class cCola
{
private:
    int arreglo[max];
    int frente=0;
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
        final=final+1;
        tamano=tamano+1;
        arreglo[final]=dato;
    }
}

bool cCola::ColaVacia()
{
    if (final<frente)
        return true;
    else
        return false;
}

bool cCola::colaLlena()
{
    if(final>=max-1)
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
        frente=frente+1;
        tamano=tamano-1;
        }
}

void cCola::mostrar()
{
    for(int i=frente;i<=final;i++)
    {
        cout<<arreglo[i]<<endl;
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


