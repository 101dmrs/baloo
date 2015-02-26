/*
   This file is part of the KDE Baloo project.
 * Copyright (C) 2015  Vishesh Handa <vhanda@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef BALOO_URLDOCUMENTDB_H
#define BALOO_URLDOCUMENTDB_H

#include "engine_export.h"
#include "postingiterator.h"

#include <QByteArray>
#include <lmdb.h>

namespace Baloo {

class BALOO_ENGINE_EXPORT UrlDocumentDB
{
public:
    explicit UrlDocumentDB(MDB_txn* txn);
    ~UrlDocumentDB();

    void put(const QByteArray& url, uint docId);
    uint get(const QByteArray& url);
    void del(const QByteArray& url);

    PostingIterator* prefixIter(const QByteArray& url);

private:
    MDB_txn* m_txn;
    MDB_dbi m_dbi;
};

}

#endif // BALOO_URLDOCUMENTDB_H
