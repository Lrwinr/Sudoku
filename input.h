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

	void showcursor(void);//输出光标位置

	bool statejudge(void)const;//光标填数控制
	int enternum(void)const;
	bool valuejudge(int n)const;
	//缺少一个将输入的数字填写在光标位置的函数（或友元函数）
	
private:
	Point cursor;//光标逻辑位置
};
#endif
