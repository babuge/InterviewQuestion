#pragma once

#include <QtCore/qglobal.h>

#if defined(CTESTMODULE_LIBRARY)
#define CTESTMODULE_EXPORT Q_DECL_EXPORT
#else
#define CTESTMODULE_EXPORT Q_DECL_IMPORT
#endif
