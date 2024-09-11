#pragma once

#include <QtCore/qglobal.h>

#if defined(TESTMODULE_LIBRARY)
#  define TESTMODULE_EXPORT Q_DECL_EXPORT
#else
#  define TESTMODULE_EXPORT Q_DECL_IMPORT
#endif
