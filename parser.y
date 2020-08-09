
%{

    #include <stdio.h>
    #include "scanner.h"
    #include "nodo.h"
    #include <string>
    #include <iostream>
    #include <vector>
    using namespace std;

    extern int yylineno;
    extern int columna;
    extern char *yytext;
    extern nodoSimple *raiz;

    int yyerror(const char* mens){
        cout<<mens<<endl;
        return 0;
    }

%}

%define parse.error verbose

%union{
    char text[200];
    class nodoSimple *nodo;
}

%token <text>   mkdisk
%token <text>   rmdisk
%token <text>   fdisk
%token <text>   mount
%token <text>   unmount
%token <text>   rep
%token <text>   exec
%token <text>   size
%token <text>   unit
%token <text>   path
%token <text>   fit
%token <text>   name
%token <text>   type
%token <text>   del
%token <text>   add
%token <text>   id
%token <text>   bf
%token <text>   ff
%token <text>   wf
%token <text> 	k
%token <text> 	m
%token <text> 	b
%token <text> 	p
%token <text> 	e
%token <text> 	l
%token <text>   fast
%token <text>   full
%token <text>   mbr
%token <text>   disk
%token <text>   igual
%token <text> 	entero
%token <text> 	cadena
%token <text> 	identificador
%token <text> 	ruta
%token <text> 	mkfs
%token <text>   login
%token <text> 	logout
%token <text>   mkgrp
%token <text>   rmgrp
%token <text>   mkusr
%token <text> 	rmusr
%token <text>   chmod
%token <text> 	mkfile
%token <text>   cat
%token <text> 	rem
%token <text>   edit
%token <text> 	ren
%token <text>   mkdir
%token <text> 	cp
%token <text>   mv
%token <text> 	findp
%token <text>   chownp
%token <text> 	chgrp
%token <text>   pausep
%token <text> 	carpeta
%token <text>   archivo
%token <text>   usr
%token <text>   pwd
%token <text>   grp
%token <text>   ugo
%token <text>   r
%token <text>   pp
%token <text>   cont
%token <text>   dest
%token <text>   rutap
%token <text>   inode
%token <text>   block
%token <text>   bm_inode
%token <text>   bm_block
%token <text>   tree
%token <text>   sb
%token <text>   file
%token <text>   ls
%token <text>   journaling



%type <nodo>	INICIO
%type <nodo>	COMANDO
%type <nodo>	MKDISK
%type <nodo>	RMDISK
%type <nodo>	FDISK
%type <nodo>	MOUNT
%type <nodo>	UNMOUNT
%type <nodo>	REP
%type <nodo>	EXEC
%type <nodo>	MKFS
%type <nodo>	LOGIN
%type <nodo>	LOGOUT
%type <nodo>	MKGRP
%type <nodo>	RMGRP
%type <nodo>	MKUSR
%type <nodo>	RMUSR
%type <nodo>	CHMOD
%type <nodo>	MKFILE
%type <nodo>	CAT
%type <nodo>	REM
%type <nodo>	EDIT
%type <nodo>    REN
%type <nodo>	MKDIR
%type <nodo>	CP
%type <nodo>	MV
%type <nodo>	FINDP
%type <nodo>	CHOWNP
%type <nodo>	CHGRP
%type <nodo>    PAUSEP


%type <nodo>	ID
%type <nodo>	TYPE
%type <nodo>	TYPEMKFS
%type <nodo>	DEL
%type <nodo>	NAME
%type <nodo>	NAMEREP
%type <nodo>	ADD
%type <nodo>	SIZE
%type <nodo>	FIT
%type <nodo>	UNIT
%type <nodo>	PATH
%type <nodo>	PWD
%type <nodo>	USR
%type <nodo>	GRP
%type <nodo>	UGO
%type <nodo>	CARPETA
%type <nodo>	DEST
%type <nodo>	CONT
%type <nodo>	PATHREM
%type <nodo>	CONTEDIT
%type <nodo>	ARCHIVO
%type <nodo>	FILE
%type <nodo>    RUTA

%start INICIO

%%

INICIO
    : COMANDO
;

