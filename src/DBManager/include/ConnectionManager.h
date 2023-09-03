#pragma once

#include <memory>

namespace db {
class ConnectionManager
{
public:
    ConnectionManager(const ConnectionManager &) = delete;
    ConnectionManager& operator= (const ConnectionManager &) = delete;
    ~ConnectionManager();

    static ConnectionManager& instance();
    bool isValid() const;

private:
    ConnectionManager();
    struct ConnectionManagerPrivate;
    std::unique_ptr<ConnectionManagerPrivate> m_d;
};
}
