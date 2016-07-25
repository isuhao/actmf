/*
 * Actor Multimedia Framework (actmf)
 * Copyright (C) 2016  Arash Shafiei
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef ACTMF_VIDEO_READER_H
#define ACTMF_VIDEO_READER_H

#include "actmf_interface/abstract_service.h"

namespace actmf {
  
  class video_reader : public abstract_service
  {
  private:
    cv::Mat frame;
    opencv_mat image;
    cv::VideoCapture * cap;
  protected:
    virtual caf::behavior awaiting_task();
  public:
    video_reader(caf::actor_config& cfg);
    ~video_reader();
  };
  
  class video_reader_factory : abstract_service_factory
  {
  protected:
   virtual caf::actor spawn();
  };
 
}

#endif // ACTMF_VIDEO_READER_H
