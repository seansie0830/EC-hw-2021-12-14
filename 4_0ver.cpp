#include<iostream>
#include<windows.h>
#include <conio.h>
using namespace std;
void display(void);
void writeMarks(void);
int judge(void);
int player=-1 ;  //1代表O -1代表X
int map[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int reference[9]={6,7,8,3,4,5,0,1,2};//map的編號
int main (){
    display();
    cout<<"-----------------------------------"<<endl;
    cout<<"the following is the result of input."<<endl;
    while(1){
        writeMarks();
        display();
    }
    return 0;
}
void display(void){
    system("cls");

    for (int i=0;i<3 ;i++ )
    {
        for (int j=0;j<3 ;j++ )
        {
            // 1代表O  -1代表X  0代表空格  其他是 ?
            if(map[i][j]==1) cout<<" o ";
            else if (map[i][j]==-1) cout<<" x ";
            else if(map[i][j]==0) cout<<"   ";
            else if (map[i][j]==-1) cout<<" * ";//for debug only
            else cout<<" ? ";
            if(j<2)cout<<"|";
        }
        cout<<endl;
        if(i<2)cout<<"-----------\n";
    }
}
int judge(){
    
}
void writeMarks(void){
    char temp;
    int number,goal;
    int *pointer=&map[0][0];
    temp=getch();
    number=temp;
    if(!(number<58&&number>48)) {
        cout<<"目洨喔!按數字鍵聽不懂喔"<<endl;
        system("pause");
        return ;
    }
    cout<<"\"for debug use\" you entered key no."<<number<<endl;

    if(*(pointer+reference[number-49])==0){
        player=player*(-1);
        *(pointer+reference[number-49])=player;
    }
    else
    {
        cout<<"木小喔!已經下過了";
        return ;
    }
    cout<<"The program has change the value number"<<reference[number-49]+1<<endl;
    system("pause");
    /*
    -----------------------------------
    the following is the result of input.
    1"for debug use" you entered key no.49
    2"for debug use" you entered key no.50
    3"for debug use" you entered key no.51
    4"for debug use" you entered key no.52
    5"for debug use" you entered key no.53
    6"for debug use" you entered key no.54
    7"for debug use" you entered key no.55
    8"for debug use" you entered key no.56
    9"for debug use" you entered key no.57
    conclusion: key value in windows is as ASCLL
    relation between key value and array index
    1->7
    2->8
    3->9
    4->4
    5->5
    6->6
    7->1
    8->2
    9->3
    */
}
