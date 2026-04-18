#include <iostream>
#include <locale.h>
#include <cstdlib>

using namespace std;

struct nodo{
    int dato;
    nodo *siguiente, *anterior;
};

class cListaDE
{
private:
    nodo *inicio, *fin, *aux, *auxfin, *aux1;
    int contador;
public:
    bool vacia();
    void aniadir();
    void aniadir2();
    void recorrer();
    void quitar();
    void quitar2(int);
    void quitar3(int);
    int contador1();
    cListaDE();
    ~cListaDE();
};

cListaDE::cListaDE()
{
    inicio=NULL;
    contador=0;
}

cListaDE::~cListaDE()
{
  while(contador>0)
  {
    aux = inicio;
    inicio = inicio->siguiente;
    delete aux;
    contador--;
  }
}

bool cListaDE::vacia()
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

void cListaDE::aniadir2()
{
	aux=new nodo;
    cout<<"\nIngrese un número: ";
    cin>>aux->dato;
    cout<<"\n";
	if(vacia())
	{
		inicio=fin=aux;
	} 
	else
	{	
		aux->siguiente=inicio;
		inicio->anterior=aux;
		inicio=aux;
	}
contador++;
}

void cListaDE::aniadir()
{
    aux=new nodo;
    cout<<"\nIngrese un número: ";
    cin>>aux->dato;
    cout<<"\n";
    aux->siguiente=NULL;
    if(vacia())
	{
        aux->anterior=NULL;
        inicio=fin=aux;
    } 
	else
	{
        aux->anterior=fin;
        fin->siguiente=aux;
        fin=aux;
    }
    contador++;
}

void cListaDE::recorrer()
{
    if (vacia())
	{
        cout<<endl<<"No hay elelmentos que mostrar en la lista\n"<<endl;
    } 
	else 
	{
		int op;
		cout<<"\n¿En que direccion?\n1)Inicio a fin\n2)Fin a inicio"<<endl;
        cin>>op;
        cout<<endl;
		switch(op)
		{
        	case 1:
			{
        		 aux=inicio;
        		 cout<<"****MUESTRA LA LISTA DE INICIO A FIN****"<<endl;

        		for (int i=1; i<=contador;i++)
				{
            	 	cout<<aux->dato<<"-->";
            		aux=aux->siguiente;
        		}
        		cout<<"NULL"<<endl<<endl;
        		break;
      		}
      		case 2:
			{
        	 	aux=fin;
        	 	cout<<"****MUESTRA LA LISTA DE FIN A INICIO****"<<endl;

        	 	for (int i=1; i<=contador;i++)
			 	{
          		    cout<<aux->dato<<"-->";
          		    aux=aux->anterior;
       			}
        	 	cout<<"NULL"<<endl<<endl;
        	 	break;
      		}
      		default:
			{
          		cout<<"Opcion no valida"<<endl;
          		system("pause");
          		system("cls");
		  		break;
      		}
    	}
	}
}

void cListaDE::quitar()
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
    	contador--;
 	}
}

void cListaDE::quitar3(int cont)
{
 	int elemento, auxx;
 	aux = aux1 = inicio;
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
				aux1->siguiente = NULL;
    		}
			else
			{
				aux=aux->siguiente;
				aux->anterior=aux1;
				aux1=aux;
				aux=aux->anterior;
				aux->siguiente=aux1;
    		}
   		delete aux;
    	cout << "\nEl elelmento eliminado fue: "<<elemento<<"\n"<<endl;
    	contador--;
 	}
}

void cListaDE::quitar2(int cont)
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
        	auxfin=aux;
        	aux=aux->siguiente;
    	}
    	elemento = aux->dato;
    	if(aux==inicio)
    	{
    		inicio = inicio->siguiente;
		}
		else
		{
    			fin = auxfin;
				auxfin->siguiente = NULL;
		}
   		delete aux;
    	cout << "\nEl elelmento eliminado fue: "<<elemento<<"\n"<<endl;
    	contador--;
 	}
}

int cListaDE::contador1()
{
	return contador;
}

int main()
{
	system("Color A");
	setlocale (LC_ALL, "spanish");
	cListaDE obj1;
    int op;
    do
    {
    cout<<"Lista doblemente enlazada\n\n1) Añadir elemento al inicio\n2) Añadir elemento al final\n3) Eliminar elemento al inicio\n4) Eliminar elemento al final\n5) Eliminar elemento en específico\n6) Recorrer elemento\n7) Salir\n\nSelecciona una opcion: ";
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
        obj1.quitar3(obj1.contador1());
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
