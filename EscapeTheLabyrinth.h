#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

/* Change this constant to contain your full first and last name (middle is ok too).
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const string kYourName = "Daniel Flores Hurtado";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "SSEEENSWNSWWNNEEE";
const string kPathOutOfTwistyMaze = "SWSWENWNEE";

/* isPathToFreedom: checks the given maze with the directions
 * and decides if it is a valid path for that maze.
 * This function returns ture or false. */
bool isPathToFreedom(MazeCell *start, const string& moves) {
  bool potionFLAG = false;
  bool spellbookFLAG = false;
  bool wandFLAG = false;
  MazeCell* cur = start;
  // if there are no moves.
  if (moves.empty() == 1) {
    return false;
  }
  // 1) Checks the start 
  if (cur->whatsHere == "Potion") {
      potionFLAG = true;
    }
  if (cur->whatsHere == "Spellbook") {
      spellbookFLAG = true;
    }
  if (cur->whatsHere == "Wand") {
      wandFLAG = true;
    }
  
  for (auto& MOVES : moves) {
    // 2) Confirm proper direction and confirm accessible path
    if (MOVES == 'W' && cur->west != nullptr) {
     cur= cur->west;
    }
    else if (MOVES == 'S' && cur->south != nullptr) {
      cur = cur->south;
    }
    else if (MOVES == 'N' && cur->north != nullptr) {
      cur = cur->north;
    }
    else if (MOVES == 'E' && cur->east != nullptr) {
      cur = cur->east;
    }
    // we were not given a valid direction
    else {
      return false;
    }
    // 4) if its a Mazecell check whatshere and activate flags as needed
    if (cur->whatsHere == "Potion") {
      potionFLAG = true;
    }
    if (cur->whatsHere == "Spellbook") {
      spellbookFLAG = true;
    }
    if (cur->whatsHere == "Wand") {
      wandFLAG = true;
    }
  }
  // 5) at the end of the for loop, if not all FLAGS are actived  return false
  if (potionFLAG == false || spellbookFLAG == false || wandFLAG == false) {
      return false;
    }
  else {
    return true;
  }
}


struct node{
  string address;
  bool print;
};
void grid_print(MazeCell *start) {
  MazeCell* cur = start;
  bool finished = false;
  vector<vector<node>> pgrid;

  while(finished != true) {
    if(cur->south != nullptr) {

    }
  }
}