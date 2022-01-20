#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include "maze.h"
#include "grid.h"
#include "EscapeTheLabyrinth.h"
#include <string>


TEST (grid, defaultConstructor) {
  Grid<int> l;
  // Testing default Grid with no name characteristics
  assert(Grid<int>().numrows() == 4);
  assert(Grid<int>().numcols(0) == 4);
  assert(Grid<int>().size() == 16);
  // Testing default Grid with name characteristics
  Grid<int> a;
  assert(a.numrows() == 4);
  assert(a.numcols(0) == 4);
  assert(a.size() == 16);
  // Testing node val accessor
  for(size_t r = 0; r < a.numrows(); ++r){
    for(size_t c = 0; c < a.numcols(r); ++c){
      assert(a(r,c) == 0);
    }
  }
  //  Testing default grid's Val change capabilities
  int num = 0;
  for (size_t r = 0; r < a.numrows(); ++r) {
    for (size_t c = 0; c < a.numcols(r); ++c) {
      a(r,c) = num;
      num++;
    }
  }
  num = 0;
  for (size_t r = 0; r < a.numrows(); ++r) {
    for (size_t c = 0; c < a.numcols(r); ++c) {
      assert(a(r,c) == num);
      num++;
    }
  }
  // Testing default grid copying constructor ()
    Grid<int> y(a);
    num = 0;
    for(size_t r = 0; r < y.numrows(); ++r){
      for(size_t c = 0; c < y.numcols(r); ++c){
        assert(y(r,c) == num);
        num++;
      }
    }
  // Testing default grid = operator
  Grid<int> u;
  u = y;
  num = 0;
  for (size_t r = 0; r < u.numrows(); ++r) {
    for (size_t c = 0; c < u.numcols(r); ++c) {
      assert(u(r,c) == num);
      num++;
    }
  }
}

// TO DO:  Write many TESTs, at least one for, if not more,
// for each member function.  Each tests should have 100s of assertions.
// Testing grid with name and set small size
TEST (grid, SpecifiedGridConstructor) {
  Grid<int> b(1,1);
  assert(b.numrows() == 1);
  assert(b.numcols(0) == 1);
  assert(b.size() == 1);
  // Testing grid with name and set med size
  Grid<int> c(6,6);
  // Also testing Val accesser and changing capabilities
  for(size_t s = 0; s < c.numcols(0); ++s){
    c(0,s) = 4;
    c(1,s) = 7;
    c(2,s) = 4;
    c(3,s) = 4;
    c(4,s) = 7;
    c(5,s) = 4;
  }
  
  
  assert(c(0,0) == 4);
  assert(c(0,1) == 4);
  assert(c(0,2) == 4);
  assert(c(0,3) == 4);
  assert(c(0,4) == 4);
  assert(c(0,5) == 4);
  assert(c(1,0) == 7);
  assert(c(1,1) == 7);
  assert(c(1,2) == 7);
  assert(c(1,3) == 7);
  assert(c(1,4) == 7);
  assert(c(1,5) == 7);
  assert(c(2,0) == 4);
  assert(c(2,1) == 4);
  assert(c(2,2) == 4);
  assert(c(2,3) == 4);
  assert(c(2,4) == 4);
  assert(c(2,5) == 4);
  assert(c(3,0) == 4);
  assert(c(3,1) == 4);
  assert(c(3,2) == 4);
  assert(c(3,3) == 4);
  assert(c(3,4) == 4);
  assert(c(3,5) == 4);
  assert(c(4,0) == 7);
  assert(c(4,1) == 7);
  assert(c(4,2) == 7);
  assert(c(4,3) == 7);
  assert(c(4,4) == 7);
  assert(c(4,5) == 7);
  assert(c(5,0) == 4);
  assert(c(5,1) == 4);
  assert(c(5,2) == 4);
  assert(c(5,3) == 4);
  assert(c(5,4) == 4);
  assert(c(5,5) == 4);
    
  // Testing grid parameter copying 
  Grid<int> z(c);  
  assert(z(0,0) == 4);
  assert(z(0,1) == 4);
  assert(z(0,2) == 4);
  assert(z(0,3) == 4);
  assert(z(0,4) == 4);
  assert(z(0,5) == 4);
  assert(z(1,0) == 7);
  assert(z(1,1) == 7);
  assert(z(1,2) == 7);
  assert(z(1,3) == 7);
  assert(z(1,4) == 7);
  assert(z(1,5) == 7);
  assert(z(2,0) == 4);
  assert(z(2,1) == 4);
  assert(z(2,2) == 4);
  assert(z(2,3) == 4);
  assert(z(2,4) == 4);
  assert(z(2,5) == 4);
  assert(z(3,0) == 4);
  assert(z(3,1) == 4);
  assert(z(3,2) == 4);
  assert(z(3,3) == 4);
  assert(z(3,4) == 4);
  assert(z(3,5) == 4);
  assert(z(4,0) == 7);
  assert(z(4,1) == 7);
  assert(z(4,2) == 7);
  assert(z(4,3) == 7);
  assert(z(4,4) == 7);
  assert(z(4,5) == 7);
  assert(z(5,0) == 4);
  assert(z(5,1) == 4);
  assert(z(5,2) == 4);
  assert(z(5,3) == 4);
  assert(z(5,4) == 4);
  assert(z(5,5) == 4);
  //  Testing = operator, grid copying
  Grid<int> g;
  g = z;
  assert(g(0,0) == 4);
  assert(g(0,1) == 4);
  assert(g(0,2) == 4);
  assert(g(0,3) == 4);
  assert(g(0,4) == 4);
  assert(g(0,5) == 4);
  assert(g(1,0) == 7);
  assert(g(1,1) == 7);
  assert(g(1,2) == 7);
  assert(g(1,3) == 7);
  assert(g(1,4) == 7);
  assert(g(1,5) == 7);
  assert(g(2,0) == 4);
  assert(g(2,1) == 4);
  assert(g(2,2) == 4);
  assert(g(2,3) == 4);
  assert(g(2,4) == 4);
  assert(g(2,5) == 4);
  assert(g(3,0) == 4);
  assert(g(3,1) == 4);
  assert(g(3,2) == 4);
  assert(g(3,3) == 4);
  assert(g(3,4) == 4);
  assert(g(3,5) == 4);
  assert(g(4,0) == 7);
  assert(g(4,1) == 7);
  assert(g(4,2) == 7);
  assert(g(4,3) == 7);
  assert(g(4,4) == 7);
  assert(g(4,5) == 7);
  assert(g(5,0) == 4);
  assert(g(5,1) == 4);
  assert(g(5,2) == 4);
  assert(g(5,3) == 4);
  assert(g(5,4) == 4);
  assert(g(5,5) == 4);
}

