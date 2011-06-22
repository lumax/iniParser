/*
Bastian Ruppert
*/

#include <stdio.h>
#include "iniParser.h"

int main(int argc, char * argv[])
{
  char buf[64];
  char tmp[]={'0','\0'};
  int len = 64;
  char c;

  for(c=0x30;c<=0x39;c++)
    {
      printf("searching for param %s\n",tmp);
      
      tmp[0]=c;
      
      if(iniParser_getParam("inifile.txt",tmp,buf,len))
	printf("error parsing %c\n",c);
      else
      printf("parsing OK: param %c = %s\n",c,buf);
    }
  return 0;
}
