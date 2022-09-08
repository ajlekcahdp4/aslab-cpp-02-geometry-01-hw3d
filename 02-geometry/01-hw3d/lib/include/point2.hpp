/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <tsimmerman.ss@phystech.edu>, wrote this file.  As long as you
 * retain this notice you can do whatever you want with this stuff. If we meet
 * some day, and you think this stuff is worth it, you can buy me a beer in
 * return.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <cmath>

namespace throttle {
namespace geometry {

template <typename T> struct point2 {
  T x;
  T y;

  static point2 origin() { return {0, 0}; }

  std::pair<unsigned, T> max_component() const { return (*this - origin()).max_component(); }

  T &operator[](unsigned index) { return (*this - origin())[index]; }

  const T &operator[](unsigned index) const { return (*this - origin())[index]; }

  bool operator==(const point2 &p_other) const { return (x == p_other.x && y == p_other.y); }
  bool operator!=(const point2 &p_other) const { return !(*this == p_other); }
};

} // namespace geometry
} // namespace throttle

#include "vec2.hpp"

namespace throttle {
namespace geometry {

template <typename T> vec2<T> operator-(const point2<T> &lhs, const point2<T> &rhs) {
  return {lhs.x - rhs.x, lhs.y - rhs.y};
}

template <typename T> point2<T> operator+(const point2<T> &lhs, const vec2<T> &rhs) {
  return {lhs.x + rhs.x, lhs.y + rhs.y};
}

template <typename T> point2<T> operator+(const vec3<T> &lhs, const point2<T> &rhs) {
  return {lhs.x + rhs.x, lhs.y + rhs.y};
}

} // namespace geometry
} // namespace throttle