COMANDO
    : mkdisk MKDISK COMANDO   {$$=new nodoSimple("---","mkdisk"); $$->agregar($2); raiz->agregar($$);}
    | rmdisk RMDISK COMANDO   {$$=new nodoSimple("---","rmdisk"); $$->agregar($2);raiz->agregar($$);}
    | fdisk FDISK COMANDO     {$$=new nodoSimple("---","fdisk"); $$->agregar($2);raiz->agregar($$);}
    | mount MOUNT COMANDO     {$$=new nodoSimple("---","mount"); $$->agregar($2);raiz->agregar($$);}
    | unmount UNMOUNT COMANDO {$$=new nodoSimple("---","unmount"); $$->agregar($2);raiz->agregar($$);}
    | rep REP COMANDO         {$$=new nodoSimple("---","rep"); $$->agregar($2);raiz->agregar($$);}
    | exec EXEC COMANDO       {$$=new nodoSimple("---","exec"); $$->agregar($2);raiz->agregar($$);}
    | mkfs  MKFS COMANDO      {$$=new nodoSimple("---","mkfs"); $$->agregar($2);raiz->agregar($$);}
    | login LOGIN COMANDO     {$$=new nodoSimple("---","login"); $$->agregar($2);raiz->agregar($$);}
    | logout LOGOUT COMANDO   {$$=new nodoSimple("---","logout"); $$->agregar($2);raiz->agregar($$);}

    | mkgrp MKGRP COMANDO     {$$=new nodoSimple("---","mkgrp"); $$->agregar($2);raiz->agregar($$);}
    | rmgrp RMGRP COMANDO     {$$=new nodoSimple("---","rmgrp"); $$->agregar($2);raiz->agregar($$);}
    | mkusr MKUSR COMANDO     {$$=new nodoSimple("---","mkusr"); $$->agregar($2);raiz->agregar($$);}
    | rmusr RMUSR COMANDO     {$$=new nodoSimple("---","rmusr"); $$->agregar($2);raiz->agregar($$);}

    | chmod CHMOD COMANDO     {$$=new nodoSimple("---","chmod"); $$->agregar($2);raiz->agregar($$);}
    | mkfile MKFILE COMANDO   {$$=new nodoSimple("---","mkfile"); $$->agregar($2);raiz->agregar($$);}
    | cat CAT COMANDO         {$$=new nodoSimple("---","cat"); $$->agregar($2);raiz->agregar($$);}
    | rem REM COMANDO         {$$=new nodoSimple("---","rem"); $$->agregar($2);raiz->agregar($$);}
    | edit EDIT COMANDO       {$$=new nodoSimple("---","edit"); $$->agregar($2);raiz->agregar($$);}
    | ren REN COMANDO         {$$=new nodoSimple("---","ren"); $$->agregar($2);raiz->agregar($$);}
    | mkdir MKDIR COMANDO     {$$=new nodoSimple("---","mkdir"); $$->agregar($2);raiz->agregar($$);}
    | cp CP COMANDO           {$$=new nodoSimple("---","cp"); $$->agregar($2);raiz->agregar($$);}
    | mv MV COMANDO           {$$=new nodoSimple("---","mv"); $$->agregar($2);raiz->agregar($$);}
    | findp FINDP COMANDO       {$$=new nodoSimple("---","find"); $$->agregar($2);raiz->agregar($$);}
    | chownp CHOWNP COMANDO     {$$=new nodoSimple("---","chown"); $$->agregar($2);raiz->agregar($$);}
    | chgrp CHGRP COMANDO     {$$=new nodoSimple("---","chgrp"); $$->agregar($2);raiz->agregar($$);}
    | pausep PAUSEP COMANDO     {$$=new nodoSimple("---","pause"); $$->agregar($2);raiz->agregar($$);}
    |                         {$$=new nodoSimple("FIN","---");}

;


/*
   ------------INICIO DE COMANDOS-----------
*/