// Testing type compatibility
TEST (grid, differntTypes) {
  //cout <<  "Compatibility for int" << endl;
  Grid<int> q;
  for(size_t r = 0; r < q.numrows(); ++r){
    for(size_t c = 0; c < q.numcols(r); ++c){
      q(r,c) =  20;
    }
  }
  for(size_t r = 0; r < q.numrows(); ++r){
    for(size_t c = 0; c < q.numcols(r); ++c){
      assert(q(r,c) ==  20);
    }
  }
  // Compatibility for char
  //cout <<  "Compatibility for char" << endl;
  Grid<char> w;
  for(size_t r = 0; r < w.numrows(); ++r){
    for(size_t c = 0; c < w.numcols(r); ++c){
      w(r,c) =  '?';
    }
  }
  for(size_t r = 0; r < w.numrows(); ++r){
    for(size_t c = 0; c < w.numcols(r); ++c){
      assert(w(r,c) ==  '?');
    }
  }
  //cout <<  "Compatibility for float" << endl;
  Grid<float> e;
  for(size_t r = 0; r < e.numrows(); ++r){
    for(size_t c = 0; c < e.numcols(r); ++c){
      e(r,c) =  12.0;
    }
  }
  for(size_t r = 0; r < e.numrows(); ++r){
    for(size_t c = 0; c < e.numcols(r); ++c){
      assert(e(r,c) ==  12.0);
    }
  }
  //cout <<  "Compatibility for bool" << endl;
  Grid<bool> y;
  for(size_t r = 0; r < y.numrows(); ++r){
    for(size_t c = 0; c < y.numcols(r); ++c){
      y(r,c) =  true;
    }
  }
  for(size_t r = 0; r < y.numrows(); ++r){
    for(size_t c = 0; c < y.numcols(r); ++c){
      assert(y(r,c) ==  true);
    }
  }
  //cout <<  "Compatibility for double" << endl;
  Grid<double> t;
  for(size_t r = 0; r < t.numrows(); ++r){
    for(size_t c = 0; c < t.numcols(r); ++c){
      t(r,c) =  12.0;
    }
  }
  for(size_t r = 0; r < t.numrows(); ++r){
    for(size_t c = 0; c < t.numcols(r); ++c){
      assert(t(r,c) ==  12.0);
    }
  }
  // cout <<  "Compatibility for string" << endl;
  Grid<string> p;
  for(size_t r = 0; r < p.numrows(); ++r){
    for(size_t c = 0; c < p.numcols(r); ++c){
      p(r,c) =  "?";
    }
  }
  for(size_t r = 0; r < p.numrows(); ++r){
    for(size_t c = 0; c < p.numcols(r); ++c){
      assert(p(r,c) ==  "?");
    }
  }
  //q._output();
}
// TO DO:  As you get to each milestone, you can comment out these provided
// tests.  They currently use grid.h and will segfault until you implement
// grid correctly.  


