#pragma once

#include <QtCore/qglobal.h>

#if defined(INTERVIEWQUESTION_LIBRARY)
#  define INTERVIEWQUESTION_EXPORT Q_DECL_EXPORT
#else
#  define INTERVIEWQUESTION_EXPORT Q_DECL_IMPORT
#endif
