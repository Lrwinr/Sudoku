#ifndef _BLOCK_H_
#define _BLOCK_H_
//棋盘区域类
class Block
{
    static const int MAXCnt = 9;//规定最大计数为9（边界）

  public:
    Block();
    bool Valid() const;
    bool Full() const;
    void print() const;
    void PushBack(PointValue *point);

  private:
    int Cnt;
    PointValue *Numbers[MAXCnt];//结构体指针 数字标识
};

#endif