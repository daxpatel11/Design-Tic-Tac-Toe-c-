#include <bits/stdc++.h>

using namespace std;


char board[3][3];
vector<int> moves;

void initialise(){
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        board[i][j]='.';
    }
    for(int i=0;i<9;i++)
    moves.push_back(i);
    
    random_shuffle(moves.begin(),moves.end());
   
}

bool rowCrossed()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0] ==board[i][1] && board[i][1]==board[i][2] && board[i][0]!='.')
        return true;
    }
    return false;
}

bool columnCrossed()
{
    for(int i=0;i<3;i++)
    {
        if(board[0][i] ==board[1][i] && board[1][i]==board[2][i] && board[i][0]!='.' )
        return true;
    }
    return false;
}

bool diagonalCrossed(){
     
    if(board[0][0] == board[1][1] && board[1][1]==board[2][2]  && board[0][0] !='.')
    return true;
     if(board[0][2] == board[1][1] && board[1][1]==board[2][0]  && board[0][2] !='.')
    return true;
    return false;
}

bool GameOver(){
    if(rowCrossed() || columnCrossed() || diagonalCrossed())
    return true;
    return false;
}
void showboard(){
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        cout<<board[i][j]<<" ";
        cout<<"\n";
    }
}

void playGame(string turn)
{
    initialise();
    showboard();
    // cout<<GameOver()<<"\n";
    int moveindex=0;
    int x,y;
    while(GameOver()==false)
    {
        if(turn=="COMPUTER")
        {
            x = moves[moveindex]/3;
            y = moves[moveindex]%3;
            board[x][y]= '0';
            cout<<"computer put 0 at position ("<<x<<"," << y<<")\n";
            showboard();
            moveindex++;
            turn = "HUMAN";
        }
        else
        {
            x = moves[moveindex]/3;
            y = moves[moveindex]%3;
            board[x][y]= 'X';
            cout<<"Human put X at position ("<<x<<"," << y<<")\n";
            showboard();
            moveindex++;
            turn = "COMPUTER";
        }
        
    }
    if(GameOver() == true && moveindex==9)
    {
        cout<<"it 's a draw\n";
    }
    else{
        if(turn=="COMPUTER")
        turn="HUMAN";
        else
        turn="COMPUTER";
        cout<<"Winner is "<<turn<<"\n";
    }
    return;
    
}



int main() {
   
   playGame("COMPUTER");
   
   
}
