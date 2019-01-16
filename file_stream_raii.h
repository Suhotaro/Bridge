#pragma once

#include <fstream>

class FileStreamRAII final
{
public:
	explicit FileStreamRAII(std::ifstream& _stream) : stream(_stream) {}

	FileStreamRAII(const FileStreamRAII&) = delete;
	FileStreamRAII& operator=(const FileStreamRAII&) = delete;

	FileStreamRAII(FileStreamRAII&&) = delete;
	FileStreamRAII& operator=(FileStreamRAII&&) = delete;

	~FileStreamRAII();

private:
	std::ifstream& stream;
};
