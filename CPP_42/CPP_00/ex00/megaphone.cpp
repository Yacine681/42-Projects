#include <iostream>
#include <ctype.h>

int main(int argc, char **argv)
{
    int i;
    int a;

    i = 1;
    a = 0;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (argv[i])
        {
            while (argv[i][a])
            {
                argv[i][a] = toupper(argv[i][a]);
                a++;
            }
            std::cout << argv[i];
            a = 0;
            i++;
        }
    }
    std::cout << "\n";
    return (0);
}
