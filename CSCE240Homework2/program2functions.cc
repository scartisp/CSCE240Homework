// Copyright 2025 Simion Cartis

#include <cctype>
#include "program2functions.h"

bool IsSquare(int a) {
  for (int i = 0; i <= a; ++i) {
    if (i*i == a) {
      return true;
    }
  }
  return false;
}

bool IsPerfect(int a) {
  int divisor_sum = 0;
  for (int i = 1; i < a; ++i) {
    if (a % i == 0) {
      divisor_sum += i;
    }
  }
  if (divisor_sum == a) {
    return true;
  }
  return false;
}

bool IsVowel(char a_char, bool a_bool) {
  if (tolower(a_char) == 'a' || tolower(a_char) == 'e'
      || tolower(a_char) == 'i' || tolower(a_char) == 'o'
      || tolower(a_char) == 'u' || (tolower(a_char) == 'y' && a_bool == true)) {
        return true;
  }
  return false;
}

bool IsConsonant(char a_char, bool a_bool) {
  if (tolower(a_char) < 97 ||  tolower(a_char) > 122) {
    return false;
  } else if (( tolower(a_char) != 'a' && tolower(a_char) != 'e'
  && tolower(a_char) != 'i' && tolower(a_char) != 'o'
  && tolower(a_char) != 'u' && tolower(a_char) != 'y')
  || (tolower(a_char) == 'y' && a_bool == true)) {
    return true;
  }
  return false;
}

int ToDigit(char a_char) {
  if (a_char < 48 || a_char > 57) {
    return 0;
  }
  return a_char-'0';
}

int Range(int& smaller_num, int& bigger_num ) {
  if (smaller_num > bigger_num) {
    int temp = smaller_num;
    smaller_num = bigger_num;
    bigger_num = temp;
  }
  return bigger_num - smaller_num;
}

int DigitInPosition(double digit, int position) {
  if (position <= 0) {
    for (int i = 0; i < position * -1; ++i) {
      digit = static_cast<int>(digit) / 10;
    }
  } else if (position > 0) {
    for (int i = 0; i < position; ++i) {
      digit *= 10;
    }
  }
  return static_cast<int>(digit) % 10;
}
