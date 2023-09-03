#include "contactsreader.h"
#include "Processor.h"
#include "dbtypes.h"

//namespace
//{
//const std::vector<Contact> mockData {
//    {"Wylie", "Johns", "380860830"},
//    {"Petya", "Pupkin", "39238981"},
//    {"Kksjda", "Popov", "580"},
//    {"KSJDL", "Johns", "38000000"},
//    {"PSDJ", "Pupkin", "39238981"},
//    {"SADSAD", "Popov", "12094280"},
//    {"GDSie", "Johns", "430"},
//    {"PeSDGDGya", "Pupkin", "39238981"},
//    {"IGDSDG", "Popov", "120921310"}
//};
//}

ContactsReader::ContactsReader()
    :m_processor {new db::Processor {}}
{

}

ContactsReader::~ContactsReader()
{}

std::vector<Contact> transform(const std::vector<db::DBEntry> &source)
{
    std::vector<Contact> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const db::DBEntry &entry)
        {
            return Contact {entry[1].toString(),
                            entry[2].toString(),
                            entry[3].toString()};
        });
    return target;
}

std::pair<bool, std::vector<Contact>> ContactsReader::requestContactsBrowse()
{
    db::DBResult result;
    std::vector<db::DBEntry> entries;
    std::tie(result, entries) = m_processor->requestTableData(db::DBTables::Contacts);
    return make_pair(result == db::DBResult::OK, transform(entries));
}
