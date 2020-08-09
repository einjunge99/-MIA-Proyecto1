/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    mkdisk = 258,
    rmdisk = 259,
    fdisk = 260,
    mount = 261,
    unmount = 262,
    rep = 263,
    exec = 264,
    size = 265,
    unit = 266,
    path = 267,
    fit = 268,
    name = 269,
    type = 270,
    del = 271,
    add = 272,
    id = 273,
    bf = 274,
    ff = 275,
    wf = 276,
    k = 277,
    m = 278,
    b = 279,
    p = 280,
    e = 281,
    l = 282,
    fast = 283,
    full = 284,
    mbr = 285,
    disk = 286,
    igual = 287,
    entero = 288,
    cadena = 289,
    identificador = 290,
    ruta = 291,
    mkfs = 292,
    login = 293,
    logout = 294,
    mkgrp = 295,
    rmgrp = 296,
    mkusr = 297,
    rmusr = 298,
    chmod = 299,
    mkfile = 300,
    cat = 301,
    rem = 302,
    edit = 303,
    ren = 304,
    mkdir = 305,
    cp = 306,
    mv = 307,
    findp = 308,
    chownp = 309,
    chgrp = 310,
    pausep = 311,
    carpeta = 312,
    archivo = 313,
    usr = 314,
    pwd = 315,
    grp = 316,
    ugo = 317,
    r = 318,
    pp = 319,
    cont = 320,
    dest = 321,
    rutap = 322,
    inode = 323,
    block = 324,
    bm_inode = 325,
    bm_block = 326,
    tree = 327,
    sb = 328,
    file = 329,
    ls = 330,
    journaling = 331
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

    char text[200];
    class nodoSimple *nodo;

#line 139 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
