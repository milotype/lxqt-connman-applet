/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * lxqt-connman-applet - a gui frontend for connman
 *
 * Copyright: 2014-2015 Christian Surlykke
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef DBUS_TYPES_H
#define DBUS_TYPES_H

#include <QMetaType>
#include <QMap>
#include <QVariantMap>
#include <QDBusMetaType>
#include <QDBusConnection>
#include <QDBusObjectPath>
#include <QDBusAbstractInterface>
#include <QDebug>

typedef QPair<QDBusObjectPath, QVariantMap> ObjectProperties;
typedef QList<ObjectProperties> ObjectPropertiesList;

Q_DECLARE_METATYPE(ObjectProperties)
Q_DECLARE_METATYPE(ObjectPropertiesList)

void registerDbusTypes();
QDebug operator<<(QDebug debug, const QDBusObjectPath &path);




// Debugging

void show(const ObjectPropertiesList& opl);

void show(const QList<QDBusObjectPath>& paths);


#endif // DBUS_TYPES_H
