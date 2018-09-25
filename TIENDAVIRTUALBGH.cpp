#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct tienda
{
    string nombre;
    int dato;
    struct tienda *siguiente;
    struct tienda *siguiente1;
}*inicio,*aux,*actual, producto,*inicio1,*aux1,*actual1 ;
void eliminartienda(int);
void insertartienda(int);
void insertartiendanombre(string );
void comprarproductos();

void mostrartienda();
void ordenar(int);
void posicion(int);
int total=0;
int main()
{
    inicio = NULL;
    int dato;
    string nomb;
    int salida,cuenta=0;
    int menu;
    do
    {
        cout<<"\n\n-----------------------TIENDA (PRECIOS A LOS PRODUCTOS)--------------------\n";
        cout<<"\t\nMENU\n\t(1)INSERTAR  NOMBRE Y PRECIO AL PRODUCTO\n\t(2)MOSTRAR PRODUCTO COSTO\n\t(3)BORRAR COSTO PRODUCTO\n\t(4)SALIR\n";
        cin>>menu;
        switch(menu)
        {
        case 1:
            cout << "\tSALIR OPRIMA  -1" << endl;
            do
            {
                cout << "\t NOMBRE DEL  PRODUCTO  : >>>>>>>>   ";

                cin >>nomb;
                insertartiendanombre(nomb);
                /////////////////////


                /////////
                cout << "\t PRECIO PRODUCTO  : >>>>>>>>   ";
                cin >> dato;
                total=total+dato;
                if(dato != -1)
                {
                    cuenta++;
                    insertartienda(dato);
                }


            }
            while (dato != -1 );

            break;
        case 2:
            cout<<"\t\tPRODUCTOS\n";
            mostrartienda();


            break;
        case 3:
            int variable,respuesta;
            do
            {
                mostrartienda();
                cout<<"\tEliminar producto ponga el precio (FIN -1)"<<endl;
                cin>>variable;
                total=total-variable;
                eliminartienda(variable);

            }
            while (variable!= -1);
            cout<<"\t\tPRODUCTOS\n";
            mostrartienda();
            break;

        default:
            break;



        }
    }
    while (menu !=4);



    cout<<"\n\tFINAL";




    //cin.get();
    return 0;
}

void insertartienda(int valor)
{
    actual=inicio;
    if(actual == NULL)
    {
        aux = new tienda();
        aux->dato = valor;
        aux->siguiente = NULL;
        inicio = aux;
    }
    else
    {
        while(actual->siguiente != NULL)
        {
            actual=actual->siguiente;
        }
        aux = new tienda();
        aux->dato = valor;
        aux->siguiente = NULL;
        actual->siguiente = aux;
    }

}

void mostrartienda()
{
    actual = inicio;
    actual1=inicio1;
    int contador=0;
    do
    {
        contador++;
       /// cout<<"Nombre >>>>"<<actual1->nombre<<endl;
       cout<<endl;
        cout <<"\t\t"<<"Producto.-"<< contador <<"  "<<actual1->nombre<<"........$" << actual->dato << ".00" << endl;

        ///actual1=actual1->siguiente1;
        actual=actual->siguiente;
        actual1=actual1->siguiente1;
    }
    while(actual!= NULL);
cout<<"\t\t\t\t\t\t\tTOTAL........"<<total;



}

void posicion(int valor)
{
    actual = inicio;
    int contador=0;
    do
    {
        contador++;
        if(contador == valor)
        {
            cout <<"\t\t"<< contador <<".- " << actual->dato << " " << endl;
        }

        actual=actual->siguiente;
    }
    while(actual!= NULL);
}
void ordenar(int cantidad)
{
    tienda *aux1;
    //aux1 = inicio;

    do
    {
        actual=inicio;
        while (actual->siguiente != NULL)
        {

            aux = actual->siguiente;

            while(aux != NULL)
            {

                if(actual->dato > actual->siguiente->dato)
                {

                    aux1->dato = actual->dato;
                    actual->dato = actual->siguiente->dato;
                    actual->siguiente->dato = aux1->dato;

                }
                aux = aux->siguiente;

            }

            actual = actual->siguiente;
        }

        cantidad--;
    }
    while(cantidad != 0);
}
void eliminartienda(int valor)
{
    if(inicio!=NULL)
    {
        aux=NULL;
        aux1=NULL;
        actual=inicio;
        ///total-actual;
        actual1=inicio1;
        while((actual!=NULL) && (actual->dato!=valor))
        {
            aux=actual;

            aux1=actual1;
            actual=actual->siguiente;


            actual1=actual1->siguiente1;
        }
        if(actual==NULL)
        {
            cout<<"\n\n\t\t\tDATO NO EXISTE"<<endl;
        }
        else if(aux==NULL)
        {
            inicio=inicio->siguiente;
            inicio1=inicio1->siguiente1;

            delete actual1;
            delete actual;

        }
        else
        { aux1->siguiente1=actual1->siguiente1;
            aux->siguiente=actual->siguiente;
            delete actual1;
            delete actual;
        }
    }
}

void insertartiendanombre(string  nomb)
{
    actual1=inicio1;
    if(actual1 == NULL)
    {
        aux1 = new tienda();
        aux1->nombre = nomb;
        aux1->siguiente1 = NULL;
        inicio1 = aux1;
    }
    else
    {
        while(actual1->siguiente1 != NULL)
        {
            actual1=actual1->siguiente1;
        }
        aux1 = new tienda();
        aux1->nombre = nomb;
        aux1->siguiente1 = NULL;
        actual1->siguiente1 = aux1;
    }

}

