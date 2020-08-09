
#include <string>
#include <list>
#include <vector>
using namespace std;

class nodoSimple{
public:
    //---MOUNT
    char letra;
    int numero;
    string path;
    string name;
    nodoSimple*siguiente;
    nodoSimple(char letra, int numero, string path,string name){
        this->letra=letra;
        this->numero=numero;
        this->path=path;
        this->name=name;
        this->siguiente=0;
    }
    //---COMANDO
    string contenido;
    string atributo;
    nodoSimple(string atributo,string contenido){
        this->contenido=contenido;
        this->atributo=atributo;
        this->siguiente=0;
    }
    //---LISTADO
    vector<nodoSimple*> listado;
    void agregar(nodoSimple *nodo){
        listado.push_back(nodo);
    }
    void agregarSiguiente(nodoSimple *nodo){
        siguiente=nodo;
    }
};
