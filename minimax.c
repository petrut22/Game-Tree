#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

int main(int argc, char **argv)
{



    if(strcmp("-c1",argv[1])==0){

        int n, m;
        char prime;
        arbore *tree1;
        init(&tree1, &n, &m, &prime,  argv[2]);
        construct(&tree1, n, m, prime);
        afis_nivel(tree1, n, m, 0, argv[3]);
        eliberaretree(&tree1, n, m);
    }
    

    if(strcmp("-c2",argv[1])==0){
        int nr = 0;
        arbore2 *tree2;
        construire2(&tree2, &nr, argv[2]);
        minmax2(&tree2);
        afis_nivel2(tree2, 0, argv[3]);
        eliberaretree2(&tree2);
        free(tree2);
    }

    if(strcmp("-c3",argv[1])==0){
        int nr = 0;
        arbore3 *tree3;
        construire3(&tree3, &nr, argv[2]);
        alphabeta3(&tree3);
        minmax3(&tree3);
        afis_nivel3(tree3, 0, argv[3]);
        eliberaretree3(&tree3);
        free(tree3);
    }
    

    
    return 0;
}