#include "GrafoDirigido.h"

template <typename T> GrafoDirigido<T>::Arco::Arco()
{

}


template <typename T> GrafoDirigido<T>::Arco::Arco(int adyacente, const T & costo)//Complejidad O(1).
{
	vertice = adyacente;
	this->costo = costo;
}


template <typename T> int GrafoDirigido<T>::Arco::devolver_adyacente() const//Complejidad O(1).
{
	return vertice;
}


template <typename T> const T & GrafoDirigido<T>::Arco::devolver_costo() const//Complejidad O(1).
{
	return costo;
}


template <typename T> void GrafoDirigido<T>::Arco::modificar_costo(const T & costo)
{
    this->costo = costo;
}


template <typename T> GrafoDirigido<T>::GrafoDirigido()
{

}


template <typename T> GrafoDirigido<T>::GrafoDirigido(const GrafoDirigido & otroGrafo)// Complejidad O(1).
{
    this->Grafo=otroGrafo.Grafo;
}


template <typename T> GrafoDirigido<T>::~GrafoDirigido()
{

}


template <typename T> bool GrafoDirigido<T>::es_vacio() const//Complejidad O(1).
{
	return Grafo.empty();//----->O(1)
}


template <typename T> int GrafoDirigido<T>::devolver_longitud() const//Complejidad O(1).
{
	return Grafo.size();//----->O(1)
}


template <typename T> bool GrafoDirigido<T>::existe_vertice(int vertice) const//Complejidad O(log n).
{
    typename map<int, Vertice>::const_iterator it=Grafo.find(vertice);//----->O(log n)
    if (it!=Grafo.end())
        return true;
    else
        return false;
}


template <typename T> bool GrafoDirigido<T>::existe_arco(int origen, int destino) const//Complejidad O(n) dado que se da una busqueda dentro de la lista de arcos.
{
    bool existe=false;
    typename map<int, Vertice>::const_iterator it=Grafo.find(origen);//----->O(log n)
    if (it!=Grafo.end())
    {
        typename list<Arco>::const_iterator it2=it->second.adyacentes.begin();
        while (!existe && (it2!=it->second.adyacentes.end()))//----->O(n)
        {
            if (it2->devolver_adyacente()==destino)
            {
                existe=true;
            }
            it2++;
        }
    }
    return existe;
}


template <typename T> const T & GrafoDirigido<T>::costo_arco(int origen, int destino) const//Complejidad O(n) con n igual al recorrido para encontrar el arco.
{
    if (existe_arco(origen, destino)==true)
    {
        bool encontrado=false;
        typename map<int, Vertice>::const_iterator it=Grafo.find(origen);//----->O(log n)
        if (it!=Grafo.end())
        {
            typename list<Arco>::const_iterator it2=it->second.adyacentes.begin();
            while (!encontrado && (it2!=it->second.adyacentes.end()))//----->O(n)
            {
                if (it2->devolver_adyacente()==destino)
                {
                    return it2->devolver_costo();
                    encontrado=true;
                }
                it2++;
            }
        }
    }
}


template <typename T> void GrafoDirigido<T>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const//Complejidad O(n) con n igual al recorrido de busqueda del arco.
{
    adyacentes.clear();
    typename map<int,Vertice>::const_iterator it = Grafo.find(origen);//----->O(log n)
	if ( it != Grafo.end())
    {
		typename list<Arco>::const_iterator it2 = it->second.adyacentes.begin();
		while ( it2 != it->second.adyacentes.end())//----->O(n)
		{
			adyacentes.push_back(Arco(it2->devolver_adyacente(),it2->devolver_costo()));
			it2++;
		}
	}
}


template <typename T> void GrafoDirigido<T>::agregar_vertice(int vertice, int costo)//Complejidad O(log n).
{
    if (!existe_vertice(vertice))
    {
        Grafo[vertice];
        typename map<int, Vertice>::iterator it=Grafo.find(vertice);//----->O(log n)
        it->second.Costo=costo;
    }
}


template <typename T> void GrafoDirigido<T>::agregar_arco(int origen, int destino, const T & costo)//Complejidad O(log n)
{
    if ( existe_vertice(origen) && existe_vertice(destino) && !existe_arco(origen,destino))
    {
		typename map<int,Vertice>::iterator it = Grafo.find(origen);//----->O(log n)
		it->second.adyacentes.push_back(Arco(destino, costo));
	}
}


template <typename T> GrafoDirigido<T> & GrafoDirigido<T>::operator = (const GrafoDirigido & otroGrafo)
{
	this->Grafo = otroGrafo.Grafo;
	return *this;
}


template <typename T> void GrafoDirigido<T>::devolver_vertices(list<int> & vertices) const//Complejidad O(n)
{
	typename map <int, Vertice>::const_iterator it = Grafo.begin();//----->O(1)
	while ( it != Grafo.end())//----->O(n)
    {
		vertices.push_back(it->first);//----->O(1)
		it++;
	}
}


template <typename T> void GrafoDirigido<T>::eliminar_vertice(int vertice)//Complejidad O(log n)
{
    Grafo.erase(vertice);//----->O(log n)
}


template <typename T> void GrafoDirigido<T>::modificar_costo_arco(int origen, int destino, const T & costo)//Complejidad O(n) con n igual a la iteracion para encontrar el arco.
{
    if (existe_vertice(origen) && existe_vertice(destino) && existe_arco(origen,destino))
    {
        bool encontrado=false;
        typename map<int, Vertice>::iterator it=Grafo.find(origen);//----->O(log n)
        typename list<Arco>::iterator it2=it->second.adyacentes.begin();
        while (!encontrado &&(it2!=it->second.adyacentes.end()))//----->O(n)
        {
            if (it2->devolver_adyacente()==destino)
            {
                it2->modificar_costo(costo);
                encontrado=true;
            }
            it2++;
        }
	}
}


template <typename T> void GrafoDirigido<T>::eliminar_arco(int origen, int destino)//Complejidad O(n) con n igual a la iteracion para encontrar el arco.
{
    if (existe_vertice(origen) && existe_vertice(destino) && existe_arco(origen,destino))
    {
        bool encontrado=false;
        typename map<int, Vertice>::iterator it=Grafo.find(origen);//----->O(log n)
        typename list<Arco>::iterator it2=it->second.adyacentes.begin();
        while (!encontrado &&(it2!=it->second.adyacentes.end()))//----->O(n)
        {
            if (it2->devolver_adyacente()==destino)
            {
                encontrado=true;
            }
            it2++;
        }
        it2--;//Sino se pasa por 1, dado el ultimo ciclo del while.
        it->second.adyacentes.erase(it2);
	}
}


template <typename T> const T & GrafoDirigido<T>::devolver_costo_vertice(int vertice)const//Complejidad O(log n)
{
    typename map<int, Vertice>::const_iterator it=Grafo.find(vertice);//----->O(log n)
    return it->second.Costo;
}


template class GrafoDirigido <int>;
