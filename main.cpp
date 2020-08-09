#include <QCoreApplication>
#include <string>
#include <iostream>
#include <stdio.h>
#include <QString>
#include <QDebug>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include <unistd.h>
#include "scanner.h"
#include "parser.h"
#include "nodo.h"
#include <cstdlib>

#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yyparse();
extern nodoSimple *raiz;

using namespace std;


//---------------------------CLASES-----------------------//



class listaSimple{
public:
    nodoSimple*cabeza;
    listaSimple(){
        this->cabeza=0;
    }
    void agregar(nodoSimple*nodo){

        if(cabeza == 0){
            cabeza = nodo;
        }else{
            nodoSimple*temp =cabeza;
            while(temp->siguiente!=0){
                temp = temp->siguiente;
            }
            temp->siguiente = nodo;
        }
    }
    bool eliminar(string id){
        if(cabeza!=0){
            string completo="vd";
            completo+= cabeza->letra;
            completo+=to_string(cabeza->numero);
            if(completo == id){
                cabeza = cabeza->siguiente;
                return 1;
            }else{
                nodoSimple*temp=cabeza;
                nodoSimple*actual=0;
                while(temp!=0){
                    completo = "vd";
                    completo+= temp->letra;
                    completo+= to_string(temp->numero);
                    if(completo == id){
                        actual->siguiente = temp->siguiente;
                        return true;
                    }
                    actual =temp;
                    temp = temp->siguiente;
                }
            }
        }
        return false;
    }


