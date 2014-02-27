#include <iostream>
#include <cstring>//չգիտեմ ինչու ա սա ստեղ
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

void BOARD::start ()//բոլոր քրերին տալիս ա արժեքներ ու դնում իրանց սկզբնական դիրքում
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

//____________________________________________________________________________________
void BOARD::print ()
{
  cout<<"   "<<" 1 "<<" "<<" 2 "<<" "<<" 3 "<<" "<<" 4 "<<" "<<" 5 "<<" "<<" 6 "<<" "<<" 7 "<<" "<<" H "<<endl;
  cout<<"   "<<" A "<<" "<<" B "<<" "<<" C "<<" "<<" D "<<" "<<" E "<<" "<<" F "<<" "<<" G "<<" "<<" H "<<endl;
       cout<<"------------------------------------"<<endl;
  for( int i=1; i<9 ; i++)
     { cout<<i<<"| ";
for( int j=1; j<9 ; j++)
          {
if (board[i][j]==0) {cout<<" "<<"  "<<"|";};
if (board[i][j]==1) {cout<<" * "<<"|";}
//-------------------------------------------------------------------white֊սպիտակներ
if (board[i][j]==11) {cout<<"(p)"<<"|";}//pawn―ինվոր 
if (board[i][j]==15) {cout<<"(R)"<<"|";}//Rook―
if (board[i][j]==13) {cout<<"(K)"<<"|";}//Knight―Ձի
if (board[i][j]==14) {cout<<"(B)"<<"|";}//Bishop
if (board[i][j]==100) {cout<<"(Q)"<<"|";}//Queen―Թագուհի
if (board[i][j]==1000) {cout<<"(+)"<<"|";}//King―Արքա
//-------------------------------------------------------------------Black֊Սևեր
if (board[i][j]==21) {cout<<"{p}"<<"|";}//pawn
if (board[i][j]==25) {cout<<"{R}"<<"|";} //Rook
if (board[i][j]==23) {cout<<"{K}"<<"|";}//Knight
if (board[i][j]==24) {cout<<"{B}"<<"|";}
if (board[i][j]==200) {cout<<"{Q}"<<"|";}
if (board[i][j]==2000) {cout<<"{+}"<<"|";}
}
       cout<<"|"<<i<<endl<<"-------------------------------------"<<endl;
     }
cout<<" "<<" A "<<" "<<" B "<<" "<<" C "<<" "<<" D "<<" "<<" E "<<" "<<" F "<<" "<<" G "<<" "<<" H "<<endl;
}

//_________________________________________________________________________________________
class PLAYER
{private:

 public:
 void GO(BOARD& ys){ ys.board[5][6]=15;};
 void Move(BOARD& ys)
{ 	int i,j,a,b;
	cout<<":from";
	cin>>i>>j;
	 if (ys.board[i][j]==11) {ys.board[i+1][j]=ys.board[i+2][j]=1;}; ys.print();
	cout<<"to";cin>>a>>b ;
	ys.board[a][b]=ys.board[i][j];
	ys.board[i][j]=0;
};
};


int main ()
{

  BOARD game;
  PLAYER gamer;
  game.start ();
  game.print();
// gamer.GO(game);
  for (int N=1 ; ;)
{
cout<<"Player"<<N<<endl;
gamer.Move(game);
game.print();
if (N==1){N++;}
else {N--;};
}
  return 0;
} 
	



