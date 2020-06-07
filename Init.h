#ifndef _INIT_H_
#define _INIT_H_
#include <string>
#include <unistd.h>
#include<ctime>
#include<cstdlib>

using namespace::std;

class Init
{
public:
Init(void);
void Proc(int& deg);

private:

        int table[9][9];
	string Binary[9] = { "000","001","010","011","100","101","110","111","---" };//将数字转换为1个二进制数
//将1个二进制数分3位存储,同时记录这一位能否被擦除
int InitNumbers[6][9][9]={{{2,8,3,6,4,5,9,7,1},
			{7,5,4,9,3,1,8,2,6},
			{6,1,9,7,8,2,3,4,5},
			{3,2,6,5,1,8,4,9,7},
			{1,4,7,2,6,9,5,8,3},
			{8,9,5,4,7,3,6,1,2},
			{5,7,8,3,2,4,1,6,9},
			{9,6,1,8,5,7,2,3,4},
			{4,3,2,1,9,6,7,5,8}},
		      {{1,5,3,8,9,2,6,7,4},
                      {8,6,2,7,1,4,9,3,5},
                      {9,7,4,3,6,5,2,8,1},
                      {2,3,5,9,7,6,1,4,8},
                      {6,1,7,4,3,8,5,9,2},
                      {4,8,9,5,2,1,7,6,3},
                      {5,9,1,6,4,3,8,2,7},
                      {3,2,8,1,5,9,4,1,6},
                      {7,4,6,2,8,7,3,5,9}},
			{{9,6,2,8,4,1,3,7,5},
                        {7,8,5,3,2,6,1,4,9},
                        {4,1,3,5,7,9,6,2,8},
                        {3,7,6,1,5,4,8,9,2},
                        {5,9,8,7,3,2,4,1,6},
                        {1,2,4,9,6,8,7,5,3},
                        {6,4,9,2,8,7,5,3,1},
                        {8,5,1,4,9,3,2,6,7},
                        {2,3,7,6,1,5,9,8,4}},
		      {{7,3,5,6,2,8,1,9,4},
                      {1,6,2,9,7,4,3,5,8},
                      {4,8,9,5,3,1,7,6,2},
                      {3,2,7,4,1,6,5,8,9},
                      {6,9,8,2,5,3,4,1,7},
                      {5,4,1,7,8,9,2,3,6},
                      {7,9,3,8,4,5,6,2,1},
                      {8,1,4,3,6,2,9,7,5},
                      {2,5,6,1,9,7,8,4,3}},
		       {{8,5,7,1,4,9,3,2,6},
                       {9,1,2,6,8,3,5,7,4},
                       {4,3,6,5,7,2,8,9,1},
                       {2,4,5,9,6,8,7,1,3},
                       {1,7,8,3,5,4,9,6,2},
                       {6,9,3,7,2,1,4,8,5},
                       {7,8,4,2,3,6,1,5,9},
                       {5,2,1,4,9,7,6,3,8},
                       {3,6,9,8,1,5,2,4,7}},
		      {{1,4,3,8,7,5,6,2,9},
                      {8,2,7,3,6,9,4,1,5},
                      {5,9,6,4,1,2,8,3,7},
                      {9,6,2,5,8,3,7,4,1},
                      {3,7,1,2,4,6,9,5,8},
                      {4,8,5,7,9,1,3,6,2},
                      {2,3,8,9,5,4,1,7,6},
                      {6,5,9,1,3,7,2,8,4},
                      {7,1,4,6,2,8,5,9,3}}};

};
#endif






