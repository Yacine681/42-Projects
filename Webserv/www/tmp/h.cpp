
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

char **ft_strdup(char **s)
{
    char **ns;
    int i;
    if (s)
    {
    	i = 0;
        for (; s[i]; i++);
        ns =(char**)malloc((i + 1) * sizeof(char *));

    	i = 0;
        for( ; s[i]; i++){
            int len = std::string(s[i]).size();
        	ns[i] = (char *)malloc(len + 1);
        }
         std::cout<<"i:"<<i<<std::endl;
     	ns[i] = NULL;
     	for (i = 0; s[i]; i++)
     	{
     		int j;
            for(j = 0; s[i][j]; j++)
            	ns[i][j] = s[i][j] ;
            ns[i][j] = '\0';
            std::cout<<"s: "<<s[i]<<" i: "<<i<<std::endl;
     	}

    }

    for(int i=0; ns[i]; i++){
    	printf("%s, ddd %i\n",ns[i], i);}

    return ns;
}




int main() {

   char s0[]= "abcd";
   char s1[] = "exf";
   char s2[] = "sdsabcd";
   char s3[] = "3323abcd";

    char** s =(char**) malloc (5 * sizeof(char *) );
    s[0] = s0;
    s[1] = s1;
    s[2] = s2;
    s[3] = s3;
    s[4] = NULL;

    char **n = ft_strdup(s);
    for (int i=0; n[i]; i++){
      printf("%s, %i\n",n[i], i);
    }
  	std::cout<<"test\n";
	free(s);
  	for (int i=0; n[i]; i++)
  		free(n[i]);
  	free(n);

  return 0;
}