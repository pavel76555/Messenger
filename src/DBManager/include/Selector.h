#pragma once

#include <QString>
#include <QVariantList>
#include <vector>

#include "dbtypes.h"
#include "Executor.h"

namespace db
{
class Selector
{
public:
    std::pair<DBResult,
              std::vector<DBEntry>> selectAll(const QString &tableName);

private:
    Executor m_executor;
    QString generateQuery(const QString &tableName) const;
};
}
