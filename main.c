#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j;
  int check=0;
  
  Stack s;
  s.size=0;
  s.top=NULL;
 
  for(i=1;i<argc;i++){
   
     for(j=0;j<strlen(argv[i]);j++){
       /* Use stack to help with the parentheses*/
       switch(argv[i][j])
       {
        case '[' :
        case '{' : push(&s, argv[i][j]); break;
        case ']' : if(pop(&s)!='[') check=1; break;
        case '}' : if(pop(&s)!='{') check=1; break;
       }
       

    if(check ) break;
     }

    if(s.size>0||check)
      printf("The parentheses not match for %s\n",argv[i]);
    else printf("The parentheses match successfully for %s\n",argv[i]);
      check=0;
      pop_all(&s);
    

  }




   return 0;
}
