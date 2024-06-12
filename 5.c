/*
 * Patient & Concise
 *
 */

char *longestPalindrome(char *s)
{
    if (s == NULL)
        return NULL;

    int i = 0;
    int j = 0;
    int lenCur = 0;
    int strLen = strlen(s);
    int oddMax = 0;
    int oddIdx = 0;
    int evenMax = 0;
    int evenIdx = 0;
    char *result;

    for (i = 0; i < strLen; ++i)
    {
        lenCur = 0;
        for (j = 0; i - j >= 0 && i + j < strLen; ++j) // consice
        {
            if (s[i - j] == s[i + j])
            {
                lenCur = j;
            }
            else
            {
                break;
            }
        }
        lenCur = (lenCur << 1) + 1;
        if (lenCur > oddMax)
        {
            oddMax = lenCur;
            oddIdx = i;
        }

        lenCur = 0;
        for (j = 0; i - j >= 0 && i + j + 1 < strLen; ++j)
        {
            if (s[i - j] == s[i + j + 1])
            {
                lenCur = j + 1;
            }
            else
            {
                break;
            }
        }
        lenCur = lenCur << 1;
        if (lenCur > evenMax)
        {
            evenMax = lenCur;
            evenIdx = i;
        }
    }

    if (oddMax < evenMax)
    {
        result = (char *)malloc(evenMax + 1);
        strncpy(result, s + evenIdx - (evenMax >> 1) + 1, evenMax);
        result[evenMax] = '\0';
    }
    else
    {
        result = (char *)malloc(oddMax + 1);
        strncpy(result, s + oddIdx - (oddMax >> 1), oddMax);
        result[oddMax] = '\0';
    }

    return result;
}