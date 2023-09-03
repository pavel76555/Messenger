#pragma once

#include "dbtypes.h"

namespace db
{
static const std::map<DBTables, QString> TableMapper {
    {DBTables::Contacts, "Contacts"}
};

static const std::map<QString, QString> TablesMapping {
    {"Contacts", "FirstName, SecondName, PhoneNumber" }

};

}
