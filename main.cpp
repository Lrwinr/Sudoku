#include "Scene.cpp"
#include "Input.cpp"
#include "Algo.cpp"



int main(){

Init table;
Scene scene;
Algo exam;

Input* pinput=new Input;//创建对象指针

scene.GameBegin();
sleep (5);//等待输入游戏开始信号，可以调用read函数
	char c;//存储输入的指令

        scene.Print(table);//待设置游戏开始和退出控制
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
                        if(exam.Logic(pinput))
                        exam.Check(pinput,scene);
                        else
                        pinput->Wrong();
                        continue;

			
                }

        }
			

delete pinput;

return 0;
}

