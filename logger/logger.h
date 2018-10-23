#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "stdio.h"


#ifdef NODEBUG
#define LOG(fmt, ...) do {} while (0)
#else
#define LOG(fmt, ...) fprintf(stdout, "[DEBUG] %s:%s:%d: " fmt "\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif
#endif // !__LOGGER_H__

