/*
 * careful about the word
 */

int myAtoi(char *s)
{
    if (s == NULL)
        return 0;

    int i = 0;
    int ans = 0;
    int isNeg = 0;
    int isOverflow = 0;
    int upperLimit = INT_MAX / 10;
    int lowerLimit = INT_MIN / 10;
    int lenStr = strlen(s);

    while (i < lenStr && s[i] == ' ')
    {
        ++i;
    }
    if (s[i] == '-' || s[i] == '+')
    {
        isNeg = s[i] == '-';
        ++i;
    }
    while (i < lenStr && s[i] >= '0' && s[i] <= '9')
    {
        if (ans > upperLimit || ans < lowerLimit || ans == upperLimit && s[i] > '7' || ans == lowerLimit && s[i] > '8')
        {
            isOverflow = 1;
            break;
        }
        ans *= 10;
        ans += s[i++] - '0';
    }
    if (isOverflow)
    {
        return isNeg ? INT_MIN : INT_MAX;
    }
    return isNeg ? -ans : ans;
}