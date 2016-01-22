/* Evan Amstutz
 Diego J Rivera-Gutierrez
 COP3275
 This program prints the board for a minesweeper game
 I had trouble getting the char array to print the correct characters
 I was consistently getting ascii type characters*/
#include <stdio.h>
#include <stdlib.h>

//variable declaration
char board[9][9];
int i=0;
int j=0;
char columnChar='\0';
int seed=0;
int mineNum=0;
int row=0;
int column=0;
int mineCount=0;
int mineCountAtLocation=0;
int errorCheck;

//function declaration
int checkForMines(int, int);

int main(void)
{
   
    
    //user enters the seed number
    printf("Enter the seed: ");
    scanf("%i", &seed);
    getchar();
    
    srand(seed);
    
    //error checks for more mines than space on the board
    while(errorCheck==0)
    {
        //user enters number of mines
        printf("Enter the desired number of mines: ");
        scanf("%i", &mineNum);
        getchar();
        
        printf("%i\n", mineNum);
        
        if(mineNum>0 && mineNum<=81)
        {
            errorCheck=1;
        }
        else
        {
            errorCheck=0;
        }
    }
    printf("\n");
    
    //declares every element of the array as '_'
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            board[i][j]='_';
        }
    }
    
    //declares space of the mine
    for(i=0; i<mineNum; i++)
    {
        row=rand()%9;
        column=rand()%9;
        board[row][column]='@';
    }
    
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            mineCountAtLocation= checkForMines(i,j);
            if (mineCountAtLocation>=1 && board[i][j]!='@')
            {
                board[i][j]=(char)(mineCountAtLocation+48);
            }
        }
    }
    
    //prints A-I
    printf(" ");
    for(i=0; i<9; i++)
    {
        columnChar=(char)(i + 65);
        printf(" %c", columnChar);
    }
    printf("\n");
    
    //prints board with leading row number
    for(i=0; i<9; i++)
    {
        printf("%i ", i+1);
        for(j=0; j<9; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//checks for mine
int checkForMines(int row, int column)
{
    mineCount=0;
    if(board[row][column]=='_')
    {
        //top left
        if(board[(row-1)][(column-1)]=='@')
        {
            if ((column-1)>=0)
                mineCount++;
        }
        //top middle
        if(board[(row-1)][column]=='@')
        {
            mineCount++;
        }
        //top right
        if(board[(row-1)][(column+1)]=='@')
        {
            if((column+1)<=8)
                mineCount++;
        }
        //middle left
        if(board[row][(column-1)]=='@')
        {
            if ((column-1)>=0)
                mineCount++;
        }
        //middle right
        if(board[row][(column+1)]=='@')
        {
            if((column+1)<=8)
                mineCount++;
        }
        //bottom left
        if(board[(row+1)][(column-1)]=='@')
        {
            if ((column-1)>=0)
                mineCount++;
        }
        //bottom middle
        if(board[(row+1)][column]=='@')
        {
            mineCount++;
        }
        //bottom right
        if(board[(row+1)][(column+1)]=='@')
        {
            if((column+1)<=8)
                mineCount++;
        }
    }
    
    else
    {
        mineCount=0;
    }
    
    return mineCount;
}

