#pragma once

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <dirent.h>
#include <vector>
# include <sys/socket.h>
# include <netinet/in.h>
# include <sys/select.h>
# include <arpa/inet.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_URI_LENGTH 4096
#define CONNECTION_TIMEOUT 60 
#define MESSAGE_BUFFER 40000


bool	is_file(std::string	name);
bool	is_directory(std::string name);
bool	is_readable(std::string name);
bool	is_exist(std::string name);


// std::string to_lower(std::string str);
void to_lower( std::string &str);
std::string statusCodeString(short statusCode);
int ft_stoi(std::string str);
std::string getErrorPage(short _code);
std::string file_deleted(const std::string name);
std::string file_upload(const std::string name);
std::string upload_list(std::string path);
template <typename T>
std::string toString(const T val);
std::string directory_list(std::string path, std::string loc);
unsigned int fromhectoDec(const std::string& nb);