 //数独格子类 
#include <cassert>
#include <iostream>
#include "common.h"
#include "block.h"
#include "color.h"

Block::Block()
    : Cnt(0) {}

//棋盘打印函数
void Block::print() const
{
    std::cout << "| ";
    for (int i = 0; i < Cnt; ++i)
    {
        auto number = *(Numbers[i]);
        if (0 == number.value)//数值为0时打印 |（因为0不属于数独有效数字）
            std::cout << ' ' << " | ";
        else
        {
            if (number.state == State::Erased)
                std::cout << Color::Modifier(Color::FG_GREEN) << number.value << Color::Modifier(Color::RESET) << " | ";
            else
                std::cout << number.value << " | ";
        }
    }
    std::cout << std::endl;
}

//判断是否有效函数
bool Block::Valid() const
{
    assert(MAXCnt == Cnt); //当计数为9时才开始判断是否有效 
    for (int i = 0; i < Cnt - 1; ++i)
    {
        for (int j = i + 1; j < Cnt; ++j)
        {   //数字为0跳过
            if (UnSelected == Numbers[i]->value || UnSelected == Numbers[j]->value)
                continue;
            //数字相等失败
            if (Numbers[i]->value == Numbers[j]->value)
                return false;
        }
    }
    return true;
}

//判断是否填满函数
bool Block::Full() const
{
    for (int i = 0; i < Cnt; ++i)
    {
        PointValue *p_Value = Numbers[i];
        if (nullptr == p_Value || UnSelected == p_Value->value)//为空指针或0时
            return false;
    }
    return true;
}

//尾部插入函数
void Block::PushBack(PointValue *point)
{
    assert(nullptr != point);
    Numbers[Cnt++] = point;
}