// Author: Miguel Severino
// Puzzle Solver

#include <iostream>
#include <fstream>
#include <unordered_set>
#include "solver.h"


using namespace std;

int main(int argc, char **argv)
{
  // Send in the name of the puzzle. This is the space that the program will
  // attempt to find the words listed in the "wordBank."
  // The program is expecting a .txt file.
  // Ex: "PuzzleGrid.txt"
  ifstream puzzle (argv[1]);

  // This is the actual puzzle that the program will try and find the
  // words within the puzzle. The program is expecting another .txt file
  // Ex: "WordBank.txt"
  ifstream wordBank (argv[2]);

  // This will be the file that the program will output the solution to.
  // the output would have to be .txt.
  // Ex: "Answer.txt"
  ofstream solution(argv[3]);


  int i, j, val;
  char letter;
  string word;
  vector<char> row;
  vector<char> lowerCase;
  vector<vector<char>> grid;
  vector<vector<char>> solutionGrid;
  unordered_set<string> wordsToFind;


  // getting the word bank
  while (getline(wordBank, word, '\n'))
    wordsToFind.insert(word);


  // getting grid of letters
  while (puzzle.get(letter))
  {
    if (letter != ' ' && letter != '\n')
    {
      row.push_back(letter);

      lowerCase.push_back(tolower(letter));
    }

    if (letter == '\n')
    {
      grid.push_back(row);
      solutionGrid.push_back(lowerCase);

      lowerCase.clear();
      row.clear();
    }
  }

  //inserting last row of the grid
  grid.push_back(row);
  solutionGrid.push_back(lowerCase);


  // will search for all the words in the word bank..
  for (auto wordSought: wordsToFind)
  {
    vector<char> search(wordSought.begin(), wordSought.end());

    lookForWord(search, grid, 0, 0);


    i = startSpot.first;
    j = startSpot.second;


    // marking the location of the word found by
    // making those letters Uppercase in a lowercase grid.
    while (i != finalSpot.first || j != finalSpot.second)
    {
      solutionGrid[i][j] = toupper(solutionGrid[i][j]);

      if (i != finalSpot.first)
      {
        val = (finalSpot.first - i);

        if (val < 0)
          i -= 1;

        else
          i += 1;
      }

      if (j != finalSpot.second)
      {
        val = (finalSpot.second - j);

        if (val < 0)
          j -= 1;

        else
          j += 1;
      }

      // marking the last spot before loop breaks
      if (i == finalSpot.first && j == finalSpot.second)
        solutionGrid[i][j] = toupper(solutionGrid[i][j]);
    }
  }


  // setting up the solution text file
  for (size_t i = 0 ; i < grid.size(); i++, solution << endl)
    for (size_t j = 0 ; j < grid[i].size(); j++)
      solution << solutionGrid[i][j] << " ";


  solution.close();
  puzzle.close();
  wordBank.close();
  return 0;
}
