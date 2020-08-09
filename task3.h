#ifndef __FILE_H3__
#define __FILE_H3__

typedef struct arbore3{
    int n;
    int lastc;
    int nivel;
    int alpha;
    int beta;
    struct arbore3 *children;
    struct arbore3 *parent;
    struct arbore3 *next;

} arbore3;


void construct_arbore3(arbore3 **tree, int nivelp, int y, int type);

void initTree3 (arbore3 ** tree, int x );

void construire3(arbore3 **tree, int *nr,  char *nume);

void eliberaretree3(arbore3 **tree);

void alphabeta3(arbore3 **tree);

void minmax3(arbore3 **tree);

void afis_nivel3(arbore3 *tree,int nivel, char *nume);


#endif /* __FILE_H3__ */