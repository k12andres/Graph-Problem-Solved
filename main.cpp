#include <iostream>
#include <GrafoDirigido.h>
#include <map>
#include <conio.h>

using namespace std;

void Floyd(const GrafoDirigido<int> & g, int,int);
void camino (int P[][12], int , int );
void ArmarVertices(GrafoDirigido<int> & g);
void AgregarArcos (GrafoDirigido<int> & g);
void EjecutarBusqueda (GrafoDirigido<int> & g);
void menu (GrafoDirigido<int> & g);

int main()
{
    GrafoDirigido<int> g;
    menu(g);
    cout<<"Hasta lueguito.";//Fin del programa.
    /*
    //Estructura prearmada por si se quiere probar el funcionamiento sin cargar.
    //VERTICES
    g.agregar_vertice(0,0);
    g.agregar_vertice(1,4);
	g.agregar_vertice(2,4);
	g.agregar_vertice(3,10);
	g.agregar_vertice(4,13);
	g.agregar_vertice(5,1);
	g.agregar_vertice(6,11);
	g.agregar_vertice(7,2);
	g.agregar_vertice(8,3);
	g.agregar_vertice(9,3);
	g.agregar_vertice(10,6);
    //ARCOS
    g.agregar_arco(0,1,0);
    g.agregar_arco(0,2,0);
    g.agregar_arco(0,3,0);
    g.agregar_arco(1,4,10);
    g.agregar_arco(4,8,8);
    g.agregar_arco(2,5,12);
    g.agregar_arco(2,6,4);
    g.agregar_arco(5,10,4);
    g.agregar_arco(6,10,8);
    g.agregar_arco(3,7,2);
    g.agregar_arco(7,9,4);
    g.agregar_arco(9,10,3);
    */
    return 0;
}

void menu(GrafoDirigido<int> & g)//Complejidad O(n^3) por contener la funcion que ejecuta floyd.
{
    cout<<"Bienvenido al Mundo Grafo.\n\n";
    cout<<"1- Ingresar vertices.\n";
    cout<<"2- Ingresar arcos.\n";
    cout<<"3- Realizar busqueda.\n";
    cout<<"4- Salir.\n";

    int rta;
    cin>>rta;
    switch(rta)
    {
        case 1:
            system("cls");
            ArmarVertices(g);
            break;
        case 2:
            system("cls");
            AgregarArcos(g);
            break;
        case 3:
            system("cls");
            EjecutarBusqueda(g);
    }
}

void AgregarArcos(GrafoDirigido<int> & g)//Complejidad O(1)
{
    int Origen, Destino, Costo;
    string respuesta;
    cout<<"Elija el vertice Origen.\n";
    cin>>Origen;
    cout<<"Elija el vertice Destino.\n";
    cin>>Destino;
    cout<<"Cual es el costo?\n";
    cin>>Costo;
    g.agregar_arco(Origen, Destino, Costo);
    cout<<"Desea agregar otro arco?(Y/N)\n";
    cin>>respuesta;
    if ((respuesta=="y") || (respuesta=="Y"))
    {
        AgregarArcos(g);
        system("cls");
    }
    else
    {
        system("cls");
        menu(g);
    }
}

void EjecutarBusqueda (GrafoDirigido<int> & g)//Complejidad O(n^3) por ejecutar floyd.
{
    int Origen, Destino;
    cout<<"Elija el vertice Origen.\n";
    cin>>Origen;
    cout<<"Elija el vertice Destino.\n";
    cin>>Destino;
    Floyd(g, Origen, Destino);
    menu(g);
}

void ArmarVertices(GrafoDirigido<int> & g)//Complejidad O(1)
{
    int vertice, costo;
    string respuesta;
    cout<<"Ingrese el numero del vertice y luego el costo\n";
    cin>>vertice;
    cin>>costo;
    g.agregar_vertice(vertice, costo);
    cout<<"Desea agregar mas vertices?(Y/N)\n";
    cin>>respuesta;
    if ((respuesta=="y") || (respuesta=="Y"))
    {
        system("cls");
        ArmarVertices(g);
    }
    else
    {
        system("cls");
        menu(g);
    }
}

void Floyd (const GrafoDirigido<int> & g, int origen, int destino)//Complejidad O(n^3)
{
	int u = g.devolver_longitud()-1;
	int A[12][12];
	int P[12][12];

	for ( int j = 0 ; j <= u ; j++ )
	{
		for ( int i = 0 ; i <= u ; i++ )
        {
            if ((g.existe_arco(j,i)==true) && (i!=j))
                {
                    A[j][i] = g.costo_arco(j,i)+g.devolver_costo_vertice(i);
                }
                else
                    A[j][i] = -1;//Representa el valor discernible
		}
	}

	for ( int j = 0 ; j <= u ; j++ )
	{
		for ( int i = 0 ; i <= u ; i++ )
        {
			P[j][i] = 0;
		}
	}


	for ( int k = 0 ; k <= u ; k++)
    {
		for ( int i = 0 ; i <= u ; i++ )
		{
			for ( int j = 0 ; j <= u ; j++ )
            {
				if ((A[i][k]!=-1) && (A[k][j]!=-1))//----->O(n^3)
                {
                    int a = A[i][k] + A[k][j] + g.devolver_costo_vertice(i)+ g.devolver_costo_vertice(j) + g.devolver_costo_vertice(k);
                    int b = A[i][j];
                    if (a > b)
                    {
                        A[i][j] = a;
                        P[i][j] = k;
                    }
                }
			}
		}
	}
    unsigned int k= P[origen][destino];
    if (k<=0)
    {
        cout<<"No existe vertice.";
    }
    else
    {
        cout<<"El camino es: " ;
        camino(P, origen, destino);
    }
	return;
}

void camino (int P[][12], int i, int j)//Complejidad O(log n) dado n el camino realizado.
{
    unsigned int k= P[i][j];
    if (k>0)
    {
       camino (P, i, k);
       cout<<k<< " ";
       camino (P, k, j);
    }
}
