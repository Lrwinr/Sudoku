#include "Algo.h"


bool Algo::Logic(Input* & input){
                   

  int Cnt=0;//记录相同的位数
  int i,j,k;
  for(j=0;j<9;++j){//对行进行遍历
     for(k=0;k<3;++k){//对于一个数，比较每三位
        Cnt=0;
        if(Numbers[input->cursor.y][input->cursor.x].bit[k]==' ')//如果该数有一位为空，则跳出循环
        break;//由于只跳出了一层循环，依然会继续遍历。可优化。
        else if(input->cursor.x==j)//遍历到这个数本身，则不进行比较
        break;  
        else if(Numbers[input->cursor.y][input->cursor.x].bit[k]==Numbers[input->cursor.y][j].bit[k])
        ++Cnt;//记录下和另一个数相同的位数
     }
     if(Cnt==3)
     return false;//有相同的数则失败
  }
  
  for(i=0;i<9;++i){//对列进行遍历
     for(k=0;k<3;++k){
        Cnt=0;
        if(Numbers[input->cursor.y][input->cursor.x].bit[k]==' ')
        break;
        else if(input->cursor.y==i)
        break;  
        else if(Numbers[input->cursor.y][input->cursor.x].bit[k]==Numbers[i][input->cursor.x].bit[k])
        ++Cnt;
     }
     if(Cnt==3)
     return false;
  }

  for(i=0;i<3;++i){//对宫进行遍历
     for(j=0;j<3;++j){
        for(k=0;k<3;++k){
           Cnt=0;
           if(Numbers[input->cursor.y][input->cursor.x].bit[k]==' ')
           break;
           else if(input->cursor.y==input->cursor.y-1+i&&input->cursor.x==input->cursor.x-1+j)
           break;  
           else if(Numbers[input->cursor.y-1+i][input->cursor.x-1+j].bit[k]==Numbers[input->cursor.y][input->cursor.x].bit[k])
           ++Cnt;
        }
        if(Cnt==3)
        return false;
     }
  }
//遍历完成，没有重复的数，则分别计数
  ++ROWCnt[input->cursor.y];
  ++COLCnt[input->cursor.x]; 
  PALnum=PalaceNum(input->cursor.x,input->cursor.y);
  ++PALCnt[PALnum];
  
  return true;

}




void Algo::Check(Input* & input,Scene& effect){

int ROW=input->cursor.y;
int COL=input->cursor.x;
int PAL=PalaceNum(input->cursor.y,input->cursor.x);
int end=9;

if(ROWCnt[ROW]==9){
	input->showcursor(ROW,end);
        cout<<"\033[1;92m"<<effect.ROWeffect[ROW];
}

if(COLCnt[COL]==9){
        for(int line=0;line<5;++line){
        end=end+line;
	input->showcursor(end,COL);
        cout<<"\033[1;92m"<<effect.COLeffect[line][COL];
        }
}

if(PALCnt[PAL]==9){
}



}




int Algo::PalaceNum(int& _row,int& _col){
     int a=_row/3+1;
     int b=_col/3+1;
     return (a-1)*3+b-1;//宫的标号为0~8
}

