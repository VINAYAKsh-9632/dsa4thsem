#include<stdio.h>
char chess_board[8][8] = {
    {'E', 'H', 'B', 'Q', 'K', 'B', 'H', 'E'},///white
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},////black
    {'E', 'H', 'B', 'Q', 'K', 'B', 'H','E'}
};
void display_chess_board(char board[8][8]) {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}
void working(char board[8][8]){
    


}
int main(){
display_chess_board(chess_board);
return 0;
}