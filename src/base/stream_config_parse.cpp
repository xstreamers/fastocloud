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

#include "base/stream_config_parse.h"

#include <string>

#include <json-c/json_tokener.h>
#include <json-c/linkhash.h>

namespace {
common::Value* MakeValueFromJson(json_object* obj) {
  json_type obj_type = json_object_get_type(obj);
  if (obj_type == json_type_null) {
    return common::Value::CreateNullValue();
  } else if (obj_type == json_type_boolean) {
    return common::Value::CreateBooleanValue(json_object_get_boolean(obj));
  } else if (obj_type == json_type_double) {
    return common::Value::CreateDoubleValue(json_object_get_double(obj));
  } else if (obj_type == json_type_int) {
    return common::Value::CreateIntegerValue(json_object_get_int(obj));
  } else if (obj_type == json_type_string) {
    return common::Value::CreateStringValueFromBasicString(json_object_get_string(obj));
  } else if (obj_type == json_type_object) {
    common::HashValue* result = common::Value::CreateHashValue();
    json_object_object_foreach(obj, key, val) {
      json_type val_type = json_object_get_type(val);
      common::Value* value = nullptr;
      switch (val_type) {
        case json_type_null:
          value = common::Value::CreateNullValue();
          break;
        case json_type_boolean:
          value = common::Value::CreateBooleanValue(json_object_get_boolean(val));
          break;
        case json_type_double:
          value = common::Value::CreateDoubleValue(json_object_get_double(val));
          break;
        case json_type_int:
          value = common::Value::CreateIntegerValue(json_object_get_int(val));
          break;
        case json_type_string:
          value = common::Value::CreateStringValueFromBasicString(json_object_get_string(val));
          break;
        case json_type_object:
          value = MakeValueFromJson(val);
          break;
        case json_type_array:
          common::ArrayValue* arr = common::Value::CreateArrayValue();
          for (size_t i = 0; i < json_object_array_length(val); i++) {
            json_object* item = json_object_array_get_idx(val, i);
            arr->Append(MakeValueFromJson(item));
          }
          value = arr;
          break;
      }

      result->Insert(key, value);
    }
    return result;
  } else if (obj_type == json_type_array) {
    common::ArrayValue* arr = common::Value::CreateArrayValue();
    for (size_t i = 0; i < json_object_array_length(obj); i++) {
      json_object* item = json_object_array_get_idx(obj, i);
      arr->Append(MakeValueFromJson(item));
    }
    return arr;
  }

  DNOTREACHED();
  return nullptr;
}

}  // namespace

namespace fastocloud {

std::unique_ptr<common::HashValue> MakeConfigFromJson(const std::string& json) {
  if (json.empty()) {
    return nullptr;
  }

  json_object* obj = json_tokener_parse(json.c_str());
  if (!obj) {
    return nullptr;
  }

  std::unique_ptr<common::HashValue> res = MakeConfigFromJson(obj);
  json_object_put(obj);
  return res;
}

std::unique_ptr<common::HashValue> MakeConfigFromJson(json_object* obj) {
  json_type obj_type = json_object_get_type(obj);
  if (obj_type == json_type_object) {
    return std::unique_ptr<common::HashValue>(static_cast<common::HashValue*>(MakeValueFromJson(obj)));
  }

  return nullptr;
}

}  // namespace fastocloud
