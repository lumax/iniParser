/* 
Bastian Ruppert
*/

#ifndef __iniParser_h__
#define __iniParser_h__


/*! \brief parse init File for param
 *
 * @file: iniFile
 * @param: The param searching for (max param length = 64 byte)
 * @target: place to copy the param in
 * @targetLen: parameter can be max 64 byte long
 */
int iniParser_getParam(char * file,char * param,char * target,int targetLen);

#endif /* __iniParser_h__ */

