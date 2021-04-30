
#ifndef WAREHOUSE_PING_H
#define WAREHOUSE_PING_H

#include "position.h"

#include <ostream>

namespace warehouse {

// A Ping represents a vehicle's position at a given timestamp
struct Ping {
  Position position_;
  // Timestamp of the ping, in seconds since a fixed (but arbitrary) epoch.
  long timestamp_;

   Ping(double x, double y, long timestamp)
       : position_(x,y),
       timestamp_(timestamp) {}

   friend std::ostream& operator<<(std::ostream& os, const Ping& ping) {
        return os << ping.position_ << " @ " << ping.timestamp_;
    }

    // The difference between the timestamps of the pings, in seconds. The
    // result is positive if ping1 is earlier than ping2.
    static long SecondsBetween(Ping ping1, Ping ping2) {
        return ping2.timestamp_ - ping1.timestamp_;
    }
};

}  // namespace warehouse

#endif  // WAREHOUSE_PING_H