    bool getMount(string path, string name){
        nodoSimple*temp = cabeza;
        while(temp!=0){
            if(path==temp->path && name==temp->name){
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }

    //---Metodos auxiliares

    string getPath(string id){
        string path="";
        nodoSimple*temp =cabeza;
        while(temp!=0){
            string completo = "vd";
            completo+= temp->letra;
            completo+= to_string(temp->numero);
            if(completo == id){
                return temp->path;
            }
            temp= temp->siguiente;
        }
        return path;
    }

    nodoSimple *getNodo(string id){
        nodoSimple*temp =cabeza;
        while(temp!=0){
            string completo = "vd";
            completo+= temp->letra;
            completo+= to_string(temp->numero);
            if(completo == id){
                return temp;
            }
            temp= temp->siguiente;
        }
        return temp;
    }




    int getLetra(string path,string name){
        int letra=97;          //---valor ASCII 'a'
        nodoSimple*temp=cabeza;
        while(temp!=0){
            if(path==temp->path&&name==temp->name){
                return 0;
            }

            if(path==temp->path){
                return temp->letra;
            }
            else if(letra<=temp->letra){
                letra++;
            }
            temp=temp->siguiente;
        }
        return letra;
    }

    int getNumero(string path){
        int numero=1;
        nodoSimple*temp = cabeza;
        while(temp!=0){
            if(path ==temp->path&&numero == temp->numero){
                numero++;
            }
            temp= temp->siguiente;
        }
        return numero;
    }

    void recorrer(){
        nodoSimple*temp = cabeza;
        int cont=1;
        cout<<"---------MOUNTS----------"<<endl;
        while(temp!=0){
            string id = "vd";
            id+= temp->letra;
            id+= to_string(temp->numero);
            cout<<to_string(cont)+". "+id+" -> "+temp->name<<endl;
            temp= temp->siguiente;
        }
        cout<<"-------------------------"<<endl;
    }

};

//---------------------------STRUCTS-----------------------//

typedef struct {
    char part_status;
    char part_type;
    char part_fit[3];
    int part_start;
    int part_size;
    char part_name[16];
} PARTITION;

typedef struct{
    int mbr_tamanio;
    time_t mbr_fecha_creacion;
    int mbr_disk_signature;
    char disk_fit[3];
    PARTITION mbr_partition[4];
}MBR;

typedef struct{
    char part_status;
    char part_fit[3];
    int part_start;
    int part_size;
    int part_next;
    char part_name[16];
}EBR;

typedef struct{
    int s_filesystem_type;
    int s_inodes_count;
    int s_blocks_count;
    int s_free_blocks_count;
    int s_free_inodes_count;
    time_t s_mtime;
    time_t s_umtime;
    int s_mnt_count;
    int s_magic;
    int s_inode_size;
    int s_block_size;
    int s_first_ino;
    int s_first_blo;
    int s_bm_inode_start;
    int s_bm_block_start;
    int s_inode_start;
    int s_block_start;
    int n;
}SUPERBLOCK;

typedef struct{
    int i_uid;
    int i_gid;
    int i_size;
    time_t i_atime;
    time_t i_ctime;
    time_t i_mtime;
    int i_block[15];
    char i_type;
    int i_perm;
}INODE;

typedef struct{
    time_t time;
    char user[12];
    char operation[256];
}JOURNALING;

typedef struct{
    char b_content[64];
}FILEBLOCK;

typedef struct{
    char b_name[12];
    int b_inodo;
}CONTENT;

typedef struct{
    CONTENT b_content[4];
}FOLDERBLOCK;

typedef struct{
    int b_pointers[16];
}POINTERBLOCK;

typedef struct{
    int id_user;
    int id_grp;
    char nombre[10];
    char grupo[10];
    int inicioSuper;
    char path[400];
    char fit;
}SESSION;
//---------------------------PARSER-----------------------//


string parse(char* a){
    string final=a;
    return final;
}
string parseContent(char* a){
    int i=0;
    char actual=a[i];
    string final="";
    while(actual!=0){
        if(actual=='\n'){
            final+="<br ALIGN=\"left\"/>";
        }
        else{
            final+=actual;
        }
        i++;
        actual=a[i];
    }
    final+="<br ALIGN=\"left\"/>";
    return final;
}

string parseDouble(double k){
    string buf;
    string ff=to_string(k);
    stringstream ss(ff);
    vector<string> test;

    while (getline(ss, buf, '.')){
        test.push_back(buf);
    }
    string parse=test[0]+"."+test[1][0]+test[1][1];
    return parse;
}

//---------------------------GLOBALES----------------------//

bool activo=false;
bool activoREM=false;
bool reporte=false;
bool cambioNombre=false; //---REN activo
bool cambioCHMOD=false;
bool cambioCHOWN=false;
bool cambioEDIT=false;


char fitLogica;

string nombre;
string directorio;
string extension;
string contenidoEXEC;
string recorrido;
string nuevoNombre; //---almacena el nuevo nombre en comando REN

int idxff;
int idxbf;
int idxwf;

int indexP;
int indexE;
int byteP;

int cambioPermiso;
/*
int byteFF;
int byteBF;
int byteWF;
*/


SESSION sesion;
SESSION sesionAux;



listaSimple *mountList=new listaSimple();

//---------------------------METODOS-------------------------//

//---------------INICIO---COMANDOS PRINCIPALES-------------------------//



void setDatos(string aux){
    nombre="";
    directorio="";
    extension="";
    string buf;
    stringstream ss(aux);

    vector<string> tokens;
    vector<string> test;

    while (getline(ss, buf, '/')){
        tokens.push_back(buf);
    }

    for(size_t i=0; i<tokens.size()-2; ++i){
        directorio+="/"+tokens[i+1];
    }

    nombre=tokens[tokens.size()-1];
    directorio+="/";

    stringstream ff(nombre);

    while (getline(ff, buf, '.')){
        test.push_back(buf);
    }
    extension=test[1];
    nombre=test[0];

}

bool comprobarExistente(string aux){
    FILE *disco;
    if((disco=fopen(aux.c_str(),"r"))){
        fclose(disco);
        return true;
    }
    return false;
}

FILE *comprobarEdicion(string aux){
    return fopen(aux.c_str(), "rb+");
}

FILE *comprobarLectura(string aux){
    return fopen(aux.c_str(), "r+");
}



bool comprobarParticion(string path, string particion){
    indexP=-1;
    byteP=-1;
    indexE=-1;

    FILE *disco=comprobarEdicion(path);
    if(disco){
        MBR mbr;
        fseek(disco,0,SEEK_SET);
        fread(&mbr, sizeof(MBR),1,disco);
        for(int i = 0; i < 4; i++){
            if(parse(mbr.mbr_partition[i].part_name)==particion){
                indexP=i;
                fclose(disco);
                return true;
            }else if(mbr.mbr_partition[i].part_type == 'e'){
                indexE=i;
            }
        }
        if(indexE!=-1){
            cout<<"dentro?"<<endl;
            fseek(disco, mbr.mbr_partition[indexE].part_start,SEEK_SET);
            EBR ebr;
            int part_end=mbr.mbr_partition[indexE].part_start + mbr.mbr_partition[indexE].part_size;

            while((fread(&ebr,sizeof(EBR),1,disco))!=0 && (ftell(disco) < part_end)){
                if(parse(ebr.part_name)==particion){
                    byteP=ftell(disco) - sizeof(EBR);
                    fitLogica=ebr.part_fit[0];
                    fclose(disco);
                    return true;
                }
                if(ebr.part_next == -1){
                    fclose(disco);
                    return false;
                }
            }
        }
    }
    fclose(disco);
    return false;
}



bool crearArchivo(){
    string aux =directorio+nombre+"."+extension;
    string mkdir = "sudo mkdir -p \'"+directorio+"\'";
    system(mkdir.c_str());
    string chmod = "sudo chmod 777 \'"+directorio+"\'";
    system(chmod.c_str());
    if(!comprobarExistente(aux)){
        fopen(aux.c_str(),"wb");
        return false;
    }
    return true;
}


/*
 * Al momento de realizar el analisis de comandos, colocar todos los atributos por defecto
 * de manera que, si viene uno, se le asigne y sha. Pero en caso no exista, se colocara 0 o NONE
 * Adicional, si no llega a cumplir con los parametros minimos ni siquiera mandarlo XD
 */


int getPart_size(string unit, int size){
    int part_size=0;

    if(unit == "b"){
        part_size = size;
    }
    else if(unit == "k"){
        part_size = size * 1024;
    }
    else{
        part_size= size*1024*1024;
    }
    return part_size;
}


void MKDISK(int size,string fit,string unit,string path){
    setDatos(path);
    if(!crearArchivo()){
        MBR mbr;
        string auxNombre=nombre;
        nombre=nombre+"_raid";

        crearArchivo();

        int mbr_tamanio=getPart_size(unit,size);

        mbr.mbr_tamanio=mbr_tamanio;
        mbr.mbr_fecha_creacion = time(0);
        mbr.mbr_disk_signature = (int)time(0);
        strcpy(mbr.disk_fit,fit.c_str());

        for(int i = 0; i < 4; i++){
            mbr.mbr_partition[i].part_status = '0';
            mbr.mbr_partition[i].part_type = '0';
            strcpy(mbr.mbr_partition[i].part_fit,"");
            mbr.mbr_partition[i].part_size = 0;
            mbr.mbr_partition[i].part_start = -1;
            strcpy(mbr.mbr_partition[i].part_name,"");
        }

        FILE *disk = fopen(path.c_str(),"rb+");
        char test[1000];
        test[0]='0';
        mbr_tamanio=mbr_tamanio/1024;
        for(int i=0;i<mbr_tamanio;i++){
            fwrite(&test,sizeof (test),1,disk);
        }
        fseek(disk,0,SEEK_SET);
        fwrite(&mbr,sizeof(MBR),1,disk);
        fclose(disk);

        string aux=directorio+nombre+"."+extension;
        FILE *diskRaid = fopen(aux.c_str(),"rb+");
        for(int i=0;i<mbr_tamanio;i++){
            fwrite(&test,sizeof (test),1,diskRaid);
        }
        fseek(diskRaid,0,SEEK_SET);
        fwrite(&mbr,sizeof(MBR),1,diskRaid);
        fclose(diskRaid);

        cout << "Disco "+auxNombre+" creado con exito" << endl;

    }
    else{
        cout << "No se ha podido crear el disco "+ nombre << endl;
    }

}

void RMDISK(string path){
    setDatos(path);
    if(comprobarExistente(path)){
        cout<<"Permitir eliminar disco "+nombre+"? (Y/N)"<<endl;
        while(true){

            string ss="";
            cin>>ss;
            if(ss=="Y"){
                string rmdisk = "rm \""+path+"\"";
                system(rmdisk.c_str());
                cout <<"Disco "+nombre+" eliminado"<< endl;
                break;
            }else if(ss=="N"){
                break;
            }
        }
    }
    else{
        cout<<"No existe el disco"+nombre<<endl;
    }
}


void setFit(MBR mbr,int size){

    idxff=-1;
    idxbf=-1;
    idxwf=-1;

    for(int i= 0; i < 4; i++){
        if(mbr.mbr_partition[i].part_start == -1||(mbr.mbr_partition[i].part_status == '1' && mbr.mbr_partition[i].part_size>=size)){
            if(idxff==-1){
                idxff=i;
                idxbf=i;
                idxwf=i;
            }else{
                if(mbr.mbr_partition[idxbf].part_size>mbr.mbr_partition[i].part_size){
                    idxbf=i;
                }
                if(mbr.mbr_partition[idxwf].part_size<mbr.mbr_partition[i].part_size){
                    idxwf=i;
                }
            }
        }
    }




}




int comprobarExtendida(MBR mbr){
    for(int i = 0; i < 4; i++){
        if (mbr.mbr_partition[i].part_type == 'e'){
            return i;
        }
    }
    return -1;
}


void crearPrimariaExtendida(MBR mbr, FILE *disco,string fit,string unit,int size, int i,char part_type,string name){

    char contenido='1';
    int part_start=0;
    int part_size=size;


    if(i == 0){
        part_start=sizeof(mbr);
    }
    else{
        int anteriorInicio=mbr.mbr_partition[i-1].part_start;
        int anteriorTamanio=mbr.mbr_partition[i-1].part_size;
        part_start = anteriorInicio+anteriorTamanio;
    }



    mbr.mbr_partition[i].part_status = '0';
    mbr.mbr_partition[i].part_type = part_type;
    strcpy(mbr.mbr_partition[i].part_fit,fit.c_str());
    mbr.mbr_partition[i].part_start=part_start;
    mbr.mbr_partition[i].part_size = part_size;
    strcpy(mbr.mbr_partition[i].part_name,name.c_str());



    fseek(disco,0,SEEK_SET);
    fwrite(&mbr,sizeof(MBR),1,disco);
    fseek(disco,mbr.mbr_partition[i].part_start,SEEK_SET);


    if(part_type=='e'){
        EBR ebr;
        strcpy(ebr.part_fit,fit.c_str());
        ebr.part_status = '0';
        ebr.part_start = mbr.mbr_partition[i].part_start;
        ebr.part_size = 0;
        ebr.part_next = -1;
        strcpy(ebr.part_name, "");

        fwrite(&ebr,sizeof (EBR),1,disco);
        int copia=part_size - (int)sizeof(EBR);
        for(int i=0;i<copia;i++){
            fwrite(&contenido,sizeof (char),1,disco);
        }
    }
    else{
        for(int i=0;i<part_size;i++){
            fwrite(&contenido,sizeof (char),1,disco);
        }
    }

}
/*
    METODO EN PROCESO, UNA FORMA MEJORADA PARA HACER LOS FITS.
void testFit(string path,int size){
    FILE *disco=comprobarLectura(path);

    byteFF=-1;
    byteBF=-1;
    byteWF=-1;

    idxbf=-1;
    idxff=-1;
    idxwf=-1;
    //exec -path=/home/anaklusmos/Downloads/Entrada.sh

    int tamBF=-1;
    int tamWF=-1;
    if(disco){


        MBR mbr;
        fseek(disco,0,SEEK_SET);
        fread(&mbr,sizeof(MBR),1,disco);

        int total = mbr.mbr_tamanio;
        int diferencia=0;
        int particion=0;
        int consumo=152;

        for(int i = 0; i < 4; i++){

            int inicio=mbr.mbr_partition[i].part_start;
            if(inicio != -1){

                int actual = mbr.mbr_partition[i].part_size;
                consumo+=actual;
                particion++;

                if(mbr.mbr_partition[i].part_status != '1'){

                    //---existe primaria
                    if(i!=3){
                        if(mbr.mbr_partition[i+1].part_start != -1){

                            int rango = inicio + actual;
                            int siguiente = mbr.mbr_partition[i+1].part_start;
                            int diferencia=rango-siguiente;
                            if((diferencia)!=0){

                                if(diferencia>size){
                                    if(byteFF==-1){
                                        idxff=i;
                                        byteFF=inicio;
                                    }
                                    if(byteWF==-1){
                                        idxbf=i;
                                        idxwf=i;

                                        byteWF=inicio;
                                        byteBF=inicio;

                                        tamBF=actual;
                                        tamWF=actual;
                                    }
                                    else{
                                        if(actual<tamBF){
                                            tamBF=actual;
                                            byteBF=inicio;
                                            idxbf=i;
                                        }
                                        if(actual>tamWF){

                                            tamWF=actual;
                                            byteWF=inicio;
                                            idxwf=i;
                                        }
                                    }
                                }

                                consumo+=diferencia;
                            }
                        }

                    }else{
                        int rango = inicio + actual;
                        diferencia=total-rango;

                        //---espacio libre en la ultima posicion
                    }

                }else{

                    if(actual>size){
                        if(byteFF==-1){
                            byteFF=inicio;
                            idxff=i;
                        }
                        if(byteWF==-1){

                            byteWF=inicio;
                            byteBF=inicio;

                            idxwf=i;
                            idxbf=i;

                            tamBF=actual;
                            tamWF=actual;
                        }
                        else{
                            if(actual<tamBF){
                                tamBF=actual;
                                byteBF=inicio;
                                idxbf=i;
                            }
                            if(actual>tamWF){
                                tamWF=actual;
                                byteWF=inicio;
                                idxwf=i;
                            }
                        }
                    }
                }
            }
        }


        if(particion<4){
            diferencia=total-consumo;
        }

        if(diferencia!=0){
            if(diferencia>size){
                if(byteFF==-1){
                    byteFF=consumo;
                    idxff=0;
                }
                if(byteWF==-1){
                    byteWF=consumo;
                    byteBF=consumo;
                    idxwf=0;
                    idxbf=0;
                }
                else{
                    if(diferencia<tamBF){
                        byteBF=consumo;
                        idxbf=3;
                    }
                    if(diferencia>tamWF){
                        idxwf=3;
                        byteWF=consumo;
                    }
                }
            }

        }


        fclose(disco);
        //cout<<"FINAL: "<<endl;
        cout<<"FF: "+to_string(byteFF)+" WF: "+to_string(byteWF)+" BF: "+to_string(byteBF)<<endl;
        cout<<"FF: "+to_string(idxff)+" WF: "+to_string(idxwf)+" BF: "+to_string(idxbf)<<endl;


    }
    else{
        cout << "El disco no exsite" << endl;
    }
}
*/


void primariaExtendida(string path,int size,string name,string fit,string unit,string tipo){
    MBR mbr;
    FILE *disco;
    disco=comprobarEdicion(path);
    bool filtro=true;
    if(disco){
        fseek(disco,0,SEEK_SET);
        fread(&mbr,sizeof(MBR),1,disco);

        char part_type='p';
        int extendida;
        comprobarParticion(path,name);
        setFit(mbr,size);
        //testFit(path,size);
        extendida=indexE;

        if(tipo=="e"){
            if(extendida==-1){
                part_type='e';
            }
            else{
                filtro=false;
            }
        }

        if(idxff!=-1&&filtro){
            int consumo=0;
            for(int i = 0; i < 4; i++){
                if(mbr.mbr_partition[i].part_status!='1'){
                    consumo += mbr.mbr_partition[i].part_size;
                }
            }

            int tamanioDisco=mbr.mbr_tamanio;
            int restante=tamanioDisco-consumo;
            int part_size=getPart_size(unit,size);
            if(restante>=part_size){
                if(!comprobarParticion(path,name)){

                    string disk_fit=parse(mbr.disk_fit);
                    int pdisk_fit=0;
                    if(disk_fit=="bf"){
                        pdisk_fit=idxbf;
                    }
                    else if(disk_fit=="ff"){
                        pdisk_fit=idxff;
                    }
                    else if(disk_fit=="wf"){
                        pdisk_fit=idxwf;
                    }
                    crearPrimariaExtendida(mbr,disco,fit,unit,part_size,pdisk_fit,part_type,name);
                    cout<<"Particion "+name+" creada con exito"<<endl;

                }
                else{
                    cout<<"Nombre "+name+" duplicado en disco"<<endl;
                }
            }

            else{
                cout<<"Espacio insuficiente en disco"<<endl;

            }
        }
        else{
            cout<<"Se ha alcanzado el limite de particiones en este disco "<<endl;
        }
        fclose(disco);
    }
    else{
        if(idxff==-1){
            cout<<"El disco no existe"<<endl;
        }
        if(!filtro){
            cout<<"Ya existe una particion extendida"<<endl;
        }

    }
}


void logica(string path,int size,string name,string fit,string unit){
    FILE *disco=comprobarEdicion(path);
    if(disco){
        if(!comprobarParticion(path,name)){
            MBR mbr;
            int extendida=indexE;
            fseek(disco,0,SEEK_SET);
            fread(&mbr,sizeof(MBR),1,disco);

            if(extendida!=-1){
                EBR ebr;
                int offset=mbr.mbr_partition[extendida].part_start;
                fseek(disco,offset,SEEK_SET);
                fread(&ebr, sizeof(EBR),1,disco);
                int part_size=getPart_size(unit,size);
                if(ebr.part_size==0){
                    int disponible=mbr.mbr_partition[extendida].part_size;
                    if(disponible >= part_size){

                        ebr.part_status = '0';
                        strcpy(ebr.part_fit,fit.c_str());
                        ebr.part_start = ftell(disco) - sizeof(EBR);
                        ebr.part_size = part_size;
                        ebr.part_next = -1;
                        strcpy(ebr.part_name, name.c_str());

                        fseek(disco, mbr.mbr_partition[extendida].part_start,SEEK_SET);
                        fwrite(&ebr,sizeof(EBR),1,disco);
                    }
                    else{
                        cout<<"El tamanio de la particion logica "+name+" excede a la extendida"<<endl;
                    }
                }
                else{

                    int part_end=mbr.mbr_partition[extendida].part_start + mbr.mbr_partition[extendida].part_size;
                    while((ebr.part_next != -1) && (ftell(disco) < part_end)){
                        fseek(disco,ebr.part_next,SEEK_SET);
                        fread(&ebr,sizeof(EBR),1,disco);
                    }

                    int tamanio = ebr.part_start + ebr.part_size + part_size;
                    int disponible=mbr.mbr_partition[extendida].part_size + mbr.mbr_partition[extendida].part_start;
                    if(tamanio <= disponible){
                        ebr.part_next=ebr.part_start+ebr.part_size;
                        int offset=ftell(disco) - sizeof (EBR);
                        fseek(disco,offset,SEEK_SET);
                        fwrite(&ebr, sizeof(EBR),1 ,disco);
                        offset=ebr.part_start + ebr.part_size;
                        fseek(disco,offset,SEEK_SET);


                        ebr.part_status = '0';
                        strcpy(ebr.part_fit,fit.c_str());
                        ebr.part_start = ftell(disco);
                        ebr.part_size = part_size;
                        ebr.part_next = -1;
                        strcpy(ebr.part_name,name.c_str());
                        fwrite(&ebr,sizeof(EBR),1,disco);

                        cout<<"Particion "+name+" creado con exito"<<endl;

                    }
                    else{
                        cout<<"El tamanio de la particion logica "+name+" excede a la extendida"<<endl;
                    }
                }

            }
            else{
                cout<<"Es necesaria una particion extendida para crear "+name<<endl;
            }
        }
        else{
            cout<<"Nombre "+name+" duplicado en disco"<<endl;
        }
        fclose(disco);
    }
    else{
        cout<<"El disco no existe"<<endl;
    }
}

void ADD(int add, string unit, string path,string name){
    FILE *disco=comprobarEdicion(path);
    if(disco){
        if(comprobarParticion(path,name)){
            bool bandera=mountList->getMount(path,name);
            if(!bandera){

                MBR mbr;
                fseek(disco,0,SEEK_SET);
                fread(&mbr,sizeof (MBR),1,disco);

                int part_add=getPart_size(unit,add);

                if((indexP!=-1||indexE!=-1)&&byteP==-1){


                    int idx=indexP;
                    if(indexE!=-1){
                        idx=indexE;
                    }

                    int tamanioActual=mbr.mbr_partition[idx].part_size;
                    int actual = mbr.mbr_partition[idx].part_start +tamanioActual;

                    if(part_add>0){
                        bool bandera=false;
                        if(idx!=3){

                            if(mbr.mbr_partition[idx+1].part_start != -1){
                                bandera=true;

                                char part_status=mbr.mbr_partition[idx+1].part_status;
                                int tamanioSiguiente= mbr.mbr_partition[idx+1].part_size;

                                int siguiente = mbr.mbr_partition[idx+1].part_start;
                                int diferencia=siguiente-actual;

                                if(diferencia!= 0){

                                    if(diferencia>= part_add){
                                        mbr.mbr_partition[idx].part_size = mbr.mbr_partition[idx].part_size + part_add;
                                        fseek(disco,0,SEEK_SET);
                                        fwrite(&mbr,sizeof(MBR),1,disco);
                                        cout << "comando -add exitoso en  "+name << endl;
                                    }else{
                                        cout << "No hay suficiente espacio para agregar en "+name << endl;
                                    }
                                }else{
                                    if(part_status== '1'){
                                        if(tamanioSiguiente>= part_add){
                                            mbr.mbr_partition[idx].part_size = tamanioActual + part_add;
                                            mbr.mbr_partition[idx+1].part_size = tamanioSiguiente - part_add;
                                            mbr.mbr_partition[idx+1].part_start = siguiente + part_add;
                                            fseek(disco,0,SEEK_SET);
                                            fwrite(&mbr,sizeof(MBR),1,disco);
                                            cout << "Atributo ADD exitoso en  "+name << endl;
                                        }else{
                                            cout << "No hay suficiente espacio para agregar en "+name << endl;
                                        }
                                    }
                                }
                            }


                        }
                        if(idx==3||!bandera){

                            int total = mbr.mbr_tamanio + (int)sizeof(MBR);
                            int diferencia=total-actual;
                            if(diferencia != 0){
                                if(diferencia >= part_add){
                                    mbr.mbr_partition[idx].part_size = tamanioActual + part_add;
                                    fseek(disco,0,SEEK_SET);
                                    fwrite(&mbr,sizeof(MBR),1,disco);
                                    cout << "comando -add exitoso en  "+name << endl;
                                }else{
                                    cout << "No hay suficiente espacio para agregar en "+name << endl;
                                }
                            }else{
                                cout << "No hay suficiente espacio para agregar en "+name << endl;
                            }
                        }


                    }
                    else{
                        if(tamanioActual<part_add*-1){
                            mbr.mbr_partition[idx].part_size = tamanioActual + part_add;
                            fseek(disco,0,SEEK_SET);
                            fwrite(&mbr,sizeof(MBR),1,disco);
                        }
                        else{
                            cout << "La cantidad a eliminar iguala o supera la particion "+name << endl;
                        }
                    }

                }

                else{
                    cout<<"Comando -add no disponible aun particiones logicas"<<endl;
                }
            }
            else{
                cout<<"Debe desmontarse la particion "+name+" para continuar"<<endl;
            }

        }
        else{
            cout<<"La particion "+name+" no existe"<<endl;
        }
        fclose(disco);
    }
    else{
        cout<<"El disco no existe"<<endl;
    }
}

void DELETE(string _delete, string name, string path){
    FILE *disco=comprobarEdicion(path);
    if(disco){
        if(comprobarParticion(path,name)){
            bool bandera=mountList->getMount(path,name);
            if(!bandera){
                cout<<"Permitir eliminar particion "+name+"? (Y/N)"<<endl;
                while(true){
                    string ss="";
                    cin>>ss;
                    if(ss=="Y"){

                        MBR mbr;
                        fseek(disco,0,SEEK_SET);
                        fread(&mbr,sizeof (MBR),1,disco);

                        if((indexP!=-1||indexE!=-1)&&byteP==-1){

                            int idx=indexP;
                            if(indexE!=-1){
                                idx=indexE;
                            }

                            mbr.mbr_partition[idx].part_status = '1';
                            strcpy(mbr.mbr_partition[idx].part_name,"");
                            fseek(disco,0,SEEK_SET);
                            fwrite(&mbr,sizeof(MBR),1,disco);


                            fseek(disco,0,SEEK_SET);
                            fread(&mbr,sizeof (MBR),1,disco);


                            if(_delete == "full"){
                                char contenido = '\0';
                                fseek(disco,mbr.mbr_partition[idx].part_start,SEEK_SET);
                                int cont=mbr.mbr_partition[idx].part_size;
                                for(int i=0;i<cont;i++){
                                    fwrite(&contenido,1,1,disco);
                                }
                            }

                        }
                        else{

                            EBR ebr;
                            fseek(disco,byteP, SEEK_SET);
                            fread(&ebr,sizeof(EBR),1,disco);

                            ebr.part_status = '1';
                            strcpy(ebr.part_name, "");
                            fseek(disco, byteP,SEEK_SET);
                            fwrite(&ebr,sizeof(EBR),1,disco);

                            fread(&ebr,sizeof(EBR),1,disco);


                            if(_delete== "full"){
                                char contenido = '\0';
                                int cont=ebr.part_size;
                                fseek(disco,byteP,SEEK_SET);
                                for(int i=0;i<cont;i++){
                                    fwrite(&contenido,1,1,disco);
                                }
                            }
                        }
                        cout<<"Particion "+name+" eliminada con exito"<<endl;
                        break;

                    }else if(ss=="N"){
                        break;
                    }
                }
            }
            else{
                cout<<"Debe desmontarse la particion "+name+" para continuar"<<endl;
            }
        }
        else{
            cout<<"La particion "+name+" no existe"<<endl;
        }
        fclose(disco);
    }
    else{
        cout<<"El disco no existe"<<endl;
    }


}


void FDISK(int size,string unit,string path,string type,string fit,string _delete, string name,int add){
    setDatos(path);
    string auxPath=directorio+nombre+"_raid."+extension;
    if(add==0&&_delete=="NONE"){
        //testFit(path,size);
        if(type=="p"||type=="e"){
            primariaExtendida(path,size,name,fit,unit,type);
            primariaExtendida(auxPath,size,name,fit,unit,type);
        }
        else if(type=="l"){
            logica(path,size,name,fit,unit);
            logica(auxPath,size,name,fit,unit);
        }
    }
    else if(add!=0){
        ADD(add,unit,path,name);
        ADD(add,unit,auxPath,name);
    }
    else if(_delete!="NONE"){
        DELETE(_delete,name,path);
        DELETE(_delete,name,auxPath);
    }


}

void UNMOUNT(string id){
    bool res=mountList->eliminar(id);
    if(res){
        cout << "Particion "+id+" desmontada" << endl;
        mountList->recorrer();
    }
    else{
        cout << "El id "+id+" no pertenece a ninguna particion" << endl;
    }
}

void MOUNT(string path, string name){
    FILE *disco=comprobarEdicion(path);
    if(disco){
        if(comprobarParticion(path,name)){
            int res = mountList->getLetra(path,name);
            if(res!=0 ){
                string id = "vd";
                int numero = mountList->getNumero(path);
                char letra = static_cast<char>(res);
                id +=letra + to_string(numero);
                nodoSimple*nodo = new nodoSimple(letra,numero,path,name);
                mountList->agregar(nodo);
                cout << "Particion "+name+"("+id+") montada con exito" << endl;
                mountList->recorrer();
            }
            else{
                cout << "La particion "+name+" se monto con anterioridad" << endl;
            }
        }
        else{
            cout<<"No se ha encontrado la particion "+name<<endl;
        }
        fclose(disco);
    }
    else{
        cout<<"El disco no existe"<<endl;
    }
}

string EXEC(string path){
    string entrada="";
    ifstream i(path);
    if(!i.fail()) {
        string s;
        while (getline(i, s)) {
            entrada += (s + "\n");
        }
        cout<<"Archivo cargado exitosamente"<<endl;
    }
    else{
        cout<<"No se ha encontrado el archivo en el directorio"<<endl;
    }
    i.close();
    return entrada;

}

// --------------INICIO DE COMANDOS DE SEGUNDA FASE----------- //


INODE crearINODO(int i_uid,int i_gid,int size,char type,int perm){
    INODE inodo;
    inodo.i_uid = i_uid;
    inodo.i_gid =  i_gid;
    inodo.i_size = size;
    inodo.i_atime = time(0);
    inodo.i_ctime = time(0);
    inodo.i_mtime = time(0);
    for(int i = 0; i < 15; i++){
        inodo.i_block[i] = -1;
    }
    inodo.i_type = type;
    inodo.i_perm = perm;
    return inodo;
}

FOLDERBLOCK crearFOLDERBLOCK(){
    FOLDERBLOCK carpeta;

    for(int i = 0; i < 4; i++){
        strcpy(carpeta.b_content[i].b_name,"");
        carpeta.b_content[i].b_inodo = -1;
    }

    return carpeta;
}

void EXT3(FILE *disco,int inicio,int tamanio_particion){

    //cout<<to_string(inicio)<<endl;
    char cero = '0';
    char uno = '1';
    char dos = '2';


    double n = (tamanio_particion - static_cast<int>(sizeof(SUPERBLOCK)))/(4+ static_cast<int>(sizeof (JOURNALING))+static_cast<int>(sizeof (INODE))+3*static_cast<int>(sizeof (FILEBLOCK)));

    int numero_estructuras = static_cast<int>(floor(n));

    int numero_bloques = 3* numero_estructuras;
    int numero_journaling = static_cast<int>(sizeof(JOURNALING))*numero_estructuras;
    int numero_inode=static_cast<int>(sizeof (INODE))*numero_estructuras;

    int tamanio_super=static_cast<int>(sizeof (SUPERBLOCK));

    //cout<<to_string(n)+" "+to_string(numero_estructuras)+" "+to_string(numero_bloques)+" "+to_string(numero_journaling)+" "+to_string(numero_inode)<<endl;

    /*
     * Tomar en consideracion que al momento de escribir el superbloque se decuentan tanto
     * los inodos como bloques utilizados por la carpeta root y el archivo users.txt
     */

    SUPERBLOCK super;

    super.s_filesystem_type = 3;
    super.s_inodes_count = numero_estructuras;
    super.s_blocks_count = numero_bloques;
    super.s_free_blocks_count = numero_bloques - 2;
    super.s_free_inodes_count = numero_estructuras - 2;
    super.s_mtime = time(0);
    super.s_umtime = 0;
    super.s_mnt_count = 0;
    super.s_magic = 0xEF53;
    super.s_inode_size = sizeof(INODE);
    super.s_block_size = sizeof(FILEBLOCK);
    super.s_first_ino = 2;
    super.s_first_blo = 2;
    super.s_bm_inode_start = inicio + tamanio_super + numero_journaling;
    super.s_bm_block_start = inicio + tamanio_super + numero_journaling + numero_estructuras;
    super.s_inode_start = inicio + tamanio_super + numero_journaling + numero_estructuras + numero_bloques;
    super.s_block_start = inicio + tamanio_super + numero_journaling + numero_estructuras + numero_bloques + numero_inode;
    super.n=0;

    fseek(disco,inicio,SEEK_SET);
    fwrite(&super,sizeof(SUPERBLOCK),1,disco);


    for(int i = 0; i < numero_estructuras; i++){
        fseek(disco,super.s_bm_inode_start + i,SEEK_SET);
        fwrite(&cero,sizeof(char),1,disco);
    }

    fseek(disco,super.s_bm_inode_start,SEEK_SET);
    fwrite(&uno,sizeof(char),1,disco);
    fwrite(&uno,sizeof(char),1,disco);

    for(int i = 0; i < numero_bloques; i++){
        fseek(disco,super.s_bm_block_start + i,SEEK_SET);
        fwrite(&cero,sizeof(char),1,disco);
    }

    fseek(disco,super.s_bm_block_start,SEEK_SET);
    fwrite(&uno,sizeof(char),1,disco);
    fwrite(&dos,sizeof(char),1,disco);


    INODE inodo;

    inodo=crearINODO(1,1,0,'0',664);
    inodo.i_block[0] = 0;

    fseek(disco,super.s_inode_start,SEEK_SET);
    fwrite(&inodo,sizeof(INODE),1,disco);

    FOLDERBLOCK folder;

    strcpy(folder.b_content[0].b_name,".");
    strcpy(folder.b_content[1].b_name,"..");
    strcpy(folder.b_content[2].b_name,"users.txt");
    strcpy(folder.b_content[3].b_name,"");

    folder.b_content[0].b_inodo=0;
    folder.b_content[1].b_inodo=0;
    folder.b_content[2].b_inodo=1;
    folder.b_content[3].b_inodo=-1;

    fseek(disco,super.s_block_start,SEEK_SET);
    fwrite(&folder,sizeof(FOLDERBLOCK),1,disco);

    inodo=crearINODO(1,1,27,'1',755);
    inodo.i_block[0]=1;

    fseek(disco,super.s_inode_start +sizeof (INODE),SEEK_SET);
    fwrite(&inodo,sizeof(INODE),1,disco);

    FILEBLOCK archivo;

    memset(archivo.b_content,0,sizeof(archivo.b_content));  // se llena el arreglo con espacios nulos
    strcpy(archivo.b_content,"1,G,root\n1,U,root,root,123\n");
    fseek(disco,super.s_block_start + sizeof(FOLDERBLOCK),SEEK_SET);
    fwrite(&archivo,sizeof(FILEBLOCK),1,disco);
}

void JOURNAL(FILE *disco,string user,string comando){
    SUPERBLOCK super;
    JOURNALING journal;
    int inicio=sesion.inicioSuper;
    fseek(disco,inicio,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);
    int n=super.n;

    journal.time=time(0);
    strcpy(journal.user,user.c_str());
    strcpy(journal.operation,comando.c_str());
    fseek(disco,inicio+static_cast<int>(sizeof (SUPERBLOCK))+static_cast<int>(sizeof (JOURNALING))*n,SEEK_SET);
    fwrite(&journal,sizeof (JOURNALING),1,disco);

    super.n=n+1;
    fseek(disco,inicio,SEEK_SET);
    fwrite(&super,sizeof(SUPERBLOCK),1,disco);


    fseek(disco,inicio,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);
    // cout<<"N: "+to_string(super.n)<<endl;

}

void MKFS(string id, string type){
    /*
     * en teoria la diferencia entre los dos tipos de formateo(full y fast)
     * recae en que el utlimo se limita a "limpiar" los valores del bitmap
     * y el otro ademas de ello, hace lo mismo con los inodos y bloques
     */
    nodoSimple *nodo=mountList->getNodo(id);
    if(nodo!=0){

        string name=nodo->name;
        string path=nodo->path;

        comprobarParticion(path,name);

        FILE *disco = fopen(path.c_str(),"rb+");

        int lectura=0;
        int tamanio_particion=0;

        if(byteP==-1){
            int idx=indexP;
            if(indexE!=-1){
                fclose(disco);
                //---esto porque en una particion extendida "solo asi" no puede establerce un sistema de archivos
                cout<<"Debe de existir al menos una particion logica dentro de "+id<<endl;
                return;
            }
            MBR mbr;
            fread(&mbr,sizeof(MBR),1,disco);
            lectura=mbr.mbr_partition[idx].part_start;
            tamanio_particion= mbr.mbr_partition[idx].part_size;
        }
        else{
            EBR ebr;
            fseek(disco,byteP,SEEK_SET);
            fread(&ebr,sizeof(EBR),1,disco);
            tamanio_particion=ebr.part_size;
            lectura=byteP;
        }
        EXT3(disco,lectura,tamanio_particion);
        fclose(disco);
        cout<<"Formateo EXT3 exitoso en "+id<<endl;
    }
    else{
        cout<<"La particion "+id+" no existe o no esta montada"<<endl;
    }
}

/*
*  Puede ser utilizado para busqueda de grupos/usuarios,
*  donde tipo especifica si es de usuario o de grupo,
*  el nombre, que sera el atributo en comun entre ellos
*  y aux que pasaria a ser el pwd en caso de usuario.
*  0: usuario y contrasenia correctos
*  1: coincide el nombre
*  2: coincide el id de usuario
*  -1: no hay coincidencias
*  en el caso de busqueda de grupo puede retornar multiples valores
*/

int buscarAtributo(string busqueda,string nombre,string aux,string path,int inicioSuper){

    FILE *disco = fopen(path.c_str(),"rb+");

    SUPERBLOCK super;
    INODE inodo;

    fseek(disco,inicioSuper,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    fseek(disco,super.s_inode_start+ static_cast<int>(sizeof(INODE)), SEEK_SET);
    fread(&inodo,sizeof(INODE),1,disco);

    string contenido="";
    for(int i = 0; i < 15; i++){
        if(inodo.i_block[i]!=-1){
            FILEBLOCK archivo;
            fseek(disco,super.s_block_start,SEEK_SET);
            for(int j = 0; j <= inodo.i_block[i]; j++){
                fread(&archivo,sizeof(FILEBLOCK),1,disco);
            }
            contenido+=parse(archivo.b_content);
        }
    }

    string buf;
    stringstream ss(contenido);

    vector<string> registros;

    while (getline(ss, buf, '\n')){
        registros.push_back(buf);
    }

    for(int i=0;i<(int)registros.size();i++){
        vector<string> campos;
        stringstream ss(registros[i]);
        while (getline(ss, buf, ',')){
            campos.push_back(buf);
        }
        string id=campos[0];
        if(id!="0"){
            string tipo=campos[1];
            string grupo=campos[2];
            if(tipo=="U"&&busqueda=="usuario"){
                string usuario=campos[3];
                string pass=campos[4];
                if(nombre==usuario&&aux==pass){
                    strcpy(sesion.nombre,usuario.c_str());
                    strcpy(sesion.path, path.c_str());
                    sesion.id_user = atoi(id.c_str());
                    sesion.id_grp = buscarAtributo("grupo",grupo,"NONE",path,inicioSuper);
                    activo=true;
                    fclose(disco);
                    return 0;
                }

                if(nombre==usuario){
                    sesionAux.id_user=atoi(id.c_str());
                    fclose(disco);
                    return 1;
                }
                if(nombre==id){
                    if(reporte){
                        strcpy(sesionAux.nombre,usuario.c_str());
                        strcpy(sesionAux.grupo,grupo.c_str());
                        fclose(disco);
                        return 2;
                    }
                }
            }
            else if(tipo=="G"&&busqueda=="grupo"){
                if(nombre==grupo){
                    fclose(disco);
                    return atoi(id.c_str());
                }
            }

        }
    }

    fclose(disco);
    return -1;
}

void LOGIN(string usr,string pwd,string id){
    nodoSimple *nodo = mountList->getNodo(id);
    if(nodo!=0){
        if(!activo){
            string path=nodo->path;
            string name=nodo->name;
            comprobarParticion(path,name);

            FILE *disco = fopen(path.c_str(),"rb+");

            int inicio=0;
            char fit=fitLogica;

            if(byteP==-1){
                int idx=indexP;
                if(indexE!=-1){
                    cout<<"Debe de existir al menos una particion logica dentro de "+id<<endl;
                    fclose(disco);
                    return;
                }
                MBR mbr;
                fread(&mbr,sizeof(MBR),1,disco);
                inicio=mbr.mbr_partition[idx].part_start;
                fseek(disco,inicio,SEEK_SET);
                fit=mbr.mbr_partition[idx].part_fit[0];
            }
            else{
                inicio=byteP+static_cast<int>(sizeof (EBR));
                fseek(disco,inicio,SEEK_SET);
            }

            SUPERBLOCK super;
            INODE inodo;

            fread(&super,sizeof(SUPERBLOCK),1,disco);
            fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE)),SEEK_SET);
            fread(&inodo,sizeof(INODE),1,disco);
            fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE)),SEEK_SET);
            inodo.i_atime = time(0);
            fwrite(&inodo,sizeof(INODE),1,disco);

            sesion.inicioSuper=inicio;
            sesion.fit=fit;

            int estado=buscarAtributo("usuario",usr,pwd,path,inicio);
            if(estado==0){
                cout<<"Bienvenido al sistema "+id+", "+usr<<endl;
                JOURNAL(disco,usr,"LOGIN");
            }
            else{
                cout<<"Credenciales incorrectas"<<endl;
            }
            fclose(disco);

        }
        else{
            cout<<"Existe otra sesion en curso, cierrala y vuelve a intentarlo"<<endl;
        }
    }
    else{
        cout<<"La particion "+id+" no existe o no esta montada"<<endl;
    }
}

