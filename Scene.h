#ifndef _SCENE_H_
#define _SCENE_H_
#include <iostream>
#include <string>
#include <unistd.h>
#include "Input.h"
using namespace::std;


class Scene
{
friend class Algo;

private:
string END1="1001110001101111010010101001 1010011100011            ";//行分隔线
string END2=" ╌╌┅┅╌┅┅╌┅┅┅╌╌ ╌╌┅┅╌┅┅╌┅┅┅╌╌ ┅╌╌┅┅╌┅┅╌┅┅┅╌╌             ";//宫分隔线


string ROWeffect[9]={"1          ","10         ","011        ","010 0      ","001 01     ",
"000 110    ","000 011 1  ","000 010 00 ","000 001 001"};//行特效，一行填满后点亮


string COLeffect[5][9]={{" 001︲","010︲","011 ","100︲","101︲","110 ","111︲","000︲","001 "},
                        {"      ","     ","    ","   ︲","   ︲","    ","   ︲","   ︲","    "},
                        {"      ","     ","    ","000︲","000︲","000 ","000︲","001︲","001 "},
                        {"      ","     ","    ","     ","     ","    ","   ︲","   ︲","    "},
                        {"      ","     ","    ","     ","     ","    ","000︲","000︲","000 "}}; //以下同上，对列和宫



string PALeffect[5][3]={{"000 ","001 ","010 "},
                        {"000 ","000 ","000 "},
                        {"011 ","100 ","101 "},                          
                        {"000 ","000 ","000 "},
                        {"110 ","111 ","--- "}};//

int i,j,k,temp;
char UIscene[18][54]={'0'};

int Draw();


public:
int Print();
void GameBegin();
void Select();
void GameWin(int& IDX);


};
#endif

