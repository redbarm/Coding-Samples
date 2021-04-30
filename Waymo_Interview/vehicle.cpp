#include "vehicle.h"

#include <vector>

namespace warehouse {

double Vehicle::GetTotalDistance(std::vector<Ping> pings) {
  double sum=0;
  for (int i=0;pings.size()-1;i++){
      double a,b,c;
      a=pow((pings[i+1].position_.x_-pings[i].position_.x_),2);
      b=pow((pings[i+1].position_.y_-pings[i].position_.y_),2);
      c=sqrt(a+b);
      sum=sum+c;   
  }
  return sum;
}

double Vehicle::GetTotalDistance() {
  return GetTotalDistance(pings_);
}

double Vehicle::GetAverageSpeed() {
  double spd,tint,totalt;
  tint=0;
  totalt=0;
  spd=0;
  for (int i=0;pings_.size()-1;i++){
      tint=(pings_[i+1].timestamp_-pings_[i].timestamp_);
      totalt=totalt+tint;   
  }
  spd=GetTotalDistance()/totalt;  
  return spd;
}

}  // namespace warehouse

