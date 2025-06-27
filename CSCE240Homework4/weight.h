// Copyright 2025 Simion Cartis
// Define a Weight class that has private integer data members for the
//    weight value - a non-negative real number (a double)
//    weight units - allow for pounds, ounces, kilograms, and grams only
//                   (a string)
// The class should ensure that the data members always remain in a consistent
// state.
#ifndef _WEIGHT_H_
#define _WEIGHT_H_
#include<iostream>
using std::cout;
using std::ostream;
#include<string>
using std::string;

class Weight {
  // Add a constructor to allow the user to initialize the value and units, in
  // that order, with default arguments of 0 and "pounds"
  // If the first argument value is invalid, the weight value should be
  // initialized to 0. If the second argument is invalid, the weight units
  // should be initialized to pound.
 public:
  explicit Weight(double value = 0, string unit = "pound");


  // Add mutator functions SetValue, and SetUnits that set the data member if
  // the argument is valid, and leave the data member unchanged if the argument
  // is invalid.
  Weight& SetValue(double value);
  Weight& SetUnits(string unit);
  // these return a Weight reference value in order to allow chaining of
  // function calls.

  // Add accessor functions GetHour, GetMinute, and GetSecond that return
  // a copy of the value of the corresponding data member.
  double GetValue() const {return value_;}
  string GetUnits() const {return unit_;}


  // Add a ConvertUnits function that takes a string parameter for units to
  // convert the Weight to. If the argument is valid, the object's value and
  // units should be updated to the equivalent weight in the new units. For
  // example, if the Weight object w has a value of 2 and units of "pounds"
  // then after the function call w.ConvertUnits("ounces"); w should have a
  // value of 32 and units of "ounces"
  // If the argument sent to the function is not "pounds" "ounces" "kilograms"
  // or "grams" then the function should leave the object unchanged.
  // Please see testweight2.cc for more examples.
  Weight& ConvertUnits(string unit);
  // this return a Weight reference value in order to allow chaining of
  // function calls.


  // note: you are welcome to add any additional member functions you would
  //       like



  // overload the <= operator to return true if the Weight on the left is
  // less than or equal to the Weight on the right, and false otherwise
  bool operator <= (Weight right) const;
  bool operator < (Weight right) const;
  double operator - (Weight right);
  // overloaded the strictly less than and minus operations

  // overload the stream insertion operator to display the Weight in the format:
  // value units
  // with a single space between the value and units
  friend ostream& operator << (ostream&, const Weight&);



// note: you are welcome to overload any other operators you would like

// private members of the class:
 private:
  double value_;
  string unit_;
};
#endif
