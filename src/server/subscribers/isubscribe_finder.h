/*  Copyright (C) 2014-2019 FastoGT. All right reserved.

    This file is part of FastoTV.

    FastoTV is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoTV is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoTV. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <common/error.h>

#include <fastotv/commands_info/auth_info.h>

#include "server/subscribers/commands_info/user_info.h"

namespace fastocloud {
namespace server {
namespace subscribers {

class ISubscribeFinder {
 public:
  virtual common::Error FindUser(const fastotv::commands_info::AuthInfo& auth,
                                 commands_info::UserInfo* uinf) const WARN_UNUSED_RESULT = 0;

  virtual ~ISubscribeFinder();
};

}  // namespace subscribers
}  // namespace server
}  // namespace fastocloud
