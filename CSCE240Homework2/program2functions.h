// Copyright 2025 Simion Cartis

#ifndef _PROGRAM2FUNCTIONS_H_
#define _PROGRAM2FUNCTIONS_H_

// tests to see if an int is a perfect square
bool IsSquare(int a);

// tests to see if an int is a perfect number
bool IsPerfect(int a);

// tests to see if a character is a vowel
bool IsVowel(char a_char, bool a_bool = true);

// tests to see if a character is a consonant
bool IsConsonant(char a_char, bool a_bool = true);

// converts a character that is a number to an int
int ToDigit(char a_char);

// finds the range of two numbers and ensures
// that the first integer argument that is passed
// becomes the smaller of the two values
// (if it is not already)
int Range(int& smaller_num, int& bigger_num);

// finds a digit in a specified location
// of a double value
int DigitInPosition(double digit, int position);

#endif
