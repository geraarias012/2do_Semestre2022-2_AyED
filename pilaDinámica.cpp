#include <iostream>
#include <locale.h>
#include <cstdlib>

using namespace std;

struct nodo{
    int dato;
    nodo *siguiente, *anterior;
};

class pilaP{
private:
    nodo *inicio, *fin, *aux;
    int contador;
public:
    bool vacia();
    void anhadir();
    void mostrar();
    void quitar();
    pilaP();
    ~pilaP();
};

//constructor
pilaP::pilaP(){
    inicio=NULL;
    contador=0;
}

//destructor
pilaP::~pilaP(){
  while(contador>0){
    aux = inicio;
    inicio = inicio->siguiente;
    delete aux;
    contador--;
  }
}

bool pilaP::vacia(){
    if (contador==0){
        return true;
    } else {
    return false;
    }
}

void pilaP::anhadir(){
    aux=new nodo;
    cout<<"\nIngrese un número: ";
    cin>>aux->dato;
    cout<<"\n";
    //EL nuevo nodo va al final de la lista, por lo que el apuntador se inicia como null
    aux->siguiente=NULL;
    if(vacia()){
        aux->anterior=NULL;
        inicio=fin=aux;
    } else{
        aux->anterior=fin;
        fin->siguiente=aux;
        fin=aux;
    }
    contador++;
}

void pilaP::mostrar(){
    if (vacia())
	{
        cout<<"\nNo hay elelmentos que mostrar en la lista\n"<<endl;
    }
	else
	{
        aux=fin;
        cout<<"\n\nElementos de la pila:"<<endl;

        for (int i=1; i<=contador;i++){
            cout<<aux->dato<<endl;
            aux=aux->anterior;
        }
    cout<<endl;
    }
    }

void pilaP::quitar(){
 //Elimina el inicio de la lista
 int elemento;
 if(vacia()){
    cout<<"\nNo hay elementos que eliminar\n\n";
    }
    else
    {
    aux = fin;
    elemento = aux->dato;
    fin = fin->anterior;
    delete aux;
    cout << "\nEl elelmento eliminado fue: "<<elemento<<"\n"<<endl;
    contador--;
    }
}

int main()
{
	system("Color A");
	setlocale (LC_ALL, "spanish");
	pilaP obj1;
    int op;
    do
    {
    cout<<"Pila\n\n1) Añadir elemento\n2) Eliminar elemento\n3) Mostrar elementos\n4) Salir\n\nSelecciona una opcion: ";
    cin>>op;
    switch(op)
	{
    case 1:
    	{
        obj1.anhadir();
        system("pause");
        system("cls");
        break;
    	}
    case 2:
    	{
        obj1.quitar();
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
        cout<<"\nOpcion no valida\n"<<endl;
        system("pause");
        system("cls");
        break;
    	}
    }
	}while(op!=4);
    return 0;
}
