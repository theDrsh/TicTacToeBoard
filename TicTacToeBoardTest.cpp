/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/
TEST(TicTacToeBoardTest, toggleTurn) {
  TicTacToeBoard testBoard;
  Piece lastTurn = X;
  Piece newTurn = testBoard.toggleTurn();
  ASSERT_NE(newTurn, lastTurn);
  lastTurn = newTurn;
  newTurn = testBoard.toggleTurn();
  ASSERT_NE(newTurn, lastTurn);
  
}

TEST(TicTacToeBoardTest, placePiece) {
  TicTacToeBoard testBoard;
  Piece validPiece;
  Piece invalidPiece;
  Piece dupPiece;
  validPiece = testBoard.placePiece(0,0);
  ASSERT_NE(validPiece, Invalid);
  dupPiece = testBoard.placePiece(0,0);
  ASSERT_EQ(dupPiece, validPiece);
  invalidPiece = testBoard.placePiece(0,3);
  ASSERT_EQ(invalidPiece, Invalid);
  invalidPiece = testBoard.placePiece(3,3);
  ASSERT_EQ(invalidPiece, Invalid);
}

TEST(TicTacToeBoardTest, getBlankPiece) {
  TicTacToeBoard testBoard;
  Piece blankPiece;
  blankPiece = testBoard.getPiece(0,0);
  ASSERT_EQ(blankPiece, Blank);
}

TEST(TicTacToeBoardTest, placeGetPiece) {
  TicTacToeBoard testBoard;
  Piece validPiece;
  Piece invalidPiece;
  Piece retPiece;
  validPiece = testBoard.placePiece(1,1);
  retPiece = testBoard.getPiece(1,1);
  ASSERT_EQ(validPiece, retPiece);
  invalidPiece = testBoard.getPiece(3,3);
  ASSERT_EQ(invalidPiece, Invalid);
}

TEST(TicTacToeBoardTest, coordinateTest) {
  TicTacToeBoard testBoard;
  Piece topLeft, topRight, botLeft, botRight;
  topLeft = testBoard.placePiece(0,0);
  topRight = testBoard.placePiece(0,2);
  botLeft = testBoard.placePiece(2,0);
  botRight = testBoard.placePiece(2,2);
  ASSERT_EQ(topLeft, X);
  ASSERT_EQ(topRight, O);
  ASSERT_EQ(botLeft, X);
  ASSERT_EQ(botRight, O);
  ASSERT_EQ(topLeft, testBoard.getPiece(0,0));
  ASSERT_EQ(topRight, testBoard.getPiece(0,2));
  ASSERT_EQ(botLeft, testBoard.getPiece(2,0));
  ASSERT_EQ(botRight, testBoard.getPiece(2,2));
}

TEST(TicTacToeBoardTest, rowWin) {
  TicTacToeBoard testBoard;
  Piece Winner;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      testBoard.placePiece(i, j);
      testBoard.placePiece(3,3);
    }
    Winner = testBoard.getWinner();
    if(Winner == Invalid)
      break;
  }
  ASSERT_NE(Invalid, Winner);
}

TEST(TicTacToeBoardTest, columnWin) {
  TicTacToeBoard testBoard;
  Piece Winner;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      testBoard.placePiece(j, i);
      testBoard.placePiece(3,3);
    }
    Winner = testBoard.getWinner();
    if(Winner == Invalid)
      break;
  }
  ASSERT_NE(Invalid, Winner);
}

TEST(TicTacToeBoardTest, diagWin) {
  TicTacToeBoard testBoard;
  Piece Winner;
  testBoard.placePiece(0,0);
  testBoard.placePiece(0,2);
  testBoard.placePiece(1,1);
  testBoard.placePiece(0,1);
  testBoard.placePiece(2,2);
  Winner = testBoard.getWinner();
  ASSERT_NE(Invalid, Winner);
}

TEST(TicTacToeBoardTest, draw) {
  TicTacToeBoard testBoard;
  Piece Winner;
  testBoard.placePiece(0,0);
  testBoard.placePiece(1,1);
  testBoard.placePiece(2,0);
  testBoard.placePiece(1,0);
  testBoard.placePiece(1,2);
  testBoard.placePiece(2,1);
  testBoard.placePiece(0,1);
  testBoard.placePiece(0,2);
  testBoard.placePiece(2,2);
  Winner = testBoard.getWinner();
  ASSERT_EQ(Blank, Winner);
}
