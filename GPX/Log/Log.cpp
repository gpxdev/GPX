//
//  Log.cpp
//  GPX
//
//  Created by George Coomber on 2015-10-11.
//  Copyright © 2015 George Coomber. All rights reserved.
//

#include "Log.h"

#include <ctime>
#include <fstream>

namespace gp
{

//////////////////////////////////////////////////////////////////////////////////////////////

std::ofstream* Log::s_logFile = nullptr;
	
//////////////////////////////////////////////////////////////////////////////////////////////

Log::Log()
{
	s_logFile = new std::ofstream("RuntimeLog.txt");
}

//////////////////////////////////////////////////////////////////////////////////////////////

Log::~Log()
{
	if (s_logFile != nullptr)
		s_logFile->close();
	delete s_logFile;
}

//////////////////////////////////////////////////////////////////////////////////////////////

void Log::write(const char* logMessage)
{
	if (s_logFile != nullptr)
	{
		*s_logFile << getFormattedTime() << " - " << logMessage << std::endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////

const char* Log::getFormattedTime()
{
	std::time_t result;
	std::time(&result);
	std::string timeString = std::ctime(&result);
	if (!timeString.empty())
		timeString = timeString.substr(0, timeString.length() - 1);
	
	return timeString.c_str();
}

} // namespace gp
