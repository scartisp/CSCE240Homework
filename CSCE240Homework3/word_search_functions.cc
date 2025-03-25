// Copyright Simion Cartis

#include<string>
using std::string;
#include<cctype>
using std::isspace;
#include<fstream>
using std::ifstream;
#include<iostream>
using std::cout;
using std::endl;
#include"word_search_functions.h"

// method for finding words horizontally.
// Used in both FindWordRight and FindWordLeft.
bool CheckWordHoriz(int row, int col, string to_find, bool left_to_right,
                      const char word_search[][kSize], int check = 0);
// method for finding words vertically.
// Used in both FindWordDown and FindWordUp
bool CheckWordVert(int row, int col, string to_find, bool up_or_down,
                      const char word_search[][kSize], int check = 0);

// function to read from a .txt and
// place the non-whitespace text into a 2d array.
bool ReadWordSearch(string file_name, char word_search[][kSize]) {
  ifstream in(file_name);
  char ch_array[kSize*kSize] = {};
  char ch;
  int num_of_chars = 0;
  while (in.get(ch)) {
    if (!isspace(ch)) {
      if (num_of_chars < kSize*kSize) {
        ch_array[num_of_chars] = ch;
      } else {
        break;
      }
      ++num_of_chars;
    }
  }
  in.close();
  int index = 0;
  if (num_of_chars >= kSize*kSize) {
    for (int i = 0; i <kSize; ++i) {
      for (int j = 0; j <kSize; ++j) {
        word_search[i][j] = ch_array[index++];
      }
    }
    return true;
  }
  return false;
}

// prints out the 2d array
void PrintWordSearch(const char word_search[][kSize]) {
  for (int i = 0; i <kSize; ++i) {
    for (int j = 0; j <kSize; ++j) {
      cout << word_search[i][j] << " ";
    }
    cout << endl;
  }
}

// checks the 2d array from left to right, up to down
// to see if a desired word is in it.
bool FindWordRight(const char word_search[][kSize],
    string to_find, int& row, int& col) {
      bool valid;
      for (int y = 0; y < kSize; ++y) {
        for (int x = 0; x <kSize; ++x) {
          if (word_search[y][x] == to_find[0]) {
            row = y;
            col = x;
            valid = CheckWordHoriz(y, x, to_find, true, word_search);
            if (valid) {
              return true;
            }
          }
        }
      }
      return false;
}

// checks the 2d array from right to left, up to down
// to see if a desired word is in it.
bool FindWordLeft(const char word_search[][kSize],
                  string to_find, int& row, int& col) {
  bool valid;
  for (int y = kSize-1; y >= 0; --y) {
    for (int x = kSize-1; x >= 0; --x) {
      if (word_search[y][x] == to_find[0]) {
        row = y;
        col = x;
        valid = CheckWordHoriz(y, x, to_find, false, word_search);
        if (valid) {
          return true;
        }
      }
    }
  }
  return false;
}

bool CheckWordHoriz(int row, int col, string to_find, bool left_to_right,
                      const char word_search[][kSize], int check) {
  int word_length = to_find.length();
  while (check < word_length) {
    if (word_search[row][col] == to_find[check] && col <kSize) {
      ++check;
      (left_to_right) ? ++col : --col;
    } else {
    return false;
    }
  }
  return true;
}

// checks the 2d array to up to down, left to right
// to see if a desired word is in it.
bool FindWordDown(const char word_search[][kSize],
                  string to_find, int& row, int& col) {
  bool valid;
  for (int x = 0; x < kSize; ++x) {
    for (int y = 0; y < kSize; ++y) {
      if (word_search[y][x] == to_find[0]) {
        row = y;
        col = x;
        valid = CheckWordVert(y, x, to_find, true, word_search);
        if (valid) {
          return true;
        }
      }
    }
  }
  return false;
}

// checks the 2d array from down to up, left to right
// to see if a desired word is in it.
bool FindWordUp(const char word_search[][kSize],
                string to_find, int& row, int& col) {
  bool valid;
  for (int x = kSize-1; x >= 0; --x) {
    for (int y = kSize-1; y >= 0; --y) {
      if (word_search[y][x] == to_find[0]) {
        row = y;
        col = x;
        valid = CheckWordVert(y, x, to_find, false, word_search);
        if (valid) {
          return true;
        }
      }
    }
  }
  return false;
  }

bool CheckWordVert(int row, int col, string to_find, bool left_to_right,
                     const char word_search[][kSize], int check) {
  int word_length = to_find.length();
  while (check < word_length) {
    if (word_search[row][col] == to_find[check] && row <kSize) {
      ++check;
      (left_to_right) ? ++row : --row;
    } else {
      return false;
    }
  }
  return true;
}

// checks the 2d array from up to down and left to right simultanously
// to see if a desired word is in it.
bool FindWordDiagonal(const char word_search[][kSize],
                      string to_find, int& row, int& col) {
  int word_length = to_find.length();
  bool valid;
  for (int y = 0; y < kSize; ++y) {
    for (int x = 0; x <kSize; ++x) {
      if (word_search[y][x] == to_find[0]) {
        row = y;
        col = x;
        int check_x = x;
        int check_y = y;
        int check_word = 0;
        valid = true;
        while (check_word < word_length) {
          if (word_search[check_y][check_x] == to_find[check_word] &&
              check_y < kSize && check_x < kSize) {
            ++check_word;
            ++check_x;
            ++check_y;
          } else {
            valid = false;
            break;
          }
        }
        if (valid == true) {
          return true;
        }
      }
    }
  }
  return false;
}
