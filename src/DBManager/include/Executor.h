#pragma once

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariantList>
#include <utility>

#include "dbtypes.h"
#include "ConnectionManager.h"


namespace db
{
class Executor {
public:
    Executor();
    Q_DISABLE_COPY(Executor)

    std::pair<DBResult,
              QSqlQuery>execute(const QString &queryText, const DBEntry &args = {});

private:
    ConnectionManager &m_connectionManager;
};
}
