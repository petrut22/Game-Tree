#ifndef __FILE_H__
#define __FILE_H__

typedef struct copaci{
    struct arbore *arborel;
    struct copaci *next;
    struct copaci *prev;
} copaci;

typedef struct arbore{
    char **table;
    copaci *children;

} arbore;


void init(arbore **tree, int *n, int *m, char *prime,  char *nume);

void afis(char **matrix, int n, int m, int nivel, char *nume);

void afis_nivel(arbore *tree, int n, int m, int nivel, char *nume);

int victory(char **matrix, int n, int m);

void construct_arbore(arbore **tree, int n, int m, char prime, int indl, int indc );

void construct(arbore **tree,int n, int m, char prime);

void parcurgere(arbore *tree, int n, int m);

void eliberaretree(arbore **tree, int n,int m);

#endif /* __FILE_H__ */