#include "../inc/ConfigFile.hpp"

ConfigFile::ConfigFile(const std::string name):name(name)
{
	if (!is_exist(name))
		throw Exception_ConfigFile("File don't exist");
	if (!is_file(name))
		throw Exception_ConfigFile("File is directory");
	if (!is_readable(name))
		throw Exception_ConfigFile("File is not readable");
	else
	{
		struct stat st;
		if(stat(name.c_str(), &st) == 0)
			size = st.st_size;
		else
			throw Exception_ConfigFile("File can't get size");
	}
}

std::string	ConfigFile::readFile()const
{

	std::ifstream config_file(name.c_str());
	if (!config_file || !config_file.is_open())
	{
		throw Exception_ConfigFile("File can't be read");
		return NULL;
	}
	std::stringstream stream_binding;
	stream_binding << config_file.rdbuf();
	return (stream_binding.str());
}
std::string	ConfigFile::getName() const
{
	return name;
}
size_t	ConfigFile::getSize() const
{
	return size;
}