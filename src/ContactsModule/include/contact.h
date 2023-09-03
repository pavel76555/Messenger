#pragma once

#include <QString>

class Contact
{
public:
    Contact() = default;
    Contact(QString firstName, QString secondName, QString phone);

    QString phone() const;
    QString firstName() const;
    QString secondName() const;

private:
    QString m_firstName;
    QString m_secondName;
    QString m_phone;
};


