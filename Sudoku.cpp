
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
  int status = 1;
  sudokuBoard *boardPtr;
  
  boardPtr = new sudokuBoard;

  boardPtr->displayStart( cout );
  
  //try a few updates
  while (true) {
    status = boardPtr->actions();
    if ( status == 0  ) {
      cout << "Error in actions" << endl;
      return EXIT_FAILURE;
    }
    else if ( status == 3 ) {
      cout << "\n\033[1;32mHope you enjoyed! \033[0m" << endl;
      sleep(2);
      system("clear");
      return EXIT_SUCCESS;
    }

    boardPtr->displayBoard( cout );
  }

  delete boardPtr;
}
