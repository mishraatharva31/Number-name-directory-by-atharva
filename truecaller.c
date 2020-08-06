#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* search_number(FILE *poi,char *i,int k) //function for searching number against the number
  { int q=0;
    char p[200];
      while(fgets(p,k+1,poi) != NULL)
           {if(strcmp(p,i)==0)
              {fgets(p,11,poi);
                 q++;
				 break;
              }
		   }
	   if(q>0 && p[0]>=48 && p[0]<=57)
	   return p;
	  else return ("No such user found (please check the spelling or make sure to enter the full name)");
  }
char* search_name(FILE *poi,char *s) //function for searching name aainst the number
    { char p[200];
       char* i="No such number found";
       int l;
      while(fgets(p,200,poi) !=NULL)
           {if(strstr(p,s) !=NULL)
              {  l=strlen(p);
                  char q[l-10];
                  int k;
                 for(k=0;k<l-10-1;k++)
                     {q[k]=p[k];
					 }
				q[k]='\0';
               i=q;
                break;
			  }
		   }
	   return i;
	}


int main()
  { FILE* poi ;
    poi= fopen("telephone.txt","r");
    char s[20];
    start:
    printf("Enter 1 if you want to search for number or enter 2 if you want to search for name\n");
    int j;    
	scanf("%d",&j);
	if(j==1)
	 {printf("Enter the name\n");
	  scanf("\n");
	  scanf("%[^\n]*c",s);
	  char* i;
	  i=strupr(s);
      int k=strlen(s) ;
      char* p=search_number(poi,i,k);
      printf("%s",p);
      }
    else {if(j==2)
	        {printf("Enter the number\n");
	         scanf("\n");
	         scanf("%s",s);
	         if(strlen(s) !=10)
	            {printf("Please enter a valid 10-digit mobile number\n");
	             goto start;
				}
			 else {  char* q=search_name(poi,s);
			         printf("%s",q);
			      
				  }
			}
		   else {printf("Please choose either 1 or 2\n");
		          goto start;
			    }
		}
		          
		        
   fclose(poi);
    return 0;
  } 
