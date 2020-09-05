#include<iostream>
#include<stdio.h>

using namespace std;

bool canPlaceQueen(int board[][10], int i, int j, int n) {

    // Check for all rows in same column before current row
    for(int row=0;row<i;row++) {
        if(board[row][j] == 1) {
            return false;
        }
    }

    // Check for left diagnol
    int x=i;
    int y=j;
    while(x>=0 && y>=0) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    // Check for left diagnol
    x=i;
    y=j;
    while(x>=0 && y>=0) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    // Check for right diagnol
    x=i;
    y=j;
    while(x>=0 && y<n) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y++;
    }

    // safe to place
    return true;
}

bool solveNQueensProblems(int board[][10], int i, int n) {

    // Base Case - Problem Solved
    if(i==n) {
        //Placed all queens succesfully on board and print the board
        for(int a=0;a<n;a++) {
            for(int b=0; b<n; b++) {
                cout<<board[a][b];
            }
            cout<<"\n";
        }
        // Problem Solved
        // To print all possible combinations return false
        return true;
    }
    
    // Loop through all columns and check if it is safe to place queen a given row i
    for(int j=0; j<n; j++) {
        if(canPlaceQueen(board, i, j, n)) {
            board[i][j]=1;
            // If it is safe to place go to next row
            bool result = solveNQueensProblems(board, i+1, n);
            if(result==true) {
                return true;
            }
            else {
                // If it is not backtrack and remove the queen from that cell, and find another position
                board[i][j]=0;
            }
        }
    }
    return false;

}

int main() {
    int n;
    cin>>n;
    int board[10][10] = {0};
    solveNQueensProblems(board, 0 ,n);
}
