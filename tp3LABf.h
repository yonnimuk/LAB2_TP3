#ifndef TP3LABF_H_INCLUDED
#define TP3LABF_H_INCLUDED
#include <stdlib.h>
using namespace std;


struct producto
{
    int id;
    char nombre[30];
    float precio;
    int stock;
    int stock_minimo;
};
/*int menu(){
       int p;
        cout << "MENU DE PRODUCTOS." << endl;
        cout << "--------------------------------------------"<<endl;
        cout << "1 - Cargar Productos." << endl;
        cout << "2 - Editar Producto por ID." << endl;
        cout << "3 - Listar Productos por ID." << endl;
        cout << "4 - Listar Productos (ordenados por precio)." << endl;
        cout << "--------------------------------------------" << endl;
        cout << "0 - Salir." << endl;
        cin >> p;

    return p;
}*/

void cargar_producto(struct producto *vec,int tam)
{
    char res;
    for(int i=0; i<tam; i++)
    {
        system("cls");
        cout << "*[Cargando producto " << i+1 <<"/10]*" <<endl;
        cout << "Cargue el ID de el producto: " << endl;
        cin >> vec[i].id;
        for(int x=0; x<i; x++)
        {
            if(vec[i].id == vec[x].id)
            {
                cout << "El ID ingresado ya esta en uso. por favor ingrese otro: " <<endl;
                cin >> vec[i].id;
                while(vec[i].id == vec[x].id)
                {
                    cout << "El ID ingresado ya esta en uso. por favor ingrese otro: " <<endl;
                    cin >> vec[i].id;
                }
            }
        }
        cout << "Cargue el NOMBRE de el producto: " << endl;
        cin >> vec[i].nombre;
        cout << "Cargue el precio: " << endl;
        cin >> vec[i].precio;
        cout << "Cargue el STOCK de el producto: " << endl;
        cin >> vec[i].stock;
        cout << "Cargue el STOCK MINIMO de el producto: " << endl;
        cin >> vec[i].stock_minimo;
        cout << "Desea finalizar? para si(s) para no(n): " << endl;
        cin >>res;
        if(res=='s')
        {
            return;
        }

    }


}
void editar_x_id(struct producto *vec,int tam)
{
    int iidd;
    char s;
    bool entrar=true;
    while(entrar)
    {
            cout << "ingrese el ID de el producto que desea modificar: " << endl;
            cin >> iidd;
        for(int i=0; i<tam; i++)
        {

            if(vec[i].id==iidd)
            {
                cout << "[********|ingrese los cambios deseados|******** ]" << endl;
                cout << "Nombre anterior: " << vec[i].nombre <<endl;
                cout << "Ingrese el Nombre nuevo: " << endl;
                cin >> vec[i].nombre;
                cout<<endl;
                cout << "Precio anterior: " << vec[i].precio << endl;
                cout << "Cargue el precio: " << endl;
                cin >> vec[i].precio;
                cout<<endl;
                cout << "Stock anterior: " << vec[i].stock <<endl;
                cout << "Ingrese el Stock nuevo: " << endl;
                cin >> vec[i].stock;
                cout<<endl;
                cout << "Stock minimo anterior: " << vec[i].stock_minimo <<endl;
                cout << "Ingrese el Stock minimo nuevo: " << endl;
                cin >> vec[i].stock_minimo;

            }
            else if(i==tam)
            {
                cout << "el ID ingresado no existe." << endl;
            }


        }
            cout << "Continuar?. para si toque (s), para no (n)" << endl;
            cin >> s;
            cin.ignore();
            switch(s)
            {
            case('s'):
            {
                cout << "-------------------ENTER PARA CONTINUAR.------------------------------" << endl;
            }
            break;
            case('n'):
            {
                entrar = false;
                return;
            }
            break;
            default:
            {
                cout << "opcion invalida." << endl;
            }
            break;
            }
            cin.get();


    }

}
void mostar_x_id(struct producto *vec, int tam)
{
    bool enter=true;
    int ido;
    char letra;
    while(enter)
    {
        cout << "Indique el ID de el producto q desea ver:" << endl;
        cin >> ido;
        for(int i=0;i<tam;i++)
        {
            if(ido == vec[i].id)
            {
                cout << "el producto con el ID: " << ido << endl;
                cout << "Tiene el nombre de: " << vec[i].nombre << endl;
                cout << "El precio es: " << vec[i].precio << endl;
                cout << "Su stock es: " << vec[i].stock << endl;
                cout << "Su stock minimo es: " << vec[i].stock_minimo <<endl;
                system("pause");
            }else if (i == tam)
            {
                cout << "-El id ingresado no existe.-" <<endl;
                system("pause");
            }
        }
        cout << "Desea ver otro producto? (s)para si//(n)para no..." << endl;
        cin >>letra;
        cin.ignore();
        if(letra == 'n')
        {
            enter=false;
        }
    }
}

void listar_x_precio(struct producto *vec, int tam)
{
    struct producto aux;
    for(int i=0; i<tam; i++)
    {
        for(int x=0; x<tam; x++)
        {
            if(vec[x].precio<vec[x+1].precio)
            {
                aux=vec[x];
                vec[x]=vec[x+1];
                vec[x+1]=aux;
            }
        }
    }

}

void listar_x_precioII(struct producto *vec, int tam){
    for(int i=0; i<tam;i++){
    if(!vec[i].precio==0)
    {
    cout<< "ID del producto: " << vec[i].id <<endl;
    cout<< "Nombre del producto: " << vec[i].nombre <<endl;
    cout<< "Precio del producto: $" << vec[i].precio <<endl;
    cout<< "Stock del producto: " << vec[i].stock <<endl;
    cout<< "Stock minimo del producto: " << vec[i].stock_minimo <<endl;
    }
    }
    system("pause");
}


#endif // TP3LABF_H_INCLUDED
