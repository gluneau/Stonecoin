#ifndef STONECOIN_UPDATER_H
#define STONECOIN_UPDATER_H

#include "chainparamsbase.h"
#include "clientversion.h"
#include "rpcclient.h"
#include "rpcprotocol.h"
#include "util.h"
#include "utilstrencodings.h"
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/predef.h>
#include <boost/thread/thread.hpp>
#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/http.h>
#include <event2/keyvalq_struct.h>
#include <fcntl.h> /// POSIX file control
#include <unistd.h>

#include "../versionbits.h"
#include <univalue.h>
#include <limits.h>

typedef enum {
    WINDOWS_64,
    WINDOWS_32,
    LINUX_64,
    LINUX_32,
    PI2,
    MAC_OSX,
    UNKNOWN
} updater_ostype;


/* Internal use only: Functions that might be missing from <sys/queue.h> */
#ifndef TAILQ_FIRST
#define TAILQ_FIRST(head) ((head)->tqh_first)
#endif
#ifndef TAILQ_END
#define TAILQ_END(head) NULL
#endif
#ifndef TAILQ_NEXT
#define TAILQ_NEXT(elm, field) ((elm)->field.tqe_next)
#endif

#ifndef TAILQ_FOREACH
#define TAILQ_FOREACH(var, head, field) \
    for ((var) = TAILQ_FIRST(head);     \
         (var) != TAILQ_END(head);      \
         (var) = TAILQ_NEXT(var, field))
#endif

updater_ostype getCurrentOs();
bool updateFile(const char* oldFile, const char* newFile);
void downloadUpdate(Consensus::Params& params);
bool downloadFile(std::string url, std::string saveas);

#endif