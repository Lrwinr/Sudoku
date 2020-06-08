#include "Algo.h"


bool Algo::Logic(Input* & input){
                   
  bool FilledIdx;
  bool WrongFlag=false;
  int Cnt=0;//记录相同的位数
  int i,j,k;

  PALnum=PalaceNum(input->cursor.y,input->cursor.x);

  ROWCnt[input->cursor.y]=0;
  COLCnt[input->cursor.x]=0;
  PALCnt[PALnum]=0;
 

  for(j=0;j<9;++j){//对行进行遍历
     FilledIdx=true;
     Cnt=0;
     for(k=0;k<3;++k){//对于一个数，比较每三位
        if(Numbers[input->cursor.y][j].bit[k]=='_'||Numbers[input->cursor.y][j].Wrong==true)
        FilledIdx=false;
        if(Numbers[input->cursor.y][input->cursor.x].bit[k]=='_')//如果这个数有一位是空的
        break;//那就不比较并计入重复
        else if(Numbers[input->cursor.y][input->cursor.x].bit[k]==Numbers[input->cursor.y][j].bit[k])
        ++Cnt;//记录下和另一个数相同的位数
        if(input->cursor.x==j)//遍历到这个数本身，则不进行比较.否则会记为重复
        Cnt=0;
     }
     if(FilledIdx)
     ++ROWCnt[input->cursor.y];
     if(Cnt==3)
     WrongFlag=true;//有相同的数则失败.
  }


  for(i=0;i<9;++i){//对列进行遍历
     FilledIdx=true;
     Cnt=0;
     for(k=0;k<3;++k){
        if(Numbers[i][input->cursor.x].bit[k]=='_'||Numbers[i][input->cursor.x].Wrong==true)
        FilledIdx=false;
        if(Numbers[input->cursor.y][input->cursor.x].bit[k]=='_')
        break;  
        else if(Numbers[input->cursor.y][input->cursor.x].bit[k]==Numbers[i][input->cursor.x].bit[k])
        ++Cnt;
        if(input->cursor.y==i)
        Cnt=0;  
     }
     if(FilledIdx)
     ++COLCnt[input->cursor.x];
     if(Cnt==3)
     WrongFlag=true;

  }


  //对宫进行遍历
  int tempy,tempx;
  tempy=PALnum/3;
  tempx=PALnum%3;
  tempy*=3;
  tempx*=3;

  for(i=0;i<3;++i){
     for(j=0;j<3;++j){
        FilledIdx=true;
        Cnt=0;
        for(k=0;k<3;++k){
           if(Numbers[tempy+i][tempx+j].bit[k]=='_'||Numbers[tempy+i][tempx+j].Wrong==true)
           FilledIdx=false;
           if(Numbers[input->cursor.y][input->cursor.x].bit[k]=='_')
           break; 
           else if(Numbers[input->cursor.y][input->cursor.x].bit[k]==Numbers[tempy+i][tempx+j].bit[k])
           ++Cnt;
           if(input->cursor.y==tempy+i&&input->cursor.x==tempx+j)
           Cnt=0;  
        }
        if(FilledIdx)
        ++PALCnt[PALnum];
        if(Cnt==3)
        WrongFlag=true;
     }
  }



  if(WrongFlag){
  --ROWCnt[input->cursor.y];
  --COLCnt[input->cursor.x];
  --PALCnt[PALnum];
  }

  return !WrongFlag;

}




bool Algo::Check(Input* & input,Scene& effect){

int ROW=input->cursor.y;
int COL=input->cursor.x;
int PAL=PalaceNum(input->cursor.y,input->cursor.x);


input->showcursor(ROW,9);
if(ROWCnt[ROW]==9)
        cout<<"\033[1;92m";
else
        cout<<"\033[0;90m";
cout<<effect.ROWeffect[ROW];


for(int line=0;line<3;++line){
input->showcursor(9+line,COL);
if(COLCnt[COL]==9)
        cout<<"\033[1;92m";
else
        cout<<"\033[0;90m";
cout<<effect.COLeffect[line*2][COL];

}


int tempy,tempx;
tempy=PAL/3;
tempx=PAL%3;
input->showcursor(tempy+9,tempx+9);
tempy=tempy*2;
if(PALCnt[PAL]==9)
        cout<<"\033[1;92m";
else
        cout<<"\033[0;90m";
cout<<effect.PALeffect[tempy][tempx];

input->showcursor();

int Count=0;

WinCnt=0;
for(int i=0;i<9;++i){  
   if(ROWCnt[i]==9)
   ++WinCnt;
}
if(WinCnt==9)
  ++Count;


WinCnt=0;
for(int i=0;i<9;++i){  
   if(COLCnt[i]==9)
   ++WinCnt;
}
if(WinCnt==9)
  ++Count;


WinCnt=0;
for(int i=0;i<9;++i){  
   if(PALCnt[i]==9)
   ++WinCnt;
}
if(WinCnt==9)
  ++Count;

if(Count>0){
   char SIG;
   SIG=read();
   effect.GameWin(Count);
   return true;
}

return false;

}



int PalaceNum(int& _row,int& _col){
     int a=_row/3+1;
     int b=_col/3+1;
     return (a-1)*3+b-1;//宫的标号为0~8
}

