#ifndef sudokuBoard_HPP
#define sudokuBoard_HPP

/* 
 * This file will be used for the obvious helper functons associated with
 * the creation and fiunction of the sudoku game.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <random> 

#define BOARDSIZE 9
#define EXIT_END 3

using namespace std;

/*
 * Object: 
 * Description:
 * Error Handling:
 */ 
class sudokuBoard {
private:
  int current_board[BOARDSIZE][BOARDSIZE];
  int display_board[BOARDSIZE][BOARDSIZE];
  bool isCreated = false;
  bool isSolved = false;
  


  int* getUpdate(int arrayPtr[3]);

  int getDifficulty();

  int isSolvable(); 
    
  void updateBoard(int value, int PosX, int PosY);

  void obfuscateBoard();

public:
    
  sudokuBoard() {
    // Fill in the Game board and the Display board
    for (int i=0; i<BOARDSIZE; i++){
      for (int j=0; j<BOARDSIZE; j++) {
        current_board[i][j] = 0;
        display_board[i][j] = 0;
      }
    }
  }

  // Destructor for the sudoku Board
  ~sudokuBoard() { }

  void displayBoard(ostream& out) const;


  void displayStart(ostream& out) const;


  int update();


  void newBoard();


  void populateBoard();


  int actions();

};
                       
#endif // sudokuBoard_HPP
