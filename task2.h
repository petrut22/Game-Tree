#ifndef __FILE_H2__
#define __FILE_H2__

typedef struct arbore2{
    int n;
    int lastc;
    int nivel;
    struct arbore2 *children;
    struct arbore2 *parent;
    struct arbore2 *next;

} arbore2;


void construct_arbore2(arbore2 **tree, int nivelp, int y, int type);

void initTree2 (arbore2 ** tree, int x );

void construire2(arbore2 **tree, int *nr,  char *nume);

void minmax2(arbore2 **tree);

void afis_nivel2(arbore2 *tree,int nivel, char *nume);

void eliberaretree2(arbore2 **tree);


#endif /* __FILE_H2__ */