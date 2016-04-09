#ifndef PILE
#define PILE

typedef struct element element;
typedef struct pile pile;

struct element{
	
int el;        // élément courant 
element* next; // pointeur sur l'élément suivant
  
};

struct pile{
	
element* init;  // pointeur sur le premier élément

};

// méthodes de gestion de la pile

pile* init(int x);  // initialisation de la  pile

void push(pile* p,int x); // insertion d'un élément dans la pile

void pop(pile* p); // supprime le premier élément de la pile

void delete(pile * p);  // supression de tous les éléments de la pile + destruction pile

void print(const pile* p);  // affichage de la pile



#endif
