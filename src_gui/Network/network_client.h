#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

#include <QObject>
#include <hv/WebSocketClient.h>
#include <hv/Http.h>

#include "../../tools/singleton.h"
#include "../../tools/thread.h"

class NetworkClient : public QObject
{
    Q_OBJECT
public:
    explicit NetworkClient(QObject *parent = nullptr);

signals:

public slots:
};

#endif // NETWORK_CLIENT_H