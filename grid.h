/* grid.h 
 * Contians the content for the Grid, which includes each CELL structure
 * When making a default grid, the fils content will defualt to making 
 * a 4x4 grid with 0s. This file also contains functions that allow for
 * accessing data about the grid as well as the data within each cell in
 * the grid. This file also holds operator functions that allow for
 * grid copying.*/
#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>

using namespace std;

template<typename T>
class Grid {
private:
  struct CELL {
    CELL* Next;  // next row basicaly
    T Val;   // the data
    size_t NumCols;  // total # of columns
    CELL(CELL* _Next = nullptr, T _Val = T(), size_t _NumCols = 0) {
      Next = _Next;   // each cell has it own
      Val = _Val;   // each cell has it own
      NumCols = _NumCols;  // each cell has it own
    }
  };

  size_t NumRows;  // total # of rows (0..NumRows-1)
  CELL** Rows;     // C array of linked lists
public:
  //
  // default constructor:
  //
  // Called automatically by C++ to construct a 4x4 Grid.  All
  // elements are initialized to the default value of T.
  //
  Grid() {
    // initialize 4 rows , builds the 4x4 grid
    Rows = new CELL*[4];
    NumRows = 4;
    // allocates the first column 
    for (size_t r = 0; r < NumRows; ++r) {
      Rows[r] = new CELL(nullptr, T(), 4);
        
      CELL* cur = Rows[r];  // pointer to 1st member of row
        // create the linked list for this row.
        for (size_t c = 1; c < Rows[r]->NumCols; ++c) {
          cur->Next = new CELL(nullptr, T(), 0);
            
          cur = cur->Next;
        }
    }
  }
  //
  // parameterized constructor:
  //
  // Called automatically by C++ to construct a Grid with R rows,
  // where each row has C columns. All elements are initialized to 
  // the default value of T.
  //
  Grid(size_t R, size_t C) {
    // TO DO:  Write this parameterized constructor.
    // initialize 4 rows , builds the 4x4 grid
    Rows = new CELL*[R];
    NumRows = R;
    // allocate the first cell of the linked list with default value:
    for (size_t r = 0; r < NumRows; ++r) {
        Rows[r] = new CELL(nullptr, T(), C);
        CELL* cur = Rows[r];
        // create the linked list for this row.
        for(size_t c = 1; c < Rows[r]->NumCols; ++c) {
            cur->Next = new CELL(nullptr, T(),0);
            cur = cur->Next;
        }
    }    
  }

  //
  // destructor:
  //
  // Called automatically by C++ to free the memory associated by the vector.
  //
  virtual ~Grid() {
    // 1) check if there is any rows at first
    if (NumRows == 0) {
      return;
    }
    for (size_t R = 0; R < NumRows; ++R) {
    // the 1st CELL leader is at Row[0], so if NumRows = 1, we access Row[0]
      CELL* cur = Rows[R];
       
      CELL* prev = nullptr;
       
      while (cur != nullptr){
        prev = cur;
         
        cur = cur->Next;
         
        delete prev;
       }
     } 
    // 3) delete the Rows array
    delete[] Rows;
  }
  //
  // copy constructor:
  //
  // Called automatically by C++ to construct a Grid that contains a
  // copy of an existing Grid.  Example: this occurs when passing
  // Grid as a parameter by value
  //
  //   void somefunction(Grid<int> G2)  <--- G2 is a copy:
  //   { ... }
  //
  Grid(const Grid<T>& other) {
    // first create a new Grid 
    
    this->NumRows = other.numrows();   // set number of rows for new Grid
    // 2. Copy all nodes to new grid 
    // Create array of same size
    this->Rows = new CELL*[this->NumRows];
    // allocate the first cell of the linked list with others value
    for (size_t r = 0; r < other.numrows(); ++r) {
      CELL* otherCur = other.Rows[r];  // head of other row of other grid
      
      this->Rows[r] = new CELL(nullptr, otherCur->Val, otherCur->NumCols); // makes and sets firs
      
      CELL* cur = this->Rows[r];  // head of this rowin this grid
      // create the linked list for this row and copy following values
      for (size_t c = 1; c < Rows[r]->NumCols; ++c) {
        otherCur = otherCur->Next;
        
        cur->Next = new CELL(nullptr, otherCur->Val);
        
        cur = cur->Next;
        }
    }
  }
  //
  // copy operator=
  //
  // Called when you assign one vector into another, i.e. this = other;
  //
  Grid& operator=(const Grid& other) {
    //1. CLEAR CURRENT GRID !
    for (size_t R = 0; R < this->NumRows; ++R) {
    // the 1st CELL leader is at Row[0], so if NumRows = 1, we access Row[0]
      CELL* cur = this->Rows[R];
       
      CELL* prev = nullptr;
       
      while (cur != nullptr){
        prev = cur;
         
        cur = cur->Next;
         
        delete prev;
       }
    }
    delete[] this->Rows;
    
    // Create array of same size
    this->Rows = new CELL*[other.NumRows];
    
    this->NumRows = other.numrows();   // set number of rows for new Grid
    // 2. Copy all nodes to new grid 
    // allocate the first cell of the linked list with others value
    for (size_t r = 0; r < other.numrows(); ++r) {
      CELL* otherCur = other.Rows[r];  // head of other row of other grid
        
      this->Rows[r] = new CELL(nullptr, otherCur->Val, otherCur->NumCols); // makes and sets firs
        
      CELL* cur = this->Rows[r];  // head of this rowin this grid
        // create the linked list for this row and copy following values
      for (size_t c = 1; c < other.Rows[r]->NumCols; ++c) {
        otherCur = otherCur->Next;
            
        cur->Next = new CELL(nullptr, otherCur->Val);
            
        cur = cur->Next;
        }
    }
    return *this;
  }
  //
  // numrows
  //
  // Returns the # of rows in the Grid.  The indices for these rows
  // are 0..numrows-1.
  //
  size_t numrows() const {
    return this->NumRows;
  }
  

  //
  // numcols
  //
  // Returns the # of columns in row r.  The indices for these columns
  // are 0..numcols-1.  For now, each row will have the same number of columns.
  //
  size_t numcols(size_t r) const {
      return Rows[r]->NumCols;
  }


  //
  // size
  //
  // Returns the total # of elements in the grid.
  //
  size_t size() const {
      return this->NumRows * Rows[0]->NumCols;  
  }


  //
  // ()
  //
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    grid(r, c) = ...
  //    cout << grid(r, c) << endl;
  //
  T& operator()(size_t r, size_t c) {
    if (NumRows <= r || r < 0 || Rows[r]->NumCols <= c || c < 0) {
      throw runtime_error("Location does not exist.");
    }
    CELL* d = Rows[r];  // access the rth row
    
      for (size_t t = 1; t <= c; ++t) {  // if we are accesing col 0 we dont need to do next
       d = d -> Next;  // from the rth row, move to the cth column
      }
      return d->Val;
  }

  //
  // _output
  //
  // Outputs the contents of the grid; for debugging purposes.  This is not
  // tested.
  //
  void _output() {
    for (size_t n = 0; n < NumRows; ++n) {
      CELL* R = Rows[n];  //Obtain first member of the row.(1col)
      for (size_t c = 0; c < Rows[n]->NumCols; ++c) {  //  iterate through current rows cols 
        cout << R->Val << " ";
        R = R->Next;
      }
      cout << endl;
    }
  }
};
