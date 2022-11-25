#ifndef POHON_H
#define POHON_H

#include "boolean.h"
#define methodUdf -999

/* Selektor */
#define Root(p) (p)->Root
#define addressChild(p) (p)->Child
#define getChild(p,i) (p)->Child[i]
#define nChild(p) (p)->nChild
#define Method(p) (p)->Method

typedef int ElType;
typedef struct tNode* Address;
typedef struct tNode { 
     ElType Root; 
     Address *Child; 
     int nChild; 
     int Method; 
} Node;

/* Definisi Pohon */
/* pohon kosong p = NULL */

typedef Address Tree;

Tree newTree(ElType root, Tree child[], int leaves); 

void CreateTree (ElType root, Tree child[], int leaves, Tree *p);

Address newTreeNode(ElType val);

void deallocTreeNode (Address p);

boolean isTreeEmpty (Tree p);

boolean isOneElmt (Tree p);


/* ****** Display Tree ***** */
void printPreorder(Tree p);

void printTree(Tree p, int h);


/* *** Searching *** */
boolean searchTree(Tree p, ElType X);

Address SearchNode(Tree p, ElType X);


/* *** Fungsi-Fungsi Lain *** */
int NbElmt(Tree p);

int NbDaun(Tree p);

int Level(Tree p, ElType X);

int Depth(Tree p);


// /* *** Operasi lain *** */
void addLeaves(Tree *p, Tree child[], int leaves);


