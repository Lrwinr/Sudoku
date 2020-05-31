#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "common.h"
#include "input.h"
Input::Input(void)
{
	cursor.x=4;
	cursor.y=4;
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
	int row;//光标的行（公式需要由棋盘确定，当前棋盘为TEST.cpp）
	int col;//光标的列
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
	//公式需要由棋盘的格式确定，以上两个公式符合“TEST.cpp”生成的棋盘
	printf("\033[%d;%dH",row,col);
}


bool Input::statejudge(void)const{//判断当前位置是否可输入数字
	if(true)//判断当前位置是否可输入数字（需要具体实现）
		return 1;//可输入
	else return 0;//不可输入
	//一种可能的实现为return PointValue.state
}

int Input::enternum(void)const{//输入三位二进制数字，得到输入的值的十进制
	char numbers[4];
	int n;
	std::cin>>numbers;

	if(numbers[0] == '1') n+=4;
	else if(numbers[0] != '0')return -1;
	if(numbers[1] == '1') n+=2;
	else if(numbers[1] != '0')return -1;
	if(numbers[2] == '1') n+=1;
	else if(numbers[2] != '0')return -1;

	return n;//
}

bool Input::valuejudge(int n)const{//遍历棋盘，判断输入与题目是否冲突,n为准备填写的数字
	Point i;

	for(i.y=cursor.y,i.x=0;i.x<9;++i.x){//判断x
		if(cursor.x==i.x)continue;//跳过两点重合的情况
		if(false)return 0;//两点的值有冲突（需要具体实现）
	}

	for(i.x=cursor.x,i.y=0;i.y<9;++i.y){//判断y
		if(cursor.y==i.y)continue;//跳过两点重合的情况
		if(false)return 0;//两点的值有冲突（需要具体实现）
	}

	int xlower,xupper,ylower,yupper;//判断宫
	if(cursor.x<3)xlower=0,xupper=2;
	else if(cursor.x<6)xlower=3,xupper=5;
	else xlower=6,xupper=8;//锁定对应三x

	if(cursor.y<3)ylower=0,yupper=2;
	else if(cursor.y<6)ylower=3,yupper=5;
	else ylower=6,yupper=8;//锁定对应三y
	
	for(i.x=xlower;i.x<=xupper;++i.x){
		for(i.y=ylower;i.y<=xupper;++i.y){
			if(cursor.x==i.x&&cursor.y==i.y)continue;//跳过两点重合的情况
			if(false)return 0;//两点的值有冲突（需要具体实现）
		}
	}
	
	return 1;//遍历后无冲突
}

main(){//对以上函数调用的参考（不要也不能单独编译运行本代码）
	Input* pinput=new Input;//创建对象指针
	char c;//存储输入的指令
	int num;//存储将要填入格子中的数
	pinput->showcursor();//光标位置初始化到中心
	while(true){//true表示未通关且未结束游戏（需要具体实现）
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
			case'J':case'j'://J键选中当前位置，并填数
			if( pinput->statejudge() ){//如果当前位置可输入
				num=pinput->enternum();//输入数字

				if( pinput->valuejudge(num)){//如果输入的数正确
					;//将输入的数字填写在光标位置(在这里补充输入相关的代码)
					pinput->showcursor();//光标复位
				}
				else
				;//填入原先的数字(在这里补充输入相关的代码)
			}
			//如果不可输入，则按j后按数字键没有反应
			continue;

			/*case'K':case'k':		//扩展功能，K键删除已经填入的数
			if( pinput->statejudge() == 1 )
				;//将当前格子恢复原样(需要具体实现)
			continue;
			*/

		}
		//判断是否通关(需要具体实现)
}
