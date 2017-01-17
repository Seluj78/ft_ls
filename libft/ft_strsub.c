#include "libft.h"

char  *ft_strsub(const char *s, unsigned int start, size_t len)
{
    char  *str;
    size_t i;

    i = 0;
    if (s)
    {
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		while (i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
    }
    return (NULL);
}
