#include<iostream>
using namespace std;

bool isDraw(char box[3][3]){
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
        if (box[i][j]==' ')
        return false;
        }
    }
    return true;
}


bool ifWon(char box[3][3], char currPlayer){
    for (int i=0;i<3;i++){
        if (box[i][0]==currPlayer && box[i][1]==currPlayer && box[i][2]==currPlayer)
            return true;
        if (box[0][i]==currPlayer && box[1][i]==currPlayer && box[2][i]==currPlayer)
            return true;
    }
    if (box[0][0]==currPlayer && box[1][1]==currPlayer && box[2][2]==currPlayer)
    return true;
    if (box[2][0]==currPlayer && box[1][1]==currPlayer && box[0][2]==currPlayer)
    return true;

    return false;
}

void printBoard(char box[3][3]){
for (int i=0;i<3;i++){
    for (int j=0;j<2;j++){
        cout<<box[i][j]<<"|";
    }
    cout<<box[i][2]<<"\n";
    if(i!=2){
    cout<<"------"<<"\n";
    }
}
}

void resetBoard(char box[3][3]){
for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
        box[i][j]=' ';
    }
}
}

int main(){
    int row,col;
    char currPlayer='X';
    int oscore=0,xscore=0;
    char box[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    cout<<"Tic tac toe\n";
    for (int round=1;round<5;round++){
        resetBoard(box);
        currPlayer = 'X';
        cout << "\nRound "<<round<<"\n";
        while(true)
        {
        printBoard(box);
        cout<<"Player "<< currPlayer <<" Enter the row and column number (0 to 2) ";
        cin>>row>>col;

            if (row>2 || row<0 || col>2 || col<0){
                cout<<"Error, try again"<<"\n";
                currPlayer = (currPlayer == 'X') ? 'O' : 'X';
            }
            else{
                if (box[row][col]==' ')
                box[row][col]= currPlayer;
                else{
                cout<<"Error, try again"<<"\n";
                currPlayer = (currPlayer == 'X') ? 'O' : 'X';
                }
            }

            if (ifWon(box,currPlayer)){
                printBoard(box);
                cout<<"Player "<<currPlayer<<" won";
            if (currPlayer=='X')
                xscore++;
            else
                oscore++;
            break;
            }

            if (isDraw(box)){
                printBoard(box);
                cout<<"It is a draw!!";
                break;
            }
        currPlayer=(currPlayer=='X')?'O':'X';
        }
        }

    cout<<"\nThe scores are: \n";
    cout<<"X won: "<<xscore;
    cout<<" O won: "<<oscore;

    if (xscore>oscore)
        cout<<"X is the winner!!";
    else if (xscore<oscore)
        cout<<"O is the winner!!";
    else
        cout<<"Its a draw!!";

    return 0;
}
