#include "pile.h"
#include <stdio.h>
#include <stdlib.h>

// fonctions de gestion de la pile

// initialisation de la pile
// paramètre x : valeur du premier élément de la pile

pile* init(int x){

pile* p=malloc(sizeof(pile));  // allocation mémoire de la pile
element* elem=malloc(sizeof(element)); // allocation mémoire d'un élément
 
if( p == NULL || elem == NULL)
{
	printf("Erreur allocation mémoire pile ou élément \n");
	exit(1);
}

elem->el=x;  // l'élément courant vaut x
elem->next=NULL;  // on pointe sur rien (suivant) car premier élément de la pile
p->init=elem;

return p;	
	
}

// insertion d'un élément dans la pile
// paramètres : p pointeur sur pile, x valeur du nouveau élément

void push(pile* p,int x){
	
if( p == NULL)
{
	printf("Erreur pointeur sur la pile \n");
	exit(1);
}

// allocation d'un nouvel élément en mémoire

element* elem=malloc(sizeof(element));

if(elem == NULL)
{
	printf("Erreur allocation nouvel élément\n");
	exit(1);
}

elem->el=x;   // le nouvel élément vaut x;
elem->next=p->init; // l'élément suivant p>init
p->init=elem;
	
}

// supression du premier élément de la pile
// paramètre : p pointeur sur pile

void pop(pile* p){
	
if( p == NULL)
{
	printf("Erreur pointeur sur pile \n");
	exit(1);	
}

element* new_init=p->init->next;  // on pointe sur le deuxième élément
free(p->init);  // on désalloue la mémoire pointée sur le premier élément

p->init=new_init;  // le nouveau premier élément

}

// supression de tous les éléments de la pile
// paramètre : p pointeur sur pile

void delete(pile * p){
	
if( p == NULL )
{	
	printf("Erreur pointeur sur pile \n");
	exit(1);
}

element* elem=p->init->next;  // on pointe sur le deuxième élément

while(p->init != NULL)
{
	free(p->init);   // on libère la mémoire pointée sur le premier élément
	p->init=elem;    // on pointe sur le deuxième élément maintenant
	if(p->init == NULL)
	break;    // on sort de la boucle
	elem=p->init->next;	
}

 free(p);   // on désalloue la mémoire de la pile
 p=NULL;
}

// affichage de la pile
// paramètre : pointeur sur la pile

void print(const pile* p){
	
 if (p == NULL)
 {
	 printf("Erreur pointeur sur pile \n");
	 exit(1);	
 }
 
 element* elem=p->init; // on pointe sur le premier élément
 
 while( elem != NULL)
 {
	 printf("%d\n",elem->el);  // on affiche l'élément
	 elem=elem->next; 
 }
}
