#ifndef WAREHOUSE_VEHICLE_H_
#define WAREHOUSE_VEHICLE_H_

#include <vector>

#include "ping.h"

namespace warehouse {

//  A named vehicle with a sequence of pings.
class Vehicle {
 public:
  Vehicle(std::string name) : name_(name), pings_(std::vector<Ping>()) {}

  // Returns the name of the vehicle.
  std::string GetName() {
    return name_;
  }


  // Returns the pings for the vehicle, in chronological order (earliest first).
  std::vector<Ping>& GetPings() {
    return pings_;
  }

  // Determines the total distance covered by the pings.
  static double GetTotalDistance(std::vector<Ping> pings);

  // Determines the total distance traveled by the vehicle.
  double GetTotalDistance();

  // Determines the average speed of the vehicle.
  double GetAverageSpeed();

 private:
  std::string name_;
  std::vector<Ping> pings_;
};

}  // namespace warehouse

#endif  // WAREHOUSE_VEHICLE_H_