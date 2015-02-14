#include <iostream>
#include <windows.h>
#include<cstdlib>
#include <ctime>
#include<vector>

using namespace std;
void update(int L);
char border[2][20] ={"===================","                   "};
char map[10][20] = {            // this is the map. 
    "###################",
    "#@                #",
    "#                 #",
    "#                 #",
    "#      *          #",
    "#                 #",
    "#                 #",
    "#                 #",
    "###################"
};

int xf=1;
int yf=1;
int xl=1;
int yl=1;
int a=1;
int d=2;
int xF=7;
int yF=4;
int BodyLength=1;
    vector<int>ordery(BodyLength,1); //initializes the storage vectors which will record the location of each element in the snake body.
    vector<int>orderx(BodyLength,1);
int foodl(int max){ // this function returns a random location for the map to put the food.
     srand(time(0));
     int x; 
     x = 1+rand()%max;
     return x;
     }
          
bool game_running = true;
int getsync();

int main()
{   

    cout<<"welcome to snake!"<<endl<<endl;
    system("pause");
    system("cls");
    cout<<"use the arrow keys to move"<<endl<<endl;
    system("pause");
    while(game_running == true){
                       char map[10][20] = {            // this is the map. 
    "###################",
    "#@                #",
    "#                 #",
    "#                 #",
    "#      *          #",
    "#                 #",
    "#                 #",
    "#                 #",
    "###################"
};
while(BodyLength>1){
                    ordery.pop_back();
                    orderx.pop_back();
                    BodyLength--;
                    }
yf=1;
xf=1;                    
ordery[0]=yf;
orderx[0]=xf;
int a=1;
int d=2; 
int xF=7;
int yF=4;                  
    while(game_running == true){
        system("cls");
        for(int display=0;display<2;display++){cout<<border[display]<<endl;};
        for(int display=0; display<10; display++){
            cout << map[display] << endl;
        }
        cout<<"    score:"<<(6*(BodyLength-1))<<endl;
        for(int display=0;display<2;display++){cout<<border[display]<<endl;};
          if(map[yF][xF] != '*')            //the map is tested to see if the food is still at it's location. if it is not, 
        {                                   // then a new food must be droped. the foodl function is called to produce a new location for the food.
                       do{
                               yF = foodl(8);
                               xF = foodl(18);
                               
                               
                          }while(map[yF][xF]!=' ');
        map[yF][xF]='*';        
        }
        Sleep(100);
        a=getsync();
        
        switch(a){                      //the following swicth  structure controls the movement and the growth of the snake.
         
        case 2: 
            { if(map[yf+1][xf]==' '){
                       yf++;
                       update(BodyLength);
                       map[yf][xf]='@';
                       map[yl][xl]=' '; 
                       }
     if(map[yf+1][xf]=='*'){
                        BodyLength++;    
                        ordery.push_back(yf);
                        orderx.push_back(xf);
                           
                        yf++;
                       update(BodyLength);
                        
                       map[yf][xf]='@';                       
            }
            if((map[yf+1][xf]=='#'||map[yf+1][xf]=='@')&&(d!=8||a!=8)&&(a==2)) {d=0;}
            }d=a;
            break;                
        case 8:
        {if(map[yf-1][xf]==' '){
                       yf--;
                       update(BodyLength);
                       map[yf][xf]='@';
                       map[yl][xl]=' ';
                      
                       }
   if(map[yf-1][xf]=='*'){
                        yf--;
                        BodyLength++;
                        ordery.push_back(yf);
                        orderx.push_back(xf);
                        update(BodyLength);
                       map[yf][xf]='@';
                       }
   if((map[yf-1][xf]=='#'||map[yf-1][xf]=='@')&&(d!=2||a!=2)&&(a==8)) {d=0;}                    
        d=a;
        }break;

        case 6:{if(map[yf][xf+1]==' '){
                       xf++;
                       update(BodyLength);
                       map[yf][xf]='@';
                       map[yl][xl]=' ';
                       }
                if(map[yf][xf+1]=='*'){
                        xf++;
                        BodyLength++;
                        ordery.push_back(yf);
                        orderx.push_back(xf);
                        update(BodyLength);
                       map[yf][xf]='@';
                        
                      }
        if((map[yf][xf+1]=='#'||map[yf][xf+1]=='@')&&(d!=4||a!=4)&&(a==6)) {d=0;}              
        d=a;
        }break;

        case 4:{
            
            if(map[yf][xf-1]==' '){
                       xf--;
                       update(BodyLength);
                       map[yf][xf]='@';
                       map[yl][xl]=' ';
                       
                       
                       }
   if(map[yf][xf-1]=='*'){
                        xf--;
                        BodyLength++;
                         ordery.push_back(yf);
                        orderx.push_back(xf);
                         update(BodyLength);
                       map[yf][xf]='@';
                       
            }
            if((map[yf][xf-1]=='#'||map[yf][xf-1]=='@')&&(d!=6||a!=6)&&(a==4)){d=0;} 
            
            d=a;
        }break;
        case 1:{
             
             switch (d){
                 case 0:{ game_running=false;} break;   
                 case 2: 
            {
            if(map[yf+1][xf]==' '){
                       yf++;
                       update(BodyLength);
                       map[yf][xf]='@';
                       map[yl][xl]=' ';
                       
                       }
     if(map[yf+1][xf]=='*'){
                        BodyLength++;    
                        ordery.push_back(yf);
                        orderx.push_back(xf);
                           
                        yf++;
                       update(BodyLength);
                        
                       map[yf][xf]='@';
            }
            if((map[yf+1][xf]=='#'||map[yf+1][xf]=='@')&&(d!=8||a!=8)&&(d==2||a==2)) {d=0;}
            }
            break;
        
        
                  case 8:{                  
                    if(map[yf-1][xf]==' '){
                       yf--;
                       update(BodyLength);
                       map[yf][xf]='@';
                       map[yl][xl]=' ';
                      
                       }
   if(map[yf-1][xf]=='*'){
                        yf--;
                        BodyLength++;
                        ordery.push_back(yf);
                        orderx.push_back(xf);
                        update(BodyLength);
                       map[yf][xf]='@';}
            if((map[yf-1][xf]=='#'||map[yf-1][xf]=='@')&&(d!=2||a!=2)&&(d==8||a==8)) {d=0;}
                  }break;

                  case 6:{
            
                     if(map[yf][xf+1]==' '){
                       xf++;
                       update(BodyLength);
                       map[yf][xf]='@';
                       map[yl][xl]=' ';
                       }
    if(map[yf][xf+1]=='*'){
                        xf++;
                        BodyLength++;
                        ordery.push_back(yf);
                        orderx.push_back(xf);
                        update(BodyLength);
                       map[yf][xf]='@';
                                          }
    if((map[yf][xf+1]=='#'||map[yf][xf+1]=='@')&& (d!=4||a!=4)&&(d==6||a==6)) {d=0;}                                       
                    }break;

                    case 4:{
                        
                         if(map[yf][xf-1]==' '){
                       xf--;
                       update(BodyLength);
                       map[yf][xf]='@';
                       map[yl][xl]=' ';
                       
                       
                       }
   if(map[yf][xf-1]=='*'){
                        xf--;
                        BodyLength++;
                         ordery.push_back(yf);
                        orderx.push_back(xf);
                         update(BodyLength);
                       map[yf][xf]='@';
                        }
    if((map[yf][xf-1]=='#'||map[yf][xf-1]=='@')&&(d!=6||a!=6)&&(d==4||a==4)){ d=0;}                    
                    }break;
            }
            
            }break;
                   
        }  
        
        
        if(GetAsyncKeyState(VK_ESCAPE)){
            game_running = false;
        }
    }
    system("cls");
    cout << "GAME OVER"<<endl<<endl<<endl<<endl<<endl;
    cout<<"your score:"<<(6*(BodyLength-1))<<endl<<endl<<endl;
    cout<<"do you want to play again? y or n."<<endl<<endl;
    char answer= 'n';
    cin>> answer;
    cout<<endl;
    if(answer=='y'||answer=='Y'){game_running=true;}
    if(answer!='y'&& answer!='Y'){ game_running = false;}
    system("cls");
    
    
    
}
system("clc");
    return 0;
}
int getsync(){                       //gets a the key state and assigns an integer for case switch
    int q=0;
    if(GetAsyncKeyState(VK_DOWN))q=2;
    if(GetAsyncKeyState(VK_UP)) q = 8;
    if(GetAsyncKeyState(VK_LEFT)) q = 4;
    if(GetAsyncKeyState(VK_RIGHT)) q = 6;
    if(!(GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState(VK_UP)||GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState(VK_RIGHT))) q=1;
    
    return q; 
    }
void update(int L){                 //this updates the storage vectors ordery and oderx.
     int index = L-1;
     ordery.push_back(ordery[index]);
     orderx.push_back(orderx[index]);
     for(int i=index;i>0;i--){
               if(i>0){
                        ordery[i]=ordery[i-1];
                        orderx[i]=orderx[i-1];
                        }
     }         
     ordery[0]=yf;
     orderx[0]=xf;
     yl=ordery[L];
     xl=orderx[L];
     ordery.pop_back();
     orderx.pop_back();
} 
     
