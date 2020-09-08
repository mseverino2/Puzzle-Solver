#ifndef SOLVER
#define SOLVER


#include <vector>


// the word being sought
std::vector<char> formedWord;

// positions of first letter sought within the grid
std::pair<int, int> startSpot;

// positions of last letter sought within the grid
std::pair<int, int> finalSpot;



// if move is valid return appropriate value
bool isValid(std::vector<std::vector<char>> grid, size_t y, size_t x)
{
  if (grid.size() == 0)
  return false;

  if (x >= 0 && x < grid.size() && y >= 0 && y < grid.size())
  return true;

  return false;
}


// send it up and right
int upRight(std::vector<std::vector<char>> grid, std::vector<char> word, int position, int x, int y)
{

  if (isValid(grid, y+1, x-1))
  {
    // if next spot equals the next letter..
    if (grid[x - 1][y + 1] == word[position])
    {
      formedWord.push_back(grid[x - 1][y + 1]);

      if (formedWord == word)
      {
        finalSpot = std::make_pair(x-1, y+1);
        return 1;
      }

      else
        if (upRight(grid, word, position + 1, x - 1, y + 1))
          return 1;

    }

    else
      return 0;
  }

  return 0;
}
// send it right
int right(std::vector<std::vector<char>> grid, std::vector<char> word, int position, int x, int y)
{

  if (isValid(grid, y+1, x))
  {
    if (grid[x][y + 1] == word[position])
    {
      formedWord.push_back(grid[x][y + 1]);

      if (formedWord.size() == word.size())
      {
        finalSpot = std::make_pair(x, y+1);
        return 1;
      }

      else
        if (right(grid, word, position + 1, x, y + 1))
          return 1;

    }

    else
      return 0;
  }

  return 0;
}
// send it down and right
int downRight(std::vector<std::vector<char>> grid, std::vector<char> word, int position, int x, int y)
{

  if (isValid(grid, y+1, x+1))
  {
    // if next spot equals the next letter..
    if (grid[x + 1][y + 1] == word[position])
    {
      formedWord.push_back(grid[x + 1][y + 1]);

      if (formedWord == word)
      {
        finalSpot = std::make_pair(x+1, y+1);
        return 1;
      }

      else
        if (downRight(grid, word, position + 1, x + 1, y + 1))
          return 1;
    }

    else
      return 0;

  }

  return 0;
}
// send it down
int down(std::vector<std::vector<char>> grid, std::vector<char> word, int position, int x, int y)
{

  if (isValid(grid, y, x+1))
  {

    // if next spot equals the next letter..
    if (grid[x + 1][y] == word[position])
    {
      formedWord.push_back(grid[x + 1][y]);

      if (formedWord == word)
      {
        finalSpot = std::make_pair(x+1, y);
        return 1;
      }

      else
        if (down(grid, word, position + 1, x + 1, y))
          return 1;
    }

    else
      return 0;

  }

  return 0;
}
// send it left
int left(std::vector<std::vector<char>> grid, std::vector<char> word, int position, int x, int y)
{

  if (isValid(grid, y-1, x))
  {
    if (grid[x][y - 1] == word[position])
    {
      formedWord.push_back(grid[x][y - 1]);

      if (formedWord == word)
      {
        finalSpot = std::make_pair(x, y-1);
        return 1;
      }

      else
        if (left(grid, word, position + 1, x, y - 1))
          return 1;

    }

    else
      return 0;

  }

  return 0;
}
// send it down and left
int downLeft(std::vector<std::vector<char>> grid, std::vector<char> word, int position, int x, int y)
{

  if (isValid(grid, y-1, x+1))
  {
    // if next spot equals the next letter..
    if (grid[x + 1][y - 1] == word[position])
    {
      formedWord.push_back(grid[x + 1][y - 1]);

      if (formedWord == word)
      {
        finalSpot = std::make_pair(x+1, y-1);
        return 1;
      }

      else
        if (downLeft(grid, word, position + 1, x + 1, y - 1))
          return 1;

    }

    else
      return 0;

  }

  return 0;
}
// send it up and left
int upLeft(std::vector<std::vector<char>> grid, std::vector<char> word, int position, int x, int y)
{

  if (isValid(grid, y-1, x-1))
  {
    // if next spot equals the next letter..
    if (grid[x - 1][y - 1] == word[position])
    {
      formedWord.push_back(grid[x - 1][y - 1]);

      if (formedWord == word)
      {
        finalSpot = std::make_pair(x-1, y-1);
        return 1;
      }

      else
        if (upLeft(grid, word, position + 1, x - 1, y - 1))
          return 1;
    }

    else
      return 0;

  }

  return 0;
}
// send it up
int up(std::vector<std::vector<char>> grid, std::vector<char> word, int position, int x, int y)
{

  if (isValid(grid, y, x-1))
  {
    // if next spot equals the next letter..
    if (grid[x - 1][y] == word[position])
    {
      formedWord.push_back(grid[x - 1][y]);

      if (formedWord == word)
      {
        finalSpot = std::make_pair(x - 1, y);
        return 1;
      }

      else
        if (up(grid, word, position + 1, x - 1, y))
          return 1;
    }

    else
      return 0;

  }

  return 0;
}


void lookForWord(std::vector<char> wordToFind, std::vector<std::vector<char>> grid, size_t x, size_t y)
{
  int startX, startY;


  // finding starting locations..
  for (size_t i = 0; i < grid.size(); i++)
  {
    for (size_t j = 0 ; j < grid.size(); j++)
    {
      // if it equals the first letter grab location
      if (grid[i][j] == wordToFind[0])
      {
        startY = j;

        startX = i;


        // capturing starting location of the word within the grid
        startSpot = std::make_pair(startX, startY);


        // getting the variable ready for the next iteration of checks
        // on every recursive dive, it will add the current letter and append it
        // to formedWord. If the formedWord matches the word being sought then
        // the word is found and the function will return.
        formedWord.clear();
        formedWord.push_back(wordToFind[0]);


         if(left(grid, wordToFind, 1, startX, startY))
           return;

          formedWord.clear();
          formedWord.push_back(wordToFind[0]);

         if (upRight(grid, wordToFind, 1, startX, startY))
           return;

          formedWord.clear();
          formedWord.push_back(wordToFind[0]);

          if(right(grid, wordToFind, 1, startX, startY))
           return;

          formedWord.clear();
          formedWord.push_back(wordToFind[0]);

          if(downRight(grid, wordToFind, 1, startX, startY))
           return;

          formedWord.clear();
          formedWord.push_back(wordToFind[0]);

          if(down(grid, wordToFind, 1, startX, startY))
           return;

          formedWord.clear();
          formedWord.push_back(wordToFind[0]);

          if(left(grid, wordToFind, 1, startX, startY))
           return;

          formedWord.clear();
          formedWord.push_back(wordToFind[0]);

          if(downLeft(grid, wordToFind, 1, startX, startY))
           return;

          formedWord.clear();
          formedWord.push_back(wordToFind[0]);

          if(upLeft(grid, wordToFind, 1, startX, startY))
           return;

          formedWord.clear();
          formedWord.push_back(wordToFind[0]);

          if(up(grid, wordToFind, 1, startX, startY))
           return;
      }
    }
  }
}
#endif
