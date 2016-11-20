/*
 * exitManagement.h
 *
 *  Created on: 27/06/2015
 *      Author: PiperoT100TA
 */

#pragma once

#include <cstdio>
#include "logger.h"

//#define LOG_TAG "ExitManagement"

namespace threemonkeybits
{
	void waitKeyAndExit(const int id)
	{
		//LOGE("Unusual exit with id: %d", id);
		getchar();
		exit(id);
	}
}	// threemonkeybits
