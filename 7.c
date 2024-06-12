/*
 * Remainder: -6 % 10 = -6
 * Exceed test
 */

int reverse(int x)
{
    int ans = 0;
    int upperLimit = INT_MAX / 10;
    int lowerLimit = INT_MIN / 10;

    while (x)
    {
        if (ans > upperLimit || ans < lowerLimit)
        {
            return 0;
        }
        ans *= 10;
        ans += (x % 10);
        x /= 10;
    }

    return ans;
}