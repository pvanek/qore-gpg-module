#include "gpgtools.h"


bool qgpg_errcheck(gpgme_error_t err, const char * msg, ExceptionSink *xsink)
{
    if (err) {
        xsink->raiseException("GPG-ERROR", "%s: %s: %s", msg, gpgme_strsource(err), gpgme_strerror(err));
        return true;
    }
    return false;
}

