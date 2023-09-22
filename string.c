#include "monty.h"

/**
 * _strcmp - compares two strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0 for success
 */
int _strcmp(const char *str1, const char *str2)
{
while (*str1 != '\0' && *str2 != '\0')
{
if (*str1 != *str2)
return (*str1 - *str2);
str1++;
str2++;
}
return (*str1 - *str2);
}

/**
 * _isdigit - Checks if d is a digit.
 * @d: a character
 * Return: Always 0.
 */
int _isdigit(int d)
{
if (d >= 48 && d <= 57)
return (1);
else
return (0);
}

/**
 * _atoi- conveerts a number to an integer
 * @s: the string to be converted
 * Return: Success;
*/
int _atoi(char *s)
{
int al = 1;
int x = 0;
unsigned int sum = 0;
/*check the sign of the number...*/
while (s[x] != '\0' && !(s[x] <= 57 && s[x] >= 48))
{
if (s[x] == 45)
al *= -1;
x++;
}
while (s[x] <= 57 && (s[x] >= 48 && s[x] != '\0'))
{
sum = (sum * 10) + (s[x] - '0');
x++;
}
sum *= al;
return (sum);
}
