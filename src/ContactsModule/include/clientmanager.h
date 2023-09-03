#pragma once

#include <QObject>
#include <QTcpSocket>

#include "contact.h"
#include "networktypes.h"
#include "connectionargumentsparser.h"


class ClientManager : public QObject
{
    Q_OBJECT
public:
    ClientManager(const net::ConnectionArgumentsParser &connectionSettings);

    constexpr static std::chrono::milliseconds reconnectionTime() {
        return std::chrono::seconds {5};
    }

private slots:
    void onSocketError(QAbstractSocket::SocketError socketError);
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

signals:
    void contactsResponse(const std::vector<Contact> &data);
    void connectionStateChanged(net::ConnectionState state);
    void reconnectionTimerStarted();


private:
    void connectToServer();
    void connectSocketSignals();

    const net::ConnectionArgumentsParser &m_connectionSettings;
    net::ConnectionState m_state;
    QTcpSocket m_serverSocket;

};
