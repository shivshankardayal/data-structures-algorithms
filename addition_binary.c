#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iso646.h>

void format(char* n1, char* n2, char* integral_part1, char* \
            integral_part2, char* fractional_part1, char* \
            fractional_part2)
{
  char* delimiters = ".";

  strcpy(integral_part1, strtok(n1, delimiters));
  strcpy(fractional_part1, strtok(NULL, delimiters));
  strcpy(integral_part2, strtok(n1, delimiters));
  strcpy(fractional_part2, strtok(NULL, delimiters));

  fractional_part1[strlen(fractional_part1 - 1)] = '\0';
  fractional_part2[strlen(fractional_part2 - 1)] = '\0';

  // make fractional parts equal in length
  
  if(strlen(fractional_part1)<strlen(fractional_part2)) {
    for (int i = strlen(fractional_part1); i<strlen(fractional_part2); i++) {
      fractional_part1[i] = '0';
    }
  } else if (strlen(fractional_part2)<strlen(fractional_part1)){
    for (int i = strlen(fractional_part2); i<strlen(fractional_part1); i++) {
      fractional_part2[i] = '0';
    }
  }
}


void addition(char* n1, char* n2)
{
}
