#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "color.h"
#include "common.h"
#include "input.h"
#include "Init.cpp"
using namespace::std;


//以下为input.cpp的实现内容
Input::Input(void)
{
	cursor.x=4;
	cursor.y=4;//光标居中
        InputIdx=false;//
        InsideCur=0;//0,1,2三位
}

char read(void){//读取一个字符
	char c;
	static struct termios oldt, newt;
	tcgetattr( STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON);
	tcsetattr( STDIN_FILENO, TCSANOW, &newt);
	system("stty -echo");

	c=getchar();//读入一个字符，不显示在屏幕上

	system("stty echo");
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
	return c;//返回其ASCLL码
}



void Input::up(void){	//光标逻辑位置移动
	cursor.y=(cursor.y+8)%9;}
void Input::down(void){	//可以跨边界
	cursor.y=(cursor.y+1)%9;}
void Input::left(void){ //如从(0,5)按左会到(8,5)
	cursor.x=(cursor.x+8)%9;}
void Input::right(void){
	cursor.x=(cursor.x+1)%9;}

void Input::showcursor(void){//将光标逻辑位置转换为实际位置并移动光标
        //row和col已调整为数据成员
	row=cursor.y*2+2;
	switch(cursor.x){
		case 0:col=2;break;
		case 1:col=7;break;
		case 2:col=12;break;
		case 3:col=16;break;
		case 4:col=21;break;
		case 5:col=26;break;
		case 6:col=30;break;
		case 7:col=35;break;
		case 8:col=40;break;
	}
	//公式由棋盘的格式确定
	printf("\033[%d;%dH",row,col);
}
//以上为input.cpp的实现内容




//以下为代码调整部分 新增函数
void Input::InsideMove(void){
        InputIdx=!InputIdx;
        char x;
        while(InputIdx){
                x=read();
		switch(x){			
			case'A':case'a':
			InsideCur=(InsideCur+2)%3;
			break;
			case'D':case'd':
			InsideCur=(InsideCur+1)%3;
			break;

                        case 32://空格键退出输入模式
                        InputIdx=!InputIdx;
                        InsideCur=0;//下次进入时，重新定位到第一位数
                        break;
                        case 8://退格键删除输入过的一位
                        if(Numbers[cursor.y][cursor.x].canErased==true){
                        std::cout<<"\033[92;1m"<<"_";//重新打印空格，并更改存储的信息
                        Numbers[cursor.y][cursor.x].bit[InsideCur]='_';
                        Numbers[cursor.y][cursor.x].canErased==false;
                        }
                        break;//退格键删除的操作加入主函数中会更好，但需要访问逻辑坐标cursor.x,y

                        case'J':case'j'://J键选中当前位置，并填0
                        if(Numbers[cursor.y][cursor.x].bit[InsideCur]=='_'){//如果这个位置是空的可填入
                        std::cout<<"\033[37m"<<"0";
                        Numbers[cursor.y][cursor.x].bit[InsideCur]='0';//并把该位的内容改为0
                        Numbers[cursor.y][cursor.x].canErased=true;//更改了内容后，就说明这一位可以被擦除了
                        InsideCur=(InsideCur+1)%3;
                        }
                        break; 
			case'K':case'k'://K键选中当前位置，并填1
                        if(Numbers[cursor.y][cursor.x].bit[InsideCur]=='_'){
                        std::cout<<"\033[37m"<<"1";
                        Numbers[cursor.y][cursor.x].bit[InsideCur]='1';
                        Numbers[cursor.y][cursor.x].canErased=true;
                        InsideCur=(InsideCur+1)%3;
                        }
                        break;
                       
                }
        printf("\033[%d;%dH",row,col+InsideCur);//接受输入后，显示光标位置
        }
//退出输入模式后，调用Init.cpp中的Logic函数 遍历判断
//此时无输入，所以逻辑坐标是静止的
        if(!Logic()) {//如果不正确                
          for(int k=0;k<3;++k){//进行一次重新打印，产生红色的错误提醒
             if(Numbers[cursor.y][cursor.x].canErased=true)
                std::cout<<"\033[91;1m"<<Numbers[cursor.y][cursor.x].bit[k];//把该位标为红色
             else
                std::cout<<"\033[92;1m"<<Numbers[cursor.y][cursor.x].bit[k];//正常打印该位为绿色              
          }
          printf("\033[%d;%dH",row,col);
        }
        else
        Check();//无误则调用该函数，检查该行、列、宫的计数是否为9，待实现
//跳出循环后，退出输入模式，返回主函数的输入
}


bool Input::Logic(void){//原本声明为类的友元函数，但好像要传递实例化对象
                   

  int Cnt=0;//记录相同的位数
  int i,j,k;
  for(j=0;j<9;++j){//对行进行遍历
     for(k=0;k<3;++k){//对于一个数，比较每三位
        Cnt=0;
        if(Numbers[cursor.y][cursor.x].bit[k]==' ')//如果该数有一位为空，则跳出循环
        break;//由于只跳出了一层循环，依然会继续遍历。可优化。
        else if(cursor.x==j)//遍历到这个数本身，则不进行比较
        break;  
        else if(Numbers[cursor.y][cursor.x].bit[k]==Numbers[cursor.y][j].bit[k])
        ++Cnt;//记录下和另一个数相同的位数
     }
     if(Cnt==3)
     return false;//有相同的数则失败
  }
  
  for(i=0;i<9;++i){//对列进行遍历
     for(k=0;k<3;++k){
        Cnt=0;
        if(Numbers[cursor.y][cursor.x].bit[k]==' ')
        break;
        else if(cursor.y==i)
        break;  
        else if(Numbers[cursor.y][cursor.x].bit[k]==Numbers[i][cursor.x].bit[k])
        ++Cnt;
     }
     if(Cnt==3)
     return false;
  }

  for(i=0;i<3;++i){//对宫进行遍历
     for(j=0;j<3;++j){
        for(k=0;k<3;++k){
           Cnt=0;
           if(Numbers[cursor.y][cursor.x].bit[k]==' ')
           break;
           else if(cursor.y==cursor.y-1+i&&cursor.x==cursor.x-1+j)
           break;  
           else if(Numbers[cursor.y-1+i][cursor.x-1+j].bit[k]==Numbers[cursor.y][cursor.x].bit[k])
           ++Cnt;
        }
        if(Cnt==3)
        return false;
     }
  }
//遍历完成，没有重复的数，则分别计数
  ++ROWCnt[cursor.y];
  ++COLCnt[cursor.x]; 
  PALnum=PalaceNum(cursor.x,cursor.y);
  ++PALCnt[PALnum-1];
  
  return true;

}




int main(){

cout<<"\033c";//清屏

PrintTest();


Input* pinput=new Input;//创建对象指针
	char c;//存储输入的指令
	int num;//存储将要填入格子中的数
	pinput->showcursor();//需先显示光标，才能初始化row和col的值，否则会有bug
	for(int i=0;i<200;++i){//测试用，只接收前50个指令，之后程序会结束
		c=read();//
		switch(c){
			//W,A,S,D控制光标上下左右			
			case'W':case'w':
			pinput->up();
			pinput->showcursor();
			continue;
			case'A':case'a':
			pinput->left();
			pinput->showcursor();
			continue;
			case'S':case's':
			pinput->down();
			pinput->showcursor();
			continue;
			case'D':case'd':
			pinput->right();
			pinput->showcursor();
			continue;

                        case 32://空格键进入输入模式
                        pinput->InsideMove();
                        continue;

			
                }

        }
			
cout<<"\033c";//清屏
return 0;
}


















