#ifndef WAREHOUSE_WAREHOUSE_SERVER
#define WAREHOUSE_WAREHOUSE_SERVER

#include <map>
#include <vector>

#include "vehicle.h"

namespace warehouse {

class WarehouseServer {
 public:
  WarehouseServer() : vehicles_(std::vector<Vehicle>()) {}

  // Returns a Map from vehicle name to that vehicle's average speed for all
  // vehicles.
  std::map<std::string, double> GetAverageSpeeds();

  // Returns a sorted vector of size max_results of vehicle names corresponding
  // to the vehicles that have traveled the most distance since the given
  // timestamp.
  std::vector<std::string> GetMostTraveledSince(int max_results, long timestamp);

  // Returns an vector of names identifying vehicles that might have been
  // damaged through any number of risky behaviors, including collision with
  // another vehicle and excessive acceleration.
  std::vector<std::string> CheckForDamage();

  void InitializeServer(std::string file_name);

 private:
  // Vehicles is a vector of Vehicle instances
  std::vector<Vehicle> vehicles_;

  void ProcessPing(std::string vehicleName, double x, double y, long timestamp);
};

}  // namespace warehouse

#endif  // WAREHOUSE_WAREHOUSE_SERVER