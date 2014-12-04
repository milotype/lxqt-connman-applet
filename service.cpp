#include "service.h"

Service::Service(QDBusObjectPath path) :
    NetConnmanServiceInterface("net.connman", path.path(), QDBusConnection::systemBus()),
    mPath(path),
    mProperties()
{
    connect(this, SIGNAL(PropertyChanged(QString,QDBusVariant)), this, SLOT(onPropertyChange(QString,QDBusVariant)));
}

void Service::setProperty(QString key, QVariant newValue)
{
    mProperties[key] = newValue;
}

void Service::onPropertyChange(QString key, QDBusVariant newValue)
{
    qDebug() << "Service::onPropertyChange" << key << ":" << newValue.variant();
    setProperty(key, newValue.variant());
}


QDebug operator<<(QDebug dbg, Service &service)
{
    dbg.nospace() << "Service(" << service.path().path() << ")";
    return dbg.maybeSpace();
}
