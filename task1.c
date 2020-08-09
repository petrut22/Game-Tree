#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task1.h"

            int n, m;
            char prime;
            arbore *tree;

void init(arbore **tree, int *n, int *m, char *prime,  char *nume)
{
    int i,j;
    FILE *fis;
    char c;
    fis = fopen(nume , "r");
    fscanf(fis, "%d %d %c", n, m, prime);
    (* tree) = malloc(sizeof(arbore));
    (* tree)->children = NULL;
    (* tree)->table = (char **)malloc(sizeof(char*) * (*n));

    for(i = 0; i < (*n); i++)
        (* tree)->table[i] = (char *)malloc(sizeof(char) * (*m));

    fgetc(fis);
    for(i = 0; i < (*n); i++)
        for(j = 0; j < (*m); j++){
            fscanf(fis,"%c", &c);
            fgetc(fis);
            (* tree)->table[i][j] = c;
        }
    fclose(fis);
     
}

void afis(char **matrix, int n, int m, int nivel, char *nume)
{
    int i, j, k;
    FILE *g;
    g = fopen(nume,"a");
    for(i = 0; i < n; i++){
        for(k = 1; k <= nivel; k++)
                fprintf(g, "\t");
        for(j = 0; j < m; j++)
            if(j != m-1)
                fprintf(g, "%c ", matrix[i][j]);
            else fprintf(g, "%c", matrix[i][j]);
        fprintf(g, "\n");
    }
    fprintf(g, "\n");
    fclose(g);
}

void afis_nivel(arbore *tree, int n, int m, int nivel, char *nume)
{
    copaci *arbori_parce;
    int i;
    afis(tree->table, n, m, nivel, nume);

    arbori_parce = tree->children;
    while(arbori_parce != NULL){
        afis_nivel(arbori_parce->arborel, n, m, nivel+1, nume);
        arbori_parce = arbori_parce->next;


    }
}
int victory(char **matrix, int n, int m)
{

    int i, j, ok = 0, k;


    for( i = 0; i < n ; i++)
        for( j = 0; j < m; j++)
          if(j+3 < m){
                    ok = 1;
                    if(matrix[i][j] == '-') ok = 0;
                    for(k = 1; k <= 3 && ok == 1; k++)
                        if(matrix[i][j+k] != matrix[i][j+k-1])  ok = 0;
                    if(ok == 1) return 1;    
                }
             

    for( j = 0; j < m ; j++)
        for( i = 0; i < n; i++)
            if(i+3 < n){
                    ok = 1;
                    if(matrix[i][j] == '-') ok = 0;
                    for(k = 1; k <= 3 && ok == 1; k++)
                        if(matrix[i+k][j] != matrix[i+k-1][j])  ok = 0;
                    if(ok == 1) return 1;    
                }

    if(n>=4 && m>=4){

        for( i = 0; i < n ; i++){
            for( j = 0; j < m ; j++){
                if(i+3 < n && j+3 < m){
                    ok = 1;
                    if(matrix[i][j] == '-') ok = 0;
                    for(k = 1; k <= 3 && ok == 1; k++)
                        if(matrix[i+k][j+k] != matrix[i+k-1][j+k-1])  ok = 0;
                    if(ok == 1) return 1;    
                }
            }         
        }

        for( i = 0; i < n ; i++){
            for( j = m-1; j >= 0 ; j--){
                if(i+3 < n && j-3 < m && j-3 >= 0){
                    ok = 1;
                    if(matrix[i][j] == '-') ok = 0;
                    for(k = 1; k <= 3 && ok == 1; k++)
                        if(matrix[i+k][j-k] != matrix[i+k-1][j-k+1])  ok = 0;
                    if(ok == 1) return 1;    
                }
            }         
        }
    }

    return 0;
}
void construct_arbore(arbore **tree, int n, int m, char prime, int indl, int indc )
{
    int i, j;
    copaci *arbori_parce;
    copaci *arbori_copil = malloc(sizeof(copaci));
    arbori_copil->arborel = malloc(sizeof(arbore));
    arbori_copil->arborel->children = NULL;
    arbori_copil->arborel->table = (char **)malloc(sizeof(char*) * n);

    for(i = 0; i < n; i++)
        arbori_copil->arborel->table[i] = (char *)malloc(sizeof(char) * m);
    arbori_copil->next =NULL;
    arbori_copil->prev =NULL;

    for(i =0; i < n; i++)
        for(j = 0; j < m; j++)
            if(i == indl && j == indc)  arbori_copil->arborel->table[i][j] = prime;
            else arbori_copil->arborel->table[i][j] = ( *tree)->table[i][j];


    if(( *tree)->children == NULL){
         ( *tree)->children = arbori_copil;  
         return; 

    }

    arbori_parce = ( *tree)->children;
    while(arbori_parce->next !=NULL)
        arbori_parce = arbori_parce->next;

    arbori_parce->next = arbori_copil;
    arbori_copil->prev = arbori_parce;

}

void construct(arbore **tree,int n, int m, char prime)
{
    int i, j;
    copaci *arbore_parce;
    for(j = 0; j < m; j++)
        for(i = n-1; i>=0; i--)
            if(( *tree)->table[i][j] == '-'){
                construct_arbore(tree, n, m, prime, i, j);
                i = -1;
            }

    
     arbore_parce = ( *tree)->children;
     while(arbore_parce != NULL){
                    if(!victory(arbore_parce->arborel->table, n ,m)){

                        if(prime != 'X' && prime != 'O'){
                        if (prime == 'R' ) construct(&arbore_parce->arborel, n, m, 'B');
                        else  construct(&arbore_parce->arborel, n, m, 'R');
                        }

                        if(prime != 'R' && prime != 'B'){
                        if (prime == 'X' ) construct(&arbore_parce->arborel, n, m, 'O');
                        else construct(&arbore_parce->arborel, n, m, 'X');
                        }
                    }
                    arbore_parce = arbore_parce->next;
                }
}

void parcurgere(arbore *tree, int n, int m)
{
copaci *arbori_parce = tree->children;
while(arbori_parce !=NULL){
        //afis(arbori_parce->arborel->table, n, m, 0);
        arbori_parce = arbori_parce->next;
        }
}


void eliberaretree(arbore **tree, int n,int m)
{
    copaci *arbori_parce = (*tree)->children;
    copaci *arbor_elib;
    int i;

    for(i = 0; i < n; i++)
        free(( *tree)->table[i]);
    free(( *tree)->table);

    while(arbori_parce !=NULL){
        arbor_elib = arbori_parce;
        eliberaretree(&arbori_parce->arborel, n, m);
        arbori_parce = arbori_parce->next;
        free(arbor_elib);
    }
    free(( *tree));

}
