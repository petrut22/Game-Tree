# Game-Tree
The project has implemented some game strategies: Minimax, Alpha - Beta Pruning, Paranoic


  Tema a fost efectuata intr-o saptamana si a fost modularizata in programe, iar 
fiecare task se afla intr-un fisier separat. Compilarea programului se face cu ajutorul 
acestor fisiere impreuna cu "minimax.c". In fisiere cu extensia .h se afla definitiile 
structurile impreuna cu  apelurile functiilor necesare fiecarui task

  Taskul 1 abordeaza cerinta de la Connect-4 si a contine 8 functii. Implementarea         
problemei s-a realizatat cu ajutorul unor doua structuri de date "copaci" si 
"arbore", prima retine o matrice, iar celelalte legaturi  vor ajuta la generarea
 altor matrici care deriva de la o aceea matrice. Functia init are rolul de a crea
tabla cu R si B cu ajutorul unei matrici care a fost mai intai alocata dinamic, 
urmand sa fie completata cu caracterele necesare din fisier. Partea in care urmeaza 
generarea tutoror combinatiilor de la matrice se face prin functia recursiva construct.
 Aceasta mai intai cauta in matrice prima valoare de '-', apoi urmeaza sa fie apelata 
functia "construct_arbore" care creeaza prima matrice cu o posbila mutare si care 
reprezinta fiul matricei din care se face cautarea. Partea recursiva se refera la 
verificarea conditiei de victorie a jucatorului (aceasta functie practic opreste 
expandarea posibilitatilor de parcurgere a matricei), iar daca aceasta nu este verificata 
se apeleaza functia pentru urmatorul oponent. Functia "victory" se refera la parcurgerea 
matricei pe linii si coloane, pentru a verifica conditia ca 4 elemente consecutive sa
fie egale. In cazul in care dimensiunile matricei depasesc valoarea 4 atunci se incearca verificarea 
pe diagonala in 2 moduri ca la cazurile precedente. Afisarea posibilelor 
miscari pe tabla se face cu ajutorul functiei recursive "afis_nivel" care primeste
ca parametrii arborele prin care se retin toate matricile, dimensiunile matricei, 
nivelul in arbore si un sir de caractere care se refera la fisierul de iesire. 
Functia apeleaza mai intai un subprogram care are rolul de a afisa matricea
corespunzatoare unei miscari "afis".Daca arborele are in continuare descendenti atunci subprogramul va apeleza nodul fiu 
pana cand se incheie ciclul.
 La final se face eliberarea memoriei utilizate cu ajutorul unei alte functii recursive "eliberaretree".

 Taskul 2 se refera la implementarea strategiei minimax. Rezolvarea taskului incepe 
cu crearea unui arbore cu valorile din fisierul de intrare (functia "construire2"). 
Aceasta functie are ca parametrii de intrare arborele care va contine nodurile "tree", 
"nr" care se refera nr de nivele si "nume" care reprezinta numele fisierului de intrare. 
Citirea fisierului se face caracter cu caracter, iar finalizarea functiei este data de 
conditia ca nr de nivele curent sa fie egal cu nr de nivele total. Trecerea de la 
un nivel la altul o reprezenta citirea pana la caracterul '\n'. Nodurile adaugate in 
arbore sunt construite cu ajutorul functiei "construct_arbore2". In realizarea 
programului am folosit o structura care retine valoarea nodului, nr de fii pe care mai 
trebuie sa ii adauge, nivelul nodului, nodul parinte, nodul copil, si o referinta catre un 
frate de-al sau. Arborele se initilizeza cu "initTree2" care are ca parametrii arborele si valoarea lui. 
Construirea intregului arbore s-a realizat iterativ (prima abordare am facut-o recursiv, insa mi-a dat timeout), 
astfel se adauga toate nodurile unui nod parinte, 
iar dupa ce nu se mai pot adauga se verifica fratii nodului curent. In cazul in 
care acestia nu exista sau sunt si ei completati, se parcurge arborele in sens invers
 si se verifica primul frate cu descendentii lui al unui nod de referinta. Implementarea "propri_zisa" 
 a strategiei o constituie functia recursiva "minmax2" care parcurge 
intreg arbore pana la frunze. Pentru un nod care are numai descendenti de tip frunza 
i se calculeaza valoarea in functie de nivel si anume daca nivelul este un nr 
impar atunci se calculeaza minimul dintre copii lui, in caz constrar se calculeaza 
maximul. Aceasta implementare efectueaza toate calculele necesare pentru obtinerea 
noului arbore. In finalul programului se afiseaza arborele in mod recursiv prin 
spatierea necesara, urmand apoi eliberarea intregii memorii.

 Taskul 3 consta in implementarea strategiei "alpha-beta prunning" care are aproape
aceleasii functii ca si taskul anterior, diferenta dintre cele doua consta in 
alcatuirea structuri care retine doi parametrii alpha si beta, dar si o noua functie
numita "alphabeta" care are rolul de a implementa strategia. In cadrul acestui
program functia aceasta este una recursiva care calculeaza valoarea alpha pentru 
un nod oarecare daca acesta se afla pe un nivel impar, in caz contrar se calculeaza beta.
 Fiecare descendent direct va mosteni de la nodul parinte valorile alpha si beta,
urmand sa fie calculata o valoare dintre cele doua in functie de nivel cu ajutorul
frunzelor sau a nodurilor( prin valorile alpha si beta). In cazul in care alpha 
este mai mare decat beta se renunta la parcurgerea "copiilor" si sunt eliminati 
din arbore. In final noul arbore se va obtine prin aplicarea functiei "minmax3", iar 
apoi se afiseaza acesta si se elibereaza memoria.