void LOGOUT(){
    if(activo){
        activo=false;
        cout<<"Se ha cerrado la sesion actual"<<endl;
        FILE *disco=fopen(sesion.path,"rb+");
        JOURNAL(disco,sesion.nombre,"LOGOUT");
        fclose(disco);
    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}

/*
* ver con el ftell si cambia al escribir
*/

/*
*  Metas para maniana:
*  tener terminada la creacion/eliminacion de usuarios/grupos
*  y...ver si puedo hacer el reporte del arbol
*/
int buscarBit(string path, string tipo, char fit){

    FILE *disco=fopen(path.c_str(),"rb+");

    SUPERBLOCK super;
    int inicio = 0;
    int tamanio = 0;

    fseek(disco,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    if(tipo == "inodo"){
        tamanio = super.s_inodes_count;
        inicio = super.s_bm_inode_start;
    }else if(tipo == "bloque"){
        tamanio = super.s_blocks_count;
        inicio = super.s_bm_block_start;
    }


    if(fit == 'f'){
        for(int i = 0; i < tamanio; i++){
            fseek(disco,inicio+i,SEEK_SET);
            int bit = fgetc(disco);
            if(bit == 48){
                fclose(disco);
                return i;
            }
        }
        fclose(disco);
        return -1;
    }else if(fit == 'b'){
        int auxtamanio=0;
        int auxbit=-1;

        int tamaniofinal=-1;
        int bitfinal=-1;

        bool final=false;
        for(int i = 0; i < tamanio; i++){
            //cout<<"BIT: "+to_string(bitfinal)<<endl;
            fseek(disco,inicio+i,SEEK_SET);
            int bit = fgetc(disco);
            if(bit == 48){
                final=true;
                if(auxbit==-1){
                    auxbit=i;
                }
                auxtamanio++;

            }
            else if(bit==49){
                final=false;
                if(auxtamanio>0){
                    if(tamaniofinal==-1){
                        tamaniofinal=auxtamanio;
                        bitfinal=auxbit;

                    }
                    else{
                        if(auxtamanio<tamaniofinal){
                            tamaniofinal=auxtamanio;
                            bitfinal=auxbit;
                        }
                    }
                }

                auxtamanio=0;
                auxbit=-1;
            }
        }
        if(final){
            if(auxtamanio>0){
                if(tamaniofinal==-1){
                    tamaniofinal=auxtamanio;
                    bitfinal=auxbit;

                }
                else{
                    if(auxtamanio<tamaniofinal){
                        tamaniofinal=auxtamanio;
                        bitfinal=auxbit;
                    }
                }
            }
        }
        fclose(disco);
        return bitfinal;

    }else if(fit == 'w'){
        int auxtamanio=0;
        int auxbit=-1;

        int tamaniofinal=-1;
        int bitfinal=-1;

        bool final=false;
        for(int i = 0; i < tamanio; i++){
            fseek(disco,inicio+i,SEEK_SET);
            int bit = fgetc(disco);
            if(bit == 48){
                final=true;
                if(auxbit==-1){
                    auxbit=i;
                }
                auxtamanio++;
            }
            else if(bit==49){
                final=false;
                if(auxtamanio>0){
                    if(tamaniofinal==-1){
                        tamaniofinal=auxtamanio;
                        bitfinal=auxbit;

                    }
                    else{
                        if(auxtamanio>tamaniofinal){
                            tamaniofinal=auxtamanio;
                            bitfinal=auxbit;
                        }
                    }
                }

                auxtamanio=0;
                auxbit=-1;
            }
        }

        if(final){
            if(auxtamanio>0){
                if(tamaniofinal==-1){
                    tamaniofinal=auxtamanio;
                    bitfinal=auxbit;

                }
                else{
                    if(auxtamanio>tamaniofinal){
                        tamaniofinal=auxtamanio;
                        bitfinal=auxbit;
                    }
                }
            }

        }

        fclose(disco);
        return bitfinal;
    }
    fclose(disco);
    return -1;
}


void agregarRegistro(string path, string contenido){

    FILE *disco = fopen(path.c_str(), "rb+");

    SUPERBLOCK super;
    INODE inodo;
    FILEBLOCK archivo;
    int blockIndex = 0;
    //int offset=0;
    int tamanio=contenido.length();

    fseek(disco,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE)), SEEK_SET);
    fread(&inodo,sizeof(INODE),1,disco);


    //--------ver si puedo encontrar el bloque libre con otro metodo...
    for(int i = 0; i < 12; i++){
        if(inodo.i_block[i] != -1){
            blockIndex = inodo.i_block[i];
        }
    }

    fseek(disco,super.s_block_start + static_cast<int>(sizeof(FILEBLOCK))*blockIndex,SEEK_SET);
    fread(&archivo,sizeof(FILEBLOCK),1,disco);
    int ocupado = static_cast<int>(strlen(archivo.b_content));
    int disponible = 64 - ocupado;

    string primeraMitad = contenido;
    string segundaMitad = "";

    /*
     * la bandera contempla el caso en el que se sobrepase la cantidad de un bloque
     * no representa gran problema porque se sabe que nunca se recibira una entrada mayor
     * a un bloque.
     */
    bool bandera=tamanio >= disponible;

    if(bandera){
        primeraMitad="";
        int cont = 0;

        while(true){
            if(cont<disponible){
                primeraMitad += contenido[cont];
            }
            else if(cont<(int)contenido.length()){
                segundaMitad+=contenido[cont];
            }
            else{
                break;
            }
            cont++;
        }
    }

    strcat(archivo.b_content,primeraMitad.c_str());
    fseek(disco,super.s_block_start + static_cast<int>(sizeof(FILEBLOCK))*blockIndex,SEEK_SET);
    fwrite(&archivo,sizeof(FILEBLOCK),1,disco);

    int bit=0;
    if(bandera){
        FILEBLOCK aux;
        strcpy(aux.b_content,segundaMitad.c_str());

        bit=buscarBit(path,"bloque",sesion.fit);
        fseek(disco,super.s_bm_block_start + bit,SEEK_SET);
        fputc('2',disco);
        fseek(disco,super.s_block_start + (static_cast<int>(sizeof(FILEBLOCK))*bit),SEEK_SET);
        fwrite(&aux,sizeof(FILEBLOCK),1,disco);

    }

    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE)),SEEK_SET);
    fread(&inodo,sizeof(INODE),1,disco);
    inodo.i_size = inodo.i_size + contenido.length();
    inodo.i_mtime = time(0);

    if(bandera){
        inodo.i_block[blockIndex] = bit;
    }

    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE)),SEEK_SET);
    fwrite(&inodo,sizeof(INODE),1,disco);

    if(bandera){
        super.s_first_blo = super.s_first_blo + 1;
        super.s_free_blocks_count = super.s_free_blocks_count - 1;
        fseek(disco,sesion.inicioSuper,SEEK_SET);
        fwrite(&super,sizeof(SUPERBLOCK),1,disco);
    }

    fclose(disco);
}

int getID(string busqueda){

    FILE *disco = fopen(sesion.path,"rb+");

    SUPERBLOCK super;
    INODE inodo;
    int actual=-1;

    fseek(disco,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    fseek(disco,super.s_inode_start+ static_cast<int>(sizeof(INODE)), SEEK_SET);
    fread(&inodo,sizeof(INODE),1,disco);

    string contenido="";
    for(int i = 0; i < 15; i++){
        if(inodo.i_block[i]!=-1){
            FILEBLOCK archivo;
            fseek(disco,super.s_block_start,SEEK_SET);
            for(int j = 0; j <= inodo.i_block[i]; j++){
                fread(&archivo,sizeof(FILEBLOCK),1,disco);
            }
            contenido+=parse(archivo.b_content);
        }
    }

    string buf;
    stringstream ss(contenido);

    vector<string> registros;

    while (getline(ss, buf, '\n')){
        registros.push_back(buf);
    }

    for(int i=0;i<(int)registros.size();i++){
        vector<string> campos;
        stringstream ss(registros[i]);
        while (getline(ss, buf, ',')){
            campos.push_back(buf);
        }
        string id=campos[0];
        if(id!="0"){
            string tipo=campos[1];
            if(tipo=="U"&&busqueda=="usuario"){
                actual=atoi(id.c_str());
                actual++;
            }
            else if(tipo=="G"&&busqueda=="grupo"){
                actual=atoi(id.c_str());
                actual++;
            }
        }
    }

    fclose(disco);
    return actual;
}

void MKGRP(string name){
    if(activo){
        if(sesion.id_user==1&& sesion.id_grp==1){
            if(name.length()<11){
                string path=sesion.path;
                int resultado=buscarAtributo("grupo",name,"",path,sesion.inicioSuper);
                if(resultado==-1){
                    int id=getID("grupo");
                    string contenido=to_string(id)+",G,"+name+"\n";
                    agregarRegistro(path,contenido);
                    cout<<"Grupo "+name+" registrado con exito"<<endl;
                    FILE *disco=fopen(sesion.path,"rb+");
                    JOURNAL(disco,sesion.nombre,"MKGRP");
                    fclose(disco);
                }
                else{
                    cout<<"El grupo "+name+" ya se encuentra registrado"<<endl;
                }
            }
            else{
                cout<<"El grupo "+name+" excede los 10 caracteres permitidos"<<endl;
            }
        }
        else{
            cout<<"Solo el usuario root dispone de permisos para MKGRP"<<endl;
        }
    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}


void eliminarRegistro(string name,string busqueda){

    FILE *disco = fopen(sesion.path,"rb+");

    SUPERBLOCK super;
    INODE inodo;
    FILEBLOCK archivo;


    char caracter;
    char tipo;
    int col = 1;
    int posicion = 0;
    int numBloque = 0;
    string coincidencia = "";


    fseek(disco,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE)),SEEK_SET);
    fread(&inodo,sizeof(INODE),1,disco);

    for (int i = 0; i < 12; i++) {
        if(inodo.i_block[i] != -1){
            fseek(disco,super.s_block_start + static_cast<int>(sizeof(FILEBLOCK))*inodo.i_block[i],SEEK_SET);
            fread(&archivo,sizeof(FILEBLOCK),1,disco);
            for(int j = 0; j < 64; j++){
                caracter = archivo.b_content[j];
                if(caracter=='\n'){
                    if(tipo == 'G'&&busqueda=="grupo"){
                        if(name==coincidencia){
                            fseek(disco,super.s_block_start+static_cast<int>(sizeof(FILEBLOCK))*numBloque,SEEK_SET);
                            fread(&archivo,sizeof(FILEBLOCK),1,disco);
                            archivo.b_content[posicion] = '0';
                            fseek(disco,super.s_block_start+static_cast<int>(sizeof(FILEBLOCK))*numBloque,SEEK_SET);
                            fwrite(&archivo,sizeof(FILEBLOCK),1,disco);

                            fclose(disco);
                            return;
                        }
                    }
                    else if(tipo=='U'&&busqueda=="usuario"){
                        if(name==coincidencia){
                            fseek(disco,super.s_block_start+static_cast<int>(sizeof(FILEBLOCK))*numBloque,SEEK_SET);
                            fread(&archivo,sizeof(FILEBLOCK),1,disco);
                            archivo.b_content[posicion] = '0';
                            fseek(disco,super.s_block_start+static_cast<int>(sizeof(FILEBLOCK))*numBloque,SEEK_SET);
                            fwrite(&archivo,sizeof(FILEBLOCK),1,disco);
                            fclose(disco);
                            return;
                        }
                    }
                    col = 1;
                    coincidencia = "";
                }else if(caracter!=','){
                    coincidencia += caracter;
                    col++;
                }else if(caracter==','){
                    if(col == 2){
                        posicion = j-1;
                        numBloque = inodo.i_block[i];
                    }
                    else if(col == 4){
                        tipo = coincidencia[0];
                    }
                    col++;
                    coincidencia = "";
                }
            }
        }
    }

    fclose(disco);
}


