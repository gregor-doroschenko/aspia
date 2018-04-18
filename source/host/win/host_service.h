//
// PROJECT:         Aspia
// FILE:            host/host_service.h
// LICENSE:         GNU Lesser General Public License 2.1
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_HOST__HOST_SERVICE_H
#define _ASPIA_HOST__HOST_SERVICE_H

#include <QCoreApplication>
#include <QScopedPointer>

#include "base/win/scoped_com_initializer.h"
#include "base/file_logger.h"
#include "base/service.h"

namespace aspia {

class Server;

class HostService : public Service<QCoreApplication>
{
public:
    HostService();

protected:
    // Service implementation.
    void start() override;
    void stop() override;
    void sessionChange(quint32 event, quint32 session_id) override;

private:
    QScopedPointer<FileLogger> file_logger_;
    QScopedPointer<ScopedCOMInitializer> com_initializer_;
    QPointer<Server> server_;

    Q_DISABLE_COPY(HostService)
};

} // namespace aspia

#endif // _ASPIA_HOST__HOST_SERVICE_H