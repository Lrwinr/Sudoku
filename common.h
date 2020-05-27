// 公共文件  
#ifndef _COMMON_H_
#define _COMMON_H_

static const unsigned int UnSelected = 0;//0不在数独有效数字中

//状态类
enum class State : int
{
    Inited = 0,
    Erased,
};
//关卡类(设计关卡同学请在这里修改具体关卡数目)
enum class Level : int
{
    One = 1,
    Two,
    Three,
    Four,
    Five
};

//标识所在处的数值和状态
using PointValue = struct PointValue {
    int value;
    State state;
};

using Point = struct Point {
    int x;
    int y;
};
class PointSort
{
  public:
    bool operator()(const Point &a, const Point &b) const
    {
        if ((a.x == b.x) && (a.y == b.y))
            return false;
        else
            return true;
    }
};

#endif