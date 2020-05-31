#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "color.h"
#include "common.h"
#include "input.h"
using namespace::std;

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


int main(){
int i,j,k;
string numbers[9][9] = { {"01_","_00","_11","110","1_0","101","9","1_1","0_1"},
			{"_1_","101","1_0","9","011","_01","_0_","0_0","110"},
			{"110","00_","9","1_1","000","_1_","_11","_00","_01"},
			{"0_1","0_0","11_","1_1","001","0_0","10_","9","_11"},
			{"0_1","100","1_1","0_0","110","9","101","_0_","011"},
			{"_0_","9","_01","1_0","111","_1_","110","001","_1_"},
			{"101","_1_","0_0","011","01_","100","_0_","110","9"},
			{"9","110","0_1","0_0","101","111","_10","011","1_0"},
			{"10_","011","01_","001","9","_1_","111","1_1","000"} };
string Reffect[9]={"1","10","011","0100","00101","000110","0000111","00001000","000001001"};
string END1="    ┈ ┈     ┈┈┈┈┈┈   ┈┈     ┈┈┈     ┈";
string END2=" ╌╌┅┅╌┅┅╌┅┅┅╌╌ ╌╌┅┅╌┅┅╌┅┅┅╌╌ ┅╌╌┅┅╌┅┅╌┅┅┅╌╌ ";
cout<<"\033c";//清屏
cout<<"\033[92;1m"<<END2<<endl;
for(i=0;i<9;++i){
	cout<<"\033[92;1m"<<"┊";
	for(j=0;j<9;++j){
		if(numbers[i][j]=="9")
			cout<<"┅┅┅";
		else
			cout<<"\033[92;1m"<<numbers[i][j];
		if(j%3==2)
			cout<<"┊";
		else
			cout<<"︲";
	}
	cout<<"\033[0;90m"<<Reffect[i];
	if(i%3==2)
		cout<<endl<<"\033[92;1m"<<END2<<endl;
	else
		cout<<endl<<"\033[0;90m"<<"1001110001101111010010101001 1010011100011"<<endl; 
}

string effect[9]={" 001︲010︲011 100︲101︲110 111︲000︲001 000 001 010",
                  "    ︲  0︲ 00 000︲000︲000 000︲001︲001 000 000 000",
                  "    ︲   ︲       ︲  0︲ 00 000︲000︲000 011 100 101",
                  "    ︲   ︲       ︲   ︲       ︲  0︲000 000 000 000",
                  "    ︲   ︲       ︲   ︲       ︲   ︲    110 111 ┅┅┅"};




for(k=0;k<9;++k){
	cout<<"\033[0;90m"<<effect[k]<<endl;
}






Input* pinput=new Input;//创建对象指针
	char c;//存储输入的指令
	int num;//存储将要填入格子中的数
	pinput->showcursor();
	for(i=0;i<50;++i){//测试用，只接收前50个指令，之后程序会结束
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

			case'J':case'j'://J键选中当前位置，并填9
			if( true ){//如果当前位置可输入
				pinput->showcursor();
				std::cout<<"┅┅┅";
				pinput->showcursor();//光标复位
			}
			else
				;//填入原先的数字(在这里补充输入相关的代码)
			}
			//如果不可输入，则按j后按数字键没有反应
			continue;
		}
cout<<"\033c";//清屏
return 0;
}


















