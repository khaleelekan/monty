#include <stdlib.h>

/**
 * Function to split a string into words.
 * @param str The input string.
 * @param delims Delimiter characters.
 * @return An array of strings (words) or NULL on failure.
 */
char **custom_strtow(char *str, char *delims);

/**
 * Function to check if a character is a delimiter.
 * @param ch The character to check.
 * @param delims Delimiter characters.
 * @return 1 if the character is a delimiter, 0 otherwise.
 */
int is_delim(char ch, char *delims);

/**
 * Function to get the length of a word.
 * @param str The string containing the word.
 * @param delims Delimiter characters.
 * @return The length of the word.
 */
int get_word_length(char *str, char *delims);

/**
 * Function to get the word count in a string.
 * @param str The input string.
 * @param delims Delimiter characters.
 * @return The word count.
 */
int get_word_count(char *str, char *delims);

/**
 * Function to get the next word in a string.
 * @param str The input string.
 * @param delims Delimiter characters.
 * @return A pointer to the beginning of the next word.
 */
char *get_next_word(char *str, char *delims);

// Implement the functions

char **custom_strtow(char *str, char *delims)
{
    char **words = NULL;
    int wc, wordLen, n, i = 0;

    if (str == NULL || !*str)
        return NULL;
    wc = get_word_count(str, delims);

    if (wc == 0)
        return NULL;
    words = malloc((wc + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;
    while (i < wc)
    {
        wordLen = get_word_length(str, delims);
        if (is_delim(*str, delims))
        {
            str = get_next_word(str, delims);
        }
        words[i] = malloc((wordLen + 1) * sizeof(char));
        if (words[i] == NULL)
        {
            while (i >= 0)
            {
                i--;
                free(words[i]);
            }
            free(words);
            return NULL;
        }
        n = 0;
        while (n < wordLen)
        {
            words[i][n] = *(str + n);
            n++;
        }
        words[i][n] = '\0';
        str = get_next_word(str, delims);
        i++;
    }
    words[i] = NULL;
    return words;
}

int is_delim(char ch, char *delims)
{
    int i = 0;

    while (delims[i])
    {
        if (delims[i] == ch)
            return 1;
        i++;
    }
    return 0;
}

int get_word_length(char *str, char *delims)
{
    int wLen = 0, pending = 1, i = 0;

    while (*(str + i))
    {
        if (is_delim(str[i], delims))
            pending = 1;
        else if (pending)
        {
            wLen++;
        }
        if (wLen > 0 && is_delim(str[i], delims))
            break;
        i++;
    }
    return wLen;
}

int get_word_count(char *str, char *delims)
{
    int wc = 0, pending = 1, i = 0;

    while (*(str + i))
    {
        if (is_delim(str[i], delims))
            pending = 1;
        else if (pending)
        {
            pending = 0;
            wc++;
        }
        i++;
    }
    return wc;
}

char *get_next_word(char *str, char *delims)
{
    int pending = 0;
    int i = 0;

    while (*(str + i))
    {
        if (is_delim(str[i], delims))
            pending = 1;
        else if (pending)
            break;
        i++;
    }
    return str + i;
}

