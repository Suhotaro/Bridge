#include "stdafx.h"

#include "file_stream_raii.h"

FileStreamRAII::~FileStreamRAII()
{
	if (stream.is_open())
		stream.close();
}