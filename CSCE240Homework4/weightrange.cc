// Copyright 2025 Simion Cartis
#include<iostream>
using std::ostream;
using std::cout;
#include<string>
using std::string;
#include"weight.h"
#include"weightrange.h"

// default constructor implementation
WeightRange::WeightRange() {
  smallest_weight_ = Weight();
  largest_weight_ = Weight();
  }

  // parameterized constructor implementation
  WeightRange::WeightRange(const Weight& s, const Weight& l)
      : smallest_weight_(s), largest_weight_(l) {
    if (largest_weight_ < smallest_weight_) {
      smallest_weight_ = l;
      largest_weight_ = s;
    }
  }

  WeightRange& WeightRange::SetSmallest(const Weight& new_weight) {
    if (new_weight <= largest_weight_) {
      smallest_weight_ = new_weight;
    }
    return *this;
  }

  WeightRange& WeightRange::SetLargest(const Weight& new_weight) {
    if (smallest_weight_ <= new_weight) {
      largest_weight_ = new_weight;
    }
    return *this;
  }

  bool WeightRange::InRange(const Weight& new_weight, bool is_inclusive) {
    if (is_inclusive) {
      return (new_weight <= largest_weight_ && smallest_weight_ <= new_weight);
    }
      return (new_weight < largest_weight_ && smallest_weight_ < new_weight);
  }

  Weight WeightRange::Width() {
    double new_value = largest_weight_ - smallest_weight_;
    return Weight(new_value, largest_weight_.GetUnits());
  }

  ostream& operator << (ostream& where_to, const WeightRange weight_range) {
    where_to << weight_range.GetSmallest() << " - "
             << weight_range.GetLargest();
    return where_to;
  }  // access the overloaded insertion string
     // function in the Weight class to work
