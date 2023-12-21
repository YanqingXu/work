
#ifndef _COMMON_API_H_INCLUDED
#define _COMMON_API_H_INCLUDED

#ifdef LIBCOMMON_EXPORTS
#define COMMON_API __declspec(dllexport)
#else
#define COMMON_API __declspec(dllimport)
#endif

#endif	//_COMMON_API_H_INCLUDED
