bool isPalindrome(int x)
{
    if (x < 0)
    {
        return 0;
    }

    int left = 0;
    int right = 0;
    int result = 1;
    char *src = (char *)malloc(127 * sizeof(char));

    sprintf(src, "%d", x);
    right = strlen(src) - 1;
    while (left < right)
    {
        if (src[left] != src[right])
        {
            result = 0;
        }
        ++left;
        --right;
    }

    return result;
}