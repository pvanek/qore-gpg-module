#ifndef GPGTOOLS_H
#define GPGTOOLS_H

#define QGPG_ERRCHECK(err) \
    if (gpg_errcheck((err))) \
        return 0;


bool qgpg_errcheck(int res, ExceptionSink *xsink);

#endif

