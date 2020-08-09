#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"
#define MAX 800000000
#define MIN -80000000


void construct_arbore2(arbore2 **tree, int nivelp, int y, int type)
{
    arbore2 *arbori_parce;
    arbore2 *arbori_copil = malloc(sizeof(arbore2));
    arbori_copil->children = NULL;
    arbori_copil->parent = ( *tree);
    arbori_copil->nivel = nivelp;
    arbori_copil->next =NULL;
    arbori_copil->n = y;
    arbori_copil->nivel = nivelp;

    if(type == 1) arbori_copil->lastc = y;
    else arbori_copil->lastc = 0;

    if(( *tree)->children == NULL){
         ( *tree)->children = arbori_copil;  
         return; 

    }
    arbori_parce = ( *tree)->children;
    while(arbori_parce->next !=NULL){

        arbori_parce = arbori_parce->next;
    }

    arbori_parce->next = arbori_copil;

}

void initTree2 (arbore2 ** tree, int x )
{
    (*tree) = malloc(sizeof(arbore2));
    (*tree)->n =x;
    (*tree)->nivel = 1;
    (*tree)->lastc = x;
    (*tree)->next= NULL; 
    (*tree)->children= NULL; 
    (*tree)->parent= NULL; 
}


void construire2(arbore2 **tree, int *nr,  char *nume)
{
    arbore2 *arborel;
    int x=0, nivelp=0 ,y=0, ok=0, type=0;
    char c = 'P';
    FILE *fis;
    fis = fopen(nume , "r");
    fscanf(fis, "%d", nr);
    fgetc(fis);
    while(*nr != nivelp){
       nivelp++;
        c='P';    
        ok = 0;
        y = 0; 
        if(nivelp == 1){
                   while(c != '\n'){
                        c = fgetc(fis);
                         if(c == '(' || c =='['){
                            while(c != ']' && c!=')'){
                                    c = fgetc(fis);
                                    if(c >= '0' && c <='9'){
                                    x = c - '0';
                                    y = y*10 + x;

                                    }
                            }
                        } 
            
                    }
                    fgetc(fis);
                    initTree2(tree, y);
              
        }
        else{
            c='P';
            arborel = ( *tree);
            while(c != '\n'){
                
                if(nivelp-1 == arborel->nivel){
                 
                    while(arborel->lastc != 0){
                        y = 0;
                        ok = 0;
                        while(c != ']' && c!=')'){
                                    c = fgetc(fis);
                                    if (c == '-') ok =1;
                                    if(c >= '0' && c <='9'){
                                       
                                        x = c - '0';
                                        y = y*10 + x;
                                    }
                                    if(c == ')') type = 1;
                                    else type = 0;
                        }
                        if( ok == 1) y = -y;
                 
                        c = fgetc(fis);
                        construct_arbore2(&arborel, nivelp, y, type);
                        arborel->lastc = arborel->lastc-1;
                    }

                    }else if(arborel->children != NULL ) arborel = arborel->children;
                  
              
                if(c != '\n' && (nivelp-1 == arborel->nivel || arborel->children == NULL) && arborel->lastc == 0){
                    while(arborel->next == NULL && arborel != (*tree))
                        arborel = arborel->parent;
                    if(arborel != (*tree)) arborel = arborel->next;
                }
     
                
            }
 

        }

    }  
    fclose(fis);
     
}


void minmax2(arbore2 **tree)
{
    int i, maxi = MAX, mini = MIN;
    arbore2 *arbore_parce;
    arbore_parce = ( *tree)->children;

    
     while(arbore_parce != NULL){
                    minmax2(&(arbore_parce));
                     if( (*tree)->nivel % 2 == 1){
                        if( mini < arbore_parce->n) 
                                mini = arbore_parce->n;
                    }
                    if( (*tree)->nivel % 2 == 0){
                        if( maxi > arbore_parce->n) 
                                maxi = arbore_parce->n;
                    }
                    arbore_parce = arbore_parce->next;
                }

    if(( *tree)->children == NULL) return;

        if( (*tree)->nivel % 2 == 1) (*tree)->n = mini;
        else (*tree)->n = maxi;

        
}

void afis_nivel2(arbore2 *tree,int nivel, char *nume)
{
    arbore2 *arbori_parce;
    int k;
    FILE *g;
    g = fopen(nume,"a");
     for(k = 1; k <= nivel; k++)
                fprintf(g, "\t");
    fprintf(g, "%d\n",tree->n);
     fclose(g);

    if (tree->children == NULL) return;
    arbori_parce = tree->children;
    while(arbori_parce != NULL){
        afis_nivel2(arbori_parce, nivel+1, nume);
        arbori_parce = arbori_parce->next;


    }
}


void eliberaretree2(arbore2 **tree)
{
    arbore2 *arbore_parce, *arbore_child;
    arbore_parce = ( *tree)->children;

        while(arbore_parce != NULL){
                   arbore_child = arbore_parce;
                   eliberaretree2(&arbore_parce);
                   arbore_parce = arbore_parce->next;
                   free(arbore_child);
                }

    

}

