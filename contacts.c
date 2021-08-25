#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../includes/contacts.h"



int main() {

    
 char *filename;
   
   int file_exists;
   filename="in1.bin";
    
 FILE *file=fopen(filename,"rb");
    if (file==NULL) file_exists=0;
    else {file_exists=1; fclose(file);}
    


      					      if (file_exists==1)
    						{
    								   printf("file exists!\n");
    								   file=fopen(filename,"ab+");

    						}
    						else
    						{
     							   printf("file does not exist!\n");
     			
				   file=fopen(filename,"wb+");

    						}
    
    
    
    if (file!=NULL)
    {
       printf ("file opened succesfully!\n");
       
    }
	
     maindisp();
     mainline();  
    
        
	return 0;
}

