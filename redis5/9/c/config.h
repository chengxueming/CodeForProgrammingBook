#ifndef __CONFIG_H
#define __CONFIG_H

#ifdef __APPLE__
#include <AvailabilityMacros.h>
#endif

#ifdef __linux__
#include <linux/version.h>
#include <features.h>
#endif

/* Test for polling API */
#ifdef __linux__
#define HAVE_EPOLL 1
#endif

#endif