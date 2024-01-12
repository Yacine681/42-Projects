#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <math.h>
#include <limits.h>
#include <iomanip>

void ft_parse(char *argv);
void toDouble(double const &ft_double, char *argv);
void toChar(char const &ft_char, double ft_double, char *argv);
void toInt(double const &ft_int, char *argv);
void toFloat(double const &ft_float, char *argv);

int	ft_strcmp(const char *s1, const char *s2);
int ft_check(char *argv);

#endif
