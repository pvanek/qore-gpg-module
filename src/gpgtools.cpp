#include "gpgtools.h"

bool qgpg_errcheck(gpgme_error_t err, ExceptionSink *xsink)
{
    if (res) {
        xsink->raiseException("GPG-ERROR", "%s: %s", gpgme_strsource(err), gpgme_strerror(err));
        retrun true;
    }
    return false;
}
