%{
    #include <iostream>
    #include "parser.h"
    #include "nodo.h"
    #include <algorithm>
    nodoSimple *raiz=new nodoSimple("INICIO","---");
%}

%option case-insensitive
%option noyywrap


identificador [a-zA-Z0-9_]+
/*
ruta	      ("/"{identificador})+("/"{identificador}"."{identificador})
*/
entero        ("-")?[0-9]+
carpeta       ("/")|((("/")({identificador}))+)
archivo       ({identificador}"."{identificador})
ruta          (({carpeta})("/")({archivo}))|(({carpeta})({archivo}))
%%


"#".*							// comentario de linea

"mkdisk"    { return mkdisk; }
"rmdisk"    { return rmdisk; }
"fdisk"     { return fdisk; }
"mount"     { return mount; }
"unmount"   { return unmount; }
"rep"       { return rep; }
"exec"      { return exec; }

"mkfs"      { return mkfs; }
"login"     { return login; }
"logout"    { return logout; }
"mkgrp"     { return mkgrp; }
"rmgrp"     { return rmgrp; }
"mkusr"     { return mkusr; }
"rmusr"     { return rmusr; }
"chmod"     { return chmod; }
"mkfile"    { return mkfile; }
"cat"       { return cat; }
"rem"       { return rem; }
"edit"      { return edit; }
"ren"       { return ren; }
"mkdir"     { return mkdir; }
"cp"        { return cp;}
"mv"        { return mv; }
"find"      { return findp; }
"chown"     { return chownp; }
"chgrp"     { return chgrp; }
"pause"     { return pausep; }


"-size"     { return size; }
"-unit"     { return unit; }
"-path"     { return path; }
"-fit"      { return fit; }
"-name"     { return name; }
"-type"     { return type; }
"-delete"   { return del; }
"-add"      { return add; }
"-id"       { return id; }
"-usr"      { return usr; }
"-pwd"      { return pwd; }
"-grp"      { return grp; }
"-ugo"      { return ugo; }
"-r"        { return r; }
"-p"        { return pp; }
"-cont"     { return cont; }
"-file"     { return file; }
"-dest"     { return dest; }
"-ruta"     { return rutap; }

{entero}    {strcpy(yylval.text, yytext); return entero;}

"bf"        { return bf; }
"ff"        { return ff; }
"wf"        { return wf; }
"k"         { return k; }
"m"         { return m; }
"b"         { return b; }
"p"         { return p; }
"e"         { return e; }
"l"         { return l; }
"fast"      { return fast; }
"full"      { return full; }
"mbr"       { return mbr; }
"disk"      { return disk; }
"inode"     { return inode; }
"block"     { return block; }
"bm_inode"  { return bm_inode; }
"bm_block"  { return bm_block; }
"tree"      { return tree; }
"sb"        { return sb; }
"file"      { return file; }
"ls"        { return ls; }
"="         { return igual; }
"journaling"    { return journaling; }




"\""[^"\""]*"\""         {

                          int j, n = strlen(yytext);
                             for (int i=j=0; i<n; i++)
                                if (yytext[i] != 34)
                                   yytext[j++] = yytext[i];

                          yytext[j] = '\0';

                          strcpy(yylval.text, yytext); return cadena;}
{identificador}    	     {strcpy(yylval.text, yytext); return identificador;}
{ruta}    	     	     {strcpy(yylval.text, yytext); return ruta;}
{archivo}    	     	 {strcpy(yylval.text, yytext); return archivo;}
{carpeta}                {strcpy(yylval.text, yytext); return carpeta;}


[ \n\t\r]+               {}


.                        {std::cout<<"Error lexico: " <<yytext<< std::endl;}


%%

