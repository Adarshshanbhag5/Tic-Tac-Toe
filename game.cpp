#include<iostream>
using namespace std;
string board[9]={" "," "," "," "," "," "," "," "," "};
int player=1;
int position=0;
char name1[10],name2[10];
class game{
// private:
public:
void intro();
bool isWinner();
bool filledUp();
void draw();
void setPos();
void updateBoard();
void changePlayer();
void takeTurn();
void endGame();
};

void game::intro(){
    cout<<"Press enter to begin\n";
    getchar();
    cout<<"\n";
    cout<<"\n";
    cout<<"***********\n";
    cout<<"Tic-Tac-Toe\n";
    cout<<"***********\n";
    cout<<"Player 1) X\n";
    cout<<"Player 2) O\n";
    cout<<"The 3X3 grid is shown below:\n\n";

    cout<<"     |     |      \n";
    cout<<"  1  |  2  |  3   \n";
    cout<<"_____|_____|_____ \n";
    cout<<"     |     |      \n";
    cout<<"  4  |  5  |  6   \n";
    cout<<"_____|_____|_____ \n";
    cout<<"     |     |      \n";
    cout<<"  7  |  8  |  9   \n";
    cout<<"     |     |      \n\n";
    cout<<"Enter player 1's name:";
    cin.getline(name1,10);
    cout<<"Enter player 2's name:";
    cin.getline(name2,10);
    cout<<"Player 1 is:";
    cout.write(name1,10);
    cout<<"\n";
    cout<<"Player 2 is:";
    cout.write(name2,10);
    cout<<"\n";

}

bool game::isWinner(){
    bool winner=false;
    //cheking row
    if((board[0]==board[1])&&(board[1]==board[2]&&board[0]!=" "))
    {
    winner=true;
    }
    else if((board[3]==board[4])&&(board[4]==board[5]&&board[3]!=" "))
    {
    winner=true;
    }
    else if((board[6]==board[7])&&(board[7]==board[8]&&board[6]!=" "))
    {
    winner=true;
    }
    else if((board[0]==board[3])&&(board[3]==board[6]&&board[0]!=" "))
    {
    winner=true;
    }
    else if((board[1]==board[4])&&(board[4]==board[7]&&board[1]!=" "))
    {
    winner=true;
    }
    else if((board[2]==board[5])&&(board[5]==board[8]&&board[2]!=" "))
    {
    winner=true;
    }
    else if((board[0]==board[4])&&(board[4]==board[8]&&board[0]!=" "))
    {
    winner=true;
    }
    else if((board[2]==board[4])&&(board[4]==board[6]&&board[2]!=" "))
    {
    winner=true;
    }
    return winner;
}

bool game::filledUp(){
    bool filled=true;
    for(int i=0;i<9;i++){
        if(board[i]==" "){
            filled=false;
        }
    }
    return filled;
}
void game::draw(){
    cout<<"     |     |      \n";
    cout<<"  "<<board[0]<<"  |  "<<board[1]<<"  |  "<<board[2]<<"   "<<"\n";
    cout<<"_____|_____|_____ \n";
    cout<<"     |     |      \n";
    cout<<"  "<<board[3]<<"  |  "<<board[4]<<"  |  "<<board[5]<<"   "<<"\n";
    cout<<"_____|_____|_____ \n";
    cout<<"     |     |      \n";
    cout<<"  "<<board[6]<<"  |  "<<board[7]<<"  |  "<<board[8]<<"   "<<"\n";
    cout<<"     |     |      \n";
    cout<<"\n";
}

void game::setPos(){
    label:
    cout<<"Player "<<player<<"'s Turn Enter(1-9):";
    cin>>position;
    if((position<1) || (position>9)){
        cout<<"Oops you choosed wrong position\nplease enter valid position\n";
        position=0;
        goto label;
    }
    while(board[position-1]!=" "){
        cout<<"Oops, that position is already filled\nTry again\n";
        cout<<"Player "<<player<<"'s Turn Enter(1-9):";
        cin>>position;
        cout<<"\n";
    }
}

void game::updateBoard(){
    if(player%2==1){
        board[position-1]="X";
    }
    else{
        board[position-1]="O";
    }
}

void game::changePlayer(){
    if(player==1){
        player++;
    }
    else{
        player--;
    }
}

void game::takeTurn(){
    while((!isWinner())&&(!filledUp())){
        setPos();
        updateBoard();
        changePlayer();
        draw();
    }
}

void game::endGame(){
    if(isWinner()){
        cout<<"There is a winner"<<endl;
        if(player==2){ //because we incremented player++ in changePlayer function(See changePlayer function)..
        cout<<"Winner is:";
        cout.write(name1,10);
        cout<<"\n";
        }
        else{
            cout<<"Winner is:";
            cout.write(name2,10);
            cout<<"\n";
        }
    }
    else if(filledUp()){
        cout<<"There is a tie!"<<endl;
    }
}

int main(){
    game g1,g2,g3;
    g1.intro();
    g2.takeTurn();
    g3.endGame();
    return 0;
}