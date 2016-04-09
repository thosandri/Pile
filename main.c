#include "pile.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	
 pile* p=init(2);
 
 push(p,3);
 push(p,4);
 push(p,6);
 
 print(p);
 
 pop(p);
 
 printf("\n");
 
 print(p);
 
 delete(p);
 	
 return 0;	
	
}
