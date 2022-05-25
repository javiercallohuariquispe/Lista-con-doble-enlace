#include <iostream>
using namespace std;

class NodoDobleEnlace {
    //Atributos
    int dato; //char, float, string, objeto
    NodoDobleEnlace* anterior;// puntero al nodo anterior..
    NodoDobleEnlace* siguiente;//puntero al nodo siguiente..
public:
    //Constructor - inicializar los atributos
    NodoDobleEnlace(int dato)
    {
        this->dato = dato;
        anterior = NULL;//por que no apuntamos a ningun nodo
        siguiente = NULL;//por que no apuntamos a ningun nodo
    }
    //getter and setter
    int getDato()
    {
        return dato;
    }
    void setDato(int dato)
    {
        this->dato = dato;
    }
    NodoDobleEnlace* getAnterior()
    {
        return this->anterior;
    }
    void setAnterior(NodoDobleEnlace* enlace)
    {
        this->anterior = enlace;
    }
    NodoDobleEnlace* getSiguiente()
    {
        return this->siguiente;
    }
    void setSiguiente(NodoDobleEnlace* enlace)
    {
        this->siguiente = enlace;
    }

    void imprimir()
    {
        cout << "/-------------------\\" << endl;
        cout << "|Dato: " << dato << endl;
        cout << "|-------------------" << endl;
        cout << "|Anterior: " << anterior << "\tSiguiente: " << siguiente << endl;
        cout << "\\------------------/" << endl;
    }
};

class ListaDobleEnlace {
    NodoDobleEnlace* inicio;
    NodoDobleEnlace* fin;
public:
    Lista()
    {
        this->inicio = NULL;
        this->fin = NULL;
    }
    bool EstaVacia()
    {
        if (inicio == NULL && fin == NULL)
            return true;
        else
            return false;
    }
    void Imprimir()
    {
        int i = 1;
        NodoDobleEnlace* recorrido = inicio;
        cout << "Lista doblemente enlazada****************************" << endl;
        while (recorrido != NULL)
        {
            cout << endl << "---> Nodo " << i++ << " -> DM: " << recorrido << endl;
            recorrido->imprimir();
            recorrido = recorrido->getSiguiente();
        }
        cout << "****************************" << endl << endl;
    }


    void InsertarAlFinal(int dato)
    {
        NodoDobleEnlace* temp = new NodoDobleEnlace(dato);
        if (EstaVacia())//lista vacia
        {
            inicio = temp;
            fin = temp;
        }
        else
        {
            fin->setSiguiente(temp);
            temp->setAnterior(fin);
            fin = temp;
        }
    }

    void InsertarAlInicio(int dato)
    {
        NodoDobleEnlace* temp = new NodoDobleEnlace(dato);
        if (EstaVacia())//lista vacia
        {
            inicio = temp;
            fin = temp;
        }
        else
        {
            temp->setSiguiente(inicio);
            inicio->setAnterior(temp);
            inicio = temp;
        }
    }
    void ImprimirEnLinea()
    {
        NodoDobleEnlace* recorrido = inicio;
        cout << "Lista enlazada****************************" << endl;
        while (recorrido != NULL)
        {
            cout << recorrido->getDato() << "\t";
            recorrido = recorrido->getSiguiente();
        }
        cout << "****************************" << endl << endl;
    }
    //------------------------------------
    //Implementar la eliminaci�n de un nodo final
    void EliminarElementoFinal()
    {
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            if (inicio->getSiguiente() == NULL) // unico nodo
            {
                inicio = NULL;
                fin = NULL;
            }
            else
            {
                fin->getAnterior()->setSiguiente(NULL);
                fin = fin->getAnterior();
            }

        }

    }
    void EliminarElementoInicio()
    {
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            if (inicio->getSiguiente() == NULL) // unico nodo
            {
                inicio = NULL;
                fin = NULL;
            }
            else
            {
                inicio->getSiguiente()->setAnterior(NULL);
                inicio = inicio->getSiguiente();
            }
        }
    }
    void Vaciar()
    {
        inicio = NULL;
        fin = NULL;
    }
};

void Buscar(){
	NodoDobleEnlace* recorrido = inicio;
	int nodoBuscado = 0, encontrado = 0;
	cout << "Digite el elemento a buscar: " << endl;
	cin >> nodoBuscado;

	if( inicio!=NULL){
		while(recorrido != NULL && encontrado != 1){

			if(actual->getDato == nodoBuscado){
				 cout << "Elemento encontrado en la dirección de memoría: " << recorrido << endl;
                encontrado = 1;
                break;
			}
			recorrido = recorrido->getSiguiente();
        }
		}
		if(encontrado == 0){
			 cout << "Elemento encontrado en la dirección de memoría: " <<endl;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}


void MostrarMenu()
{
    cout << "1.- Ver el contenido de la lista enlazada" << endl;
    cout << "2.- Insertar un elemento al inicio" << endl;
    cout << "3.- Insertar un elemento al final" << endl;
    cout << "4.- Buscar un elemento" << endl;
    cout << "5.- Eliminar un elemento inicial" << endl;
    cout << "6.- Eliminar un elemento final" << endl;
    cout << "7.- Vaciar la lista" << endl;
    cout << "8.- Eliminar un elemento en la posici�n" << endl;
    cout << "9.- Insertar elementos ordenadamente (desendente)" << endl;
    cout << "0.- Salir" << endl;
}
int main()
{
    ListaDobleEnlace lista = ListaDobleEnlace();
    for (int i = 0; i < 5; i++)
        lista.InsertarAlInicio(i + 1);

    lista.ImprimirEnLinea();

    lista.EliminarElementoInicio();

    lista.ImprimirEnLinea();

    lista.EliminarElementoInicio();

    lista.ImprimirEnLinea();
    int elemento;
    int opcion;
    do
    {
        MostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 0:
            cout << "Ingeniería de Sistemas, hasta luego." << endl;
            break;
        case 1:
             lista.ImprimirEnLinea();
            break;
        case 2:
            cout << "Digite el elemento a insertar: " << endl;
            cin >> elemento;
            lista.InsertarAlInicio(elemento);
            break;
        case 3:
            cout << "Digite el elemento a insertar: " << endl;
            cin >> elemento;
            lista.InsertarAlFinal(elemento);
            break;
        case 4:
            lista.Buscar();
            break;
        case 5:
            edadelista.EliminarElementoInicio();
            break;
        case 6:
            lista.EliminarElementoFinal();
            break;
        case 7:
            lista.Vaciar();
            break;
        case 8:
            cout << "Digite posición: " << endl;
            cin >> elemento;
            lista.EliminarElementoEnPosicion(elemento);
            break;
        case 9:
            cout << "Digite el elemento a insertar: " << endl;
            cin >> elemento;
            lista.InsertarDesendentemente(elemento);
            break;
        default:
            cout << "Opción no valida." << endl;
            break;
        }
    } while (opcion != 0);


}