void RMGRP(string name){
    if(activo){
        if(sesion.id_user==1&& sesion.id_grp==1){
            string path=sesion.path;
            int resultado=buscarAtributo("grupo",name,"",path,sesion.inicioSuper);
            if(resultado!=-1){
                eliminarRegistro(name,"grupo");
                cout<<"Grupo "+name+" eliminado con exito"<<endl;
                FILE *disco=fopen(sesion.path,"rb+");
                JOURNAL(disco,sesion.nombre,"RMGRP");
                fclose(disco);
            }
            else{
                cout<<"El grupo "+name+" no existe o ya se ha eliminado anteriormente"<<endl;
            }
        }
        else{
            cout<<"Solo el usuario root dispone de permisos para RMGRP"<<endl;

        }
    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}

void MKUSR(string usr,string pwd,string grp){
    if(activo){
        if(sesion.id_user==1&& sesion.id_grp==1){
            if(usr.length()<11||pwd.length()<11||grp.length()<11){
                string path=sesion.path;
                int resultado=buscarAtributo("grupo",grp,"",path,sesion.inicioSuper);
                if(resultado!=-1){
                    resultado=buscarAtributo("usuario",usr,"",path,sesion.inicioSuper);
                    if(resultado!=1){
                        //1,U,root,root,123\n
                        int id=getID("usuario");
                        string contenido=to_string(id)+",U,"+grp+","+usr+","+pwd+"\n";
                        agregarRegistro(path,contenido);
                        cout<<"Usuario "+usr+" registrado con exito"<<endl;
                        FILE *disco=fopen(sesion.path,"rb+");
                        JOURNAL(disco,sesion.nombre,"MKUSR");
                        fclose(disco);
                    }
                    else{
                        cout<<"El usuario "+usr+" no existe o ya se ha eliminado anteriormente"<<endl;
                    }
                }
                else{
                    cout<<"El grupo "+grp+" no existe o ya se ha eliminado anteriormente"<<endl;
                }
            }
            else{
                cout<<"Uno o varios atributos sobrepasan tamanio permitido"<<endl;
            }

        }
        else{
            cout<<"Solo el usuario root dispone de permisos para RMGRP"<<endl;

        }
    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}

void RMUSR(string usr){
    if(activo){
        if(sesion.id_user==1&& sesion.id_grp==1){
            string path=sesion.path;
            int resultado=buscarAtributo("usuario",usr,"",path,sesion.inicioSuper);
            if(resultado==1){
                eliminarRegistro(usr,"usuario");
                cout<<"Usuario "+usr+" eliminado con exito"<<endl;
                FILE *disco=fopen(sesion.path,"rb+");
                JOURNAL(disco,sesion.nombre,"RMUSR");
                fclose(disco);
            }
            else{
                cout<<"El usuario "+usr+" no existe o ya se ha eliminado anteriormente"<<endl;
            }
        }
        else{
            cout<<"Solo el usuario root dispone de permisos para RMGRP"<<endl;
        }
    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}


int getLibreExistente(int numInodo,INODE &inodo, FOLDERBLOCK &carpeta, POINTERBLOCK &apuntadores,int &content,int &bloque,int &pointer){
    FILE *disco = fopen(sesion.path,"rb+");
    SUPERBLOCK super;
    fseek(disco,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);
    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*numInodo,SEEK_SET);
    fread(&inodo,sizeof(INODE),1,disco);

    for(int i = 0; i < 15; i++){
        if(inodo.i_block[i] != -1){
            if(i == 12){
                fseek(disco,super.s_block_start + static_cast<int>(sizeof(POINTERBLOCK))*inodo.i_block[i],SEEK_SET);
                fread(&apuntadores,sizeof(POINTERBLOCK),1,disco);
                for(int j = 0; j < 16; j++){
                    if(apuntadores.b_pointers[j] != -1){
                        fseek(disco,super.s_block_start + static_cast<int>(sizeof(POINTERBLOCK))*apuntadores.b_pointers[j],SEEK_SET);
                        fread(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                        for(int k = 0; k < 4; k++){
                            if(carpeta.b_content[k].b_inodo == -1){
                                bloque = i;
                                pointer = j;
                                content = k;
                                fclose(disco);
                                return 1;
                            }
                        }
                    }
                }

            }else if(i == 13){
                /*
                fseek(disco,super.s_block_start + static_cast<int>(sizeof(POINTERBLOCK))*inodo.i_block[i],SEEK_SET);
                fread(&apuntadores,sizeof(POINTERBLOCK),1,disco);
                for(int j = 0; j < 16; j++){
                    if(apuntadores.b_pointers[j] != -1){
                        fseek(disco,super.s_block_start + static_cast<int>(sizeof(POINTERBLOCK))*apuntadores.b_pointers[j],SEEK_SET);
                        fread(&apuntadoresDobles,sizeof(POINTERBLOCK),1,disco);
                        for(int k=0;k<16;k++){
                            if(apuntadoresDobles.b_pointers[j]!=-1){
                                fseek(disco,super.s_block_start + static_cast<int>(sizeof(POINTERBLOCK))*apuntadoresDobles.b_pointers[k],SEEK_SET);
                                fread(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                                for(int l = 0; l < 4; l++){
                                    if(carpeta.b_content[l].b_inodo == -1){
                                        bloque = i;
                                        pointer = j;
                                        doublePointer=k;
                                        content = l;
                                        fclose(disco);
                                        return 1;
                                    }
                                }

                            }
                        }
                    }
                }
                */

            }else if(i == 14){

            }else{
                fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*inodo.i_block[i],SEEK_SET);
                fread(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                for(int j = 0; j < 4; j++){
                    if(carpeta.b_content[j].b_inodo == -1){
                        bloque = i;
                        content = j;
                        fclose(disco);
                        return 1;
                    }
                }
            }
        }

    }
    fclose(disco);
    return -1;
}

void inodoLibre(FILE *disco,SUPERBLOCK super,bool &flag,int &pointer,int &bloque,INODE &inodo,POINTERBLOCK &apuntadores,int numInodo){
    flag = false;
    pointer = -1;
    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*numInodo,SEEK_SET);
    fread(&inodo,sizeof(INODE),1,disco);
    for (int i = 0; i < 15; i++) {
        if(i == 12){
            if(inodo.i_block[i] == -1){
                bloque = 12;
                flag = true;
                break;
            }else{
                fseek(disco,super.s_block_start + static_cast<int>(sizeof(POINTERBLOCK))*inodo.i_block[12],SEEK_SET);
                fread(&apuntadores,sizeof(POINTERBLOCK),1,disco);
                for(int j = 0; j < 16; j++){
                    if(apuntadores.b_pointers[j] == -1){
                        bloque = 12;
                        pointer = j;
                        i=14;
                        break;
                    }
                }
            }
        }else if(i == 13){

        }else if(i == 14){

        }else{
            if(inodo.i_block[i] == -1){
                bloque = i;
                break;
            }
        }
    }
}



int buscarArchivo(string aux,string path,int inicio){
    if(path=="/"){
        return 0;
    }
    FILE *disco=fopen(aux.c_str(),"rb+");

    SUPERBLOCK super;
    INODE inodo;
    FOLDERBLOCK carpeta;
    POINTERBLOCK apuntador;


    vector<string> registros;
    string buf;
    stringstream ss(path);

    while (getline(ss, buf, '/')){
        if(buf!=""){
            registros.push_back(buf);
        }

    }

    fseek(disco,inicio,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);
    int numInodo = super.s_inode_start; //Byte donde inicia el inodo

    int tamanio=registros.size();
    //cout<<"TAMANIO: "+to_string(tamanio)<<endl;
    for (int i = 0; i < tamanio; i++) {
        fseek(disco,numInodo,SEEK_SET);
        fread(&inodo,sizeof(INODE),1,disco);
        for(int j = 0; j < 15; j++){
            if(inodo.i_block[j] != -1){
                int byteBloque=super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*inodo.i_block[j];
                fseek(disco,byteBloque,SEEK_SET);
                if(j < 12){
                    fread(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                    for (int k = 0; k < 4; k++) {
                        //cout<<parse(carpeta.b_content[k].b_name)+" "+registros[i]<<endl;
                        if((i == tamanio- 1) && (parse(carpeta.b_content[k].b_name)==registros[i])){
                            int retorno=carpeta.b_content[k].b_inodo;
                            if(cambioNombre){
                                strcpy(carpeta.b_content[k].b_name,nuevoNombre.c_str());
                                fseek(disco,byteBloque,SEEK_SET);
                                fwrite(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                            }
                            if(activoREM){
                                fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*inodo.i_block[j],SEEK_SET);
                                fread(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                                memset(carpeta.b_content[k].b_name,0,sizeof(carpeta.b_content[k].b_name));
                                carpeta.b_content[k].b_inodo = -1;
                                fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*inodo.i_block[j],SEEK_SET);
                                fwrite(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                            }
                            /*
                             *     block = inodo.i_block[j];
                                   posicion = k;
                            */
                            fclose(disco);
                            return retorno;
                        }else if((i != tamanio - 1) && (parse(carpeta.b_content[k].b_name)==registros[i])){
                            numInodo=super.s_inode_start + static_cast<int>(sizeof(INODE))*carpeta.b_content[k].b_inodo;
                            j=14;
                            break;
                        }
                    }
                }else if(j == 12){

                    fread(&apuntador,sizeof(POINTERBLOCK),1,disco);
                    for(int k = 0; k < 16; k++){
                        if(apuntador.b_pointers[k] != -1){
                            byteBloque=super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*apuntador.b_pointers[k];
                            fseek(disco,byteBloque,SEEK_SET);
                            fread(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                            for (int p = 0; p < 4; p++) {
                                if((i == tamanio - 1) && ((parse(carpeta.b_content[p].b_name)==registros[i]))){
                                    if(cambioNombre){
                                        strcpy(carpeta.b_content[p].b_name,nuevoNombre.c_str());
                                        fseek(disco,byteBloque,SEEK_SET);
                                        fwrite(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                                    }
                                    /* pointer = inodo.i_block[i];
                                    posPointer = j;
                                    block = apuntador.b_pointer[j];
                                    posicion = k;
                                    */


                                    fclose(disco);
                                    return carpeta.b_content[p].b_inodo;
                                }else if((i != tamanio- 1) && ((parse(carpeta.b_content[p].b_name)==registros[i]))){
                                    numInodo=super.s_inode_start + static_cast<int>(sizeof(INODE))*carpeta.b_content[p].b_inodo;
                                    k=15;
                                    j=14;
                                    break;
                                }
                            }
                        }
                    }

                }else if(j == 13){
                    //---dobles indirectos
                }else if(j == 14){
                    //---triples indirectos
                }

            }
        }
    }
    fclose(disco);
    return -1;
}

int tabs=0;

string setRecorrido(){
    string concat="";
    for(int i=0;i<tabs;i++){
        concat+=" ";
    }
    return concat;
}
/*
 * PENDIENTES:
 * ver que ondas con el caso en que ya no quedan espacios en los bloques
 * que el reporte sale mero raro...
 * y pos terminar las ondas indirectas
 */



/*  este metodo es MUUUY parecido al buscarArchivo, pero no lo pude parametrizar
 *  lo suficiente para juntarlos :c
*/

bool escritura(INODE inodo){

    if(parse(sesion.nombre)=="root"){
        return true;
    }
    bool propietario=inodo.i_uid ==sesion.id_user;
    bool grupo=inodo.i_gid ==sesion.id_grp;
    string aux = to_string(inodo.i_perm);
    char U = aux[0];
    char G = aux[1];
    char O = aux[2];

    if((U== '2' || U == '3' || U == '6' || U || '7') && propietario){
        return true;
    }
    else if((G == '2' || G == '3' || G == '6' || G == '7') && grupo){
        return true;
    }
    else if(O == '2' || O == '3' || O == '6' || O == '7'){
        return true;
    }
    return false;
}

bool lectura(INODE inodo){

    if(parse(sesion.nombre)=="root"){
        return true;
    }
    bool propietario=inodo.i_uid ==sesion.id_user;
    bool grupo=inodo.i_gid ==sesion.id_grp;
    string aux = to_string(inodo.i_perm);
    int U = aux[0];
    int G = aux[1];
    int O = aux[2];

    if(U>50 && propietario){
        return true;
    }
    else if(G>50 && grupo){
        return true;
    }
    else if(O>50){
        return true;
    }
    return false;
}


void getRecorrido(FILE *disco,string aux,string path,int inodoAux){

    SUPERBLOCK super;
    INODE inodo;
    FOLDERBLOCK carpeta;
    POINTERBLOCK apuntador;

    fseek(disco,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);
    fseek(disco,inodoAux,SEEK_SET);
    fread(&inodo,sizeof(INODE),1,disco);
    for(int j = 0; j < 15; j++){
        if(inodo.i_block[j] != -1){

            int byteBloque=super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*inodo.i_block[j];
            fseek(disco,byteBloque,SEEK_SET);
            if(j < 12){
                fread(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                for (int k = 0; k < 4; k++) {
                    int estado=carpeta.b_content[k].b_inodo;
                    if(estado!=-1){
                        string nombre=parse(carpeta.b_content[k].b_name);
                        if(nombre!="."&&nombre!=".."){

                            //cout<<"NOMBRE: "+nombre<<endl;


                            /*  PASOS A SERGUIR
                             *  1. Verificar permisos
                             *  2. Ver tipo: usuario o permisos
                             *  3. En caso de estar todo correcto, seguir mandandolo a recursividad
                             *
                             */
                            bool permisos=escritura(inodo);
                            if(cambioCHMOD){
                                if(permisos){
                                    fseek(disco,inodoAux,SEEK_SET);
                                    inodo.i_perm=cambioPermiso;
                                    fwrite(&inodo,sizeof(INODE),1,disco);
                                }
                            }
                            else if(cambioCHOWN){
                                if(permisos){
                                    //cout<<"dentro de CHOWN, con ID: "+to_string(sesionAux.id_user)<<endl;
                                    inodo.i_uid=sesionAux.id_user;
                                    fseek(disco,inodoAux,SEEK_SET);
                                    fwrite(&inodo,sizeof(INODE),1,disco);
                                }
                            }
                            else{
                                permisos=true;
                            }
                            //string ss="";
                            //ss+=inodo.i_type;
                            //cout<<"TYPE: "+ss+" "+to_string(permisos)<<endl;
                            if(inodo.i_type=='0'&&permisos){
                                recorrido+=setRecorrido()+"|_"+nombre+"\n";
                                int n=super.s_inode_start + static_cast<int>(sizeof(INODE))*carpeta.b_content[k].b_inodo;
                                tabs++;
                                getRecorrido(disco,aux,nombre,n);
                                tabs--;
                            }

                        }
                    }
                }
            }else if(j == 12){

                fread(&apuntador,sizeof(POINTERBLOCK),1,disco);
                for(int k = 0; k < 16; k++){
                    if(apuntador.b_pointers[k] != -1){
                        byteBloque=super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*apuntador.b_pointers[k];
                        fseek(disco,byteBloque,SEEK_SET);
                        fread(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                        for (int p = 0; p < 4; p++) {
                            int estado=carpeta.b_content[p].b_inodo;
                            if(estado!=-1){
                                string nombre=parse(carpeta.b_content[p].b_name);
                                if(nombre!="."&&nombre!=".."){   bool permisos=escritura(inodo);
                                    if(cambioCHMOD){
                                        if(permisos){
                                            fseek(disco,inodoAux,SEEK_SET);
                                            inodo.i_perm=cambioPermiso;
                                            fwrite(&inodo,sizeof(INODE),1,disco);
                                        }
                                    }
                                    else if(cambioCHOWN){
                                        if(permisos){
                                            // cout<<"dentro de CHOWN, con ID: "+to_string(sesionAux.id_user)<<endl;
                                            inodo.i_uid=sesionAux.id_user;
                                            fseek(disco,inodoAux,SEEK_SET);
                                            fwrite(&inodo,sizeof(INODE),1,disco);
                                        }
                                    }
                                    else{
                                        permisos=true;
                                    }


                                    if(inodo.i_type=='0'&&permisos){
                                        recorrido+=setRecorrido()+"|_"+nombre+"\n";
                                        int n=super.s_inode_start + static_cast<int>(sizeof(INODE))*carpeta.b_content[p].b_inodo;
                                        tabs++;
                                        getRecorrido(disco,aux,nombre,n);
                                        tabs--;
                                    }
                                }
                            }
                        }
                    }
                }

            }else if(j == 13){
                //---dobles indirectos
            }else if(j == 14){
                //---triples indirectos
            }

        }
    }
}

void carpetaDirecta(FILE *disco,FOLDERBLOCK carpetaNueva,SUPERBLOCK super,INODE inodoNuevo,int numInodo,int bitInodo,int res){
    char uno='1';

    inodoNuevo = crearINODO(sesion.id_user,sesion.id_grp,0,'0',664);
    int bitBloque = buscarBit(sesion.path,"bloque",sesion.fit);
    inodoNuevo.i_block[0] = bitBloque;
    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*bitInodo,SEEK_SET);
    fwrite(&inodoNuevo,sizeof(INODE),1,disco);

    fseek(disco,super.s_bm_inode_start + bitInodo,SEEK_SET);
    fwrite(&uno,sizeof(char),1,disco);

    fseek(disco,super.s_bm_inode_start + bitInodo,SEEK_SET);//--

    carpetaNueva = crearFOLDERBLOCK();
    carpetaNueva.b_content[0].b_inodo = bitInodo;
    carpetaNueva.b_content[1].b_inodo = numInodo;
    strcpy(carpetaNueva.b_content[0].b_name,".");
    strcpy(carpetaNueva.b_content[1].b_name,"..");
    fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*bitBloque,SEEK_SET);
    fwrite(&carpetaNueva,sizeof(FOLDERBLOCK),1,disco);

    fseek(disco,super.s_bm_block_start + bitBloque,SEEK_SET);
    fwrite(&uno,sizeof(char),1,disco);

    fseek(disco,super.s_bm_block_start + bitBloque,SEEK_SET);//--

    super.s_free_inodes_count = super.s_free_inodes_count - 1;
    super.s_free_blocks_count = super.s_free_blocks_count - res;
    super.s_first_ino = super.s_first_ino + 1;
    super.s_first_blo = super.s_first_blo + res;
    fseek(disco,sesion.inicioSuper,SEEK_SET);
    fwrite(&super,sizeof(SUPERBLOCK),1,disco);

}

void agregarContenido(FILE *disco,SUPERBLOCK &super,int finalSize,int numInodo,string concat,INODE inodo,string contentSize,string auxPath){
    char dos='2';
    double n = static_cast<double>(finalSize)/static_cast<double>(63);
    int numBloques = static_cast<int>(ceil(n));
    int caracteres = finalSize;
    size_t charNum = 0;
    size_t contChar = 0;
    numInodo = buscarArchivo(sesion.path,auxPath,sesion.inicioSuper);
    for (int i = 0; i < numBloques; i++) {
        FILEBLOCK archivo;
        memset(archivo.b_content,0,sizeof(archivo.b_content));
        if(i == 12){

        }else if(i > 12 && i < 28){

        }else if(i == 29){

        }else{
            int bitBloque = buscarBit(sesion.path,"bloque",sesion.fit);
            fseek(disco,super.s_bm_block_start + bitBloque,SEEK_SET);
            fwrite(&dos,sizeof(char),1,disco);
            if(caracteres > 63){
                for(int j = 0; j < 63; j++){
                    if(concat.length() != 0){
                        archivo.b_content[j] = concat[contChar];
                        contChar++;
                    }else{
                        archivo.b_content[j] = contentSize[charNum];
                        charNum++;
                        if(charNum == 10){
                            charNum = 0;
                        }
                    }
                }
                caracteres -= 63;
            }else{
                for (int j = 0; j < caracteres; j++) {
                    if(concat.length() != 0){
                        archivo.b_content[j] = concat[contChar];
                        contChar++;
                    }else{
                        archivo.b_content[j] = contentSize[charNum];
                        charNum++;
                        if(charNum == 10){
                            charNum = 0;
                        }
                    }
                }

            }
            fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*numInodo,SEEK_SET);
            fread(&inodo,sizeof(INODE),1,disco);
            inodo.i_block[i] = bitBloque;
            inodo.i_size = finalSize;
            fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*numInodo,SEEK_SET);
            fwrite(&inodo,sizeof(INODE),1,disco);

            fseek(disco,super.s_block_start + static_cast<int>(sizeof(FILEBLOCK))*bitBloque,SEEK_SET);
            fwrite(&archivo,sizeof(FILEBLOCK),1,disco);
        }
    }

    super.s_free_blocks_count = super.s_free_blocks_count - numBloques;
    super.s_free_inodes_count = super.s_free_inodes_count - 1;
    super.s_first_ino = super.s_first_ino + 1;
    super.s_first_blo = super.s_first_blo + numBloques;
    fseek(disco,sesion.inicioSuper,SEEK_SET);
    fwrite(&super,sizeof(SUPERBLOCK),1,disco);
}


/* Al poder llegar a ser recursiva esta cosa, en conjunto con otros casos
 * se manejaran estados para verificar el progreso de la operacion:
 * 0-Ya existe
 * 1-Correcto
 * 2-Problemas de permisos
 * 3-Problema con lectura de parametro cont
 * 4-es necesario el comando -p para continuar?
 */

int nuevoArchivo(FILE *disco,bool p, string path, int size, string contenido, int index, string tipo,string auxPath){


    SUPERBLOCK super;
    fseek(disco,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);


    INODE inodo,inodoNuevo;
    FOLDERBLOCK carpeta, carpetaNueva,carpetaAux;
    POINTERBLOCK apuntadores;

    string buf;
    stringstream ss(path);

    vector<string> registros;

    while (getline(ss, buf, '/')){
        if(buf!=""){
            registros.push_back(buf);
        }
    }

    int tamanio =registros.size();
    //cout<<"TAMANIO:"+to_string(tamanio)+" PATH: "+path<<endl;
    int retorno=0;

    int n=path.length();
    char arr[n+1];
    char aux[n+1];

    strcpy(arr,path.c_str());
    strcpy(aux,arr);

    string directorio=dirname(arr);
    string padre=basename(aux);


    string contentSize = "0123456789";


    int numInodo = index;
    int finalSize = size;

    char uno='1';
    char dos='2';
    char tres='3';


    //------------esto mejor tenerlo desde afuera--------//
    string concat="";
    if(contenido.length() != 0){
        if(cambioEDIT){
            finalSize=contenido.length();
            concat=contenido;
        }
        else{
            FILE *archivo;
            if((archivo = fopen(contenido.c_str(),"r"))){
                fseek(archivo,0,SEEK_END);
                finalSize = static_cast<int>(ftell(archivo));
                fseek(archivo,0,SEEK_SET);
                for (int i = 0; i < finalSize; i++){
                    concat += static_cast<char>(fgetc(archivo));
                }
                fclose(archivo);
            }else{
                return 3;
            }
        }
    }
    //------------esto mejor tenerlo desde afuera--------//


    if(tamanio==1){
        int bloque = 0;
        int pointer = 0;
        int b_content = 0;
        int libre =getLibreExistente(numInodo,inodo,carpeta,apuntadores,b_content,bloque,pointer);
        bool permisos = escritura(inodo);
        if(!permisos){
            return 2;
        }
        if(libre == 1){
            if(tipo=="archivo"){

                int bitInodo = buscarBit(sesion.path,"inodo",sesion.fit);

                carpeta.b_content[b_content].b_inodo = bitInodo;
                strcpy(carpeta.b_content[b_content].b_name,padre.c_str());
                fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*inodo.i_block[bloque],SEEK_SET);
                fwrite(&carpeta,sizeof(FOLDERBLOCK),1,disco);

                inodoNuevo = crearINODO(sesion.id_user,sesion.id_grp,0,'1',664);
                fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*bitInodo,SEEK_SET);
                fwrite(&inodoNuevo,sizeof(INODE),1,disco);

                fseek(disco,super.s_bm_inode_start + bitInodo,SEEK_SET);
                fwrite(&uno,sizeof(char),1,disco);

                if(finalSize != 0){
                    agregarContenido(disco,super,finalSize,numInodo,concat,inodo,contentSize,auxPath);
                    return 1;
                }

                super.s_free_inodes_count = super.s_free_inodes_count - 1;
                super.s_first_ino = super.s_first_ino + 1;
                fseek(disco,sesion.inicioSuper,SEEK_SET);
                fwrite(&super,sizeof(SUPERBLOCK),1,disco);
                return 1;

            }
            else if(tipo=="carpeta"){
                if(bloque==12){

                    int bitInodo = buscarBit(sesion.path,"inodo",sesion.fit);
                    carpeta.b_content[b_content].b_inodo = bitInodo;
                    strcpy(carpeta.b_content[b_content].b_name,padre.c_str());
                    fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*apuntadores.b_pointers[pointer],SEEK_SET);
                    fwrite(&carpeta,sizeof(FOLDERBLOCK),1,disco);

                    carpetaDirecta(disco,carpetaNueva,super,inodoNuevo,numInodo,bitInodo,1);

                    return 1;
                }
                else if(bloque == 13){
                    return 1;
                }
                else if(bloque == 14){
                    return 1;
                }
                else{

                    int bitInodo = buscarBit(sesion.path,"inodo",sesion.fit);

                    carpeta.b_content[b_content].b_inodo = bitInodo;
                    strcpy(carpeta.b_content[b_content].b_name,padre.c_str());
                    fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*inodo.i_block[bloque],SEEK_SET);
                    fwrite(&carpeta,sizeof(FOLDERBLOCK),1,disco);

                    carpetaDirecta(disco,carpetaNueva,super,inodoNuevo,numInodo,bitInodo,1);
                    return 1;
                }
            }

        }
        else{
            if(tipo=="carpeta"){
                bool crearIndirecto = false;
                inodoLibre(disco,super,crearIndirecto,pointer,bloque,inodo,apuntadores,numInodo);
                if(bloque == 12){
                    int bitBloque;
                    int bitBloqueCarpeta;
                    if(crearIndirecto){

                        bitBloque = buscarBit(sesion.path,"bloque",sesion.fit);
                        inodo.i_block[bloque] = bitBloque;
                        fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*numInodo,SEEK_SET);
                        fwrite(&inodo,sizeof(INODE),1,disco);

                        fseek(disco,super.s_bm_block_start + bitBloque,SEEK_SET);
                        fwrite(&tres,sizeof(char),1,disco);

                        fseek(disco,super.s_bm_block_start + bitBloque,SEEK_SET);//---

                        bitBloqueCarpeta = buscarBit(sesion.path,"bloque",sesion.fit);
                        apuntadores.b_pointers[0] = bitBloqueCarpeta;
                        for(int i = 1; i < 16; i++){
                            apuntadores.b_pointers[i] = -1;
                        }
                        fseek(disco,super.s_block_start + static_cast<int>(sizeof(POINTERBLOCK))*bitBloque,SEEK_SET);
                        fwrite(&apuntadores,sizeof(POINTERBLOCK),1,disco);

                    }
                    else{

                        bitBloque = buscarBit(sesion.path,"bloque",sesion.fit);
                        bitBloqueCarpeta=bitBloque;
                        apuntadores.b_pointers[pointer] = bitBloque;
                        fseek(disco,super.s_block_start + static_cast<int>(sizeof(POINTERBLOCK))*inodo.i_block[12],SEEK_SET);
                        fwrite(&apuntadores,sizeof(POINTERBLOCK),1,disco);


                    }


                    int bitInodo =buscarBit(sesion.path,"inodo",sesion.fit);
                    carpetaAux = crearFOLDERBLOCK();
                    carpetaAux.b_content[0].b_inodo = bitInodo;
                    strcpy(carpetaAux.b_content[0].b_name,padre.c_str());
                    fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*bitBloqueCarpeta,SEEK_SET);
                    fwrite(&carpetaAux,sizeof(FOLDERBLOCK),1,disco);

                    fseek(disco,super.s_bm_block_start + bitBloqueCarpeta,SEEK_SET);
                    fwrite(&uno,sizeof(char),1,disco);

                    fseek(disco,super.s_bm_block_start + bitBloqueCarpeta,SEEK_SET);//---

                    carpetaDirecta(disco,carpetaNueva,super,inodoNuevo,numInodo,bitInodo,3);
                    return 1;
                }
                else if(bloque == 13){

                }else if(bloque == 14){

                }
                else{

                    int bitBloque = buscarBit(sesion.path,"bloque",sesion.fit);
                    inodo.i_block[bloque] = bitBloque;

                    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*numInodo,SEEK_SET);
                    fwrite(&inodo,sizeof(INODE),1,disco);

                    int bitInodo = buscarBit(sesion.path,"inodo",sesion.fit);
                    carpetaAux = crearFOLDERBLOCK();

                    carpetaAux.b_content[0].b_inodo = bitInodo;
                    strcpy(carpetaAux.b_content[0].b_name,padre.c_str());
                    fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*bitBloque,SEEK_SET);
                    fwrite(&carpetaAux,sizeof(FOLDERBLOCK),1,disco);


                    fseek(disco,super.s_bm_block_start + bitBloque,SEEK_SET);
                    fwrite(&uno,sizeof(char),1,disco);

                    fseek(disco,super.s_bm_block_start + bitBloque,SEEK_SET);

                    carpetaDirecta(disco,carpetaNueva,super,inodoNuevo,numInodo,bitInodo,2);

                    // cout<<"Creacion de carpeta exitoso"<<endl;
                    return 1;
                }
            }
            else if(tipo=="archivo"){
                fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*numInodo,SEEK_SET);
                fread(&inodo,sizeof(INODE),1,disco);
                for (int i = 0; i < 15; i++) {
                    if(inodo.i_block[i] == -1){
                        bloque = i;
                        break;
                    }
                }
                if(bloque == 12){
                    return 1;

                }else if(bloque == 13){
                    return 1;

                }else if(bloque == 14){
                    return 1;

                }else{
                    int bitBloque = buscarBit(sesion.path,"bloque",sesion.fit);

                    inodo.i_block[bloque] = bitBloque;
                    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*numInodo,SEEK_SET);
                    fwrite(&inodo,sizeof(INODE),1,disco);

                    int bitInodo = buscarBit(sesion.path,"inodo",sesion.fit);
                    carpetaNueva=crearFOLDERBLOCK();
                    carpetaNueva.b_content[0].b_inodo = bitInodo;
                    strcpy(carpetaNueva.b_content[0].b_name,padre.c_str());
                    fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*bitBloque,SEEK_SET);
                    fwrite(&carpetaNueva,sizeof(FOLDERBLOCK),1,disco);

                    fseek(disco,super.s_bm_block_start + bitBloque,SEEK_SET);
                    fwrite(&uno,sizeof(char),1,disco);

                    inodoNuevo = crearINODO(sesion.id_user,sesion.id_grp,0,'1',664);
                    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*bitInodo,SEEK_SET);
                    fwrite(&inodoNuevo,sizeof(INODE),1,disco);
                    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*bitInodo,SEEK_SET);
                    fwrite(&inodoNuevo,sizeof(INODE),1,disco);

                    fseek(disco,super.s_bm_inode_start + bitInodo,SEEK_SET);
                    fwrite(&uno,sizeof(char),1,disco);

                    if(finalSize != 0){
                        agregarContenido(disco,super,finalSize,numInodo,concat,inodo,contentSize,auxPath);
                        return 1;
                    }

                    super.s_free_inodes_count = super.s_free_inodes_count - 1;
                    super.s_first_ino = super.s_first_ino + 1;
                    fseek(disco,sesion.inicioSuper,SEEK_SET);
                    fwrite(&super,sizeof(SUPERBLOCK),1,disco);
                    return 1;
                }

            }
        }
    }else{
        int existe = buscarArchivo(sesion.path,directorio,sesion.inicioSuper);
        if(existe == -1){
            if(p){

                int index = 0;
                string aux = "";
                for (int i = 0; i < tamanio; i++) {
                    if(tipo=="carpeta"){
                        aux += "/"+registros[i];
                        //cout<<"AUX: "+aux<<endl;
                        int carpeta = buscarArchivo(sesion.path,aux,sesion.inicioSuper);
                        //cout<<"INDEX: "+to_string(carpeta)<<endl;

                        if(carpeta == -1){
                            retorno=1;
                            retorno=nuevoArchivo(disco,p,aux,size,contenido,index,"carpeta",auxPath);
                            if(retorno==2){
                                return 2;
                            }
                            index = buscarArchivo(sesion.path,aux,sesion.inicioSuper);
                        }else{
                            index = carpeta;
                        }
                    }
                    else if(tipo=="archivo"){
                        if(i == tamanio-1){
                            padre="/"+padre;
                            return nuevoArchivo(disco,false,padre,size,contenido,index,"archivo",auxPath);
                        }else{
                            aux += "/"+registros[i];
                            int carpeta = buscarArchivo(sesion.path,aux,sesion.inicioSuper);
                            if(carpeta == -1){
                                nuevoArchivo(disco,false,aux,size,contenido,index,"carpeta",auxPath);
                                index = buscarArchivo(sesion.path,aux,sesion.inicioSuper);
                            }else{
                                index = carpeta;
                            }
                        }
                    }
                }
            }else{
                return 4;
            }
        }else{
            padre="/"+padre;
            return nuevoArchivo(disco,false,padre,size,contenido,existe,tipo,auxPath);
        }
    }

    return retorno;

}
/* Al poder llegar a ser recursiva esta cosa, en conjunto con otros casos
 * se manejaran estados para verificar el progreso de la operacion:
 * 0-Ya existe
 * 1-Correcto
 * 2-Problemas de permisos
 * 3-Problema con lectura de parametro cont
 * 4-es necesario el comando -p para continuar?
 */
