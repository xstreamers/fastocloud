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

#include <fastotv/commands_info/auth_info.h>

#include "server/subscribers/rpc/user_rpc_info.h"

namespace fastocloud {
namespace server {
namespace subscribers {

class ServerAuthInfo : public fastotv::commands_info::AuthInfo {
 public:
  typedef fastotv::commands_info::AuthInfo base_class;

  ServerAuthInfo();
  ServerAuthInfo(const fastotv::user_id_t& uid, const AuthInfo& auth);

  bool IsValid() const;
  fastotv::user_id_t GetUserID() const;
  bool Equals(const ServerAuthInfo& auth) const;

  rpc::UserRpcInfo MakeUserRpc() const;

 protected:
  common::Error DoDeSerialize(json_object* serialized) override;
  common::Error SerializeFields(json_object* deserialized) const override;

 private:
  fastotv::user_id_t uid_;
};

}  // namespace subscribers
}  // namespace server
}  // namespace fastocloud
