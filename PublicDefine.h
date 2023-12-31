#pragma once

#define DllExport  __declspec(dllexport)

#define XLOG_DEBUG(format, ...) \
    do { \
        if (XLog::GetInstance()->GetLogLevel() <= XLog::DEBUG) { \
            char buffer[256]; \
            sprintf(buffer, format, __VA_ARGS__); \
            XLog::GetInstance()->log("[DEBUG]["+ XLog::GetInstance()->GetTimestamp() + "]" + std::string(buffer)); \
        } \
    } while (0)

#define XLOG_INFO(format, ...) \
    do { \
        if (XLog::GetInstance()->GetLogLevel() <= XLog::INFO) { \
            char buffer[256]; \
            sprintf(buffer, format, __VA_ARGS__); \
            XLog::GetInstance()->log("[INFO]["+ XLog::GetInstance()->GetTimestamp() + "]" +std::string(buffer)); \
        } \
    } while (0)

#define XLOG_ERROR(format, ...) \
    do { \
        if (XLog::GetInstance()->GetLogLevel() <= XLog::ERROR) { \
            char buffer[256]; \
            sprintf(buffer, format, __VA_ARGS__); \
            XLog::GetInstance()->log("[ERROR][" + XLog::GetInstance()->GetTimestamp() + "]" + std::string(buffer)); \
        } \
    } while (0)