void errores(FILE *disco,int estado,string operacion){
    switch (estado) {
    case 0:
        cout<<"El archivo/carpeta ya existe dentro del directorio"<<endl;
        break;
    case 1:
        cout<<operacion+" exitoso!"<<endl;
        JOURNAL(disco,sesion.nombre,operacion);
        break;
    case 2:
        cout<<"No dispones de los permisos requeridos"<<endl;
        break;
    case 3:
        cout<<"El archivo especificado en el parametro -cont no se ha podido abrir"<<endl;
        break;
    case 4:
        cout<<"Es necesario el parametro -p para continuar"<<endl;
        break;
    }
}


void MKFILE(string path,bool p,int size,string cont){
    if(activo){
        FILE *disco = fopen(sesion.path,"rb+");
        int existe = buscarArchivo(sesion.path,path,sesion.inicioSuper);
        if(existe==-1){
            int estado=nuevoArchivo(disco,p,path,size,cont,0,"archivo",path);
            errores(disco,estado,"MKFILE");
        }
        else{
            cout<<"El archivo ya existe en el directorio"<<endl;
        }
        fclose(disco);
    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}

void MKDIR(string path,bool p){
    if(activo){
        FILE *disco = fopen(sesion.path,"rb+");
        int existe = buscarArchivo(sesion.path,path,sesion.inicioSuper);
        if(existe==-1){
            int estado=nuevoArchivo(disco,p,path,0,"",0,"carpeta",path);
            errores(disco,estado,"MKDIR");
        }
        else{
            fclose(disco);
            cout<<"El directorio ya existe"<<endl;

        }
        fclose(disco);

    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}

void FIND(string path, string name){
    if(activo){
        int n=0;
        if(path!="/"){
            n=buscarArchivo(sesion.path,path,sesion.inicioSuper);
        }
        if(n!=-1){
            FILE *disco=fopen(sesion.path,"rb+");
            SUPERBLOCK super;
            fseek(disco,sesion.inicioSuper,SEEK_SET);
            fread(&super,sizeof(SUPERBLOCK),1,disco);
            int inicio=super.s_inode_start + static_cast<int>(sizeof(INODE))*n;
            recorrido="";
            getRecorrido(disco,sesion.path,path,inicio);
            cout<<recorrido<<endl;
            if(recorrido.find(name) != string::npos){
                cout<<"Archivo/directorio "+name+" encontrado!"<<endl;
                JOURNAL(disco,sesion.nombre,"FIND");
            }
            else{
                cout<<name+" no se encontro en la ruta especificada"<<endl;
            }
            fclose(disco);

        }
        else{
            cout<<"aca?"<<endl;
        }

    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}

string getContenido(int n){
    FILE *disco = fopen(sesion.path,"rb+");
    SUPERBLOCK super;
    INODE inodo;
    string contenido = "";
    fseek(disco,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);
    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*n,SEEK_SET);
    fread(&inodo,sizeof(INODE),1,disco);
    for (int i = 0; i < 15; i++) {
        if(inodo.i_block[i] != -1){
            if(i < 12){
                FILEBLOCK archivo;
                fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*inodo.i_block[i],SEEK_SET);
                fread(&archivo,sizeof(FOLDERBLOCK),1,disco);
                contenido += archivo.b_content;
            }else if(i == 12){
                //Apuntador indirecto simple
            }
        }
    }
    fclose(disco);
    return contenido;
}



void CAT(string file){
    if(activo){
        int n = buscarArchivo(sesion.path,file,sesion.inicioSuper);
        if(n != -1){
            FILE *disco = fopen(sesion.path,"rb+");
            SUPERBLOCK super;
            INODE inodo;
            fseek(disco,sesion.inicioSuper,SEEK_SET);
            fread(&super,sizeof(SUPERBLOCK),1,disco);
            fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*n,SEEK_SET);
            fread(&inodo,sizeof(INODE),1,disco);
            bool permisos=lectura(inodo);
            if(!permisos){
                cout<<"No dispones de los permosos requeridos"<<endl;
                fclose(disco);
                return;
            }
            cout<<getContenido(n)<<endl;
            JOURNAL(disco,sesion.nombre,"CAT");
            fclose(disco);
        }
        else{
            cout<<"No existe el archivo especificado"<<endl;
        }

    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}



void PAUSE(){
    cout<<"Presione cualquier tecla para continuar"<<endl;
    string ss;
    cin>>ss;
}
/*  agregar la validacion de permisos, recuperando el inodo
 *  y verificando que sea de escritura
 */
void REN(string path, string name){
    if(activo){
        nuevoNombre=name;
        cambioNombre=true;
        int res = buscarArchivo(sesion.path,path,sesion.inicioSuper);
        if(res != -1){
            cout<<"Cambio de nombre exitoso a "+name<<endl;
            FILE *disco=fopen(sesion.path,"rb+");
            JOURNAL(disco,sesion.nombre,"REN");
            fclose(disco);
        }
        else{
            cout<<"No existe el archivo especificado"<<endl;
        }
        cambioNombre=false;
    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}

void CHOWN(string path,bool r,string usr){
    if(activo){
        int n = buscarArchivo(sesion.path,path,sesion.inicioSuper);
        if(n != -1){
            int estado=buscarAtributo("usuario",usr,"",sesion.path,sesion.inicioSuper);
            if(estado==1){
                cout<<"INODO: "+to_string(n)<<endl;
                FILE *disco = fopen(sesion.path,"rb+");
                SUPERBLOCK super;
                INODE inodo;
                fseek(disco,sesion.inicioSuper,SEEK_SET);
                fread(&super,sizeof(SUPERBLOCK),1,disco);
                fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*n,SEEK_SET);
                fread(&inodo,sizeof(INODE),1,disco);
                bool permisos=lectura(inodo);
                if(!permisos){
                    cout<<"No dispones de los permisos requeridos"<<endl;
                    fclose(disco);
                    return;
                }

                if(r){
                    cambioCHOWN=true;
                    int inicio=super.s_inode_start + static_cast<int>(sizeof(INODE))*n;
                    getRecorrido(disco,sesion.path,"",inicio);
                    cambioCHOWN=false;
                }
                else{
                    inodo.i_uid=sesionAux.id_grp;
                    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*n,SEEK_SET);
                    fwrite(&inodo,sizeof(INODE),1,disco);
                }

                JOURNAL(disco,sesion.nombre,"CHOWN");
                fclose(disco);
            }
            else{
                cout<<"El usuario "+usr+" no se encuentra registrado o se ha eliminado"<<endl;
            }

        }
        else{
            cout<<"No existe el archivo especificado"<<endl;
        }
    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}

void CHMOD(string path,bool r,int ugo){
    if(activo){
        int n = buscarArchivo(sesion.path,path,sesion.inicioSuper);
        if(n != -1){
            cout<<"INODO: "+to_string(n)<<endl;
            FILE *disco = fopen(sesion.path,"rb+");
            SUPERBLOCK super;
            INODE inodo;
            fseek(disco,sesion.inicioSuper,SEEK_SET);
            fread(&super,sizeof(SUPERBLOCK),1,disco);
            fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*n,SEEK_SET);
            fread(&inodo,sizeof(INODE),1,disco);
            bool permisos=lectura(inodo);
            if(!permisos){
                cout<<"No dispones de los permisos requeridos"<<endl;
                fclose(disco);
                return;
            }

            if(r){
                cambioCHMOD=true;
                cambioPermiso=ugo;
                int inicio=super.s_inode_start + static_cast<int>(sizeof(INODE))*n;
                getRecorrido(disco,sesion.path,"",inicio);
                cambioCHMOD=false;
            }
            else{
                inodo.i_uid=sesionAux.id_grp;
                fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*n,SEEK_SET);
                fwrite(&inodo,sizeof(INODE),1,disco);
            }

            JOURNAL(disco,sesion.nombre,"CHOWN");
            fclose(disco);
        }
        else{
            cout<<"No existe el archivo especificado"<<endl;
        }
    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;

    }
}




void eliminarReferencia(FILE *disco, int n){
    SUPERBLOCK super;
    INODE inodo;
    char cero= '0';

    fseek(disco,sesion.inicioSuper,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);
    fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*n,SEEK_SET);
    fread(&inodo,sizeof(INODE),1,disco);

    if(inodo.i_type == '0'){
        for (int i = 0; i < 15; i++) {
            if(inodo.i_block[i] != -1){
                if(i<12){
                    fseek(disco,super.s_bm_block_start + inodo.i_block[i],SEEK_SET);
                    int byte=fgetc(disco);
                    if(byte == '1'){
                        FOLDERBLOCK carpeta;
                        fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*inodo.i_block[i],SEEK_SET);
                        fread(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                        for (int j = 0; j < 4; j++) {
                            if(carpeta.b_content[j].b_inodo != -1){
                                string nombre=parse(carpeta.b_content[j].b_name);
                                if(nombre!="." && nombre!=".."){
                                    eliminarReferencia(disco,carpeta.b_content[j].b_inodo);
                                }
                            }
                        }
                        fseek(disco,super.s_bm_block_start + inodo.i_block[i],SEEK_SET);
                        fputc(cero,disco);
                    }
                }

            }
        }
        fseek(disco,super.s_bm_inode_start + n,SEEK_SET);
        fputc(cero,disco);
    }else if(inodo.i_type=='1'){
        for (int i = 0; i < 15; i++) {
            if(inodo.i_block[i] != -1){
                if(i<12){
                    fseek(disco,super.s_bm_block_start + inodo.i_block[i],SEEK_SET);
                    fputc(cero,disco);
                }
            }
        }
        fseek(disco,super.s_bm_inode_start + n,SEEK_SET);
        fputc(cero,disco);
    }

}


void REM(string path){
    if(activo){
        activoREM=true;
        int res = buscarArchivo(sesion.path,path,sesion.inicioSuper);
        activoREM=false;
        if(res != -1){
            FILE *disco=fopen(sesion.path,"rb+");
            eliminarReferencia(disco,res);
            JOURNAL(disco,sesion.nombre,"REM");
            fclose(disco);
        }
        else{
            cout<<"No existe el archivo especificado"<<endl;
        }
    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}
//----------------COMANDOS DE EMERGENCIA-------------------------//
/*
 *  Este es un comando de emergencia, al eliminar el archivo y volverlo a crear resulta
 *  el problema de que se pierden los datos originales en cuanto a permisos y propieetario
 *  asi que tomar en cuenta...
 */

/*    Tanto CP y MV son variaciones de EDIT, asi que...manejare a estos por medio de estados
 *    que sean strings para ser mas entendible, con las variaciones:
 *    EDIT: "edit"
 *    CP:   "cp"
 *    MV:   "mv"
 */

void EDIT(string path,string cont,string tipo){
    if(activo){
        string auxPath=path;
        bool comprobarExiste=tipo=="MV"||tipo=="CP";
        bool bandera=tipo=="EDIT"||tipo=="MV";
        if(comprobarExiste){
            int n=buscarArchivo(sesion.path,path,sesion.inicioSuper);
            if(n==-1){
                cout<<"No existe el archivo especificado"<<endl;
                return;
            }

            n=path.length();
            char arr[n+1];
            strcpy(arr,path.c_str());
            string padre=basename(arr);
            if(cont!="/"){
                auxPath=cont+"/"+padre;
            }
            else{
                auxPath=cont+padre;
            }

        }
        if(bandera){
            activoREM=true;
        }
        int n = buscarArchivo(sesion.path,path,sesion.inicioSuper);
        activoREM=false;
        if(n != -1){
            FILE *disco = fopen(sesion.path,"rb+");
            SUPERBLOCK super;
            INODE inodo;
            fseek(disco,sesion.inicioSuper,SEEK_SET);
            fread(&super,sizeof(SUPERBLOCK),1,disco);
            fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*n,SEEK_SET);
            fread(&inodo,sizeof(INODE),1,disco);
            bool permisos=escritura(inodo);
            if(!permisos){
                cout<<"No dispones de los permosos requeridos"<<endl;
                fclose(disco);
                return;
            }
            string contenido=getContenido(n)+=cont;

            if(bandera){
                eliminarReferencia(disco,n);
            }

            cambioEDIT=true;
            int estado=nuevoArchivo(disco,false,auxPath,0,contenido,0,"archivo",auxPath);
            cambioEDIT=false;
            errores(disco,estado,tipo);
            fclose(disco);
        }
        else{
            cout<<"No existe el archivo especificado"<<endl;
        }

    }
    else{
        cout<<"No hay ninguna sesion activa"<<endl;
    }
}





//---------------FIN---COMANDOS PRINCIPALES-------------------------//


//---------------INICIO---GENERAR REPORTES-------------------------//

