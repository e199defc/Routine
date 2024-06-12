/*
 * Hash Table
 * Max Length String
 */

#define HASH_SIZE 256

int lengthOfLongestSubstring(char *s)
{
    int maxLength = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int hash[HASH_SIZE]; // Utilize an array as a hash table for ASCII values.
    memset(hash, 0, sizeof(hash));
    while (s[i] != '\0')
    {
        if (hash[s[i]])
        {
            for (k = j; s[k] != s[i]; ++k)
            {
                --hash[s[k]];
            }
            j = k + 1;
        }
        else
        {
            ++hash[s[i]];
            if (i - j + 1 > maxLength)
            {
                maxLength = i - j + 1;
            }
        }
        ++i;
    }
    return maxLength;
}