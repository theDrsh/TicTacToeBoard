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

TEST(TicTacToeBoardTest, getWinner) {

}
