/* 
 * Filename: sudokoBoard.cpp
 * Author: Jack Wampler
 * Description: 
 *
 * Date:
 */
 
#include "sudokuBoard.hpp"

void sudokuBoard::displayBoard(ostream& out) const {
  //out << "|---|---|---|---|---|---|---|---|---|" << endl;
  system ("clear");
  out << " ___ ___ ___ ___ ___ ___ ___ ___ ___ " << endl;
  for (int i=0; i< BOARDSIZE; i++) {
    out << "|";
    for (int j=0; j< BOARDSIZE; j++) {
    out << " ";
    if (current_board[i][j] != -1) 
      out << current_board[i][j];
    else 
      out << " ";  
    out<< " |";
    }
    out << "\n|---|---|---|---|---|---|---|---|---|" << endl;
  }

}                  


int sudokuBoard::isSolvable() {
  return true;

}

int sudokuBoard::update() {
int InfoPtr[3] = {-1, -1, -1};  // Make this a refference to the array
  getUpdate(InfoPtr);
  
  updateBoard(InfoPtr[0], InfoPtr[1], InfoPtr[2]);

  cout << "\033[1;31m"<<InfoPtr[0]<<" "<<InfoPtr[1]<<" ";
  cout<<InfoPtr[2]<<"\033[0m\n"<<endl;

  return 1;
}



void sudokuBoard::updateBoard(int PosX, int PosY, int value) {
  current_board[PosX - 1][PosY - 1] = value;
}


void sudokuBoard::newBoard() {
  for (int i=0; i<BOARDSIZE; i++) {
    for (int j=0; j<BOARDSIZE; j++) {
      current_board[i][j] = rand() % 11 - 1;
    }
  }
  if ( isSolvable() ) {
    isCreated = true;
    isSolved = true;
  } 
  else 
    newBoard();
}


int* sudokuBoard::getUpdate(int arrayPtr[3]) {

  // Get the updated x position for the update
  cout << "New position (X): ";
  cin >> arrayPtr[0];
  while ( (arrayPtr[0] > 9) || (arrayPtr[0] < 0) ) {
    cout << "\033[1;31mOut of Bounds, please re-enter\033[0m"<< endl;
    cout << "New position (X): ";
    cin >> arrayPtr[0];
  }

  // Get the updated y position for the update
  cout << "New position (Y): ";
  cin >> arrayPtr[1];
  while ( (arrayPtr[1] > 9) || (arrayPtr[1] < 0) ) {
    cout << "\033[1;31mOut of Bounds, please re-enter\033[0m"<< endl;
    cout << "New position (Y): ";
    cin >> arrayPtr[1];
  }


  cout << "New Value: ";
  cin >> arrayPtr[2];
  while ( (arrayPtr[2] > 9) || (arrayPtr[2] < 1) ) {
    cout << "\033[1;31mOut of Bounds, please re-enter\033[0m"<< endl;
    cout << "New value: ";
    cin >> arrayPtr[2];
  }


  return arrayPtr;
}                


int sudokuBoard::actions() {
  int option;
  cout<<"\033[1;34m(1)Update  (2)Check  (3)New Puzzle  (4)Exit\033[0m" << endl;
  cout<<"Action: ";
  cin >> option;

  switch(option) {
    case(1):
        cout << endl;
        if ( !update() )    
            return EXIT_FAILURE;
        cout << "\033[1;32mAdding Update\033[0m"<<endl;
        sleep(2);
        break;
    case(2): 
        cout << "\n\033[1;32mChecking solution\033[0m"<<endl;
        sleep(2);
        break;
    case(3):
        cout << "\n\033[1;32mNew puzzle\033[0m"<<endl;
        sleep(2);
        break;
    case(4):
        cout << "\n\033[1;32mExiting... \033[0m" << endl;
        sleep(2);
        break;
    default: 
        cout << "\n\033[1;31Incorrect option entered! Try again\033[0m\n\n" << endl;
        return actions();
        break;
  }
  return true;
}
