#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <mutex>
#include "PublicDefine.h"

class DllExport XLog{
public:
	enum Level
	{
		DEBUG,
		INFO,
		ERROR
	};

public:
	XLog(const std::string& logFilePath);

	~XLog();

	static XLog* GetInstance();

	static void InitLogger();

	static void SetLogLevel(XLog::Level level);

	Level GetLogLevel();

	static std::string GenerateLogFileName();

	void log(const std::string& message);

	std::string GetTimestamp();

private:
	std::ofstream logFile;
	static Level LogLevel;
	static XLog* instance;

	std::mutex mtx;  // ÃÌº”ª•≥‚¡ø
};