// Provided Test: sample maze from handout, make lots more yourself!
TEST(maze, basic) {
  vector<string> textMaze;

   textMaze.push_back("* *-W *");
   textMaze.push_back("| |   |");
   textMaze.push_back("*-* * *");
   textMaze.push_back("  | | |");
   textMaze.push_back("S *-*-*");
   textMaze.push_back("|   | |");
   textMaze.push_back("*-*-* P");

   Maze m(textMaze);

   MazeCell* start = m.getStart(2, 2);

   /* These paths are the ones in the handout. They all work. */
   EXPECT_TRUE(isPathToFreedom(start, "ESNWWNNEWSSESWWN"));
   EXPECT_TRUE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES"));
   EXPECT_TRUE(isPathToFreedom(start, "WNNEWSSESWWNSEENES"));

   /* These paths don't work, since they don't pick up all items. */
   EXPECT_FALSE(isPathToFreedom(start, "ESNW"));
   EXPECT_FALSE(isPathToFreedom(start, "SWWN"));
   EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

   /* These paths don't work, since they aren't legal paths. */
   EXPECT_FALSE(isPathToFreedom(start, "WW"));
   EXPECT_FALSE(isPathToFreedom(start, "NN"));
   EXPECT_FALSE(isPathToFreedom(start, "EE"));
   EXPECT_FALSE(isPathToFreedom(start, "SS"));
}

// Provided Test: don't allow going through walls
TEST(maze, tryingToGoThroughWalls) {
   vector<string> textMaze;

   textMaze.push_back("* S *");
   textMaze.push_back("     ");
   textMaze.push_back("W * P");
   textMaze.push_back( "     ");
   textMaze.push_back( "* * *");

   Maze m(textMaze);

   MazeCell* start = m.getStart(1, 1);

   EXPECT_FALSE(isPathToFreedom(start, "WNEES"));
   EXPECT_FALSE(isPathToFreedom(start, "NWSEE"));
   EXPECT_FALSE(isPathToFreedom(start, "ENWWS"));
   EXPECT_FALSE(isPathToFreedom(start, "SWNNEES"));
}

// Provided Test: Works when starting on an item
TEST(maze, startOnItem) {
   vector<string> textMaze;

   textMaze.push_back("P-S-W");

   Maze m(textMaze);
   MazeCell* start = m.getStart(0, 0);

   EXPECT_TRUE(isPathToFreedom(start, "EE"));
   start = m.getStart(0, 1);
   EXPECT_TRUE(isPathToFreedom(start, "WEE"));
   start = m.getStart(0, 2);
   EXPECT_TRUE(isPathToFreedom(start, "WW"));

}

// Provided Test: Reports errors if given illegal characters.
TEST(maze, invalidChar) {
   vector<string> textMaze;

   textMaze.push_back("* *-W *");
   textMaze.push_back("| |   |");
   textMaze.push_back("*-* * *");
   textMaze.push_back("  | | |");
   textMaze.push_back("S *-*-*");
   textMaze.push_back("|   | |");
   textMaze.push_back("*-*-* P");

   Maze m(textMaze);
   MazeCell* start = m.getStart(0, 0);

   /* These paths contain characters that aren't even close to permissible. */
   EXPECT_FALSE(isPathToFreedom(start, "Q"));
   EXPECT_FALSE(isPathToFreedom(start, "X"));
   EXPECT_FALSE(isPathToFreedom(start, "!"));
   EXPECT_FALSE(isPathToFreedom(start, "?"));

   EXPECT_FALSE(isPathToFreedom(start, "n"));
   EXPECT_FALSE(isPathToFreedom(start, "s"));
   EXPECT_FALSE(isPathToFreedom(start, "e"));
   EXPECT_FALSE(isPathToFreedom(start, "w"));

   ///* These are tricky - they're legal paths that happen to have an unexpected
   // * character at the end.
   start = m.getStart(2, 2);
   EXPECT_FALSE(isPathToFreedom(start, "ESNWWNNEWSSESWWNQ"));
   EXPECT_FALSE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES!!!"));
   EXPECT_FALSE(isPathToFreedom(start, "WNNEWSSESWWNSEENES??"));

}

// Provided Test: This tests your personalized regular maze to see if you were
// able to escape.
TEST(maze, escapeRegularMaze) {
   Maze m(4, 4);
   MazeCell* start = m.mazeFor(kYourName);
   EXPECT_TRUE(isPathToFreedom(start, kPathOutOfRegularMaze));
}

// Provided Test: This tests your personalized twisty maze to see if you were
// able to escape.
TEST(maze, escapeTwistyMaze) {
   Maze m(4, 4);
   MazeCell* start = m.twistyMazeFor(kYourName);
   EXPECT_TRUE(isPathToFreedom(start, kPathOutOfTwistyMaze));
}

// int main(int argc, char* argv[])
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }