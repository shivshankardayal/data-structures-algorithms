#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void format(char *n1,char*n2,char* integral_part1,char* integral_part2,char* fractional_part1,char* fractional_part2)
{
  char* delimiters=".";
  strcpy(integral_part1,strtok(n1, delimiters));
  strcpy(fractional_part1,strtok(NULL, delimiters));
  strcpy(integral_part2,strtok(n2, delimiters));
  strcpy(fractional_part2,strtok(NULL, delimiters));
  fractional_part1[strlen(fractional_part1)-1]='\0';
  fractional_part2[strlen(fractional_part2)-1]='\0';
  if(strlen(fractional_part1)<strlen(fractional_part2))
  {
    for(int i=strlen(fractional_part1);i<strlen(fractional_part2);i++)
    {
      fractional_part1[i]='0';
    }
  }
  else if(strlen(fractional_part2)<strlen(fractional_part1))
  {
    for(int i=strlen(fractional_part2);i<strlen(fractional_part1);i++)
    {
      fractional_part2[i]='0';
    }
  }
}
void addition(char* n1,char* n2)
{
  char integral_part1[512]={0}, integral_part2[512]={0}, carry=0;    
  char fractional_part1[512]={0}, fractional_part2[512]={0};
  char sum1[512] = {0}, sum2[512] = {0};
  char sum[1024]= {0};
  char orig1[512],orig2[512];
  strcpy(orig1,n1);
  strcpy(orig2,n2);
  format(n1, n2, integral_part1, integral_part2, fractional_part1, fractional_part2);
  \\ only one counter needed because we have made lengths equal//
    int i=strlen(fractional_part1);
  while(i not_eq 1)
  {
    if(fractional_part1[i] == '0' and fractional_part2[i] == '0' and carry==0)
    {
      sum1[i] = '0';
    }
    else if(fractional_part1[i] == '0' and fractional_part2[i] == '0' and carry == 1)
    {
      sum[i]= '1';
      carry=0;
    }
    else if(fractional_part1[i] == '1' and fractional_part2[i] == '0' and carry == 0)
    {
      sum[i] = '1';
    }
    else if(fractional_part1[i] == '0' and fractional_part2[i] == '1' and carry == 0)
    {
      sum[i]= '1';
    }
    else if(fractional_part1[i] == '1' and fractional_part2[i] == '1' and carry == 0)
    {
      sum[i]= '0';
      carry= 1;
    }
    else if(fractional_part1[i] == '1' and fractional_part2[i] == '0' and carry == 1)
    {
      sum[i]= '0';
    }
    else if(fractional_part1[i] == '0' and fractional_part2[i] == '1' and carry == 1)
    {
      sum[i]= '0';
    }
    else if(fractional_part1[i] == '1' and fractional_part2[i] == '1' and carry == 1)
    {
      sum[i]= '1';
    }
    i--;
  }
  i=strlen(integral_part1);
  int j=strlen(integer part_2);
  while(i not_eq -1 or j not_eq -1)
  {
    if(integral_part1[i] == '0' and integral_part2[i] == '0' and carry == 0)
    {
      sum2[i+1] = '0';
    }
    else if(integral_part1[i] == '0' and integral_part2[i] == '0' and carry == 1)
    {
      sum2[i+1] = '1';
      carry= 0;
    }
    else if(integral_part1[i] == '1' and integral_part2[i] == '0' and carry = 0)
    {
      sum2[i+1] = '1';
    }
    else if(integral_part1[i] == '0' and integral_part2[i] == '1' and carry = 0)
    {
      sum2[i+1]= '1';
    }
    else if(integral_part1[i] == '1' and integral_part2[i] == '1' and carry == 0)
    {
      sum2[i+1] = '0';
      carry= 1;
    }
    else if(integral_part1[i] == '1'  and integral_part2[i] == '0' and carry == 1)
    {
      sum2[i+1] = '0';
    }
    else if(integral_part1[i] == '0' and integral_part2[i] == '1' and carry == 1)
    {
      sum2[i+1] = '0';
    }
    else if(integral_part1[i] == '1' and integral_part2[i] == '1' and carry == 1)
    {
      sum2[i+1] = '1';
    }

    i--;
    j--;
  }
  if(i == -1 and j == -1)
  {
    if(carry == 0)
      sum2[0] = '0';
    else
      sum2[0] = '1';
  }
  else if(i not_eq -1)
  {
    while(i not_eq -1)
    {
      if(integral_part1[i] == '0' and carry == 0)
      {
        sum2[i+1] = '0';
      }
      else if(integral_part1[i] == '0' and carry == 1)
      {
        sum2[i+1] = '1';
      }
      else if(integral_part1[i] == '1' and carry == 0)
      {
        sum2[i+1]= '1';
      }
      else if(integral_part1[i] == '1' and carry == 1)
      {
        sum2[i+1] = '0';
        carry = 1;
      }
    }
  }
  else if(j not_eq -1)
  {
    while(j not_eq -1)
    {
      if(integral_part2[j] == '0' and carry == 0)
      {
        sum2[j+1]= '0';
        else if(integral_part2[j] == '0' and carry == 1)
        {
          sum2[j+1] = '1';
          else if(integral_part2[j] == '1' and carry == 0)
          {
            sum2[j+1] = '1';
            else if(integral_part2[j] == '1' and carry == 1)
            {
              sum2[j+1] = '0';
              carry = 1;
            }
          }
        }
        if(carry == 0)
          sum2[0] = '0';
        else
          sum2[0] = '1';
        strcat(sum,sum2);
        strcat(sum,".");
        strcat(sum,sum1);
        printf("%s + s = %s\n",n1, n2, sum);
      }
      int main()
      {
        char c='\0';
        char n1[1024] = {0};
        char n2[1024] = {0};
        while(c not_eq 'n')
        {
          puts("plz enter two floating point numbders(base2)and corresponding operation ");
          puts("+for addition");
          puts("-for subtraction");
          puts("*for multiplication");
          puts("%for division");
          puts("n for existing the program");
          puts("plz enter 1st no");
          fgets(n1, 1024, stdin);
          puts("plz enter 2nd  no");
          fgets(n2, 1024, stdin);
          c=getchar();
          getchar();
          if(c=='+' or c=='-' or c=='*' or c=='/')
            if(c=='+')
              addition(n1,n2);
            else if (c=='-')
              subtraction(n1,n2);
            else if (c=='*')
              multiplication(n1,n2);
            else if (c=='/')
              division(n1,n2);
        }
      }
    } 
    return 0;
  }