void getDisk(string auxPath,string path){
    FILE *disco=comprobarLectura(auxPath);
    if(disco){

        string contenido="";
        contenido+="digraph G { \n";

        contenido+= "     disk [fontname=Helvetica shape=box label=<\n";
        contenido+= "     <table border=\'0\' cellborder=\'1\' width=\'600\' height=\"200\">\n";
        contenido+= "     <tr>\n";
        contenido+= "           <td height=\'200\' width=\'100\'> MBR </td>\n";

        MBR mbr;
        fseek(disco,0,SEEK_SET);
        fread(&mbr,sizeof(MBR),1,disco);

        double total = mbr.mbr_tamanio;
        double diferencia=0;
        int particion=0;
        int consumo=0;

        for(int i = 0; i < 4; i++){

            if(mbr.mbr_partition[i].part_start != -1){
                double actual = mbr.mbr_partition[i].part_size;
                consumo+=actual;
                particion++;

                double fijo= (actual*100)/total;
                double aux = (fijo*500)/100;

                if(mbr.mbr_partition[i].part_status != '1'){

                    if(mbr.mbr_partition[i].part_type == 'p'){

                        contenido+="           <td height=\'200\' width=\'"+parseDouble(aux)+"\'>Primaria <br/>  "+parseDouble(fijo)+"% del Disco</td>\n";

                        if(i!=3){
                            if(mbr.mbr_partition[i+1].part_start != -1){

                                double actual = mbr.mbr_partition[i].part_start + mbr.mbr_partition[i].part_size;
                                double siguiente = mbr.mbr_partition[i+1].part_start;
                                double diferencia=siguiente-actual;
                                if((diferencia)!=0){

                                    double fijo = (diferencia*100)/total;
                                    double aux = (fijo*500)/100;
                                    contenido+="           <td height=\'200\' width=\'"+parseDouble(aux)+"\'>Libre(1)<br/>"+parseDouble(fijo)+"% del Disco</td>\n";
                                    consumo+=diferencia;
                                }
                            }

                        }else{
                            double actual = mbr.mbr_partition[i].part_start + mbr.mbr_partition[i].part_size;
                            double mbr_tamanio=total+double(sizeof(MBR));
                            diferencia=(mbr_tamanio-actual);
                        }
                    }
                    else{
                        EBR ebr;
                        fseek(disco, mbr.mbr_partition[i].part_start,SEEK_SET);
                        fread(&ebr,sizeof(EBR),1,disco);

                        contenido+="           <td  height=\'200\' width=\'"+parseDouble(fijo)+"\'> \n";
                        contenido+="           <table border=\'0\'  height=\'200\' WIDTH=\'"+parseDouble(fijo)+"\' cellborder=\'1\'> \n";
                        contenido+="           <tr> \n";
                        contenido+="                <td height=\'60\' colspan=\'15\'>Extendida</td> \n ";
                        contenido+="           </tr>\n ";
                        contenido+="           <tr>\n";

                        if(ebr.part_size != 0){
                            fseek(disco, mbr.mbr_partition[i].part_start,SEEK_SET);
                            int part_end=mbr.mbr_partition[i].part_start + mbr.mbr_partition[i].part_size;
                            while(fread(&ebr,sizeof (EBR),1,disco)!=0 && (ftell(disco) < part_end)){

                                actual = ebr.part_size;
                                fijo = (actual*100)/total;

                                if(fijo!=0){
                                    if(ebr.part_status != '1'){
                                        contenido+= "                 <td height=\'140\'>EBR</td>\n";
                                        contenido+= "                 <td height=\'140\'>Lógica<br/>"+parseDouble(fijo)+"% del Disco</td>\n";
                                    }
                                    else{
                                        contenido+= "                 <td height=\'150\'>Libre <br/>"+parseDouble(fijo)+"%  del Disco</td>\n";
                                    }
                                    if(ebr.part_next==-1){
                                        actual = (mbr.mbr_partition[i].part_start + mbr.mbr_partition[i].part_size) - (ebr.part_start + ebr.part_size);
                                        fijo = (actual*100)/total;
                                        if(fijo!=0){
                                            contenido+= "                 <td height=\'150\'>Libre <br/>"+parseDouble(fijo)+"% del Disco</td>\n";
                                        }
                                        break;
                                    }
                                    else{
                                        fseek(disco,ebr.part_next,SEEK_SET);
                                    }
                                }
                            }
                        }
                        else{
                            contenido+="                 <td height=\'140\'>"+parseDouble(fijo)+"%  del Disco</td>\n";
                        }
                        contenido+="           </tr>\n  ";
                        contenido+="           </table>\n";
                        contenido+="           </td>\n";

                        if(i!=3){

                            double siguiente = mbr.mbr_partition[i+1].part_start;

                            if(siguiente!= -1){

                                double actual = mbr.mbr_partition[i].part_start + mbr.mbr_partition[i].part_size;
                                double diferencia=siguiente-actual;

                                if((diferencia)!=0){
                                    double fijo = (diferencia*100)/total;
                                    double aux = (fijo*500)/100;
                                    contenido+="           <td height=\'200\' width=\'"+parseDouble(aux)+"\'>Libre?!(3)<br/>"+parseDouble(fijo)+"%  del Disco</td>\n";
                                    consumo+=diferencia;
                                }

                            }
                        }else{
                            double actual= mbr.mbr_partition[i].part_start + mbr.mbr_partition[i].part_size;
                            double mbr_tamanio=total+double(sizeof(MBR));
                            diferencia=(mbr_tamanio-actual);
                        }
                    }
                }else{
                    contenido+="           <td height=\'200\' width=\'"+parseDouble(aux)+"\'>Libre! <br/>"+parseDouble(fijo)+"% del Disco</td>\n";
                }
            }
        }
        if(particion<4){
            //sumar cuando haya fragmentacion a nivel extendida/primaria
            diferencia=total-consumo;
        }

        if(diferencia!=0){
            double fijo = (diferencia*100)/total;
            double aux=(fijo*500)/100;
            contenido+="           <td height=\'200\' width=\'"+parseDouble(aux)+"\'>Libre?<br/> "+parseDouble(fijo)+"% del Disco</td>\n";

        }


        contenido+="     </tr> \n";
        contenido+="     </table> \n";
        contenido+="\n>];\n\n}";

        fclose(disco);

        string ruta=directorio+nombre+".dot";
        ofstream file;
        file.open(ruta,ios::out);
        file<<contenido;
        file.close();
        string comando = "dot -T"+extension+" "+ruta+" -O "+path;
        system(comando.c_str());
        cout << "Reporte generado con exito " << endl;
    }
    else{
        cout << "El disco no exsite" << endl;
    }
}

void getMBR(string auxPath,string path){
    FILE *disco=comprobarLectura(auxPath);
    if(disco){

        string contenido="";
        contenido+="digraph G { \n";
        contenido+="    subgraph cluster{\n";

        contenido+="subgraph cluster{\n label=\"MBR\"";
        contenido+="labeljust=\"l\"; ";
        contenido+="fontsize = 20;";
        contenido+="\ntbl[fontname=Helvetica  shape=plaintext label=<\n";
        contenido+="<table border=\'0\' cellborder=\'1\' cellspacing=\'0\' width=\'300\'  height=\'200\' >\n";
        contenido+= "<tr>  <td  BGCOLOR=\"gray\"  width=\'150\'> <b>Nombre</b> </td> <td  BGCOLOR=\"gray\" width=\'150\'> <b>Valor</b> </td>  </tr>\n";

        MBR mbr;
        fseek(disco,0,SEEK_SET);
        fread(&mbr,sizeof(MBR),1,disco);
        struct tm *tm;
        char fecha[100];
        tm = localtime(&mbr.mbr_fecha_creacion);
        string disk_fit=parse(mbr.disk_fit);
        strftime(fecha,100,"%d/%m/%y %H:%S",tm);

        contenido+="<tr>  <td ALIGN=\"LEFT\"><b>mbr_tamaño</b></td><td>"+parseDouble(mbr.mbr_tamanio)+"</td>  </tr>\n";
        contenido+="<tr>  <td ALIGN=\"LEFT\"><b>mbr_fecha_creacion</b></td> <td>"+parse(fecha)+"</td>  </tr>\n";
        contenido+="<tr>  <td ALIGN=\"LEFT\"><b>mbr_disk_signature</b></td> <td>"+parseDouble(mbr.mbr_disk_signature)+"</td>  </tr>\n";
        contenido+="<tr>  <td ALIGN=\"LEFT\"><b>Disk_fit</b></td> <td>"+parse(mbr.disk_fit)+"</td>  </tr>\n";

        int extendida = -1;
        for (int i = 0; i < 4; i++){
            if(mbr.mbr_partition[i].part_start!=-1 && mbr.mbr_partition[i].part_status!='1'){
                if(mbr.mbr_partition[i].part_type == 'e'){
                    extendida = i;
                }

                string idx=to_string(i+1);
                string part_status="";
                string part_type="";
                part_status+=mbr.mbr_partition[i].part_status;
                part_type=+mbr.mbr_partition[i].part_type;

                contenido+="<tr>  <td ALIGN=\"LEFT\"><b>part_status_"+idx+"</b></td> <td>"+part_status+"</td>  </tr>\n";
                contenido+="<tr>  <td ALIGN=\"LEFT\"><b>part_type_"+idx+"</b></td> <td>"+part_type+"</td>  </tr>\n";
                contenido+="<tr>  <td ALIGN=\"LEFT\"><b>part_fit_"+idx+"</b></td> <td>"+parse(mbr.mbr_partition[i].part_fit)+"</td>  </tr>\n";
                contenido+="<tr>  <td ALIGN=\"LEFT\"><b>part_start_"+idx+"</b></td> <td>"+to_string(mbr.mbr_partition[i].part_start)+"</td>  </tr>\n";
                contenido+="<tr>  <td ALIGN=\"LEFT\"><b>part_size_"+idx+"</b></td> <td>"+to_string(mbr.mbr_partition[i].part_size)+"</td>  </tr>\n";
                contenido+="<tr>  <td ALIGN=\"LEFT\"><b>part_name_"+idx+"</b></td> <td>"+parse(mbr.mbr_partition[i].part_name)+"</td>  </tr>\n";
            }
        }

        contenido+="</table>\n";
        contenido+= ">];\n}\n";

        if(extendida != -1){

            EBR ebr;
            fseek(disco,mbr.mbr_partition[extendida].part_start,SEEK_SET);
            int cluster=0;
            int part_end=mbr.mbr_partition[extendida].part_start + mbr.mbr_partition[extendida].part_size;
            while(fread(&ebr,sizeof(EBR),1,disco)!=0 && (ftell(disco) < part_end)) {
                if(ebr.part_status != '1'){
                    cluster++;
                    string idx=to_string(cluster);
                    contenido+="subgraph cluster"+idx+"{\n label=\"EBR_"+idx+"\"\n";
                    contenido+="labeljust=\"l\"; ";
                    contenido+="fontsize = 20;";
                    contenido+="\ntbl_"+idx+"[fontname=Helvetica  shape=plaintext label=<\n ";
                    contenido+= "<table border=\'0\' cellborder=\'1\' cellspacing=\'0\'  width=\'300\' height=\'160\' >\n ";
                    contenido+= "<tr>  <td BGCOLOR=\"gray\" width=\'150\'><b>Nombre</b></td> <td BGCOLOR=\"gray\" width=\'150\'><b>Valor</b></td>  </tr>\n";

                    string part_status="";
                    part_status+=ebr.part_status;
                    contenido+= "<tr>  <td ALIGN=\"LEFT\"><b>part_status_1</b></td> <td>"+part_status+"</td>  </tr>\n";
                    contenido+= "<tr>  <td ALIGN=\"LEFT\"><b>part_fit_1</b></td> <td>"+parse(ebr.part_fit)+"</td>  </tr>\n";
                    contenido+= "<tr>  <td ALIGN=\"LEFT\"><b>part_start_1</b></td> <td>"+to_string(ebr.part_start)+"</td>  </tr>\n";
                    contenido+= "<tr>  <td ALIGN=\"LEFT\"><b>part_size_1</b></td> <td>"+to_string(ebr.part_size)+"</td>  </tr>\n";
                    contenido+= "<tr>  <td ALIGN=\"LEFT\"><b>part_next_1</b></td> <td>"+to_string(ebr.part_next)+"</td>  </tr>\n";
                    contenido+= "<tr>  <td ALIGN=\"LEFT\"><b>part_name_1</b></td> <td>"+parse(ebr.part_name)+"</td>  </tr>\n";

                    contenido+= "</table>\n";
                    contenido+= ">];\n}\n";

                }

                if(ebr.part_next == -1){
                    break;
                }
                else{
                    fseek(disco,ebr.part_next,SEEK_SET);
                }

            }

        }
        contenido+="}\n";
        contenido+="}\n";
        fclose(disco);
        string ruta=directorio+nombre+".dot";
        ofstream file;
        file.open(ruta,ios::out);
        file<<contenido;
        file.close();
        string comando = "dot -T"+extension+" "+ruta+" -O "+path;
        system(comando.c_str());
        cout<<"Reporte generado con exito"<<endl;
    }
    else{
        cout<<"El disco no existe"<<endl;
    }
}

