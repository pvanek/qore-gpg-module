/* -*- mode: c++; indent-tabs-mode: nil -*- */
/*
  libmagic Qore wrapper

  Qore Programming Language

  Copyright 2012 - 2013 Petr Vanek, Qore Technologies

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <qore/Qore.h>


QoreStringNode *gpg_module_init();                                                                                
void gpg_module_ns_init(QoreNamespace *rns, QoreNamespace *qns);                                                  
void init_gpg_functions(QoreNamespace& ns);
void gpg_module_delete();                                                                                         

// qore module symbols                                                                                              
DLLEXPORT char qore_module_name[] = "gpg";                                                                        
DLLEXPORT char qore_module_version[] = PACKAGE_VERSION;                                                             
DLLEXPORT char qore_module_description[] = "GNUPG/gpgme wrapper";                                                          
DLLEXPORT char qore_module_author[] = "Petr Vanek";                                                                 
DLLEXPORT char qore_module_url[] = "http://qore.org";                                                               
DLLEXPORT int qore_module_api_major = QORE_MODULE_API_MAJOR;                                                        
DLLEXPORT int qore_module_api_minor = QORE_MODULE_API_MINOR;                                                        
DLLEXPORT qore_module_init_t qore_module_init = gpg_module_init;                                                  
DLLEXPORT qore_module_ns_init_t qore_module_ns_init = gpg_module_ns_init;                                         
DLLEXPORT qore_module_delete_t qore_module_delete = gpg_module_delete;                                            
DLLEXPORT qore_license_t qore_module_license = QL_LGPL;


static QoreNamespace GPGNS("GPG");


QoreStringNode * gpg_module_init() {
    init_gpg_functions(GPGNS);
    return 0;
}

void gpg_module_ns_init(QoreNamespace *rns, QoreNamespace *qns) {
    qns->addInitialNamespace(GPGNS.copy());
}

void gpg_module_delete() {
    // nothing to do here in this case
}

