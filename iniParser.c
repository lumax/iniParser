/*
Bastian Ruppert
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "iniParser.h"


/*
 * trim: get rid of trailing and leading whitespace...
 *       ...including the annoying "\n" from fgets()
 */
static char * trim (char * s)
{
  // Initialize start, end pointers 
  char *s1 = s, *s2 = &s[strlen (s) - 1];

  // Trim and delimit right side 
  while ( (isspace (*s2)) && (s2 >= s1) )
    s2--;
  *(s2+1) = '\0';

  // Trim left side 
  while ( (isspace (*s1)) && (s1 < s2) )
    s1++;

  // Copy finished string 
  strcpy (s, s1);
  return s;
}

int iniParser_getParam(char * file,char * param,char * target,int targetLen)
{
  char *s, buff[64];
  FILE *fp = fopen (file, "r");
  int ret=-1;

  if(targetLen<64)
    return -1;

  if (fp == NULL)
  {
    return -1;
  }

  // Read next line 
  while ((s = fgets (buff, sizeof buff, fp)) != NULL)
  {
    // Skip blank lines and comments 
    if (buff[0] == '\n' || buff[0] == '#')
      continue;

    // Parse name/value pair from line 
    char name[64], value[64];
    s = strtok (buff, "=");
    if (s==NULL)
      continue;
    else{
      strncpy (name, s, 64);
      trim (name);
    }
    s = strtok (NULL, "=");
    if (s==NULL)
      continue;
    else
      strncpy (value, s, 64);
    trim (value);

    //compare to requested param 
    if (strcmp(name,param)==0)
      {
	strncpy (target, value, 64);
	ret = 0;
	break;
      }
  }
  // Close file 
  fclose (fp);
  return ret;
}  

