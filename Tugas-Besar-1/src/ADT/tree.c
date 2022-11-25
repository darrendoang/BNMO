
#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

Tree newTree(ElType Root,Tree child[], int leaves){

   Address p = newTreeNode(Root);
    if (p != NULL) {
        addressChild(p) = (Tree*) malloc(leaves * sizeof(Tree));

        if(addressChild(p) != NULL){
            for(int i = 0; i<leaves;i++){
            getChild(p,i) = child[i];
            nChild(p) = leaves;
        }  
        
        }
        else{//Gagal alokasi
            nChild(p) = 0;
        }
        
    }
    return p; 
}

void CreateTree (ElType Root, Tree child[], int leaves, Tree *p){
    *p = newTree(Root,child,leaves);
}

Address newTreeNode(ElType val) {
    Address p = (Address)(malloc(sizeof(Tree)));
    if (p != NULL) {
        Root(p) = val;
        addressChild(p) = NULL;
        nChild(p) = 0;
        Method(p) = methodUdf;
    }
    return p;
}

void deallocTreeNode (Address p){
   free(p);
}


boolean isTreeEmpty (Tree p){
    return p == NULL;
}

boolean isOneElmt (Tree p){
    return (!isTreeEmpty(p)) && (nChild(p) == 0);
}

/* ****** Display Tree ***** */
void printPreorder(Tree p){
    printf("(");
    if (p != NULL) {
        printf("%d", Root(p));
        if(!isOneElmt(p)){
        for(int i = 0; i < nChild(p); i++)printPreorder(getChild(p,i));
        }
        else printf("()");
    }
    printf(")");
}

void printtree(Tree p, int h, int depth){
    if (!isTreeEmpty(p)){
        printf("%*s%d\n", depth*h, "", Root(p));
        for(int i = 0; i < nChild(p); i++){
            printtree(getChild(p,i),h,depth+1);
        }
    }
}
void printTree(Tree p, int h){
    printtree(p,h,0);
}

/* *** Searching *** */
boolean searchTree(Tree p, ElType X){
    boolean state = false;
    if(isTreeEmpty(p)){
        return false;
    }
    else if(isOneElmt(p)){
        return (Root(p)==X);
    }
    else{
        for(int k = 0; k < nChild(p);k++){
                state |= (Root(p)==X) || (searchTree(getChild(p,k),X));
        }
        return state;
    }
}

Address searchNodeTrue(Tree p, ElType X){ //Terdapat address dengan elemen yang dimaksud
    if(Root(p) == X) return p;
    else if(!isOneElmt(p)){
        for(int i = 0; i < nChild(p); i++){
            searchNodeTrue(getChild(p,i),X);
        }
    }
}

Address SearchNode(Tree p, ElType X){
    if(searchTree(p,X)){
        searchNodeTrue(p,X);
    }
    else return NULL;
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(Tree p){
    //BASIS
    
    if(isTreeEmpty(p)){
        return 0;
    }
    else if(isOneElmt(p)){
        return 1;
    }
    //REKURENS
    else{
       int counter = 1;
       for(int k = 0; k < nChild(p); k++){
            counter += NbElmt(getChild(p,k)); 
        }
        return counter;
    }
}

int NbDaun(Tree p){
    int counter = 0;
    if(isTreeEmpty(p)){
        return 0;
    }
    else if(isOneElmt(p)){
        return 1;
    }
    //REKURENS
    else{
       for(int k = 0; k < nChild(p); k++){
            counter += NbDaun(getChild(p,k)); 
        }
        return counter;
    }
}

void level(Tree p, ElType x, int depth, int *q){
    if (!isTreeEmpty(p)){
        
        printf("Root sekarang: %d, dengan depth: %d\n",Root(p),depth);
        if(x == Root(p)) *q = depth;
        if(!isOneElmt(p)){
            for(int i = 0; i < nChild(p); i++){
            level(getChild(p,i),x,depth+1,q);
        }
        }

    }
}

int Level(Tree p, ElType X){
    if (searchTree(p,X)){
        int z;
        level(p,X,1,&z);
        return z;
    }
    else return -1;
}

void depthh(Tree p, int depth, int *buffer){
    
    if(*buffer < depth) *buffer = depth;   
    for(int i = 0; i < nChild(p); i++){
        depthh(getChild(p,i),depth+1,buffer);
    } 
    
}
int Depth(Tree p){
   if(isTreeEmpty(p))
        return 0;
    else{
        int depth = 1;
        depthh(p,1,&depth);
        return depth;
    }
   
}

// /* *** Operasi lain *** */
void addLeaves(Tree *p, Tree child[], int leaves){
    addressChild(*p) = (Tree*) malloc(leaves * sizeof(Tree));
    if(addressChild(*p) != NULL){
        for(int i = 0; i<leaves;i++){
            getChild(*p,i) = child[i];
        } 
        nChild(*p) = leaves;
    }
    
}