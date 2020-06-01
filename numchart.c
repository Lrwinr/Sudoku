#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//the defination of num array

int state[9][5];
int work;
int num[9][9];

void randomchart( void );
int randomconduct(int) ;
void holedig(void);


//the random number function
void randomchart( )
{
    int i ; 
    int j ;
    srand(time(NULL));
    work=randomconduct(5) + 1;


} 
 


//This function is used to conduct a random number ranging from 1 to n(a int number)
int randomconduct(int n)
{
    int temp ;
    srand(time(NULL)) ;
    temp=1 +  rand()%n ; 
    return temp ;
}

void holedig()
{
    int i,j,k;
    for (i=0 ; i<=8 ; i++)
    {
       for(j=0 ; j<=4 ; j++)
       {
          state[i][j]=randomconduct(9) - 1 ;
            if (j>=1)
            {
               while(1)
               {
                int arg=1;   
                state[i][j]=randomconduct(9) - 1 ;
                for(k=0 ; k<=j-1 ; k++)
                {
                   if (state[i][j]!=state[i][k])
                   {continue;}
                   else
                   { arg=0;
                     break;  } 
                 }
                 if (arg==1)
                 {  break; }
                 else
                 {   ;}  
               }   
            }
            
        }
    }
}





int main()
{
int i;
int j=0;
randomchart();
switch(work)
 {
    case 1:
      num[9][9] = {{1,5,3,8,9,2,6,7,4},
                      {8,6,2,7,1,4,9,3,5},
                      {9,7,4,3,6,5,2,8,1},
                      {2,3,5,9,7,6,1,4,8},
                      {6,1,7,4,3,8,5,9,2},
                      {4,8,9,5,2,1,7,6,3},
                      {5,9,1,6,4,3,8,2,7},
                      {3,2,8,1,5,9,4,1,6},
                      {7,4,6,2,8,7,3,5,9}};
            break;
    case 2:
      num[9][9] = {{9,6,2,8,4,1,3,7,5},
                      {7,8,5,3,2,6,1,4,9},
                      {4,1,3,5,7,9,6,2,8},
                      {3,7,6,1,5,4,8,9,2},
                      {5,9,8,7,3,2,4,1,6},
                      {1,2,4,9,6,8,7,5,3},
                      {6,4,9,2,8,7,5,3,1},
                      {8,5,1,4,9,3,2,6,7},
                      {2,3,7,6,1,5,9,8,4 }};
            break;
    case 3:
      num[9][9] = {{7,3,5,6,2,8,1,9,4},
                      {1,6,2,9,7,4,3,5,8},
                      {4,8,9,5,3,1,7,6,2},
                      {3,2,7,4,1,6,5,8,9},
                      {6,9,8,2,5,3,4,1,7},
                      {5,4,1,7,8,9,2,3,6},
                      {7,9,3,8,4,5,6,2,1},
                      {8,1,4,3,6,2,9,7,5},
                      {2,5,6,1,9,7,8,4,3 }};
            break;
    case 4:
      num[9][9] = {{8,5,7,1,4,9,3,2,6},
                      {9,1,2,6,8,3,5,7,4},
                      {4,3,6,5,7,2,8,9,1},
                      {2,4,5,9,6,8,7,1,3},
                      {1,7,8,3,5,4,9,6,2},
                      {6,9,3,7,2,1,4,8,5},
                      {7,8,4,2,3,6,1,5,9},
                      {5,2,1,4,9,7,6,3,8},
                      {3,6,9,8,1,5,2,4,7 }};
            break;

    case 5:
      num[9][9] = {{1,4,3,8,7,5,6,2,9},
                      {8,2,7,3,6,9,4,1,5},
                      {5,9,6,4,1,2,8,3,7},
                      {9,6,2,5,8,3,7,4,1},
                      {3,7,1,2,4,6,9,5,8},
                      {4,8,5,7,9,1,3,6,2},
                      {2,3,8,9,5,4,1,7,6},
                      {6,5,9,1,3,7,2,8,4},
                      {7,1,4,6,2,8,5,9,3}};
             break;
}
for (i=0;i<=8;i++)
{
  for (j=0; j<=8 ; j++)
  {
    printf("%d  ", num[i][j]); 
  }
printf("\n");
return 0;
}
}








 
