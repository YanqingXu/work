#ifndef _COMMON_TYPES_H_INCLUDED
#define _COMMON_TYPES_H_INCLUDED

#include "api.h"

#include <string>
#include <map>
#include <vector>

//
//	basic data type
//
#ifdef WIN32
typedef char				int8;
typedef unsigned char		uint8;

typedef short				int16;
typedef unsigned short		uint16;

typedef int					int32;
typedef unsigned int		uint32;

typedef __int64				int64;
typedef unsigned __int64	uint64;

#else

typedef char				int8;
typedef unsigned char		uint8;

typedef short				int16;
typedef unsigned short		uint16;

typedef int					int32;
typedef unsigned int		uint32;

typedef long long			int64;
typedef unsigned long long	uint64;
#endif

#endif	//_COMMON_TYPES_H_INCLUDED
