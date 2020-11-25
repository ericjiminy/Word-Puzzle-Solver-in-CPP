// Eric Chun - jc2ppp - 10/10/20 - wordPuzzle.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "hashTable.h"
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
		     int numRows, int numCols);
string direction(int k);

bool readInGrid(string filename, int& rows, int& cols) {
  ifstream file(filename);
  if (!file.is_open()) return false;

  string data;
  file >> rows;
  file >> cols;
  file >> data;
  file.close();

  int pos = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      grid[r][c] = data[pos++];
    }
  }
  return true;
}

string getWordInGrid(int startRow, int startCol, int dir, int len,
		     int numRows, int numCols) {
  static string output;
  output.clear();
  output.reserve(256);

  int r = startRow, c = startCol;
  for (int i = 0; i < len; i++) {
    if ( c >= numCols || r >= numRows || r < 0 || c < 0) {
      break;
    }
    output += grid[r][c];
    switch (dir) {             
    case 0:
      r--;
      break;                                                
    case 1:
      r--;
      c++;
      break;                                            
    case 2:
      c++;
      break;                                                 
    case 3:
      r++;
      c++;
      break;                                           
    case 4:
      r++;
      break;                                                 
    case 5:
      r++;
      c--;
      break;                                           
    case 6:
      c--;
      break;                                                 
    case 7:
      r--;
      c--;
      break;                                            
    }
  }
  return output;
}

string direction(int k){
  switch(k){
  case 0:
    return "N";
  case 1:
    return "NE";
  case 2:
    return "E";
  case 3:
    return "SE";
  case 4:
    return "S";
  case 5:
    return "SW";
  case 6:
    return "W";
  case 7:
    return "NW";
  }
  return "direction error  ";
}

int main(int argc, char* argv[]) {
  
  int wordCount = 0;
  string dict(argv[1]);
  ifstream file(dict);
  while (file.good()){
    string word;
    file >> word;
    if (word != ""){
      wordCount++;
    }
  }
  hashTable* myHashtable = new hashTable(wordCount);

  file.clear();
  file.seekg(0, ios::beg);
  
  while (file.good()){
    string word;
    file >> word;
    if (word != ""){
      myHashtable->insert(word);
    }
  }
  file.close();

  int rows, cols;
  string grid(argv[2]);
  readInGrid(grid, rows, cols);

  string output = "";
  int count = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      for (int k = 0; k < 8; k++) {
	for (int l = 3; l < 23; l++) {
	  string word = getWordInGrid(i, j, k, l, rows, cols);
	  if (word.length() < l) break;
	  if (word.length() >= 3) {
	    if (myHashtable->contains(word)) {
	      //cout << direction(k) << " (" << i << ", " << j << "):\t" << word << endl;
	      output += direction(k) + " (" + std::to_string(i) + ", " + std::to_string(j) + "):\t" + word + "\n";
	      count++;
	    }
	  }
	}
      }
    }
  }
  
  return 0;
}
