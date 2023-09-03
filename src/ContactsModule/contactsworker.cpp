#include "contactsworker.h"

ContactsWorker::ContactsWorker()
{

}

bool ContactsWorker::requestBrowseContacts()
{

}

void ContactsWorker::onConnectionStateChanged(net::ConnectionState state)
{
    if (state == net::ConnectionState::Connected)
    {
        requestBrowseContacts();
    }
}
