char* reverseWords(char* s)
{
    int len = strlen(s);

    char* result = (char*)malloc((len + 1) * sizeof(char));

    if (result == NULL)
    {
        return NULL;
    }

    int i = len - 1;
    int k = 0;

    while (i >= 0)
    {
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }

        if (i < 0)
        {
            break;
        }

        int end = i;

        while (i >= 0 && s[i] != ' ')
        {
            i--;
        }

        if (k > 0)
        {
            result[k++] = ' ';
        }

        for (int j = i + 1; j <= end; j++)
        {
            result[k++] = s[j];
        }
    }

    result[k] = '\0';

    return result;
}
