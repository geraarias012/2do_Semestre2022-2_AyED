#include <iostream>
#include <locale.h>
#include <cstdlib>

using namespace std;

struct nodo{
    int dato;
    nodo *siguiente;
};

class cLista{
private:
    nodo *inicio, *fin, *aux, *auxfin, *aux1, *aux2;
    int contador;
public:
    bool vacia();
    void aniadir();
    void aniadir2();
    void recorrer();
    void quitar();
    void quitar2(int);
    void quitar3();
    int contador1();
    cLista();
    ~cLista();
};

cLista::cLista()
{
    inicio=NULL;
    contador=0;
}

cLista::~cLista()
{
  while(contador>0)
  {
    aux = inicio;
    inicio = inicio->siguiente;
    delete aux;
    contador--;
  }
}

bool cLista::vacia()
{
    if (contador==0)
	{
        return true;
    } 
	else
	{
    	return false;
    }
}

void cLista::aniadir2()
{
	aux=new nodo;
    cout<<"\nIngrese un número: ";
    cin>>aux->dato;
    cout<<endl;
	if(vacia())
	{
		inicio=fin=aux;
		aux->siguiente=inicio;
	} 
	else
	{	
		aux->siguiente=inicio;
		inicio=aux;
		fin->siguiente=inicio;
	}
contador++;
}

void cLista::aniadir()
{
    aux=new nodo;
    cout<<"\nIngrese un número: ";
    cin>>aux->dato;
    cout<<"\n";
    aux->siguiente=NULL;
    if(vacia())
	{
        inicio=fin=aux;
        aux->siguiente=inicio;
    } 
	else
	{
        fin->siguiente=aux;
        fin=aux;
        aux->siguiente=inicio;
    }
    contador++;
}

void cLista::recorrer()
{
    if (vacia())
	{
        cout<<endl<<"No hay elelmentos que mostrar en la lista\n"<<endl;
    } 
	else 
	{
   		aux=inicio;
		cout<<endl<<"****MUESTRA LA LISTA DE INICIO A FIN****"<<endl<<"inicio: ";
        for (int i=1; i<=contador;i++)
		{
            cout<<aux->dato<<"-->";
       		aux=aux->siguiente;
   		}
   		cout<<"inicio: "<<aux->dato<<endl<<endl;
	}
}

void cLista::quitar()
{
 	int elemento;
	if(vacia())
 	{
 	    cout<<"\nNo hay elementos que eliminar\n\n";
	} 
 	else 
	{
     	aux = inicio;
		elemento = aux->dato;
		inicio = inicio->siguiente;
   		delete aux;
    	cout << "\nEl elelmento eliminado fue: "<<elemento<<"\n"<<endl;
    	fin->siguiente=inicio;
    	contador--;
 	}
}

void cLista::quitar3()
{
 	int elemento, auxx;
 	aux = aux1 = aux2 = inicio;
	if(vacia())
 	{
 	    cout<<"\nNo hay elementos que eliminar\n\n";
	} 
 	else 
	{
		for (int i=1; i<=contador;i++)
		{
            cout<<"Posición "<<i<<": "<<aux->dato<<endl;
       		aux=aux->siguiente;
   		}
		cout<<endl<<"Qué posición desea eliminar desde 1 hasta "<<contador<<": ";
		cin>>auxx;
		aux=inicio;
		for(int i=1;i<auxx;i++)
		{
			aux1=aux;
			aux=aux->siguiente;
		}
		elemento = aux->dato;
		if(aux==inicio)
    	{
    		inicio = inicio->siguiente;
		}
		else if (aux==fin)
			{
    			fin = aux1;
    		}
			else
			{
				aux2=aux->siguiente;
				aux=aux1;
				aux->siguiente=aux2;
    		}
   		delete aux;
    	cout << "\nEl elelmento eliminado fue: "<<elemento<<"\n"<<endl;
    	fin->siguiente=inicio;
    	contador--;
 	}
}

void cLista::quitar2(int cont)
{
 	int elemento;
 	aux = auxfin = inicio;
	if(vacia())
 	{
 	    cout<<"\nNo hay elementos que eliminar\n\n";
	} 
 	else 
	{
		for(int i=1;i<cont;i++)
		{
        	auxfin = aux;
        	aux = aux->siguiente;
    	}
    	elemento = aux->dato;
    	if(aux==inicio)
    	{
    		inicio = inicio->siguiente;
		}
		else
		{
    			fin = auxfin;
		}
   		delete aux;
    	cout << "\nEl elelmento eliminado fue: "<<elemento<<"\n"<<endl;
    	fin->siguiente=inicio;
    	contador--;
 	}
}

int cLista::contador1()
{
	return contador;
}

int main()
{
	system("Color A");
	setlocale (LC_ALL, "spanish");
	cLista obj1;
    int op;
    do
    {
    cout<<"Lista enlazada\n\n1) Añadir elemento al inicio\n2) Añadir elemento al final\n3) Eliminar elemento al inicio\n4) Eliminar elemento al final\n5) Eliminar elemento en específico\n6) Recorrer elemento\n7) Salir\n\nSelecciona una opcion: ";
    cin>>op;
    switch(op)
	{
    case 1:
    	{
        obj1.aniadir2();
        system("pause");
        system("cls");
        break;
    	}
    	case 2:
    	{
        obj1.aniadir();
        system("pause");
        system("cls");
        break;
    	}
    case 3:
    	{
        obj1.quitar();
        system("pause");
        system("cls");
        break;
    	}
    case 4:
    	{
        obj1.quitar2(obj1.contador1());
        system("pause");
        system("cls");
        break;
    	}
    case 5:
    	{
        obj1.quitar3();
        system("pause");
        system("cls");
        break;
    	}
    case 6:
    	{
        obj1.recorrer();
        system("pause");
        system("cls");
        break;
    	}
    case 7:
    	{
        cout<<"\nADIOS"<<endl;
        break;
        }
    default:
    	{
        cout<<endl<<"Opcion no valida"<<endl<<endl;
        system("pause");
        system("cls");
        break;
    	}
    }
	}while(op!=7);
    return 0;
}