void getBM(nodoSimple *nodo,string ruta,string tipo){

    string path=nodo->path;
    string name=nodo->name;

    comprobarParticion(path,name);

    FILE *disco = fopen(nodo->path.c_str(),"rb+");
    MBR mbr;
    SUPERBLOCK super;

    // cout<<to_string(byteP)+" "+to_string(indexP)+" "+to_string(indexE)<<endl;
    int lectura=byteP;

    if(lectura==-1){
        int idx=indexE;
        if(indexP!=-1){
            idx=indexP;
        }
        fread(&mbr,sizeof(MBR),1,disco);
        lectura=mbr.mbr_partition[idx].part_start;
    }
    //cout<<"Lectura: "+to_string(lectura)<<endl;


    fseek(disco,lectura,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    int start=super.s_bm_inode_start;
    int n=super.s_inodes_count;
    if(tipo=="bm_block"){
        start=super.s_bm_block_start;
        n=super.s_blocks_count;
    }

    //cout<<"START: "+to_string(start)+" N: "+to_string(n)<<endl;

    ofstream file;
    file.open(ruta,ios::out);

    int cont = 0;
    for (int i = 0; i < n; i++) {
        fseek(disco,start + i,SEEK_SET);
        int ascii=fgetc(disco);
        if(ascii == 48){
            file<<"0 ";
        }
        else{
            file<<"1 ";
        }
        if(cont == 19){
            cont = 0;
            file<<"\n";
        }else{
            cont++;
        }
    }
    file.close();
    fclose(disco);
    cout << "Reporte generado con exito"<< endl;
}


/*
 * vamo a dejarlo por aca, la meta?
 * file
 */


void getInode(string path,string name){


    comprobarParticion(path,name);

    FILE *disco = fopen(path.c_str(),"rb+");
    MBR mbr;
    SUPERBLOCK super;

    int lectura=byteP;

    if(lectura==-1){
        int idx=indexE;
        if(indexP!=-1){
            idx=indexP;
        }
        fread(&mbr,sizeof(MBR),1,disco);
        lectura=mbr.mbr_partition[idx].part_start;
    }


    //fread(&mbr,sizeof(MBR),1,disco);
    fseek(disco,lectura,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    int bm_inode_start=super.s_bm_inode_start;
    int inode_start=super.s_inode_start;
    int bm_block_start=super.s_bm_block_start;


    INODE inodo;
    int k=bm_inode_start;
    int prev=-1;

    string contenido="";
    contenido+="digraph G{ \n";
    contenido+="    rankdir=\"LR\"; \n";

    for(int i=0; k<bm_block_start;k++&&i++){
        fseek(disco,bm_inode_start+i,SEEK_SET);
        int ascii = fgetc(disco);
        if(ascii == 49){
            fseek(disco,inode_start + static_cast<int>(sizeof(INODE))*i,SEEK_SET);  //---se salta i veces el sizeof de un INODE
            fread(&inodo,sizeof(INODE),1,disco);
            contenido+= "   nodo_"+to_string(i)+" [ fontname=Helvetica  shape=plaintext  label=<\n";
            contenido+= "       <table border=\'0\' cellborder=\'1\' cellspacing=\'0\'> \n";
            contenido+= "           <tr> <td  BGCOLOR=\"gray\" colspan=\'2\'> Inodo "+to_string(i)+" </td></tr>\n";
            contenido+= "           <tr> <td ALIGN=\"LEFT\"> <b> i_uid </b> </td> <td > "+to_string(inodo.i_uid)+" </td>  </tr>\n";
            contenido+= "           <tr> <td ALIGN=\"LEFT\"> <b> i_gid </b> </td> <td > "+to_string(inodo.i_gid)+" </td>  </tr>\n";
            contenido+= "           <tr> <td ALIGN=\"LEFT\"> <b> i_size </b> </td> <td > "+to_string(inodo.i_size)+" </td> </tr>\n";

            struct tm*tm;
            char fecha[100];
            tm=localtime(&inodo.i_atime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);

            contenido+= "           <tr> <td ALIGN=\"LEFT\"> <b> i_atime </b> </td> <td > "+parse(fecha)+" </td>  </tr>\n";
            tm=localtime(&inodo.i_ctime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            contenido+= "           <tr> <td ALIGN=\"LEFT\"> <b> i_ctime </b> </td> <td > "+parse(fecha)+" </td>  </tr>\n";
            tm=localtime(&inodo.i_mtime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            contenido+= "           <tr> <td ALIGN=\"LEFT\"> <b> i_mtime </b> </td> <td > "+parse(fecha)+" </td></tr>\n";

            for(int i = 0; i < 15; i++){
                int temp=i+1;
                contenido+= "           <tr> <td ALIGN=\"LEFT\"> <b> i_block_"+to_string(temp)+"</b> </td> <td > "+to_string(inodo.i_block[i])+" </td> </tr>\n";
            }

            string type="";
            type+=inodo.i_type;

            contenido+= "           <tr> <td ALIGN=\"LEFT\"> <b> i_type </b> </td> <td > "+type+" </td> </tr>\n";
            contenido+= "           <tr> <td ALIGN=\"LEFT\"> <b> i_perm </b> </td> <td > "+to_string(inodo.i_perm)+" </td> </tr>\n";
            contenido+= "       </table>>]\n";
            if(prev==-1){
                prev=i;
            }
            else if(prev!=i){
                contenido+= "nodo_"+to_string(prev)+" -> nodo_"+to_string(i)+"\n";
                prev=i;
            }
        }
    }

    contenido+="\n}";

    fclose(disco);

    string ruta=directorio+nombre+".dot";
    ofstream file;
    file.open(ruta,ios::out);
    file<<contenido;
    file.close();
    string comando = "dot -T"+extension+" "+ruta+" -O "+path;
    system(comando.c_str());
    cout<<"Reporte generado con exito"<<endl;
}


void getBlock(string path,string name){


    comprobarParticion(path,name);

    FILE *disco = fopen(path.c_str(),"rb+");
    MBR mbr;
    SUPERBLOCK super;

    int lectura=byteP;

    if(lectura==-1){
        int idx=indexE;
        if(indexP!=-1){
            idx=indexP;
        }
        fread(&mbr,sizeof(MBR),1,disco);
        lectura=mbr.mbr_partition[idx].part_start;
    }


    //fread(&mbr,sizeof(MBR),1,disco);
    fseek(disco,lectura,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    int s_bm_block_start=super.s_bm_block_start;
    int s_block_start=super.s_block_start;
    int s_inode_start=super.s_inode_start;


    FOLDERBLOCK folder;
    FILEBLOCK archivo;
    POINTERBLOCK puntero;
    int k=s_bm_block_start;

    int prev=-1;

    string contenido="";
    contenido+="digraph G{ \n";
    contenido+="    rankdir=\"LR\"; \n";

    //cout<<to_string(k)+" "+to_string(s_inode_start)<<endl;

    //---NOTA: el numero en el encabezado del bloque no representa su entero de referencia
    for(int i=0; k<s_inode_start;k++&&i++){
        fseek(disco,s_bm_block_start+i,SEEK_SET);
        int ascii = fgetc(disco);
        if(ascii == 49){
            fseek(disco,s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*i,SEEK_SET);  // se salta i veces el sizeof de un FOLDERBLOCK
            fread(&folder,sizeof(FOLDERBLOCK),1,disco);
            contenido+= "    nodo_"+to_string(i)+" [ fontname=Helvetica  shape=plaintext  label=<\n";
            contenido+= "       <table border=\'0\' cellborder=\'1\' cellspacing=\'0\'> \n";
            contenido+= "           <tr> <td  BGCOLOR=\"gray\" colspan=\'2\'> Bloque Carpeta "+to_string(i)+" </td></tr>\n";
            contenido+= "           <tr> <td ALIGN=\"LEFT\"> <b> b_name </b> </td> <td > b_inode </td>  </tr>\n";
            for(int i = 0;i < 4;i++){
                contenido+="           <tr> <td ALIGN=\"LEFT\"> <b> "+parse(folder.b_content[i].b_name)+" </b> </td> <td > "+to_string(folder.b_content[i].b_inodo)+" </td></tr>\n";
            }
            contenido+= "       </table>>]\n\n";
            if(prev!=-1){
                contenido+= "nodo_"+to_string(prev)+" -> nodo_"+to_string(i)+"\n";
            }
            prev=i;
        }
        else if(ascii==50){
            fseek(disco,s_block_start + static_cast<int>(sizeof(FILEBLOCK))*i,SEEK_SET);
            fread(&archivo,sizeof(FILEBLOCK),1,disco);
            contenido+= "    nodo_"+to_string(i)+" [fontname=Helvetica  shape=plaintext label=< \n";
            contenido+= "       <table border=\'0\' cellborder='1' cellspacing='0'>\n";
            contenido+= "           <tr> <td BGCOLOR=\"gray\" colspan=\'2\'> Bloque Archivo "+to_string(i)+" </td></tr>\n";
            contenido+= "           <tr> \n";
            contenido+= "           <td colspan=\'2\' ALIGN=\"LEFT\">\n";
            contenido+=             parseContent(archivo.b_content);
            contenido+= "           </td>\n";
            contenido+= "           </tr>\n";
            contenido+= "       </table>>]\n\n";

            if(prev!=-1){
                contenido+= "nodo_"+to_string(prev)+" -> nodo_"+to_string(i)+"\n";
            }
            prev=i;
        }
        else if(ascii==51){
            fseek(disco,s_block_start + static_cast<int>(sizeof(POINTERBLOCK))*i,SEEK_SET);
            fread(&puntero,sizeof(POINTERBLOCK),1,disco);
            fseek(disco,s_block_start + static_cast<int>(sizeof(POINTERBLOCK))*i,SEEK_SET);
            fread(&puntero,sizeof(POINTERBLOCK),1,disco);
            contenido+= "    nodo_"+to_string(i)+" [fontname=Helvetica  shape=plaintext label=< \n";
            contenido+= "       <table border=\'0\'  cellborder='1' cellspacing='0'>\n";
            contenido+= "           <tr> <td  BGCOLOR=\"gray\"> Bloque Apuntadores "+to_string(i)+"</td></tr>\n";
            contenido+= "    <tr> <td >\n";
            int cont=0;
            for(int j = 0; j < 16; j++){
                contenido+=to_string(puntero.b_pointers[j])+", ";
                if(cont==3){
                    //---aqui me quede
                    contenido+="<br/>\n";
                    cont=-1;
                }
                cont++;
            }
            contenido+="</td> </tr>\n";
            contenido+= "       </table>>]\n\n";
            if(prev!=-1){
                contenido+= "nodo_"+to_string(prev)+" -> nodo_"+to_string(i)+"\n";
            }
            prev=i;

        }


    }

    contenido+="\n}";

    fclose(disco);

    string ruta=directorio+nombre+".dot";
    ofstream file;
    file.open(ruta,ios::out);
    file<<contenido;
    file.close();
    string comando = "dot -T"+extension+" "+ruta+" -O "+path;
    system(comando.c_str());
    cout<<"Reporte generado con exito"<<endl;
}

void getSb(string path,string name){

    comprobarParticion(path,name);

    FILE *disco = fopen(path.c_str(),"rb+");
    MBR mbr;
    SUPERBLOCK super;

    int lectura=byteP;

    if(lectura==-1){
        int idx=indexE;
        if(indexP!=-1){
            idx=indexP;
        }
        fread(&mbr,sizeof(MBR),1,disco);
        lectura=mbr.mbr_partition[idx].part_start;
    }


    //fread(&mbr,sizeof(MBR),1,disco);
    fseek(disco,lectura,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    string contenido="";

    contenido+= "digraph G{\n";
    contenido+= "   nodo [fontname=Helvetica  shape=plaintext label=<";
    contenido+= "       <table border=\'0\' cellborder='1\' cellspacing=\'0\' >\n";
    contenido+= "       <tr> <td BGCOLOR=\"gray\"> <b>Nombre</b> </td><td BGCOLOR=\"gray\"><b>Valor</b></td></tr>\n";
    contenido+= "       <tr> <td ALIGN=\"LEFT\"> s_inodes_count </td> <td > "+to_string(super.s_inodes_count)+" </td> </tr>\n";
    contenido+= "       <tr> <td ALIGN=\"LEFT\"> s_blocks_count </td> <td > "+to_string(super.s_blocks_count)+" </td> </tr>\n";
    contenido+= "       <tr> <td ALIGN=\"LEFT\"> s_free_block_count </td> <td > "+to_string(super.s_free_blocks_count)+" </td> </tr>\n";
    contenido+= "       <tr> <td ALIGN=\"LEFT\"> s_free_inodes_count </td> <td > "+to_string(super.s_free_inodes_count)+" </td> </tr>\n";
    struct tm *tm;
    char fecha[100];
    tm=localtime(&super.s_mtime);
    strftime(fecha,100,"%d/%m/%y %H:%S",tm);
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_mtime </td> <td > "+parse(fecha)+" </td></tr>\n";
    tm=localtime(&super.s_umtime);
    strftime(fecha,100,"%d/%m/%y %H:%S",tm);
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_umtime </td> <td > "+parse(fecha)+" </td> </tr>\n";
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_mnt_count </td> <td > "+to_string(super.s_mnt_count)+" </td> </tr>\n";
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_magic </td> <td > "+to_string(super.s_magic)+" </td> </tr>\n";
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_inode_size </td> <td > "+to_string(super.s_inode_size)+" </td> </tr>\n";
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_block_size </td> <td > "+to_string(super.s_block_size)+" </td> </tr>\n";
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_first_ino </td> <td > "+to_string(super.s_first_ino)+" </td> </tr>\n";
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_first_blo </td> <td > "+to_string(super.s_first_blo)+" </td> </tr>\n";
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_bm_inode_start </td> <td > "+to_string(super.s_bm_inode_start)+" </td></tr>\n";
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_bm_block_start </td> <td >"+to_string(super.s_bm_block_start)+" </td> </tr>\n";
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_inode_start </td> <td > "+to_string(super.s_inode_start)+" </td> </tr>\n";
    contenido+= "    <tr> <td ALIGN=\"LEFT\"> s_block_start </td> <td > "+to_string(super.s_block_start)+" </td> </tr>\n";
    contenido+= "   </table>>]\n";
    contenido+="\n}";
    fclose(disco);

    string ruta=directorio+nombre+".dot";
    ofstream file;
    file.open(ruta,ios::out);
    file<<contenido;
    file.close();
    string comando = "dot -T"+extension+" "+ruta+" -O "+path;
    system(comando.c_str());
    cout<<"Reporte generado con exito"<<endl;
}

/*
 * IMPORTANTE:
 * en caso de elegirse una particion extendida debera notificar error
 * debido a que netamente en ella NO se puede montar un sistema de archivos,
 * solo en las logicas que se encuentren dentro de ella!
 */
void getTree(string path,string name){

    comprobarParticion(path,name);
    FILE *disco = fopen(path.c_str(),"rb+");

    MBR mbr;
    SUPERBLOCK super;

    int lectura=byteP;

    if(lectura==-1){
        int idx=indexE;
        if(indexP!=-1){
            idx=indexP;
        }
        fread(&mbr,sizeof(MBR),1,disco);
        lectura=mbr.mbr_partition[idx].part_start;
    }


    //fread(&mbr,sizeof(MBR),1,disco);
    fseek(disco,lectura,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    INODE inodo;
    FOLDERBLOCK carpeta;
    FILEBLOCK archivo;
    POINTERBLOCK puntero;


    //int aux = super.s_bm_inode_start;
    int inicioInodos=super.s_bm_inode_start;
    int inicioBloques=super.s_bm_block_start;



    string contenido="";


    contenido+="digraph G{\n";
    contenido+="    rankdir=\"LR\" \n";
    contenido+="    splines=false;\n";
    //contenido+="overlap = false";
    //contenido+="splines = true";


    int cont = 0;
    for (int i=inicioInodos;i<inicioBloques;i++&&cont++) {
        int port=0;
        fseek(disco,super.s_bm_inode_start+cont,SEEK_SET);
        int bit = fgetc(disco);
        if(bit==49){

            fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*cont,SEEK_SET);
            fread(&inodo,sizeof(INODE),1,disco);
            contenido+="    inodo_"+to_string(cont)+" [ fontname=Helvetica  shape=plaintext label=<\n";
            contenido+="        <table border=\'0\' cellborder=\'1\' cellspacing=\'0\'> \n";
            contenido+="            <tr> <td  bgcolor=\"#5a99d5\" port=\"c\" colspan=\'2\'><b><font color=\"white\">Inodo "+to_string(cont)+"</font></b></td></tr>\n";
            contenido+="            <tr> <td ALIGN=\"LEFT\"><b> i_uid </b> </td> <td > "+to_string(inodo.i_uid)+" </td>  </tr>\n";
            contenido+="            <tr> <td ALIGN=\"LEFT\"><b> i_gid </b></td> <td > "+to_string(inodo.i_gid)+" </td>  </tr>\n";
            contenido+="            <tr> <td ALIGN=\"LEFT\"><b> i_size </b> </td><td > "+to_string(inodo.i_size)+" </td> </tr>\n";
            struct tm *tm;
            char fecha[100];
            tm=localtime(&inodo.i_atime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            contenido+="            <tr> <td ALIGN=\"LEFT\"><b> i_atime </b></td> <td > "+parse(fecha)+" </td> </tr>\n";
            tm=localtime(&inodo.i_ctime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            contenido+="            <tr> <td ALIGN=\"LEFT\"><b> i_ctime </b></td> <td > "+parse(fecha)+" </td> </tr>\n";
            tm=localtime(&inodo.i_mtime);
            strftime(fecha,100,"%d/%m/%y %H:%S",tm);
            contenido+="            <tr> <td ALIGN=\"LEFT\"><b> i_mtime </b></td> <td > "+parse(fecha)+" </td> </tr>\n";

            for(int j= 0; j < 15; j++){
                contenido+="            <tr> <td ALIGN=\"LEFT\"><b>  i_block_"+to_string(port)+"</b> </td> <td  port=\"f"+to_string(j)+"\"> "+to_string(inodo.i_block[j])+" </td></tr>\n";
                port++;
            }
            string ss="";
            ss+=inodo.i_type;
            contenido+="            <tr> <td ALIGN=\"LEFT\"><b>  i_type </b></td> <td > "+ss+" </td>  </tr>\n";
            contenido+="            <tr> <td ALIGN=\"LEFT\"><b>  i_perm </b></td> <td > "+to_string(inodo.i_perm)+"</td>  </tr>\n";
            contenido+="            </table>>]\n\n";
            //-------------------------------------------------------------------------------




            for(int j = 0; j < 15; j++){
                if(inodo.i_block[j] != -1){
                    fseek(disco,super.s_bm_block_start + inodo.i_block[j],SEEK_SET);
                    port=0;
                    int bit = fgetc(disco);
                    if(bit==49){

                        fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*inodo.i_block[j],SEEK_SET);
                        fread(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                        contenido+="    bloque_"+to_string(inodo.i_block[j])+" [fontname=Helvetica  shape=plaintext label=< \n";
                        contenido+="        <table  border=\'0\' cellborder=\'1\' cellspacing=\'0\'>\n";
                        contenido+="            <tr> <td bgcolor=\"#76aa4e\" port=\"c\"  colspan=\'2\'><b><font color=\"white\">Bloque "+to_string(inodo.i_block[j])+"</font></b></td></tr>\n";
                        for(int k = 0;k < 4; k++){
                            contenido+="            <tr> <td  ALIGN=\"LEFT\"><b> "+parse(carpeta.b_content[k].b_name)+"</b> </td> <td   port=\"f"+to_string(port)+"\"> "+to_string(carpeta.b_content[k].b_inodo)+" </td></tr>\n";
                            port++;
                        }
                        contenido+="        </table>>]\n\n";

                        for(int k = 0; k < 4; k++){
                            if(carpeta.b_content[k].b_inodo !=-1){
                                if(parse(carpeta.b_content[k].b_name)!="."&&parse(carpeta.b_content[k].b_name)!=".."){
                                    contenido+="    bloque_"+to_string(inodo.i_block[j])+":f"+to_string(k)+" -> inodo_"+to_string(carpeta.b_content[k].b_inodo)+":c;\n";
                                }
                            }
                        }

                    }
                    else if(bit==50){
                        fseek(disco,super.s_block_start + static_cast<int>(sizeof(FILEBLOCK))*inodo.i_block[j],SEEK_SET);
                        fread(&archivo,sizeof(FILEBLOCK),1,disco);
                        contenido+="    bloque_"+to_string(inodo.i_block[j])+" [fontname=Helvetica  shape=plaintext label=< \n";
                        contenido+="   <table border=\'0\' cellborder=\'1\' cellspacing=\'0\'>\n";
                        contenido+="    <tr> <td bgcolor=\"#fcba00\" port=\"c\" > <b><font color=\"white\">Bloque "+to_string(inodo.i_block[j])+"</font></b></td></tr>\n";
                        contenido+="    <tr> <td >"+parseContent(archivo.b_content)+"</td></tr>\n";
                        contenido+="   </table>>]\n\n";
                    }
                    else if(bit==51){
                        fseek(disco,super.s_block_start + static_cast<int>(sizeof(POINTERBLOCK))*inodo.i_block[j],SEEK_SET);
                        fread(&puntero,sizeof(POINTERBLOCK),1,disco);
                        contenido+="    bloque_"+to_string(inodo.i_block[j])+" [fontname=Helvetica  shape=plaintext label=< \n";
                        contenido+="   <table border=\'0\' cellborder=\'1\' cellspacing=\'0\'>\n";
                        contenido+="    <tr> <td bgcolor=\"#e38343\" port=\"c\" > <b><font color=\"white\">Bloque "+to_string(inodo.i_block[j])+"</font></b></td></tr>\n";
                        for(int k = 0; k < 16; k++){
                            contenido+="    <tr> <td ALIGN=\"LEFT\"  port=\"f"+to_string(port)+"\"><b>"+to_string(puntero.b_pointers[k])+"</b></td> </tr>\n";
                            port++;
                        }
                        contenido+="   </table>>]\n\n";

                        for (int k = 0; k < 16; k++) {
                            port = 0;
                            if(puntero.b_pointers[k] != -1){
                                fseek(disco,super.s_bm_block_start + puntero.b_pointers[k],SEEK_SET);
                                int bit = fgetc(disco);
                                if(bit == 49){
                                    fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*puntero.b_pointers[k],SEEK_SET);
                                    fread(&carpeta,sizeof(FOLDERBLOCK),1,disco);
                                    contenido+="    bloque_"+to_string(puntero.b_pointers[k])+" [fontname=Helvetica  shape=plaintext label=< \n";
                                    contenido+="    <table border=\'0\' cellborder=\'1\' cellspacing=\'0\'>\n";
                                    contenido+="    <tr> <td bgcolor=\"#76aa4e\" port=\"c\"  colspan=\'2\'><b><font color=\"white\">Bloque "+to_string(inodo.i_block[k])+"</font></b></td></tr>\n";
                                    for(int l = 0;l < 4; l++){
                                        contenido+="    <tr> <td ALIGN=\"LEFT\"><b> "+parse(carpeta.b_content[l].b_name)+"</b> </td> <td  port=\"f"+to_string(port)+"\"> "+to_string(carpeta.b_content[l].b_inodo)+"</td></tr>\n";
                                        port++;
                                    }
                                    contenido+="   </table>>]\n\n";

                                    for(int l = 0; l < 4; l++){
                                        if(carpeta.b_content[l].b_inodo !=-1){
                                            if(parse(carpeta.b_content[l].b_name)!="."&&parse(carpeta.b_content[l].b_name)!=".."){
                                                contenido+="    bloque_"+to_string(puntero.b_pointers[k])+":f"+to_string(l)+" -> inodo_"+to_string(carpeta.b_content[l].b_inodo)+":c;\n";
                                            }
                                        }
                                    }
                                }else if(bit == 50){
                                    fseek(disco,super.s_block_start + static_cast<int>(sizeof(FILEBLOCK))*puntero.b_pointers[k],SEEK_SET);
                                    fread(&archivo,sizeof(FILEBLOCK),1,disco);
                                    contenido+="    bloque_"+to_string(puntero.b_pointers[k])+" [shape=plaintext fontname=\"Century Gothic\" label=< \n";
                                    contenido+="   <table border=\'0\' cellborder=\'1\' cellspacing=\'0\'>\n";
                                    contenido+="    <tr> <td bgcolor=\"#fcba00\" port=\"c\" > <b><font color=\"white\">Bloque "+to_string(inodo.i_block[k])+"</font></b></td></tr>\n";
                                    contenido+="    <tr> <td >"+parseContent(archivo.b_content)+"</td></tr>\n";
                                    contenido+="   </table>>]\n\n";
                                }else if(bit == 51){
                                    //---el lunes sin falta :c
                                }
                            }
                        }

                        for(int k = 0; k < 16;k++){
                            if(puntero.b_pointers[k] != -1){
                                contenido+="    bloque_"+to_string(inodo.i_block[j])+":f"+to_string(k)+" -> bloque_"+to_string(puntero.b_pointers[k])+":c;\n";
                            }
                        }
                    }


                    contenido+="    inodo_"+to_string(cont)+":f"+to_string(j)+" -> bloque_"+to_string(inodo.i_block[j])+":c; \n";
                }
            }


        }

    }

    //--------------------------



    //----------------------------------------


    contenido+="\n\n}";
    fclose(disco);
    string ruta=directorio+nombre+".dot";
    ofstream file;
    file.open(ruta,ios::out);
    file<<contenido;
    file.close();
    string comando = "dot -T"+extension+" "+ruta+" -O "+path;
    system(comando.c_str());
    cout<<"Reporte generado con exito"<<endl;
}

void getFile(string path,string name,string ruta){

    comprobarParticion(path,name);
    FILE *disco = fopen(path.c_str(),"rb+");

    MBR mbr;
    SUPERBLOCK super;

    int lectura=byteP;

    if(lectura==-1){
        int idx=indexE;
        if(indexP!=-1){
            idx=indexP;
        }
        fread(&mbr,sizeof(MBR),1,disco);
        lectura=mbr.mbr_partition[idx].part_start;
    }

    fseek(disco,lectura,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    int res= buscarArchivo(path,ruta,lectura);
    if(res!=-1){

        int n=ruta.length();
        char arr[n+1];

        strcpy(arr,ruta.c_str());

        string padre=basename(arr);

        INODE inodo;
        FILEBLOCK archivo;


        fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*res,SEEK_SET);
        fread(&inodo,sizeof(INODE),1,disco);

        string contenido="";
        contenido+="digraph G{\n";
        contenido+="    nodo [fontname=Helvetica  shape=plaintext label=<\n";
        contenido+="        <table border=\'0\' cellborder='1\' cellspacing=\'0\' >\n";
        contenido+="            <tr><td BGCOLOR=\"gray\" align=\"left\"> <b>"+padre+"</b> </td></tr>\n";
        contenido+="            <tr><td >\n";
        for (int i = 0; i < 15; i++) {
            if(inodo.i_block[i] != -1){
                if(i == 12){
                }else if(i == 13){

                }else if(i == 14){

                }else{
                    fseek(disco,super.s_block_start + static_cast<int>(sizeof(FOLDERBLOCK))*inodo.i_block[i],SEEK_SET);
                    fread(&archivo,sizeof(FILEBLOCK),1,disco);
                    contenido+=parseContent(archivo.b_content);
                }
            }
        }
        contenido+="            </td></tr>\n";
        contenido+="        </table>>]\n";
        contenido+="\n}";

        string ruta=directorio+nombre+".dot";
        ofstream file;
        file.open(ruta,ios::out);
        file<<contenido;
        file.close();
        string comando = "dot -T"+extension+" "+ruta+" -O "+path;
        system(comando.c_str());
        cout<<"Reporte generado con exito"<<endl;

    }
    else{
        cout<<"El directorio o el archivo no existe dentro de "+name<<endl;
    }
    fclose(disco);

}

string getPermisos(char ss){
    string contenido="";
    if(ss == '0'){
        contenido="---";
    }
    else if(ss == '1'){
        contenido="--x";
    }
    else if(ss == '2'){
        contenido="-w-";
    }
    else if(ss == '3'){
        contenido="-wx";
    }
    else if(ss == '4'){
        contenido="r--";
    }
    else if(ss == '5'){
        contenido="r-x";
    }
    else if(ss == '6'){
        contenido="rw-";
    }
    else if(ss == '7'){
        contenido="rwx";
    }
    return contenido;
}

void getLs(string path,string name,string ruta){

    comprobarParticion(path,name);
    FILE *disco = fopen(path.c_str(),"rb+");

    MBR mbr;
    SUPERBLOCK super;

    int lectura=byteP;

    if(lectura==-1){
        int idx=indexE;
        if(indexP!=-1){
            idx=indexP;
        }
        fread(&mbr,sizeof(MBR),1,disco);
        lectura=mbr.mbr_partition[idx].part_start;
    }

    fseek(disco,lectura,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    int res= buscarArchivo(path,ruta,lectura);
    if(res!=-1){
        int n=ruta.length();
        char arr[n+1];

        strcpy(arr,ruta.c_str());

        string padre=basename(arr);

        INODE inodo;

        fseek(disco,super.s_inode_start + static_cast<int>(sizeof(INODE))*res,SEEK_SET);
        fread(&inodo,sizeof(INODE),1,disco);

        reporte=true;
        res=buscarAtributo("usuario",to_string(inodo.i_uid),"",path,lectura);
        reporte=false;
        if(res==2){

            string contenido="";
            contenido+="digraph G{\n\n";
            contenido+="    nodo [ fontname=Helvetica  shape=plaintext \n";
            contenido+="    label=< <table border=\'0\' cellborder='1\' cellspacing=\'0\' >\n";
            contenido+="     <tr> <td  BGCOLOR=\"gray\"><b>Permisos</b></td><td  BGCOLOR=\"gray\"><b>Owner</b></td><td BGCOLOR=\"gray\"><b>Grupo</b></td><td  BGCOLOR=\"gray\"><b>Size</b></td><td  BGCOLOR=\"gray\"><b>Fecha</b></td><td  BGCOLOR=\"gray\"><b>Hora</b></td><td  BGCOLOR=\"gray\"><b>Tipo</b></td><td  BGCOLOR=\"gray\"><b>Name</b></td> </tr>\n";

            string auxPermisos = to_string(inodo.i_perm);
            char usuario = auxPermisos[0];
            char grupo = auxPermisos[1];
            char otros = auxPermisos[2];

            string permisos=getPermisos(usuario);
            permisos+=getPermisos(grupo);
            permisos+=getPermisos(otros);

            string tipo="Archivo";
            if(inodo.i_type == '0'){
                tipo="Carpeta";
            }

            contenido+="<tr> <td >"+permisos+"</td> ";
            contenido+="<td >"+parse(sesionAux.nombre)+"</td>";
            contenido+="<td >"+parse(sesionAux.grupo)+"</td>";
            contenido+="<td >"+to_string(inodo.i_size)+"</td>";

            struct tm *tm;
            char fecha[100];
            tm=localtime(&inodo.i_atime);
            strftime(fecha,100,"%d/%m/%y",tm);
            contenido+="<td >"+parse(fecha)+"</td>";
            strftime(fecha,100,"%H:%S",tm);
            contenido+="<td >"+parse(fecha)+"</td>";
            contenido+="<td >"+tipo+"</td>";
            contenido+="<td >"+padre+"</td> </tr>\n";

            contenido+="    </table>>]\n";
            contenido+="\n}";


            string ruta=directorio+nombre+".dot";
            ofstream file;
            file.open(ruta,ios::out);
            file<<contenido;
            file.close();
            string comando = "dot -T"+extension+" "+ruta+" -O "+path;
            system(comando.c_str());
            cout<<"Reporte generado con exito"<<endl;
        }
        else{
            cout<<"El usuario propietario ya no existe"<<endl;
        }
    }
    else{
        cout<<"El directorio o el archivo no existe dentro de "+name<<endl;
    }
    fclose(disco);
}

void getJournal(string path,string name,string particion){

    comprobarParticion(path,name);
    FILE *disco = fopen(path.c_str(),"rb+");

    MBR mbr;
    SUPERBLOCK super;
    JOURNALING journal;

    int lectura=byteP;

    if(lectura==-1){
        int idx=indexE;
        if(indexP!=-1){
            idx=indexP;
        }
        fread(&mbr,sizeof(MBR),1,disco);
        lectura=mbr.mbr_partition[idx].part_start;
    }

    fseek(disco,lectura,SEEK_SET);
    fread(&super,sizeof(SUPERBLOCK),1,disco);

    string contenido="";

    contenido+="digraph G{\n";
    contenido+= "   nodo [fontname=Helvetica  shape=plaintext label=<\n";
    contenido+= "       <table border=\'0\' cellborder='1\' cellspacing=\'0\'>\n";
    contenido+= "            <tr> <td BGCOLOR=\"gray\"><b>time</b></td><td BGCOLOR=\"gray\"><b>user</b></td><td BGCOLOR=\"gray\"><b>part_name</b></td><td BGCOLOR=\"gray\"><b>operation</b></td></tr> \n";
    fseek(disco,lectura + static_cast<int>(sizeof(SUPERBLOCK)),SEEK_SET);
    int n=super.n;
    //cout<<"N: "+to_string(n)<<endl;
    int cont=0;
    while(ftell(disco) < super.s_bm_inode_start){
        if(cont==n){
            break;
        }
        fread(&journal,sizeof(JOURNALING),1,disco);
        struct tm *tm;
        char fecha[100];
        tm = localtime(&journal.time);
        strftime(fecha,100,"%d/%m/%y %H:%S",tm);
        contenido+="            <tr>\n";
        contenido+="                <td>"+parse(fecha)+"</td>\n";
        contenido+="                <td>"+parse(journal.user)+"</td>\n";
        contenido+="                <td>"+particion+"</td>\n";
        contenido+="                <td>"+parse(journal.operation)+"</td>\n";
        contenido+="            </tr>\n";
        cont++;
    }
    contenido+= "       </table>>]\n";
    contenido+="}";

    fclose(disco);

    string ruta=directorio+nombre+".dot";
    ofstream file;
    file.open(ruta,ios::out);
    file<<contenido;
    file.close();
    string comando = "dot -T"+extension+" "+ruta+" -O "+path;
    system(comando.c_str());
    cout<<"Reporte generado con exito"<<endl;

}

void REP(string name, string path, string id,string ruta){
    nodoSimple *nodo=mountList->getNodo(id);
    setDatos(path);
    if(nodo!=0){
        string auxPath=nodo->path;
        string mkdir = "sudo mkdir -p \'"+directorio+"\'";
        system(mkdir.c_str());
        string chmod = "sudo chmod 777 \'"+directorio+"\'";
        system(chmod.c_str());
        if(name=="mbr"){
            getMBR(auxPath,path);
        }
        else if(name=="disk"){
            getDisk(auxPath,path);
        }
        else if(name=="bm_inode"||name=="bm_block"){
            getBM(nodo,path,name);
        }
        else if(name=="inode"){
            getInode(nodo->path,nodo->name);
        }
        else if(name=="block"){
            getBlock(nodo->path,nodo->name);
        }
        else if(name=="sb"){
            getSb(nodo->path,nodo->name);
        }
        else if(name=="tree"){
            getTree(nodo->path,nodo->name);
        }
        else if(name=="file"){
            getFile(nodo->path,nodo->name,ruta);
        }
        else if(name=="ls"){
            getLs(nodo->path,nodo->name,ruta);
        }
        else if(name=="journaling"){
            getJournal(nodo->path,nodo->name,id);
        }

    }
    else{
        cout << "El id "+id+" no pertenece a ninguna particion" << endl;
    }

}

//---------------FIN---GENERAR REPORTES-------------------------//



//---------------INICIO---VALIDACION DE PARAMETROS-------------------------//
/*
 * Se colocan todos los parametros que existen por defecto, en caso de ser cadenas
 * se toma como NONE en caso de estar vacios y los enteros como -1 o el valor que
 * se considere conveniente para denotar su ausencia;
 *
*/
void validarMKDISK(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string fit="bf";
        string unit="m";
        string path="NONE";
        int size=-1;

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="fit"){
                fit=param;
            }
            else if(entrada=="unit"){
                unit=param;
            }
            else if(entrada=="path"){
                path=param;
            }
            else if(entrada=="size"){
                stringstream ss(param);
                ss >> size;
            }
            temp=temp->siguiente;
        }

        if(path!="NONE"&&size>0){
            MKDISK(size,fit,unit,path);
        }
        else{
            cout<<"MKDISK invalido"<<endl;
        }
    }
    else{
        cout<<"MKDISK sin parametros"<<endl;
    }
}

void validarRMDISK(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }

            temp=temp->siguiente;
        }
        if(path!="NONE"){
            RMDISK(path);
        }
        else{
            cout<<"RMDISK invalido"<<endl;
        }
    }
    else{
        cout<<"RMDISK sin parametros"<<endl;
    }
}

void validarFDISK(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        int size=-1;
        string unit="k";
        string path="NONE";
        string type="p";
        string fit="wf";
        string del="NONE";
        string name="NONE";
        int add=0;

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;
            if(entrada=="size"){
                stringstream ss(param);
                ss >> size;
            }
            else if(entrada=="unit"){
                unit=param;
            }
            else if(entrada=="path"){
                path=param;
            }
            else if(entrada=="type"){
                type=param;
            }
            else if(entrada=="fit"){
                fit=param;
            }
            else if(entrada=="del"){
                del=param;
            }
            else if(entrada=="name"){
                name=param;
            }
            else if(entrada=="add"){
                stringstream ss(param);
                ss >> add;
            }

            temp=temp->siguiente;
        }


        if(path!="NONE"&&name!="NONE"){
            if(size>0&&del=="NONE"&&add==0){
                FDISK(size,unit,path,type,fit,del,name,add);
            }
            else if(del!="NONE"&&add==0){
                FDISK(size,unit,path,type,fit,del,name,add);
            }
            else if(del=="NONE"&&add!=0){
                FDISK(size,unit,path,type,fit,del,name,add);
            }
            else{
                cout<<"FDISK invalido"<<endl;
            }
        }
        else{
            cout<<"FDISK invalido"<<endl;
        }

    }
    else{
        cout<<"FDISK sin parametros"<<endl;
    }
}

