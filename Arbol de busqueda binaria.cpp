#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

struct Nodo {
        int dato;
        Nodo* der;
        Nodo* izq;
        Nodo* padre;
        };

class arboles{
private:
    Nodo* arbol = NULL;
public:
    arboles();
    ~arboles();
    void insertarNodo(Nodo &, int, Nodo);
    void mostrarArbol(Nodo*, int);
    void preOrden(Nodo*);
    void inOrden(Nodo*);
    void postOrden(Nodo*);
};

arboles::arboles(){
    Nodo* minimo(Nodo*);
    Nodo* arbol = NULL;
}

arboles::~arboles(){
}

//Función para insertar nodos en el árbol
void arboles::insertarNodo(Nodo *&arbol, int n, Nodo*padre) {
    if (arbol == NULL) { //Si el arbol está vacío
        Nodo* nuevo_nodo = new Nodo();

           nuevo_nodo->dato = n;
        nuevo_nodo->der = NULL;
        nuevo_nodo->izq = NULL;
        nuevo_nodo->padre = padre;

        arbol = nuevo_nodo;
    }
    else { // Si el arbol tiene un nodo o más
        int valorRaiz = arbol->dato; // Obtener valor de la raíz
        if (n < valorRaiz) {
            insertarNodo(arbol->izq, n,arbol);
        }
        else {
            insertarNodo(arbol->der, n,arbol);
        }
    }
}
//Función para mostrar el arbol
void arboles::mostrarArbol(Nodo* arbol, int cont) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout <<"    ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont + 1);
    }
}

// Funcion para recorrido en profundidad - PreOrden
void arboles::preOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->dato << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
// Funcion para recorrido en profundidad - InOrden
void arboles::inOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        inOrden(arbol->izq);
        cout << arbol->dato << " - ";
        inOrden(arbol->der);
    }
}
// Funcion para recorrido en profundidad - PostOrden
void arboles::postOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->dato << " - ";
    }
}

int main()
{
    arboles obj1;
    int dato, opcion,contador= 0;

    do {
        cout << "\t.:MENU:." << endl;
        cout << "1.Insertar un nuevo nodo" << endl;
        cout << "2.Mostrar el arbol" << endl;
        
        cout << "3.Recorrer el arbol en PreOrden" << endl;
        cout << "4.Recorrer el arbol en InOrden" << endl;
        cout << "5.Recorrer el arbol en PostOrden" << endl;
        
        cout << "6.Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Digite un numero: ";
            cin >> dato;
            obj1.insertarNodo(arbol, dato,NULL);
            cout << "\n";
            system("pause");
            break;
        case 2:
            cout << "Aqui tienes el arbol impreso de forma recursiva: " << endl;
            obj1.mostrarArbol(arbol, contador);
            cout << "\n";
            system("pause");
            break;
        case 3:
            cout << "\nRecorrido en PreOrden: " << endl;
            obj1.preOrden(arbol);
            cout << "\n\n";
            system("pause");
            break;
        case 4:
            cout << "\nRecorrido en InOrden: " << endl;
            obj1.inOrden(arbol);
            cout << "\n\n";
            system("pause");
            break;
        case 5:
            cout << "\nRecorrido en PostOrden: " << endl;
            obj1.postOrden(arbol);
            cout << "\n\n";
            system("pause");
            break;
        
        }
        system("cls");
    } while (opcion != 6);
    
    
    return 0;
}
