#include <syslog.h>
#include <iostream>
#include <cstdio>

class SyslogLogger {
   public:
    SyslogLogger() {
        openlog("udpspeed", LOG_PID, LOG_USER);
    }
    static void log(const char* str, ...) {
        char buffer[1024];
        va_list args;
        va_start(args, str);
        vsnprintf(buffer, sizeof(buffer), str, args);
        va_end(args);
        syslog(LOG_INFO, "%s", buffer);
    }
};
