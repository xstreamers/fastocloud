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

#include <string>

#include <common/error.h>
#include <common/file_system/path.h>

namespace fastocloud {
namespace utils {

common::ErrnoError CreateAndCheckDir(const std::string& directory_path);
void RemoveOldFilesByTime(const common::file_system::ascii_directory_string_path& dir,
                          common::utctime_t max_life_secs,
                          const char* ext);
void RemoveFilesByExtension(const common::file_system::ascii_directory_string_path& dir, const char* ext);

}  // namespace utils
}  // namespace fastocloud
