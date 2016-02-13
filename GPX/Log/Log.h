//
//  Log.h
//  GPX
//
//  Created by George Coomber on 2015-10-11.
//  Copyright © 2015 George Coomber. All rights reserved.
//

#pragma once

#include <iostream>
#include <string>

namespace gp
{

class Log
{
public:
	Log();
	~Log();
	
	static void write(const char* logMessage);
	static const char* getFormattedTime();
	
private:
	static std::ofstream* s_logFile;
};
	
}

