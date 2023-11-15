# XLog
a log lib
#使用方法
#先通过静态成员函数初始化日志对象，然后设置日志等级（默认DEBUG）
XLog::InitLogger()
XLog::SetLogLevel()
#日志库支持DEBUG和INFO两个等级，ERROR无论如何都会打印，设置为INFO的时候会屏蔽DEBUG日志
XLOG_DEBUG
XLOG_INFO
XLOG_ERROR
