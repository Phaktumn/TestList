#define STREAM_FILE_H
#ifdef STREAM_FILE_H

#ifndef __cplusplus
#error A C++ compiler is required!
#endif

#include "stdafx.h"
#include <fstream>

#pragma once

class Print
{
public:
	Print();
	void toFile();
private:

};

class Read
{
public:
	Read();
	void fromFile();
private:

};

#endif
