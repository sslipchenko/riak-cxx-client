/*  
 Copyright 2011 Basho Technologies, Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#ifndef RIAKCXX_BASIC_CLIENT_HPP_
#define RIAKCXX_BASIC_CLIENT_HPP_

#include <riak_client/cxx/riak_client_fwd.hpp>
#include <riak_client/cxx/basic/riak_result.hpp>
#include <riak_client/cxx/basic/response.hpp>
#include <riak_client/cxx/basic/bucket_properties.hpp>
#include <riak_client/cxx/basic/store_params.hpp>
#include <riak_client/cxx/object.hpp>
#include <cstddef>

namespace riak
{

class RIAKC_API basic_client
{
public:
    virtual response<bool> ping() = 0;
    virtual response<riak_result> fetch(const std::string& bucket,
            const std::string& key, int r, int pr) =0;
    virtual response<bool> del(const std::string& bucket,
            const std::string& key, int dw) = 0;
    virtual response<bucket_properties> fetch_bucket(
            const std::string& bucket) = 0;
    virtual response<bool> set_bucket(const std::string& bucket,
            const bucket_properties& properties) = 0;
    virtual response<uint32_t> client_id() = 0;
    virtual response<bool> client_id(uint32_t client_id) = 0;
    virtual response<riak_result> store(object_ptr object,
            const store_params& params) = 0;
    virtual response<string_vector> list_buckets() = 0;
    virtual response<string_vector> list_keys(const std::string& bucket) = 0;
};

enum RIAKC_API protocol
{
    PBC
};


RIAKC_API client_ptr new_client(const std::string& host,
        const std::string& port, const protocol protocol = PBC);

} // :: riak

#endif // include guard
