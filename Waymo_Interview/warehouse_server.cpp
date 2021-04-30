#include "warehouse_server.h"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "ping.h"
#include "position.h"
#include "vehicle.h"

namespace warehouse {
namespace {

std::vector<std::string> StrSplitOnComma(const std::string& s) {
  std::vector<std::string> substrings;
  std::string part;
  std::istringstream stream(s);
  while (std::getline(stream, part, ','))
    substrings.emplace_back(std::move(part));

  return substrings;
}

}  // namespace

std::map<std::string, double> WarehouseServer::GetAverageSpeeds() {
  std::map<std::string, double> avg_speeds = std::map<std::string, double>();
  for (Vehicle vehicle : vehicles_) {
    avg_speeds.emplace(vehicle.GetName(), vehicle.GetAverageSpeed());
  }
  return avg_speeds;
}

std::vector<std::string> WarehouseServer::GetMostTraveledSince(
    int max_results, long timestamp) {
    double max_dist=0;
    max_dist=vehicles_[0].GetTotalDistance();
    
    for (int i=1;vehicles_.size();i++)
    {
        if(vehicles_[i].GetTotalDistance()>max_dist){
            max_dist=vehicles_[i].GetTotalDistance();
        }      
    }

  return std::vector<std::string>();
}

std::vector<std::string> WarehouseServer::CheckForDamage() {
  // TODO: Implement.
  return std::vector<std::string>();
}

void WarehouseServer::InitializeServer(std::string file_name) {
  std::ifstream input{file_name};
  if (!input.good())
    return;

  std::string line;
  while (std::getline(input, line)) {
    bool read_error = false;
    double x;
    double y;
    long timestamp;

    std::vector<std::string> parts = StrSplitOnComma(line);
    {
      size_t len_parsed = 0;
      x = std::stod(parts[1], &len_parsed);
      read_error = read_error || len_parsed == 0;
    }
    {
      size_t len_parsed = 0;
      y = std::stod(parts[2], &len_parsed);
      read_error = read_error || len_parsed == 0;
    }
    {
      size_t len_parsed = 0;
      timestamp = std::stol(parts[3], &len_parsed);
      read_error = read_error || len_parsed == 0;
    }
    if (read_error) {
      std::cerr << "Error parsing vehicle data line : " << line << std::endl;
    } else {
      ProcessPing(parts[0], x, y, timestamp);
    }
  }
}

void WarehouseServer::ProcessPing(std::string vehicle_name,
                                   double x, double y, long timestamp) {
  Ping ping = Ping(x, y, timestamp);
  if (vehicles_.empty() ||
      vehicles_.back().GetName() != vehicle_name) {
    vehicles_.push_back(Vehicle(vehicle_name));
  }
  vehicles_.back().GetPings().push_back(ping);
}

}  // namespace warehouse
