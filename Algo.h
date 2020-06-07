#ifndef _ALGO_H_
#define _ALGO_H_
#include <iostream>
#include "Scene.h"
using namespace::std;

class Algo
{
private:
int PALnum;
int WinCnt=0;

public:
        bool Logic(Input* & input);//新增遍历判断函数，一是弥补代码的严谨性随机性，二是防止bug玩法的出现

        void Check(Input* & input,Scene& effect);


};
#endif
