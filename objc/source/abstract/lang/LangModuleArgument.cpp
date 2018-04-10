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

#include <WCDB/Lang.h>

namespace WCDB {

namespace Lang {

ModuleArgument::ModuleArgument() : type(Type::NotSet)
{
}

CopyOnWriteString ModuleArgument::SQL() const
{
    std::string description;
    switch (type) {
        case Type::TableConstraint:
            assert(!tableConstraint.empty());
            description.append(tableConstraint.description().get());
            break;
        case Type::ColumnDef:
            assert(!columnDef.empty());
            description.append(columnDef.description().get());
            break;
        case Type::LeftRight:
            assert(!left.empty() && !right.empty());
            description.append(left.get() + "=" + right.get());
            break;
        default:
            assert(false);
            break;
    }
    return description;
}

} // namespace Lang

} // namespace WCDB