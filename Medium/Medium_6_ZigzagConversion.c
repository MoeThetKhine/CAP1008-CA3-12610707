char* convert(char* s, int numRows)
{
    int len = strlen(s);

    char* result = (char*)malloc((len + 1) * sizeof(char));

    if (result == NULL)
    {
        return NULL;
    }

    if (numRows == 1 || numRows >= len)
    {
        strcpy(result, s);
        return result;
    }

    int cycle = 2 * numRows - 2;
    int index = 0;

    for (int row = 0; row < numRows; row++)
    {
        for (int j = row; j < len; j += cycle)
        {
            result[index++] = s[j];

            int diagonal = j + cycle - 2 * row;

            if (row != 0 && row != numRows - 1 &&
                diagonal < len)
            {
                result[index++] = s[diagonal];
            }
        }
    }

    result[index] = '\0';

    return result;
}
