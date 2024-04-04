#include <iostream>
#include <queue>
#include <stack>
#include<stdlib.h>
#include <algorithm>

using namespace std;

struct Nodo{
	int value;
	Nodo *siguiente;
	Nodo*der;
    Nodo*izq;
};

struct Arbol 
{
    int value;
    
};

void menu();
Nodo*crearNodo(int);
void insertarNodo(Nodo*&,int);
void mostrarArbol(Nodo*,int);
bool busqueda(Nodo*,int);

Nodo*arbol = NULL;

struct Data {
    int value;
    int priority;
};

void displayData(const queue<Data>& q) {
    queue<Data> temp = q;
    while (!temp.empty()) {
        cout << "Dato: " << temp.front().value << " | Prioridad: " << temp.front().priority << endl;
        temp.pop();
    }
}

void agregarPila(Nodo *&,int); 
void sacarPila(Nodo *&,int &);

int main() {
	int quequiere;
	Nodo *pila = NULL;
    queue<Data> queue_priority1;
    queue<Data> queue_priority2;
    queue<Data> queue_priority3;
    stack<Data> stack_data;
    char rpt;
    
    do{
	cout << "Bienvenido";
	cout << "¿Cómo desea hacerlo, por pilas o colas?";
	cout << "1. Pilas";
	cout << "2. Colas";
	cin >> quequiere;
	
	switch (quequiere) {
		case 1 : {
			
		int option;
        do {
        cout << "\n1. Insertar dato\n";
        cout << "2. Eliminar dato\n";
        cout << "3. Ver datos ingresados\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
            case 1: {
                int value, priority;
                cout << "Ingrese el dato: ";
                cin >> value;
                cout << "Ingrese el nivel de prioridad (1, 2 o 3): ";
                cin >> priority;

                Data data;
                data.value = value;
                data.priority = priority;

                switch (priority) {
                    case 1:
                        queue_priority1.push(data);
                        break;
                    case 2:
                        queue_priority2.push(data);
                        break;
                    case 3:
                        queue_priority3.push(data);
                        break;
                    default:
                        cout << "Prioridad inválida. Intente nuevamente.\n";
                        break;
                }

                break;
            }
            case 2: {
                if (!queue_priority1.empty()) {
                    cout << "Dato eliminado con prioridad 1: " << queue_priority1.front().value << endl;
                    queue_priority1.pop();
                } else if (!queue_priority2.empty()) {
                    cout << "Dato eliminado con prioridad 2: " << queue_priority2.front().value << endl;
                    queue_priority2.pop();
                } else if (!queue_priority3.empty()) {
                    cout << "Dato eliminado con prioridad 3: " << queue_priority3.front().value << endl;
                    queue_priority3.pop();
                } else {
                    cout << "No hay datos para eliminar.\n";
                }

                break;
            }
            case 3: {
                cout << "\nDatos ingresados con prioridad 1:\n";
                displayData(queue_priority1);
                cout << "\nDatos ingresados con prioridad 2:\n";
                displayData(queue_priority2);
                cout << "\nDatos ingresados con prioridad 3:\n";
                displayData(queue_priority3);
                break;
            }
            case 4:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }
    } while (option != 4);
}
		
		case 2 : {
			int option;
            do {
        cout << "\n1. Insertar dato\n";
        cout << "2. Eliminar dato\n";
        cout << "3. Ver datos ingresados\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
            case 1: {
                int value, priority;
                cout << "Ingrese el dato: ";
                cin >> value;
                cout << "Ingrese el nivel de prioridad (1, 2 o 3): ";
                cin >> priority;

                Data data;
                data.value = value;
                data.priority = priority;

                switch (priority) {
                    case 1:
                        queue_priority1.push(data);
                        break;
                    case 2:
                        queue_priority2.push(data);
                        break;
                    case 3:
                        queue_priority3.push(data);
                        break;
                    default:
                        cout << "Prioridad inválida. Intente nuevamente.\n";
                        break;
                }

                break;
            }
            case 2: {
                if (!queue_priority1.empty()) {
                    cout << "Dato eliminado con prioridad 1: " << queue_priority1.front().value << endl;
                    queue_priority1.pop();
                } else if (!queue_priority2.empty()) {
                    cout << "Dato eliminado con prioridad 2: " << queue_priority2.front().value << endl;
                    queue_priority2.pop();
                } else if (!queue_priority3.empty()) {
                    cout << "Dato eliminado con prioridad 3: " << queue_priority3.front().value << endl;
                    queue_priority3.pop();
                } else {
                    cout << "No hay datos para eliminar.\n";
                }

                break;
            }
            case 3: {
                cout << "\nDatos ingresados con prioridad 1:\n";
                displayData(queue_priority1);
                cout << "\nDatos ingresados con prioridad 2:\n";
                displayData(queue_priority2);
                cout << "\nDatos ingresados con prioridad 3:\n";
                displayData(queue_priority3);
                break;
            }
            case 4:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }
    } while (option != 4);
			break;
		}
	}
}while (quequiere != 3);
    return 0;
}
		void agregarPila(Nodo *&pila,int n){
	    Nodo *nuevo_nodo = new Nodo();
	    nuevo_nodo->value = n;
	    nuevo_nodo->siguiente = pila;
	    pila = nuevo_nodo;
        }

        void sacarPila(Nodo *&pila,int &n){
	    Nodo *aux = pila;
	    n = aux->value;
	    pila = aux->siguiente;
	    delete aux;
        }
        
        
        Nodo*crearNodo(int n)
{
    Nodo*nuevo_nodo=new Nodo();
    
    nuevo_nodo->value=n;
    nuevo_nodo->der=NULL;
    nuevo_nodo->izq=NULL;
    
    return nuevo_nodo;
}

void insertarNodo(Nodo*&arbol,int n)
{
    if(arbol==NULL)
    {
        Nodo*nuevo_nodo=crearNodo(n);
        arbol=nuevo_nodo;
    }
    else
    {
        int valorRaiz=arbol->value;
        if(n<valorRaiz)
        {
            insertarNodo(arbol->izq,n);
        }
        else
        {
            insertarNodo(arbol->der,n);
        }
    }
}
