#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _putchar(char c) {
    return putchar(c);
}

int _islower(int c) {
    return (c >= 'a' && c <= 'z');
}

int _isalpha(int c) {
    return (_islower(c) || _isupper(c));
}

int _abs(int n) {
    return (n >= 0 ? n : -n);
}

int _isupper(int c) {
    return (c >= 'A' && c <= 'Z');
}

int _isdigit(int c) {
    return (c >= '0' && c <= '9');
}

int _strlen(char *s) {
    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }
    return length;
}

void _puts(char *s) {
    while (*s != '\0') {
        _putchar(*s);
        s++;
    }
    _putchar('\n');
}

char *_strcpy(char *dest, char *src) {
    char *original_dest = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return original_dest;
}

int _atoi(char *s) {
    int sign = 1;
    int result = 0;

    if (*s == '-') {
        sign = -1;
        s++;
    }

    while (*s != '\0') {
        if (*s >= '0' && *s <= '9') {
            result = result * 10 + (*s - '0');
        } else {
            break;
        }
        s++;
    }

    return sign * result;
}

char *_strcat(char *dest, char *src) {
    char *original_dest = dest;

    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return original_dest;
}

char *_strncat(char *dest, char *src, int n) {
    char *original_dest = dest;

    while (*dest != '\0') {
        dest++;
    }

    while (n > 0 && *src != '\0') {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    *dest = '\0';

    return original_dest;
}

char *_strncpy(char *dest, char *src, int n) {
    char *original_dest = dest;

    while (n > 0 && *src != '\0') {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    while (n > 0) {
        *dest = '\0';
        dest++;
        n--;
    }

    return original_dest;
}

int _strcmp(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    return (*s1 - *s2);
}

char *_memset(char *s, char b, unsigned int n) {
    char *original_s = s;

    while (n > 0) {
        *s = b;
        s++;
        n--;
    }

    return original_s;
}

char *_memcpy(char *dest, char *src, unsigned int n) {
    char *original_dest = dest;

    while (n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    return original_dest;
}

char *_strchr(char *s, char c) {
    while (*s != '\0') {
        if (*s == c) {
            return s;
        }
        s++;
    }

    return NULL;
}

unsigned int _strspn(char *s, char *accept) {
    unsigned int count = 0;

    while (*s != '\0' && _strchr(accept, *s) != NULL) {
        count++;
        s++;
    }

    return count;
}

char *_strpbrk(char *s, char *accept) {
    while (*s != '\0') {
        if (_strchr(accept, *s) != NULL) {
            return s;
        }
        s++;
    }

    return NULL;
}

char *_strstr(char *haystack, char *needle) {
    while (*haystack != '\0') {
        char *h = haystack;
        char *n = needle;

        while (*h == *n && *n != '\0') {
            h++;
            n++;
        }

        if (*n == '\0') {
            return haystack;
        }

        haystack++;
    }

    return NULL;
}

