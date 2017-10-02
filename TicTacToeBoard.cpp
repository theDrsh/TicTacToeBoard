#include "TicTacToeBoard.h"

/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X) {
    turn = O;
    return turn;
  }
  else{
    turn = X;
    return turn;
  }
  return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if((row > BOARDSIZE-1 || row < 0) || (column > BOARDSIZE-1 || column < 0)) {
    toggleTurn();
    return Invalid;
  }
  if(board[row][column] == Blank) {
    board[row][column] = turn;
    Piece lastTurn = turn;
    toggleTurn();
    return lastTurn;
  }
  else {
    return board[row][column];
  }
  toggleTurn();
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if((row > 2 || row < 0) || (column > 2 || column < 0)) {
    return Invalid;
  }
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/

/** BUG: The bug is within the check to see if the board is in a draw state, it doesn't check
* if all the squares are filled it should return blank, but it returns invalid, as if the game
* isn't over
**/
Piece TicTacToeBoard::getWinner()
{
  int squaresFilled = 0;
  for(int i = 0; i < 3; i++) {
    if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
      if(board[i][0] != Blank) {
        return board[i][0];
      }
    }
    if((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
      if(board[0][i] != Blank) {
        return board[0][i];
      }
    }
  }
  if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
    if(board[0][0] != Blank) {
        return board[0][0];
    }
  }
  if((board[0][3] == board[1][1]) && (board[1][1] == board[2][0])) {
    if(board[0][0] != Blank) {
        return board[0][0];
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(board[i][j] != Blank) {
        squaresFilled++;
      }
    }
  }
  if(squaresFilled == 9) {
    return Blank;
  }
  return Invalid;
}
