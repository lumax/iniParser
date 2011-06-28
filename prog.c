/*
Bastian Ruppert
*/

#include <stdio.h>
#include "iniParser.h"

static struct t_iniParserParams params[] = {
  [0] = {
    .key = "0",
    .value="null"
  },
  [1] = {
    .key = "1",
    .value="eins",
  },
  [2] = {
    .key = "2",
    .value="zwei",
  },
  [3] = {
    .key = "3",
    .value="drei",
  },
  [4] = {
    .key = "4",
    .value="vier",
  },
  [5] = {
    .key = "5",
    .value="fünf",
  },
  [6] = {
    .key = 0,
  },
};

int main(int argc, char * argv[])
{
  char buf[64];
  char tmp[]={'0','\0'};
  int len = 64;
  char c;
  struct t_iniParserParams * pParam;

  for(c=0x30;c<=0x39;c++)
    {
      printf("searching for param %s\n",tmp);
      
      tmp[0]=c;
      
      if(iniParser_getParam("inifile.txt",tmp,buf,len))
	printf("error parsing %c\n",c);
      else
      printf("parsing OK: param %c = %s\n",c,buf);
    }


  printf("vor iniParser_getParamList:\n");

  pParam = params;
  while(pParam->key)
    {
      printf("key:%s value:%s valid:%i\n",pParam->key,pParam->value,pParam->valid);
      pParam++;
    }
  
  printf("iniParser_getParamList retuns:%i\n",		\
	 iniParser_getParamList("inifile.txt",params));
  
  pParam = params;
  while(pParam->key)
    {
      printf("key:%s value:%s valid:%i\n",pParam->key,pParam->value,pParam->valid);
      pParam++;
    }
  return 0;
}
