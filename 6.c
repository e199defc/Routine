/*
 * Pay attension to malloc size
 */

char *convert(char *s, int numRows)
{
    if (s == NULL || numRows <= 0)
        return NULL;

    int i = 0;
    int j = 0;
    int number = 0;
    int isAscend = 1;
    int strLen = strlen(s);
    int cases = strLen / numRows + 1;
    int *index = (int *)malloc(strLen * sizeof(int));
    int *rowNumber = (int *)malloc(numRows * sizeof(int));
    char *result = (char *)malloc(strLen * sizeof(char));
    char **multiRow = (char **)malloc(numRows * sizeof(char *));
    memset(rowNumber, 0, numRows * sizeof(int));
    for (i = 0; i < numRows; ++i)
    {
        multiRow[i] = (char *)malloc(cases * sizeof(char));
    }

    for (i = 0; i < strLen; ++i)
    {
        index[i] = isAscend ? number++ : number--;
        multiRow[index[i]][rowNumber[index[i]]++] = s[i];
        if (number == 0)
        {
            isAscend = 1;
        }
        if (number == numRows - 1)
        {
            isAscend = 0;
        }
        if (number >= numRows)
        {
            number--;
        }
    }
    number = 0;
    for (i = 0; i < numRows; ++i)
        for (j = 0; j < rowNumber[i]; ++j)
        {
            result[number++] = multiRow[i][j];
        }

    result[number] = '\0';
    return result;
}