MKDISK
    : size SIZE MKDISK  {$$=$2;$$->agregarSiguiente($3);}
    | fit FIT MKDISK    {$$=$2;$$->agregarSiguiente($3);}
    | unit UNIT MKDISK  {$$=$2;$$->agregarSiguiente($3);}
    | path PATH MKDISK  {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;


RMDISK
    : path PATH  {$$=$2;}
    | {$$=new nodoSimple("VACIO","---");}
;

FDISK
    : size SIZE FDISK {$$=$2;$$->agregarSiguiente($3);}
    | unit UNIT FDISK {$$=$2;$$->agregarSiguiente($3);}
    | path PATH FDISK {$$=$2;$$->agregarSiguiente($3);}
    | type TYPE FDISK {$$=$2;$$->agregarSiguiente($3);}
    | fit FIT FDISK   {$$=$2;$$->agregarSiguiente($3);}
    | del DEL FDISK   {$$=$2;$$->agregarSiguiente($3);}
    | name NAME FDISK {$$=$2;$$->agregarSiguiente($3);}
    | add ADD FDISK   {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

MOUNT
    : name NAME MOUNT {$$=$2;$$->agregarSiguiente($3);}
    | path PATH MOUNT {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

UNMOUNT
    : id ID {$$=$2;}
    | {$$=new nodoSimple("VACIO","---");}
;

REP
    : name NAMEREP REP  {$$=$2;$$->agregarSiguiente($3);}
    | path PATH REP     {$$=$2;$$->agregarSiguiente($3);}
    | id ID REP         {$$=$2;$$->agregarSiguiente($3);}
    | rutap RUTA REP     {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

EXEC
    : path PATH {$$=$2;}
    | {$$=new nodoSimple("VACIO","---");}
;

MKFS
    : id ID MKFS          {$$=$2;$$->agregarSiguiente($3);}
    | type TYPEMKFS MKFS {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

LOGIN
    : usr USR LOGIN {$$=$2;$$->agregarSiguiente($3);}
    | pwd PWD LOGIN {$$=$2;$$->agregarSiguiente($3);}
    | id ID LOGIN   {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

LOGOUT
    : {$$=new nodoSimple("VACIO","---");}
;

MKGRP
    : name NAME {$$=$2;}
    | {$$=new nodoSimple("VACIO","---");}
;

RMGRP
    : name NAME {$$=$2;}
    | {$$=new nodoSimple("VACIO","---");}
;

MKUSR
    : usr USR MKUSR {$$=$2;$$->agregarSiguiente($3);}
    | pwd PWD MKUSR {$$=$2;$$->agregarSiguiente($3);}
    | grp GRP MKUSR {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

RMUSR
    : usr USR   {$$=$2;}
    | {$$=new nodoSimple("VACIO","---");}
;

CHMOD
    : path CARPETA CHMOD {$$=$2;$$->agregarSiguiente($3);}
    | ugo UGO CHMOD         {$$=$2;$$->agregarSiguiente($3);}
    | r CHMOD               {$$=new nodoSimple("r","r");$$->agregarSiguiente($2); }
    | {$$=new nodoSimple("VACIO","---");}
;

MKFILE
    : path PATH MKFILE {$$=$2;$$->agregarSiguiente($3);}
    | pp MKFILE        {$$=new nodoSimple("p","p");$$->agregarSiguiente($2); }
    | size SIZE MKFILE {$$=$2;$$->agregarSiguiente($3);}
    | cont CONT MKFILE {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

CAT
    : file FILE {$$=$2;}
    | {$$=new nodoSimple("VACIO","---");}
;

REM
    : path PATHREM  {$$=$2;}
    | {$$=new nodoSimple("VACIO","---");}
;

EDIT
    : path PATH EDIT        {$$=$2;$$->agregarSiguiente($3);}
    | cont CONTEDIT EDIT    {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

REN
    : path PATH REN     {$$=$2;$$->agregarSiguiente($3);}
    | name ARCHIVO REN  {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

MKDIR
    : path CARPETA MKDIR {$$=$2;$$->agregarSiguiente($3);}
    | pp MKDIR              {$$=new nodoSimple("p","p");$$->agregarSiguiente($2); }
    | {$$=new nodoSimple("VACIO","---");}
;

CP
    : path CARPETA CP    {$$=$2;$$->agregarSiguiente($3);}
    | dest DEST CP          {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

MV
    : path CARPETA MV    {$$=$2;$$->agregarSiguiente($3);}
    | dest DEST MV          {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;


FINDP
    : path PATH FINDP    {$$=$2;$$->agregarSiguiente($3);}
    | name ARCHIVO FINDP {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

CHOWNP
    : path CARPETA CHOWNP {$$=$2;$$->agregarSiguiente($3);}
    | r CHOWNP               {$$=new nodoSimple("r","r");$$->agregarSiguiente($2); }
    | usr USR CHOWNP         {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

CHGRP
    : usr USR CHGRP {$$=$2;$$->agregarSiguiente($3);}
    | grp GRP CHGRP {$$=$2;$$->agregarSiguiente($3);}
    | {$$=new nodoSimple("VACIO","---");}
;

PAUSEP
    : {$$=new nodoSimple("VACIO","---");}
;
/*
   ---------INICIO DE PARAMETROS DE COMANDOS-----------
*/

ID
    : igual identificador {$$=new nodoSimple($2,"id"); }
;

TYPE
    : igual p {$$=new nodoSimple("p","type"); }
    | igual e {$$=new nodoSimple("e","type"); }
    | igual l {$$=new nodoSimple("l","type"); }
;

TYPEMKFS
    : igual full {$$=new nodoSimple("full","type"); }
    | igual fast {$$=new nodoSimple("fast","type"); }
;

DEL
    : igual fast {$$=new nodoSimple("fast","del"); }
    | igual full {$$=new nodoSimple("full","del"); }
;

NAME
    : igual identificador {$$=new nodoSimple($2,"name"); }
    | igual cadena        {$$=new nodoSimple($2,"name"); }
;


NAMEREP
    : igual mbr         {$$=new nodoSimple("mbr","name"); }
    | igual disk        {$$=new nodoSimple("disk","name"); }
    | igual inode       {$$=new nodoSimple("inode","name"); }
    | igual journaling  {$$=new nodoSimple("journaling","name"); }
    | igual block       {$$=new nodoSimple("block","name"); }
    | igual bm_inode    {$$=new nodoSimple("bm_inode","name"); }
    | igual bm_block    {$$=new nodoSimple("bm_block","name"); }
    | igual tree        {$$=new nodoSimple("tree","name"); }
    | igual sb          {$$=new nodoSimple("sb","name"); }
    | igual file        {$$=new nodoSimple("file","name"); }
    | igual ls          {$$=new nodoSimple("ls","name"); }
;

ADD
    : igual entero {$$=new nodoSimple($2,"add"); }
;


SIZE
    : igual entero {$$=new nodoSimple($2,"size"); }
;

FIT
    : igual bf {$$=new nodoSimple("bf","fit"); }
    | igual ff {$$=new nodoSimple("ff","fit"); }
    | igual wf {$$=new nodoSimple("wf","fit"); }
;

UNIT
    : igual k {$$=new nodoSimple("k","unit"); }
    | igual m {$$=new nodoSimple("m","unit"); }
    | igual b {$$=new nodoSimple("b","unit"); }
;

PATH
    : igual cadena {$$=new nodoSimple($2,"path"); }
    | igual ruta   {$$=new nodoSimple($2,"path"); }
;

PWD
    : igual cadena          {$$=new nodoSimple($2,"pwd"); }
    | igual identificador   {$$=new nodoSimple($2,"pwd"); }
    | igual entero          {$$=new nodoSimple($2,"pwd"); }
;

USR
    : igual cadena          {$$=new nodoSimple($2,"usr"); }
    | igual identificador   {$$=new nodoSimple($2,"usr"); }
    | igual entero          {$$=new nodoSimple($2,"usr"); }
;

GRP
    : igual cadena          {$$=new nodoSimple($2,"grp"); }
    | igual identificador   {$$=new nodoSimple($2,"grp"); }
;

UGO
    : igual entero  {$$=new nodoSimple($2,"ugo"); }
;

CARPETA
    : igual carpeta  {$$=new nodoSimple($2,"path"); }
    | igual cadena      {$$=new nodoSimple($2,"path"); }
;

RUTA
    : igual carpeta  {$$=new nodoSimple($2,"ruta"); }
    | igual cadena   {$$=new nodoSimple($2,"ruta"); }
    | igual ruta     {$$=new nodoSimple($2,"ruta"); }
;


DEST
    : igual carpeta   {$$=new nodoSimple($2,"dest"); }
    | igual cadena       {$$=new nodoSimple($2,"dest"); }
;

CONT
    : igual cadena  {$$=new nodoSimple($2,"cont"); }
    | igual ruta    {$$=new nodoSimple($2,"cont"); }
;

PATHREM
    : igual cadena      {$$=new nodoSimple($2,"path"); }
    | igual ruta        {$$=new nodoSimple($2,"path"); }
    | igual carpeta  {$$=new nodoSimple($2,"path"); }
;

CONTEDIT
    : igual cadena          {$$=new nodoSimple($2,"cont"); }
    | igual identificador   {$$=new nodoSimple($2,"cont"); }
;

ARCHIVO
    : igual cadena      {$$=new nodoSimple($2,"name"); }
    | igual archivo     {$$=new nodoSimple($2,"name"); }
;

FILE
    : igual cadena  {$$=new nodoSimple($2,"file"); }
    | igual ruta    {$$=new nodoSimple($2,"file"); }
;




