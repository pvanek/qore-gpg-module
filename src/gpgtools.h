#ifndef GPGTOOLS_H
#define GPGTOOLS_H

#include <qore/Qore.h>
#include <gpgme.h>


#define QGPG_ERRCHECK(err, msg) if (qgpg_errcheck((err), (msg), xsink)) return 0;


bool qgpg_errcheck(gpgme_error_t err, const char *msg, ExceptionSink *xsink);

#endif