void validarMOUNT(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";
        string name="NONE";


        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;
            if(entrada=="path"){
                path=param;
            }
            else if(entrada=="name"){
                name=param;
            }

            temp=temp->siguiente;
        }

        if(path!="NONE"&&name!="NONE"){
            MOUNT(path,name);
        }
        else{
            cout<<"MOUNT invalido"<<endl;
        }

    }
    else{
        cout<<"MOUNT sin parametros"<<endl;
    }

}

void validarUNMOUNT(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string id="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="id"){
                id=param;
            }

            temp=temp->siguiente;
        }

        if(id!="NONE"){
            UNMOUNT(id);
        }
        else{
            cout<<"UNMOUNT invalido"<<endl;
        }

    }
    else{
        cout<<"UNMOUNT sin parametros"<<endl;
    }
}

void validarREP(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string name="NONE";
        string path="NONE";
        string id="NONE";
        string ruta="NONE";


        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="name"){
                name=param;
            }
            else if(entrada=="path"){
                path=param;
            }
            else if(entrada=="id"){
                id=param;
            }
            else if(entrada=="ruta"){
                ruta=param;
            }
            temp=temp->siguiente;
        }


        if(name!="NONE"&&path!="NONE"&&id!="NONE"){
            REP(name,path,id,ruta);
        }
        else{
            cout<<"REP invalido"<<endl;
        }

    }
    else{
        cout<<"REP sin parametros"<<endl;
    }
}

void validarEXEC(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }
            temp=temp->siguiente;
        }


        if(path!="NONE"){
            contenidoEXEC=EXEC(path);
        }
        else{
            cout<<"EXEC invalido"<<endl;
        }

    }
    else{
        cout<<"EXEC sin parametros"<<endl;
    }
}

void validarMKFS(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string id="NONE";
        string type="full";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="id"){
                id=param;
            }
            temp=temp->siguiente;
        }


        if(id!="NONE"){
            // cout<<"valido?"<<endl;
            MKFS(id,type);
        }
        else{
            cout<<"MKFS invalido"<<endl;
        }

    }
    else{
        cout<<"MKFS sin parametros"<<endl;
    }
}

void validarLOGIN(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string usr="NONE";
        string pwd="NONE";
        string id="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="id"){
                id=param;
            }
            else if(entrada=="pwd"){
                pwd=param;
            }
            else if(entrada=="usr"){
                usr=param;
            }
            temp=temp->siguiente;
        }

        if(id!="NONE"&&usr!="NONE"&&pwd!="NONE"){
            LOGIN(usr,pwd,id);
        }
        else{
            cout<<"LOGIN invalido"<<endl;
        }

    }
    else{
        cout<<"LOGIN sin parametros"<<endl;
    }
}



void validarMKGRP(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string name="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="name"){
                name=param;
            }
            temp=temp->siguiente;
        }

        if(name!="NONE"){
            MKGRP(name);
        }
        else{
            cout<<"MKGRP invalido"<<endl;
        }

    }
    else{
        cout<<"MKGRP sin parametros"<<endl;
    }
}

void validarRMGRP(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string name="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="name"){
                name=param;
            }
            temp=temp->siguiente;
        }

        if(name!="NONE"){
            RMGRP(name);
        }
        else{
            cout<<"RMGRP invalido"<<endl;
        }

    }
    else{
        cout<<"RMGRP sin parametros"<<endl;
    }
}

void validarMKUSR(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string usr="NONE";
        string pwd="NONE";
        string grp="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="usr"){
                usr=param;
            }
            else if(entrada=="pwd"){
                pwd=param;
            }
            else if(entrada=="grp"){
                grp=param;
            }
            temp=temp->siguiente;
        }

        if(usr!="NONE"&&pwd!="NONE"&&grp!="NONE"){
            MKUSR(usr,pwd,grp);
        }
        else{
            cout<<"MKUSR invalido"<<endl;
        }

    }
    else{
        cout<<"MKUSR sin parametros"<<endl;
    }
}

void validarRMUSR(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string usr="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="usr"){
                usr=param;
            }
            temp=temp->siguiente;
        }

        if(usr!="NONE"){
            RMUSR(usr);
        }
        else{
            cout<<"RMUSR invalido"<<endl;
        }

    }
    else{
        cout<<"RMUSR sin parametros"<<endl;
    }
}

void validarMKFILE(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";
        bool p=false;;
        int size=0;
        string cont="";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }
            else if(entrada=="p"){
                p=true;
            }
            else if(entrada=="size"){
                stringstream ss(param);
                ss >> size;
            }
            else if(entrada=="cont"){
                cont=param;
            }

            temp=temp->siguiente;
        }

        if(path!="NONE"&&size>-1){
            MKFILE(path,p,size,cont);
        }
        else{
            cout<<"RMUSR invalido"<<endl;
        }

    }
    else{
        cout<<"RMUSR sin parametros"<<endl;
    }
}

void validarMKDIR(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";
        bool p=false;;

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }
            else if(entrada=="p"){
                p=true;
            }

            temp=temp->siguiente;
        }

        if(path!="NONE"){
            MKDIR(path,p);
        }
        else{
            cout<<"RMUSR invalido"<<endl;
        }

    }
    else{
        cout<<"RMUSR sin parametros"<<endl;
    }
}

void validarFIND(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";
        string name="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }
            else if(entrada=="name"){
                name=param;
            }

            temp=temp->siguiente;
        }

        if(path!="NONE"&&name!="NONE"){
            FIND(path,name);
        }
        else{
            cout<<"FIND invalido"<<endl;
        }

    }
    else{
        cout<<"FIND sin parametros"<<endl;
    }
}

void validarCAT(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string file="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="file"){
                file=param;
            }

            temp=temp->siguiente;
        }

        if(file!="NONE"){
            CAT(file);
        }
        else{
            cout<<"CAT invalido"<<endl;
        }

    }
    else{
        cout<<"CAT sin parametros"<<endl;
    }
}


void validarREN(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";
        string name="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }
            else if(entrada=="name"){
                name=param;
            }
            temp=temp->siguiente;
        }

        if(path!="NONE"&&name!="NONE"){
            REN(path,name);
        }
        else{
            cout<<"REN invalido"<<endl;
        }
    }
    else{
        cout<<"REN sin parametros"<<endl;
    }
}

void validarCHOWN(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";
        bool r=false;
        string usr="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }
            else if(entrada=="usr"){
                usr=param;
            }
            else if(entrada=="r"){
                r=true;
            }
            temp=temp->siguiente;
        }

        if(path!="NONE"&&usr!="NONE"){
            CHOWN(path,r,usr);
        }
        else{
            cout<<"USR invalido"<<endl;
        }
    }
    else{
        cout<<"USR sin parametros"<<endl;
    }
}

void validarCHMOD(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";
        int ugo=0;
        bool r=false;

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }
            else if(entrada=="ugo"){
                stringstream ss(param);
                ss >> ugo;
            }
            else if(entrada=="r"){
                r=true;
            }
            temp=temp->siguiente;
        }

        if(path!="NONE"&&ugo>-1&&ugo<778){
            CHMOD(path,r,ugo);
        }
        else{
            cout<<"USR invalido"<<endl;
        }
    }
    else{
        cout<<"USR sin parametros"<<endl;
    }
}

void validarREM(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }

            temp=temp->siguiente;
        }

        if(path!="NONE"){
            REM(path);
        }
        else{
            cout<<"REM invalido"<<endl;
        }

    }
    else{
        cout<<"REM sin parametros"<<endl;
    }
}

void validarEDIT(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";
        string cont="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }
            else if(entrada=="cont"){
                cont=param;
            }

            temp=temp->siguiente;
        }

        if(path!="NONE"&&cont!="NONE"){
            EDIT(path,cont,"EDIT");
        }
        else{
            cout<<"EDIT invalido"<<endl;
        }

    }
    else{
        cout<<"EDIT sin parametros"<<endl;
    }
}


void validarCP(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";
        string dest="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }
            else if(entrada=="dest"){
                dest=param;
            }

            temp=temp->siguiente;
        }

        if(path!="NONE"&&dest!="NONE"){
            EDIT(path,dest,"CP");
        }
        else{
            cout<<"CP invalido"<<endl;
        }

    }
    else{
        cout<<"CP sin parametros"<<endl;
    }
}

void validarMV(vector<nodoSimple*> parametros){
    if(parametros.size()!=0){
        string path="NONE";
        string dest="NONE";

        nodoSimple *temp=parametros[0];
        while(temp!=0){
            string entrada=temp->contenido;
            string param=temp->atributo;

            if(entrada=="path"){
                path=param;
            }
            else if(entrada=="dest"){
                dest=param;
            }

            temp=temp->siguiente;
        }

        if(path!="NONE"&&dest!="NONE"){
            EDIT(path,dest,"MV");
        }
        else{
            cout<<"MV invalido"<<endl;
        }

    }
    else{
        cout<<"MV sin parametros"<<endl;
    }
}





//--------------FIN---VALIDACION DE PARAMETROS-------------------------//

void recorrerListado(vector<nodoSimple*> nodos){

    for(int i = nodos.size()-1; i>-1; i--) {
        string entrada=nodos[i]->contenido;
        vector<nodoSimple*> param=nodos[i]->listado;


        if(entrada=="mkdisk"){
            validarMKDISK(param);
        }
        else if(entrada=="rmdisk"){
            validarRMDISK(param);
        }
        else if(entrada=="fdisk"){
            validarFDISK(param);
        }
        else if(entrada=="mount"){
            validarMOUNT(param);
        }
        else if(entrada=="unmount"){
            validarUNMOUNT(param);
        }
        else if(entrada=="rep"){
            validarREP(param);
        }
        else if(entrada=="exec"){
            validarEXEC(param);
        }
        else if(entrada=="mkfs"){
            validarMKFS(param);
        }
        else if(entrada=="login"){
            validarLOGIN(param);
        }
        else if(entrada=="logout"){
            LOGOUT();
        }
        else if(entrada=="mkgrp"){
            validarMKGRP(param);
        }
        else if(entrada=="rmgrp"){
            validarRMGRP(param);
        }
        else if(entrada=="mkusr"){
            validarMKUSR(param);
        }
        else if(entrada=="rmusr"){
            validarRMUSR(param);
        }
        else if(entrada=="mkfile"){
            validarMKFILE(param);
        }
        else if(entrada=="mkdir"){
            validarMKDIR(param);
        }
        else if(entrada=="find"){
            validarFIND(param);
        }
        else if(entrada=="cat"){
            validarCAT(param);
        }
        else if(entrada=="pause"){
            PAUSE();
        }
        else if(entrada=="ren"){
            validarREN(param);
        }else if(entrada=="chown"){
            validarCHOWN(param);
        }
        else if(entrada=="chmod"){
            validarCHMOD(param);
        }
        else if(entrada=="rem"){
            validarREM(param);
        }
        else if(entrada=="edit"){
            validarEDIT(param);
        }
        else if(entrada=="cp"){
            validarCP(param);
        }
        else if(entrada=="mv"){
            validarMV(param);
        }

    }
}

void analizar(string entrada){
    raiz->listado.clear();
    contenidoEXEC="NONE";
    YY_BUFFER_STATE bufferState = yy_scan_string(entrada.c_str());
    if(yyparse()==0){
        recorrerListado(raiz->listado);
    }
    yy_delete_buffer(bufferState);
    if(contenidoEXEC!="NONE"){
        analizar(contenidoEXEC);
    }

}


/*
 * LISTADO DE PENDIENTES:
 *  -separar el nombre del disco para notificar error
 *  -cerrar el disco despues de invovarlo
 */

int main(int argc, char *argv[])
{


    //exec -path=/home/anaklusmos/Downloads/Bichulga.sh
    //exec -path=/home/anaklusmos/Downloads/Entrada1.sh
    //exec -path=/home/anaklusmos/Downloads/archivoNoobie.sh
    //exec -path=/home/anaklusmos/Downloads/CalificacionProyecto2.sh
    //exec -path=/home/anaklusmos/indirectos.sh
    QCoreApplication a(argc, argv);


    while(true){
        cout<<endl;
        cout<<">> ";
        string test="";
        getline(cin,test);
        if(test=="out"){
            break;
        }
        analizar(test);
    }

    /*
    string path="/home/dist";
    int n=path.length();
    char arr[n+1];
    char aux[n+1];

    strcpy(arr,path.c_str());
    strcpy(aux,arr);

    string directorio=dirname(arr);
    string padre=basename(aux);

    cout<<directorio+" "+padre<<endl;
    */

    return a.exec();
}

