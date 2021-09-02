/*
 * Copyright 2019-2020, Offchain Labs, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <avm_values/code.hpp>

Code::~Code() = default;

void CoreCode::commitChanges(
    RunningCode& code,
    const std::map<uint64_t, uint64_t>& segment_counts) {
    const std::unique_lock<std::shared_mutex> lock(mutex);
    impl->next_segment_num = code.fillInCode(impl->segments, segment_counts);
}
