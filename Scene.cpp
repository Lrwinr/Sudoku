#include "Scene.h"


int Scene::Print()
{
printf("\033[1;1H");

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

     for(k=0;k<3;++k){
     cout<<"\033[92;1m"<<Numbers[i][j].bit[k];

     sleep (0.5);

        }


   }//第二层循环结束

cout<<"\033[92;1m"<<"┊";//打印右边界的分隔符

cout<<"\033[0;90m"<<ROWeffect[i]<<endl;//打印灰色01串
}

//棋盘打印结束
//接着打印列特效和宫特效
cout<<"\033[92;1m"<<END2<<endl;


for(i=0;i<5;++i){

  for(j=0;j<9;++j){
  
       cout<<"\033[0;90m"<<COLeffect[i][j];

  }
  cout<<PALeffect[i][0]<<PALeffect[i][1]<<PALeffect[i][2]<<endl;

}//打印完成



return 0;
}




int Scene::Draw(){


int draw[7][54]={ 
{3,4,5,6,10,11,17,18,20,21,22,30,31,33,34,38,39,42,43,45,46,52,53},
{1,2,7,8,10,18,20,23,24,29,35,38,42,45,53},
{1,10,18,20,25,26,28,36,38,40,41,45,53},
{2,3,4,5,6,7,10,18,20,26,28,36,38,39,45,53},
{8,10,18,20,25,26,28,36,38,40,41,45,53},
{1,2,7,8,10,11,17,18,20,23,24,29,35,38,42,45,46,52,53},
{3,4,5,6,12,13,14,15,16,20,21,22,30,31,33,34,38,39,42,43,47,48,49,50,51}};
//绘制SUDUKO图案作为交互界面的背景


for(i=0;i<7;++i){
   for(j=0;j<54;++j){
       if(!draw[i][j])
       break;
       else
       temp=draw[i][j];
       UIscene[i+2][temp-1]='1';
   }
}

for(i=0;i<18;++i){
   for(j=0;j<54;++j){
       if(UIscene[i][j]=='1')
       cout<<"\033[1;92m"<<'1';
       else
       cout<<"\033[0;90m"<<'0';
   }
cout<<endl;
}


return 0;
}



void Scene::GameBegin(){

for(i=0;i<18;++i){
   for(j=0;j<54;++j){

       cout<<"\033[0;90m"<<'0';
       sleep (0.1);

   }

cout<<endl;
}

printf("\033[1;1H");

Draw();

string Help[3]={"0000000000000000000000W0A0S0D0000000000000000000000000",
                "00000000000000000000000Space00000000000000000000000000",
                "00000000000000000000000J0K0L00000000000000000000000000"};

string tempstr;
for(int i=0;i<3;i++){
    printf("\033[%d;1H",i+13);
    tempstr=Help[i];
    for(int j=0;j<54;j++){
         if(tempstr[j]=='0')
         cout<<"\033[0;90m";
         else
         cout<<"\033[1;92m";
         
         cout<<tempstr[j];
    }

}
printf("\033[1;1H");

}
            
void Scene::Select(){

printf("\033[1;1H");

Draw();

string Choice[4]={"00","01","10","11"};

for(int i=0;i<4;++i){
        string CHAR=Choice[i];
        printf("\033[%d;%dH",12+i,26);
        cout<<"\033[1;92m"<<CHAR[0]<<"\033[0;90m0"<<"\033[1;92m"<<CHAR[1];
}

printf("\033[%d;%dH",12,24);

}




void Scene::GameWin(int& IDX){

printf("\033[1;1H");

for(i=0;i<16;++i){
   for(j=0;j<54;++j){

       cout<<"\033[1;92m"<<'0';
       sleep (0.1);

   }

cout<<endl;
}

printf("\033[1;1H");

Draw();

string Hint="00000000000000000000Y0O0U000W0O0N0!0000000000000000000";


printf("\033[15;1H");

    for(int i=0;i<54;++i){
         if(Hint[i]=='0')
         cout<<"\033[0;90m";
         else
         cout<<"\033[1;92m";
         
         cout<<Hint[i];
    }

string Pity="000000000000000000W0i0t0h00A00B0u0g0!000000000000000000";
string Bonus= "00000000000000000000P0e0r0f0e0c0t0!0000000000000000000";

printf("\033[16;1H");

if(IDX==3)
   Hint=Bonus;
else
   Hint=Pity;

    for(int i=0;i<54;++i){
         if(Hint[i]=='0')
         cout<<"\033[0;90m";
         else
         cout<<"\033[1;92m";
         
         cout<<Hint[i];
    }

printf("\033[1;1H");

}




