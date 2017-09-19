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
}

TEST(TicTacToeBoardTest, placePiece) {
  TicTacToeBoard testBoard;
  Piece validPiece;
  Piece invalidPiece;
  validPiece = testBoard.placePiece(0,0);
  ASSERT_NE(validPiece, Invalid);
  invalidPiece = testBoard.placePiece(0,3);
  ASSERT_EQ(invalidPiece, Invalid);
  invalidPiece = testBoard.placePiece(3,3);
  ASSERT_EQ(invalidPiece, Invalid);
}

TEST(TicTacToeBoardTest, getPiece) {
  TicTacToeBoard testBoard;
  Piece validPiece;
  Piece retPiece;
  validPiece = testBoard.placePiece(1,1);
  retPiece = testBoard.getPiece(1,1);
  ASSERT_EQ(validPiece, retPiece);
}

TEST(TicTacToeBoardTest, rowWin) {
  TicTacToeBoard testBoard;
  Piece Winner;
  for(int i = 0; i < 3; i++) {
    testBoard.placePiece(0,i);
    Winner = testBoard.getWinner();
    if(Winner != Invalid) {
      std::cout << "Winner:" << Winner << std::endl;
      break;
    }
    testBoard.placePiece(2,i);
  }
  ASSERT_NE(Invalid, Winner);
}

TEST(TicTacToeBoardTest, columnWin) {
  TicTacToeBoard testBoard;
  Piece Winner;
  for(int i = 0; i < 3; i++) {
    testBoard.placePiece(i,0);
    Winner = testBoard.getWinner();
    if(Winner != Invalid) {
      std::cout << "Winner:" << Winner << std::endl;
      break;
    }
    testBoard.placePiece(i,2);
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
