#pragma once

#include <utility>
#include <vector>
#include <memory.h>

#include "contact.h"
namespace db {
class Processor;
}

class ContactsReader
{
public:
    ContactsReader();
    ~ContactsReader();
    std::pair<bool,
              std::vector<Contact>> requestContactsBrowse();
private:
    std::unique_ptr<db::Processor> m_processor;
};

