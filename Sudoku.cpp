
/*
 * Filename: Sudoku.cpp
 * Author: Jack Wampler
 * Description:
 *
 * Date: 19 JULY 2015
 */ 

#include "sudokuBoard.hpp"
#include <fstream>  // For reading and writing from files
#include <iostream>


using namespace std;


int main(int argc, char *argv[]) {
  
  //main run-time variabels
  sudokuBoard *boardPtr;
  
  boardPtr = new sudokuBoard;

  boardPtr->newBoard();

  boardPtr->displayBoard( cout );
  
  //try a few updates
  while (true) {
    if ( !boardPtr->actions( ) ) {
      cout << "Error in actions" << endl;
      return EXIT_FAILURE;
    }

    boardPtr->displayBoard( cout );
  }

  delete boardPtr;
}
