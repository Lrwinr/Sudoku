#include <iostream>
#include <string>
#include "color.h"
#include "input.h"
using namespace::std;






      int InitNumbers[9][9] = { {2,8,3,6,4,5,9,7,1},
				{7,5,4,9,3,1,8,2,6},
				{6,1,9,7,8,2,3,4,5},
				{3,2,6,5,1,8,4,9,7},
				{1,4,7,2,6,9,5,8,3},
				{8,9,5,4,7,3,6,1,2},
				{5,7,8,3,2,4,1,6,9},
				{9,6,1,8,5,7,2,3,4},
				{4,3,2,1,9,6,7,5,8} };   //测试用 初始化后的数独表
	string Binary[9] = { "000","001","010","011","100","101","110","111","---" };//将数字转换为1个二进制数
	struct { char bit[3];bool canErased[3]={false,false,false}; }Numbers[9][9];//将1个二进制数分3位存储,同时记录这一位能否被擦除


int ROWCnt[9]={0};//每行、列、宫里非空的数
int COLCnt[9]={0};
int PALCnt[9]={0},PALnum;


string END1="1001110001101111010010101001 1010011100011";//行分隔线
string END2=" ╌╌┅┅╌┅┅╌┅┅┅╌╌ ╌╌┅┅╌┅┅╌┅┅┅╌╌ ┅╌╌┅┅╌┅┅╌┅┅┅╌╌ ";//宫分隔线


string ROWeffect[9]={"1","10","011","010 0","001 01","000 110","000 011 1","000 010 00","000 001 001"};//行特效，一行填满后点亮


string COLeffect[5][9]={{" 001︲","010︲","011 ","100︲","101︲","110 ","111︲","000︲","001 "},
                        {"      ","     ","    ","   ︲","   ︲","    ","   ︲","   ︲","    "},
                        {"      ","     ","    ","000︲","000︲","000 ","000︲","001︲","001 "},
                        {"      ","     ","    ","     ","     ","    ","   ︲","   ︲","    "},
                        {"      ","     ","    ","     ","     ","    ","000︲","000︲","000 "}}; //以下同上，对列和宫



string PALeffect[5][3]={{"000 ","001 ","010 "},
                        {"000 ","000 ","000 "},
                        {"011 ","100 ","101 "},                          
                        {"000 ","000 ","000 "},
                        {"110 ","111 ","--- "}};

//以上为五毛特效组


int PrintTest(){
int i,j,k;
int value;
string temp;
string blank="_";

for(i=0;i<9;++i){

if(i%3==0)  //判断打印宫分隔线或行分隔线
cout<<"\033[92;1m"<<END2<<endl;
else
cout<<"\033[0;90m"<<END1<<endl; 



  for(j=0;j<9;++j){

     if(j%3==0)
        cout<<"\033[92;1m"<<"┊";//打印数字间的分隔符
     else
        cout<<"︲";

//先调用随机数生成函数，得到0~80里哪些数需要挖空
//而且，9不能挖空
//开局打印棋盘时，完成数字到二进制的转化
        value = InitNumbers[i][j];
	temp = Binary[value-1];
//      if(blank(i,j))  blank函数名未定义，可更改。判断该数是否要挖空 
//如果这个数要挖空，再调用随机数生成函数，得到1~3位里哪几个位要挖空
//如010挖空为_1_,则 Numbers[i][j].bit1 = blank; bit3=blank;  blank为"_"
//且原本的010不需要存储，已设计遍历判断函数，后续根据一位是否为"_"来确定能否输入一个数


/*      else { // 不挖空则进行计数，每行、列非空的数加1
        ++ROWCnt[i-1];
        ++COLCnt[j-1];
        PALnum=PalaceNum(i,j);
        ++PALCnt[PALnum-1];
       }
*/
 
        for(k=0;k<3;++k){

           Numbers[i][j].bit[k]=temp[k];
           cout<<"\033[92;1m"<<Numbers[i][j].bit[k];
        }

   }//第二层循环结束

cout<<"\033[92;1m"<<"┊";//打印右边界的分隔符

if(ROWCnt[i]==9)//代表第i行全填满
   cout<<"\033[1;92m"<<ROWeffect[i]<<endl;//01串被点亮
else
   cout<<"\033[0;90m"<<ROWeffect[i]<<endl;//打印灰色01串



}
//第一层循环结束，棋盘打印结束
//接着打印列特效和宫特效
cout<<"\033[92;1m"<<END2<<endl;


for(i=0;i<5;++i){

  for(j=0;j<9;++j){
  
     if(COLCnt[j]==9)
       cout<<"\033[1;92m"<<COLeffect[i][j];
     else
       cout<<"\033[1;90m"<<COLeffect[i][j];

  }
  cout<<PALeffect[i][0]<<PALeffect[i][1]<<PALeffect[i][2]<<endl;

}//打印完成



return 0;
}




//一个从坐标得到第几宫的小函数
int PalaceNum(int& _row,int& _col){
     int a=_row/3+1;
     int b=_col/3+1;
     return (a-1)*3+b;//宫的标号为1~9
}

void Check(void){
//待实现
}












