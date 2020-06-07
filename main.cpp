#include "Init.cpp"
#include "Scene.cpp"
#include "Input.cpp"
#include "Algo.cpp"

int main(){

cout<<"\033c";//清屏

char c;//存储输入的指令
int  level=0;//存储输入的难度
		
Scene scene;
Algo exam;
Input* pinput=new Input;
bool ExitFlag=false;
bool EnterFlag=false;
Init initTable;
scene.GameBegin();
c=read();
scene.Select();

	while(!EnterFlag){
        c=read();
        switch(c){
        case'S':case's':++level;
                        break;
        case 32:EnterFlag=true;
                break;
        default:continue;
        }
        level=level%4;
        cout<<"\033[0;90m0";
        printf("\033[%d;%dH",level+12,24);
        cout<<"\033[1;92m-";
        printf("\033[%d;%dH",level+12,24);
        }

	switch(level){
	case 0: level=20 ;break;
	case 1: level=40 ;break;
	case 2: level=50 ;break;
	case 3: level=60 ;break;
	}
        initTable.Proc(level);
        scene.Print();
	pinput->showcursor();


	while(!ExitFlag){
		c=read();
		switch(c){		
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
                        if(!exam.Logic(pinput))
                        pinput->Wrong();
                        ExitFlag=exam.Check(pinput,scene);
                        continue;
			case 27://ESC键退出游戏
			cout<<"\033c";//清屏
			ExitFlag=true;
			default:continue;
               }

        }
			

delete pinput;

return 0;
}

