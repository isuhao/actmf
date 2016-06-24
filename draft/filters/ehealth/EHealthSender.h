/*
 * 
 *  Act Multimedia Framework (actmf)
 *  Copyright (C) 2014 Arash Shafiei
 *
 *  This file is part of actmf.
 *
 *  actmf is free software; you can redistribute it and/or 
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 3 of the License, or (at your option) any later version.
 *
 *  actmf is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with actmf.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef EHEALTHSENDER_H_
#define EHEALTHSENDER_H_

#include "core/Factory.h"
#include "core/Filter.h"
#include "core/Port.h"

#include <ehealthsensor/Sensor.h>
#include <filters/ehealth/tools/JSONHandler.h>
#include <filters/ehealth/tools/HTTPHandler.h>
#include <filters/ehealth/tools/Chronometer.h>

struct EHealthSender: public actmf::Filter {
private:

  actmf::InputPort<ehealthsensor::SensorData> * input;

  static actmf::FilterRegister<EHealthSender> reg;

  int mode;  
  int sendingPeriod;  
  int sessionDuration;
  int sessionGap;
  boolean gapPeriod;

  JSONHandler jsonHandler;    
  HTTPHandler httpHandler;
  Chronometer chronometer;

public:
  
  EHealthSender(const std::string& name);
  
  virtual void init();
  
  virtual void run(); 
  
  virtual ~EHealthSender();
  
};

#endif /* EHEALTHSENDER_H_ */