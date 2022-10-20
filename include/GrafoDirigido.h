#ifndef GRAFODIRIGIDO_H
#define GRAFODIRIGIDO_H
#include <list>
#include <map>


using namespace std;

template <typename T>
class GrafoDirigido
{

    public:
        class Arco
        {
        public:
            Arco();
            Arco(int adyacente, const T & costo);
            int devolver_adyacente() const;
            const T & devolver_costo() const;
            void modificar_costo(const T & costo);
        private:
            int vertice;
            T costo;
        }; //FIN DE LA CLASE ARCO

    public:

    GrafoDirigido();
	GrafoDirigido(const GrafoDirigido & otroGrafo);

	~GrafoDirigido();

	GrafoDirigido & operator = (const GrafoDirigido & otroGrafo);//REVISAR

	bool es_vacio() const;// Devuelve true si la cantidad de vértices es cero

	int devolver_longitud() const;// Indica la cantidad de vértices del grafo

	bool existe_vertice(int vertice) const;

	bool existe_arco(int origen, int destino) const;

	// PRE CONDICION: existe_arco(origen, destino)
	const T & costo_arco(int origen, int destino) const;

	void devolver_vertices(list<int> & vertices) const;

	void devolver_adyacentes(int origen, list<Arco> & adyacentes) const;

	void agregar_vertice(int vertice, int costo);

	// POST CONDICION: Para todo vértice v != vertice: !existeArco(v, vertice) && !existeArco(vertice, v)
	void eliminar_vertice(int vertice);

	// PRE CONDICION: existeArco(origen, destino)
	void modificar_costo_arco(int origen, int destino, const T & costo);

	// PRE CONDICION: existeVertice(origen) && existeVertice(destino)
	// POST CONDICION: existeArco(origen, destino)
	void agregar_arco(int origen, int destino, const T & costo);

	// POST CONDICION: !existeArco(origen, destino)
	void eliminar_arco(int origen, int destino);

	const T & devolver_costo_vertice(int vertice)const;


    private:
        struct Vertice
        {
            int Num_Vertice;
            T Costo;
            list<Arco> adyacentes;
        };

        map<int, Vertice> Grafo;
};

#endif // GRAFODIRIGIDO_H
