#include <iostream>
using namespace std;

class BOARD {
private:
   int board[8][8];
  public:
    void start ();
    void print();
 friend class PLAYER;
};
//______________________________________________________________________________________________________________________________________

void BOARD::start ()
{
  for( int i=1; i<9 ; i++)
      for( int j=1; j<9 ; j++)
        board[i][j]=0;
//-------------------------------------------------------------------white
  board[1][1]= board[1][8]=15;
  board[1][2]= board[1][7]=13;
  board[1][3]= board[1][6]=14;
  board[1][4]=100;
  board[1][5]=1000;
  board[2][1]=board[2][2]=board[2][3]=board[2][4]=board[2][5]=board[2][6]=board[2][7]=board[2][8]=11 ;
//-------------------------------------------------------------------Black
  board[8][1]= board[8][8]=25;
  board[8][2]= board[8][7]=23;
  board[8][3]= board[8][6]=24;
  board[8][4]=200;
  board[8][5]=2000;
  board[7][1]=board[7][2]=board[7][3]=board[7][4]=board[7][5]=board[7][6]=board[7][7]=board[7][8]=21 ;
}

//_______________________________________________________________________________________________________________________________________
void BOARD::print ()
{

  cout<<"   "<<" A "<<" "<<" B "<<" "<<" C "<<" "<<" D "<<" "<<" E "<<" "<<" F "<<" "<<" G "<<" "<<" H "<<endl;
       cout<<"------------------------------------"<<endl;
  for( int i=1; i<9 ; i++)
     {  cout<<i<<"| ";
      for( int j=1; j<9 ; j++)
          {
        if (board[i][j]==0) {cout<<" "<<"  "<<" ";};
//-------------------------------------------------------------------white
       if (board[i][j]==11) {cout<<"(p)"<<" ";}
       if (board[i][j]==15) {cout<<"(r)"<<" ";}
       if (board[i][j]==13) {cout<<"(k)"<<" ";}
       if (board[i][j]==14) {cout<<"(b)"<<" ";}
       if (board[i][j]==100) {cout<<"(Q)"<<" ";}
       if (board[i][j]==1000) {cout<<"(+)"<<" ";}
//-------------------------------------------------------------------Black
       if (board[i][j]==21) {cout<<"{p}"<<" ";}
       if (board[i][j]==25) {cout<<"{r}"<<" ";}
       if (board[i][j]==23) {cout<<"{k}"<<" ";}
       if (board[i][j]==24) {cout<<"{b}"<<" ";}
       if (board[i][j]==200) {cout<<"{Q}"<<" ";}
       if (board[i][j]==2000) {cout<<"{+}"<<" ";}
      }
       cout<<"|"<<i<<endl<<"-------------------------------------"<<endl;
     }
cout<<"   "<<" A "<<" "<<" B "<<" "<<" C "<<" "<<" D "<<" "<<" E "<<" "<<" F "<<" "<<" G "<<" "<<" H "<<endl;
}

//____________________________________________________________________________________________________________________________
class PLAYER
{private:

 public:
 void GO(BOARD& ys){ ys.board[5][6]=15;};
 void From(BOARD& ys) { int i,j,a,b;cout<<"from";cin>>i>>j;cout<<"to";cin>>a>>b ; ys.board[a][b]=ys.board[i][j];ys.board[i][j]=0;};
};


int main () {
  BOARD game;
  PLAYER gamer;
  game.start ();
  game.print();
  gamer.GO(game);
  gamer.From(game);
  game.print();
  return 0;
}
