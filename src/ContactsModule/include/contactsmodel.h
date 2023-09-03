#pragma once


#include <QAbstractListModel>
#include <QQmlEngine>
#include <QDebug>

#include <vector>

#include "contact.h"
#include "contactsreader.h"


class ContactsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ContactsModel();
    static void registerMe(const std::string &moduleName);

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index = {}, int role = Qt::DisplayRole) const override;
private:
    ContactsReader m_contactsReader;
    std::vector<Contact> m_contacts;
    enum ContactRoles {
        FirstNameRole = Qt::UserRole + 1,
        SecondNameRole,
        PhoneNumberRole
    };

    bool updateContacts();
};

