/*
 * Copyright (c) 2011-2018, Meituan Dianping. All Rights Reserved.
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements. See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef CAT_CLIENT_C_CONTEXT_H
#define CAT_CLIENT_C_CONTEXT_H

#include "message_tree.h"

#include "lib/cat_static_queue.h"

typedef struct _CatContext {
    CatMessageTree *tree;
    CATStaticStack *transactionStack;
    int elementSize;
    unsigned long long lastTruncateTransDurationUs;
} CatContext;

CatContext *getCatContext();

CatMessageTree *getContextMessageTree();

void resetCatContext();

void catContextAdd(CatMessage *message);

void catContextAddTransChild(CatMessage *message, CatTransaction *trans);

void catContextAdjustForTruncatedTrans(CatTransaction *root);

void catContextStartTrans(CatTransaction *trans);

int catContextEndTrans(CatTransaction *trans);

CatTransaction *catContextPeekTransaction();


#endif //CAT_CLIENT_C_CONTEXT_H
