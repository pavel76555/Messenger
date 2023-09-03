#include "Processor.h"
#include "Selector.h"
#include "dbmapper.h"
#include "Manipulator.h"

#include <mutex>

namespace db
{

struct Processor::ProcessorPrivate
{
    Selector selector;
    Manipulator manipulator;
// TEST
    std::once_flag initialized;
    void insertMockData();
//ENDTEST
};

Processor::Processor()
    :m_d {new ProcessorPrivate {}}
{
}

Processor::~Processor()
{}

std::pair<DBResult,
          std::vector<DBEntry> > Processor::requestTableData(DBTables table)
{
// TEST
    auto inserter = [this] {
        m_d->insertMockData();
    };

    std::call_once(m_d->initialized, inserter);
//ENDTEST
    const auto &result {m_d->selector.selectAll(TableMapper.at(table))};
    return result;
}

void Processor::ProcessorPrivate::insertMockData()
{
    manipulator.insertRow("Contacts", {"Ivan", "Popov", "38989819"});
    manipulator.insertRow("Contacts", {"Alexey", "Kulagin", "872387323"});
    manipulator.insertRow("Contacts", {"Pavel", "Popov", "34123213214"});
    manipulator.insertRow("Contacts", {"Ya", "Kulagin", "23123213123"});
    manipulator.insertRow("Contacts", {"Andrey", "Popov", "21312123"});
    manipulator.insertRow("Contacts", {"Alexander", "SASHA", "213231321"});
    manipulator.insertRow("Contacts", {"Doter", "Popov", "123221313"});
    manipulator.insertRow("Contacts", {"Sanya", "SANYA", "546365"});
    manipulator.insertRow("Contacts", {"Ivan", "Popov", "36536565"});
    manipulator.insertRow("Contacts", {"Alexey", "Kulagin", "345365"});
    manipulator.insertRow("Contacts", {"Ivan", "Popov", "354665"});
    manipulator.insertRow("Contacts", {"Alexey", "Kulagin", "3563546"});
}

}
