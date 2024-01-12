#ifndef MIME_HPP
#define MIME_HPP

#include "utiles.hpp"

class Mime
{
    public:
        Mime();
        std::string getMimeType(std::string extension);
    private:
        std::map<std::string, std::string> _mime_types;
};

#endif// MIME_HPP