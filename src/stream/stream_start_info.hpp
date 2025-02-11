/*  Copyright (C) 2014-2019 FastoGT. All right reserved.
    This file is part of fastocloud.
    fastocloud is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    fastocloud is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with fastocloud.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "stream/cmd_args.h"

#include "base/stream_config.h"
#include "base/stream_info.h"

namespace fastocloud {

struct StreamStartInfo {
  std::string feedback_dir;
  common::logging::LOG_LEVEL log_level;
  std::string streamlink_path;
  StreamConfig config_args;
  StreamInfo sha;
};

}  // namespace fastocloud
