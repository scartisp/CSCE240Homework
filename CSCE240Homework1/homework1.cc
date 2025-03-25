// Copyright 2025 Simion Cartis
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int findBaseTen(int, int);
void finalOutput(int, int, int);
int findPower(int, int, int);
int main() {
  int num;
  int base;
  char moreNum;
  int largestNumIndex = 1, currentNum, largestNum = 0, index = 0;

  do {
    cin >> num >> base >> moreNum;

    if (base <= 1 || base >= 10) {  // Ensures inputted base is valid
      cout << "Base Not Accepted" << endl;
      return 0;
    }
    cout << (currentNum = findBaseTen(num, base)) << endl;
    ++index;
    if (currentNum > largestNum || index == 1) {  // If an inputted value
      largestNum = currentNum;  // is larger than the current largest value,
      largestNumIndex = index;  // changes largest value to the current value
    }
  } while (moreNum != 'n');
  finalOutput(index, largestNumIndex, largestNum);
  return 0;
}

// Finds the numbers value in base 10.
// Parameters are the number and the desired base.
// Returns the number's value in base 10
  int findBaseTen(int num, int base) {
    int index = 0;
    int decimalValue = 0;
    while (num != 0) {
      int power = 1;
      int digit = num%10;
      if (digit >= base) {
        cout << "Invalid Digit(s) in Number" << endl;
        exit(0);
      }
      if (digit != 0) {
        if (index == 0) {
          decimalValue = digit;
          ++index;
          num = num/10;
          continue;
        } else {
          power = findPower(power, base, index);
        }
        decimalValue += power * digit;
      }
      num = num/10;
      ++index;
    }
    return decimalValue;
  }

  // finds what the powered value of a digit in a given number
  // parameters are the powered value, the number's base,
  // and the index of where the digit is within the number
  // returns the powered value which will then be multiplied 
  // by whatever the current digit in the number that
  // is currently being operated on
  int findPower(int power, int base, int index){
    for (int i = 1; i<= index; ++i) {
            power *= base;  // Is the power operation that multiplies
          }
    return power;
  }

// Goes through and prints the possible final outputs for the program.
// parameters are the index, the largest number's index, and the largest number
  void finalOutput(int index, int largestNumIndex, int largestNum) {
    if (largestNumIndex%100 >= 11 && largestNumIndex%100 <= 13) {
      cout << "Of the " << index << " values input, the " << largestNumIndex
           <<"th value entered (" <<largestNum << ") was the largest" << endl;
      return;
    }
    switch (largestNumIndex%10) {
      case 1:
        cout << "Of the " << index << " values input, the " << largestNumIndex
             <<"st value entered (" << largestNum << ") was the largest"
             << endl;
        break;
      case 2:
        cout << "Of the " << index << " values input, the " << largestNumIndex
             <<"nd value entered (" << largestNum << ") was the largest"
             << endl;
        break;
      case 3:
        cout << "Of the " << index << " values input, the " << largestNumIndex
             <<"rd value entered (" << largestNum << ") was the largest"
             << endl;
        break;
      default:
         cout << "Of the " << index << " values input, the " << largestNumIndex
              <<"th value entered (" << largestNum << ") was the largest"
              << endl;
    }
  }
