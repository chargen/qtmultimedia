/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QMEDIANETWORKPAYLISTPROVIDER_P_H
#define QMEDIANETWORKPAYLISTPROVIDER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API. It exists purely as an
// implementation detail. This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qmediaplaylistprovider_p.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Multimedia)


class QMediaNetworkPlaylistProviderPrivate;
class Q_MULTIMEDIA_EXPORT QMediaNetworkPlaylistProvider : public QMediaPlaylistProvider
{
    Q_OBJECT
public:
    QMediaNetworkPlaylistProvider(QObject *parent=0);
    virtual ~QMediaNetworkPlaylistProvider();

    virtual bool load(const QNetworkRequest &request, const char *format = 0);

    virtual int mediaCount() const;
    virtual QMediaContent media(int pos) const;

    virtual bool isReadOnly() const;

    virtual bool addMedia(const QMediaContent &content);
    virtual bool addMedia(const QList<QMediaContent> &items);
    virtual bool insertMedia(int pos, const QMediaContent &content);
    virtual bool insertMedia(int pos, const QList<QMediaContent> &items);
    virtual bool removeMedia(int pos);
    virtual bool removeMedia(int start, int end);
    virtual bool clear();

public Q_SLOTS:
    virtual void shuffle();

private:
    Q_DISABLE_COPY(QMediaNetworkPlaylistProvider)
    Q_DECLARE_PRIVATE(QMediaNetworkPlaylistProvider)
    Q_PRIVATE_SLOT(d_func(), void _q_handleParserError(QPlaylistFileParser::ParserError err, const QString &))
    Q_PRIVATE_SLOT(d_func(), void _q_handleNewItem(const QVariant& content))
};

QT_END_NAMESPACE

QT_END_HEADER


#endif // QMEDIANETWORKPAYLISTSOURCE_P_H