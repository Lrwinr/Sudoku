#include <iostream>
#include <string>

using namespace::std;

	string Binary[9] = { "000","001","010","011","100","101","110","111","---" };//将数字转换为1个二进制数
	struct { char bit[3];bool canErased[3]={false,false,false}; }Numbers[9][9];//将1个二进制数分3位存储,同时记录这一位能否被擦除



class Init
{

//放置白景元的函数
friend class Scene;
      private:
      int InitNumbers[9][9] = { {2,8,3,6,4,5,9,7,1},
				{7,5,4,9,3,1,8,2,6},
				{6,1,9,7,8,2,3,4,5},
				{3,2,6,5,1,8,4,9,7},
				{1,4,7,2,6,9,5,8,3},
				{8,9,5,4,7,3,6,1,2},
				{5,7,8,3,2,4,1,6,9},
				{9,6,1,8,5,7,2,3,4},
				{4,3,2,1,9,6,7,5,8} };   //测试用 初始化后的数独表


};









