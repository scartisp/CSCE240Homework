// Copyright 2025 Simion Cartis
#include<iostream>
using std::ostream;
using std::cout;
#include<string>
using std::string;
#include"weight.h"

  Weight::Weight(double value, string unit) : value_(0), unit_("pounds") {
    SetValue(value);
    SetUnits(unit);
  }

  Weight& Weight::SetValue(double value) {
    if (value >= 0) {
      value_ = value;
    }
    return *this;
  }

  Weight& Weight::SetUnits(string unit) {
    if (unit == "pounds" || unit == "ounces" || unit == "grams"
        || unit == "kilograms") {
      unit_ = unit;
    }
    return *this;
  }

  Weight& Weight::ConvertUnits(string unit) {
    if (unit_ == "pounds") {  // nested if and elses for pound conversions
      if (unit == "ounces") {
        unit_ = unit;
        value_ *= 16;
        return *this;
      } else if (unit == "grams") {
        unit_ = unit;
        value_ *= 453.59237;
        return *this;
      } else if (unit == "kilograms") {
        unit_ = unit;
        value_ *= 0.453592;
        return *this;
      }
    } else if (unit_ == "ounces") {  // nested if and elses for
      if (unit == "pounds") {  // ounce conversions
        unit_ = unit;
        value_ *= 0.0625;
        return *this;
      } else if (unit == "grams") {
        unit_ = unit;
        value_ *= 28.3495;
        return *this;
      } else if (unit == "kilograms") {
        unit_ = unit;
        value_ *= 0.0283495;
        return *this;
      }
    } else if (unit_ == "grams") {  // nested if and elses for gram conversions
      if (unit == "pounds") {
        unit_ = unit;
        value_ *= 0.00220462;
        return *this;
      } else if (unit == "ounces") {
        unit_ = unit;
        value_ *= 0.035274;
        return *this;
      } else if (unit == "kilograms") {
        unit_ = unit;
        value_ *= 0.001;
        return *this;
      }
    } else if (unit_ == "kilograms") {  // nested if and elses for
      if (unit == "pounds") {  //  kilogram conversions
        unit_ = unit;
        value_ *= 2.20462;
        return *this;
      } else if (unit == "ounces") {
        unit_ = unit;
        value_ *= 35.274;
        return *this;
      } else if (unit == "grams") {
        unit_ = unit;
        value_ *= 1000;
        return *this;
      }
    }
  return *this;
  }

  bool Weight::operator <= (Weight right) const {
    right.ConvertUnits(unit_);
    return value_ <= right.GetValue();
  }

  bool Weight::operator < (Weight right) const {
    right.ConvertUnits(unit_);
    return value_ < right.GetValue();
  }

  double Weight::operator - (Weight right) {
    return this->value_ - right.ConvertUnits(this->unit_).GetValue();
  }  // the chaining of function calls workd because ConvertUnits returns
     //  a reference to the object.
  ostream& operator << (ostream& where_to, const Weight& weight) {
    where_to << weight.value_ << " " << weight.unit_;
    return where_to;
  }  // implementation of the overloaded insertion string operation
     // (which belongs to a friended class)
