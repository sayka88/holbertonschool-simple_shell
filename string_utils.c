#include "shell.h"


int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	    
	return (len);
}

char *_strcat(char *dest, char *src)
{
	int i;
	int len = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
	  {
	    dest[len] = src[i];
	    len++;
	  }
	dest[len] = '\0';
	
	return (dest);
}

char *_strcpy(char *dest, char *src)
{
	int i;
	int length = _strlen(src);

	for (i = 0; i < length; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

char *_strdup(char *str)
{
	char *dup;
	unsigned int i = 0, len = 0;

	if (str == NULL)
		return (NULL);

	/*
	while (str[len] != '\0')
		len++;
	*/
	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	while ((dup[i] = str[i]) != '\0')
		i++;

	return (dup);
}

int _strcmp(char *s1, char *s2)
{
  while (*s1 && *s2 && *s1 == *s2)
    {
      s1++;
      s2++;
    }

  return (*s1 - *s2);
}

int _str_n_cmp(char *s1, char *s2, int n)
{
	char c1, c2;

	while (n--)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0' || c1 != c2)
		  {
		    if (c1 > c2)
		      return (1);
		    else
		      {
			if (c1 < c2)
			  return (-1);
			else
			  return (0);
		      }
		  }
		    /** shortcut notation using ternary operator. Give it a try 
		     *	return (c1 > c2 ? 1 : (c1 < c2 ? -1 : 0));
		     */
	}
	return (0);
}
