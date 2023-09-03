#include <QSqlQuery>
#include <QSqlRecord>
#include "Selector.h"

namespace db
{

std::pair<DBResult,
          std::vector<DBEntry>> Selector::selectAll(const QString &tableName)
{
    QString query{generateQuery(tableName)};

    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

    std::vector<DBEntry> returnData;

    if (result == DBResult::OK) {
        while (resultQuery.next())
        {
            const QSqlRecord &entryRecord {resultQuery.record()};
            DBEntry entryData;
            entryData.reserve(entryRecord.count());

            for (int i = 0; i < entryRecord.count(); ++i)
            {
                entryData.push_back(entryRecord.value(i));

            }

            returnData.push_back(std::move(entryData));
        }
    }

    return std::make_pair(result, returnData);
}

QString Selector::generateQuery(const QString &tableName) const
{
    QString query {"SELECT rowid, * FROM " + tableName};
    return query;
}

}
