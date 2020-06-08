#include "Init.h"

int ROWCnt[9]={0};//每行、列、宫里非空的数
int COLCnt[9]={0};
int PALCnt[9]={0};
int PalaceNum(int& _row,int& _col);

struct { char bit[3];bool canErased[3]={false,false,false};bool Wrong=false; }Numbers[9][9];


Init::Init(void){
srand((int)time(0));
int random=rand()%6;
for(int i=0;i<9;i++)
{
	for(int j=0;j<9;j++)
	{
		table[i][j]=InitNumbers[2][i][j];
//		table[i][j]=InitNumbers[random][i][j];
	}
}


}

void Init::Proc(int& deg){

srand((int)time(0));

int value;
string temp;
char blank='_';
int FilledIdx;

for(int i=0;i<9;++i){

  for(int j=0;j<9;++j){

        value = table[i][j];
	temp = Binary[value-1];
        FilledIdx=0;
        for(int k=0;k<3;++k){
	int r=rand()%100;
	if(r<=deg && table[i][j]!=9)//25%概率挖空
	   Numbers[i][j].bit[k]=blank;
	else{
	   Numbers[i][j].bit[k]=temp[k];
           ++FilledIdx;
        }   
        }

        if(FilledIdx==3){
           ++ROWCnt[i];
           ++COLCnt[j];
           int PALnum=PalaceNum(i,j);
           ++PALCnt[PALnum];
        }

   }
}

}
