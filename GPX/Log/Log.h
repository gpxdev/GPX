#pragma once

#include <iostream>
#include <string>

namespace std
{

class Log
{
	public:
		// Do not allow copying
		Log(Log& rhs) = delete;
		Log& operator=(const Log& rhs) = delete;
	
		static Log& getInstance();
	
		void writeError(const char* logMessage);
		void writeWarning(const char* logMessage);
	
	private:
		Log();
		~Log();
	
		const char* getFormattedTime();
	
	private:
		static ofstream* s_logFile;
};
	
} // namespace std

