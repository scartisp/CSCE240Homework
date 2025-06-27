// Copyright 2025 Simion Cartis
// Define a WeightRange class that has two WeightRange objects as private
// data members: one for the smallest weight for the range and one for the
// largest weight for the range.
// The class should ensure that the value of the smallest Weight data member
// is less than or equal to the value of the largest Weight data member.
#ifndef _WEIGHTRANGE_H_
#define _WEIGHTRANGE_H_

#include<iostream>
using std::cout;
using std::ostream;
#include<string>
using std::string;
#include"weight.h"

class WeightRange {
  // Add a default constructor that initializes the smallest and largest
  // weights to 0 pounds
 public:
  WeightRange();

  // Add a constructor that takes two Weights (as constant reference
  // parameters)as arguments.
  // The constructor should initialize the data member for the smallest weight
  // for the range to the smaller of the two arguments, and it should set the
  // data member for the largest weight for the range to the larger of the two
  // arguments. Please see testweightrange1.cc for examples.

  explicit WeightRange(const Weight& s,
                      const Weight& l = Weight(0, "pounds"));


  // Add an accessor function to return the smallest weight for the range
  Weight GetSmallest() const {return smallest_weight_;}

  // Add an accessor function to return the largest weight for the range
  Weight GetLargest() const {return largest_weight_;}

  // Add a SetSmallestWeight member function that takes a const Weight& as an
  // argument.
  // The function should update the smallest Weight for the range if the value
  // of the argument is not larger the current value of the largest Weight
  // for the range.
  // If the value of the argument is larger than the current value of the
  // largest Weight for the range, the function should leave the smallest
  // Weight data member unchanged. Please see testWeightRange.cc for examples.
  WeightRange& SetSmallest(const Weight&);


  // Add a SetLargest member function that takes a const Weight& as an
  // argument.
  // The function should update the largest Weight for the range if the value
  // of the argument is not smaller than the current value of the smallest
  // Weight for the range.
  // If the value of the argument is smaller than the current value of the
  // smallest weight for the range, the function should leave the largest
  // Weight data member unchanged.
  WeightRange& SetLargest(const Weight&);

  // Add an InRange function that takes a const Weight& as the first parameter,
  // and a bool (that defaults to true) as the second parameter.
  // The function will return true if the Weight argument is within the
  // WeightRange, and false if the Weight argument is not within the weight
  // range. The second argument determines whether or not the endpoints of
  // the WeightRange should (true) or should not (false) be considered in range.
  // For example,
  //    Weight w1(10, "pounds"), w2(20, "pounds");
  //    WeightRange wr(w1, w2);
  //    wr.InRange(w1);  // should return true since the default argument of
  //                     // true means the endpoints of the range are in range
  //    wr.InRange(w1, false);  // should return false since the second
  //                            // argument of false means the endpoints of the
  //                            // range are not in range.
  // See testweightrange3.cc for more examples.
  bool InRange(const Weight& new_weight, bool is_inclusive = true);


  // Add a Width member function that returns a Weight representing the
  // difference between the largest Weight in the range and the smallest
  // Weight in the range. The units of the returned value should match the
  // units of the data member for the largest weight in the range.
Weight Width();

// overload the stream insertion operator to display the weight range in the
// format smallest weight - largest weight

friend ostream& operator << (ostream&, const WeightRange&);

 private:
  Weight smallest_weight_;
  Weight largest_weight_;
};
#endif
