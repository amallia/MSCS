/*
 * endian.cpp
 *
 *  Created on: Sep 17, 2018
 *      Author: chris
 */
#include <stdio.h>
int main()
{
   unsigned int i = 1;
   char *c = (char*)&i;
   if (*c)
       printf("Little endian");
   else
       printf("Big endian");
   getchar();
   return 0;
}



