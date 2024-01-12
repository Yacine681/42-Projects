#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    char str[100];

    size_t pos;

    std::string fichier;
    std::string x = argv[2];
    std::string y = argv[3];
    std::ifstream input_file(argv[1]);

    if (argc != 4)
    {
        std::cout << "Error arg : ./file file_path str1 str2" << std::endl;
        return 0;
    }

    if (x.length() == 0 || y.length() == 0)
    {
        std::cout << "Error : empty string" << std::endl;
        return (0);
    }

    if (!input_file)
    {
        std::cout << "Error : file not found" << std::endl;
        return (0);
    }

    strcpy(str, argv[1]);
    char *replace = strcat(str, ".replace");                   
    std::ofstream tfile(replace, std::ios::binary);

    while (getline(input_file, fichier))
    {
        pos = fichier.find(x);
        while (pos != std::string::npos)
        {
            fichier.erase(pos, x.length());
            fichier.insert(pos, y);
            pos = fichier.find(x);
        }
        tfile << fichier << std::endl;
    }
}
