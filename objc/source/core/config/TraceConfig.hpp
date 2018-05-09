/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TraceConfig_hpp
#define TraceConfig_hpp

#include <WCDB/Config.hpp>

#pragma GCC visibility push(hidden)

namespace WCDB {

class TraceConfig : public Config {
public:
    static std::shared_ptr<Config> config();
    static constexpr const int order = INT_MIN;

    bool invoke(Handle *handle) const override;

    void setPerformanceTrace(const Handle::PerformanceTraceCallback &trace);
    void setSQLTrace(const Handle::SQLTraceCallback &trace);

protected:
    TraceConfig();
    TraceConfig(const TraceConfig &) = delete;
    TraceConfig &operator=(const TraceConfig &) = delete;

    std::shared_ptr<Handle::PerformanceTraceCallback> m_performanceTrace;
    std::shared_ptr<Handle::SQLTraceCallback> m_sqlTrace;
};

} //namespace WCDB

#pragma GCC visibility pop

#endif /* TraceConfig_hpp */