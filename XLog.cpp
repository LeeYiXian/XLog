#include "XLog.h"

XLog* XLog::instance = nullptr;
XLog::Level XLog::LogLevel = DEBUG;

XLog::XLog(const std::string& logFilePath) {
	logFile.open(logFilePath, std::ios::out | std::ios::trunc);
	if (!logFile.is_open()) {
		throw std::runtime_error("Failed to open log file");
	}
}

XLog::~XLog() {
	if (logFile.is_open()) {
		logFile.close();
	}
}

XLog* XLog::GetInstance()
{
	if (instance == NULL)
	{
		std::cout << "XLog Object not init!";
		return NULL;
	}
	return instance;
}

void XLog::InitLogger() {
	instance = new XLog(GenerateLogFileName());
}

void XLog::SetLogLevel(XLog::Level level) {
	LogLevel = level;
}

XLog::Level XLog::GetLogLevel()
{
	return LogLevel;
}

std::string XLog::GenerateLogFileName() {
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::tm* now_tm = std::localtime(&now_c);

	std::stringstream ss;
	ss << "./log/log_"
		<< std::put_time(now_tm, "%m_%d_%H_%M_%S");

	std::string logDir = "./log";
	if (!std::filesystem::exists(logDir)) {
		std::filesystem::create_directory(logDir);
	}

	return ss.str();
}

void XLog::log(const std::string& message) {
	std::lock_guard<std::mutex> lock(mtx);  // 获取锁
	if (logFile.is_open()) {
		logFile << message << std::endl;
	}
}

