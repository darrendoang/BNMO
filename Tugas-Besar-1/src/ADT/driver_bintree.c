#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    //menghasilkan pohon biner

    Address l1 = newTreeNode(3);
    Address l2 = newTreeNode(4);
    BinTree left = NewTree(2, l1, l2);
    
    Address r1 = newTreeNode(6);
    Address r2 = newTreeNode(8);
    BinTree right = NewTree(5, r1, NULL);

    //menghasilkan pohon p
    BinTree p;
    CreateTree(5,left,right,&p);
    printf("Pohon telah terbentuk\n");
    printTree(p, 2);

    //Mengecek pohon
    if(isTreeEmpty(p)){
        printf("pohon kosong.\n");
    }
    else if (isOneElmt(p)){
        printf("Pohon terdiri dari satu elemen.\n");
    }
    else if(isUnerLeft(p)){
        printf("Pohon hanya mempunyai subpohon kiri.\n");
    }
    else if(isUnerRight(p)){
        printf("Pohon hanya mempunyai subpohon kanan.\n");
    }
    else if(isBinary(p)){
        printf("Pohon biner.\n");
    }

    //print preorder
    printPreorder(p);
    printf("\n");

    //print inorder
    printInorder(p);
    printf("\n");


    //print postorder
    printPostorder(p);
    printf("\n");


}
