#pragma once
#define REVERSE_RANGE_IMPLEMENTED
class RangeIterator {
  int current_;
  int step_;
public:
  RangeIterator(int current, int step) : current_(current), step_(step) {
  }

  int operator*() const {
    return current_;
  }

  RangeIterator& operator++() {
    current_ += step_;
    return *this;
  }

  bool operator!=(const RangeIterator& other) const {
    if (step_ == 0) {
      return false;
    }
    if (step_ > 0) {
      return current_ < other.current_;
    }
    return current_ > other.current_;
  }
};

class ReverseRangeIterator {
  int current_;
  int step_;
public:
  ReverseRangeIterator(int current, int step) : current_(current), step_(-step) {}

  int operator*() const {
    return current_;
  }

  ReverseRangeIterator& operator++() {
    current_ += step_;
    return *this;
  }

  bool operator!=(const ReverseRangeIterator& other) const {
    if (step_ == 0) {
      return false;
    }
    if (step_ < 0) {
      return current_ > other.current_;
    }
    return current_ < other.current_;
  }
};

class Range {
  int begin_;
  int end_;
  int step_;
public:
  explicit Range(int end) : begin_(0), end_(end), step_(1) {
  }

  Range(int begin, int end) : begin_(begin), end_(end), step_(1) {
  }

  Range(int begin, int end, int step) : begin_(begin), end_(end), step_(step) {
  }

  RangeIterator begin() const { // NOLINT
    return {begin_, step_};
  }

  RangeIterator end() const { // NOLINT
    return {end_, step_};
  }
  ReverseRangeIterator rbegin() const { // NOLINT
    if (step_ == 0) {
      return {end_, step_};
    }
    if (step_ > 0) {
      return {begin_ + ((end_ - begin_ + step_ - 1) / step_) * step_ - step_, step_};
    }
    return {begin_ + ((end_ - begin_ + step_ + 1) / step_) * step_ - step_, step_};
  }
  ReverseRangeIterator rend() const { // NOLINT
    return {begin_ - step_, step_};
  }
};