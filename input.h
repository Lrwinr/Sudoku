#ifndef _INPUT_H_
#define _INPUT_H_
char read(void);//输入函数

//输入判断类
class Input
{
public:
	Input(void);//构造函数

	void up(void);//光标位置控制
	void down(void);
	void left(void);
	void right(void);
	//缺少一个在棋盘上显示光标当前位置的函数
	//可能还缺少一个光标位置恢复原状态的函数

	bool statejudge(void)const;//光标填数控制
	int enternum(void)const;
	bool valuejudge(int n)const;
	//缺少一个将输入的数字填写在光标位置的函数（或友元函数）
	
private:
	Point cursor;//光标位置
	
}
#endif
