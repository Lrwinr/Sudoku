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

        void InsideMove(void);//内部输入模式

            
private:
	Point cursor;//光标逻辑位置
        //Point为结构体 int x;int y;


//代码调整部分：
	int row;//光标实际位置
	int col;//
        bool InputIdx;//是否为内部移动模式的标志
        int InsideCur;//新增：内部三位移动的光标
        bool Logic(void);//新增遍历判断函数，一是弥补代码的严谨性随机性，二是防止bug玩法的出现


};
#endif


