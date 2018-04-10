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

#import "WTCWINQTestCase.h"

@interface WTCWithClauseTests : WTCWINQTestCase

@end

@implementation WTCWithClauseTests

- (void)testWithClause
{
    WINQAssertEqual(WCDB::WithClause()
                        .with(self.class.cteTableName, self.class.statementSelect),
                    @"WITH testTable AS(SELECT testColumn FROM testTable)");

    std::string tableName2 = "testTable2";
    WCDB::CTETableName cteTableName2(tableName2);
    WCDB::StatementSelect statementSelect2 = WCDB::StatementSelect()
                                                 .select(self.class.resultColumn)
                                                 .from(WCDB::TableOrSubquery(tableName2));

    WINQAssertEqual(WCDB::WithClause()
                        .with(self.class.cteTableName, self.class.statementSelect)
                        .with(cteTableName2, statementSelect2),
                    @"WITH testTable AS(SELECT testColumn FROM testTable), testTable2 AS(SELECT testColumn FROM testTable2)");

    WINQAssertEqual(WCDB::WithClause()
                        .withRecursive(self.class.cteTableName, self.class.statementSelect),
                    @"WITH RECURSIVE testTable AS(SELECT testColumn FROM testTable)");
}

@end