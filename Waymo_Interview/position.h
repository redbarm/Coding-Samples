#ifndef WAREHOUSE_POSITION_H_
#define WAREHOUSE_POSITION_H_

#include <cmath>
#include <ostream>

namespace warehouse {

 // A Position represents an x, y coordinate in a given warehouse. Position
 // can be used to determine how far apart or near together two vehicles are.
struct Position {
  double x_;
  double y_;

  Position(double x, double y) : x_(x), y_(y) {}

  friend std::ostream& operator <<(std::ostream& os, const Position& position) {
      return os << "(" << position.x_ << ", " << position.y_ << ")";
  }

  friend bool operator==(const Position& lhs, const Position& rhs) {
    return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
  }

  // Determines the distance between two Positions
  // Distance is calculated as the Euclidean distance in two dimensions
  // https://en.wikipedia.org/wiki/Euclidean_distance
  static double GetDistance(Position position1, Position position2) {
    double xDiff = std::abs(position1.x_ - position2.x_);
    double yDiff = std::abs(position1.y_ - position2.y_);
    return std::sqrt(std::pow(xDiff, 2) + std::pow(yDiff, 2));
  }

};

}  // namespace warehouse

#endif  // WAREHOUSE_POSITION_H_