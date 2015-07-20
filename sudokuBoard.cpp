/* 
 * Filename: sudokoBoard.cpp
 * Author: Jack Wampler
 * Description: 
 *
 * Date:
 */
 
#include "sudokuBoard.hpp"

void sudokuBoard::displayBoard(ostream& out) const {
  system ("clear");
  out << " ___ ___ ___  ___ ___ ___  ___ ___ ___ " << endl;
  for (int i=0; i< BOARDSIZE; i++) {
    out << "|";
    for (int j=0; j< BOARDSIZE; j++) {
    
      // print number
      out << " ";
      if (current_board[i][j] != -1) 
        out << current_board[i][j];
      else            
        out << " ";   
        
      // Print divider  
      if ( ( j%3 == 2 ) && ( j!=8 ) )
        out<< " ||";
      else
       out<< " |";
    }            
    if ( ( i%3 == 2 ) && ( i!=8 ) )
      out << "\n|===|===|===||===|===|===||===|===|===|";
    else
      out << "\n|---|---|---||---|---|---||---|---|---|";

    if ( i == 1)
      out << "\033[1;34m   (1) Update\033[0m" << endl;
    else if ( i == 3 )
      out << "\033[1;34m   (2) Check\033[0m" << endl;
    else if ( i == 5 )
      out << "\033[1;34m   (3) New Puzzle\033[0m" << endl;
    else if ( i == 7 )
      out << "\033[1;34m   (3) Exit\033[0m" << endl;
    else
      out << endl;
  }

}                  


int sudokuBoard::isSolvable() {
  return true;

}

int sudokuBoard::update() {
int InfoPtr[3] = {-1, -1, -1};  // Make this a refference to the array
  getUpdate(InfoPtr);
  
  cout << "\033[1;31m"<<InfoPtr[0]<<" "<<InfoPtr[1]<<" ";
  cout<<InfoPtr[2]<<"\033[0m\n"<<endl;

  updateBoard(InfoPtr[0], InfoPtr[1], InfoPtr[2]);

  return 1;
}



void sudokuBoard::populateBoard() { 
  int temp[3][3];
  vector<int> nums;

  for (int i=0; i<10; ++i) nums.push_back(i); // 0 1 2 3 4 5 6 7 8 9

  random_shuffle ( nums.begin(), nums.end() );

  // test output for shuffled numbers
  //for (vector<int>::iterator it=nums.begin(); it!=nums.end(); ++it)
  //    cout << ' ' << *it;

  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      temp[i][j] = nums[i*3 +j];
    }
  }

  // (0,0) x
  current_board[0][0]=current_board[3][2]=current_board[6][1]=
    current_board[2][3]=current_board[5][5]=current_board[8][4]=
    current_board[1][6]=current_board[4][8]=current_board[7][7] = temp[0][0]; 

  // (0,1) x   
  current_board[1][0]=current_board[4][2]=current_board[7][1]=
    current_board[0][3]=current_board[3][5]=current_board[6][4]=
    current_board[2][6]=current_board[5][8]=current_board[8][7] = temp[0][1]; 
        
  // (0,2) x   
  current_board[2][0]=current_board[5][2]=current_board[5][1]=
    current_board[1][3]=current_board[4][5]=current_board[7][4]=
    current_board[0][6]=current_board[3][8]=current_board[6][7] = temp[0][2]; 
        
  // (1,0) x   
  current_board[0][1]=current_board[3][0]=current_board[6][2]=
    current_board[2][4]=current_board[5][3]=current_board[8][5]=
    current_board[1][7]=current_board[4][6]=current_board[7][8] = temp[1][0]; 
        
  // (1,1) x   
  current_board[1][1]=current_board[4][0]=current_board[7][2]=
    current_board[0][4]=current_board[3][3]=current_board[6][5]=
    current_board[2][7]=current_board[5][6]=current_board[8][8] = temp[1][1]; 
        
  // (1,2) x   
  current_board[2][1]=current_board[5][0]=current_board[8][2]=
    current_board[1][4]=current_board[4][3]=current_board[7][5]=
    current_board[0][7]=current_board[3][6]=current_board[6][8] = temp[1][2]; 
        
  // (2,0) x   
  current_board[0][2]=current_board[3][1]=current_board[6][0]=
    current_board[2][5]=current_board[5][4]=current_board[8][3]=
    current_board[1][8]=current_board[4][7]=current_board[7][6] = temp[2][0]; 
        
  // (2,1) x   
  current_board[1][2]=current_board[4][2]=current_board[7][0]=
    current_board[0][5]=current_board[3][4]=current_board[6][3]=
    current_board[2][8]=current_board[5][7]=current_board[8][6] = temp[2][1]; 
        
  // (2,2) x   
  current_board[2][2]=current_board[5][1]=current_board[8][0]=
    current_board[1][5]=current_board[4][4]=current_board[7][3]=
    current_board[0][8]=current_board[3][7]=current_board[6][6] = temp[2][2]; 
  

  return;
}


void sudokuBoard::updateBoard(int PosX, int PosY, int value) {
  current_board[PosX - 1][PosY - 1] = value;
}


void sudokuBoard::newBoard() {
  // simple random generator
  /*for (int i=0; i<BOARDSIZE; i++) {
    for (int j=0; j<BOARDSIZE; j++) {
      current_board[i][j] = rand() % 11 - 1;
    }
  } */

  // Robust generator
  populateBoard();
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
  cout<<"\n\tAction: ";
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
