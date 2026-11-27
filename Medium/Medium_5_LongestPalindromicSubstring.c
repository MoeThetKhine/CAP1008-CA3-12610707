char* longestPalindrome(char* s)
{
    int len = strlen(s);

    if (len == 0)
    {
        char* empty = (char*)malloc(1);
        if (empty == NULL) return NULL;
        empty[0] = '\0';
        return empty;
    }

    int start = 0;
    int maxLength = 1;

    for (int center = 0; center < len; center++)
    {
        int left = center;
        int right = center;

        // Odd-length palindrome
        while (left >= 0 && right < len &&
               s[left] == s[right])
        {
            left--;
            right++;
        }

        int length = right - left - 1;

        if (length > maxLength)
        {
            maxLength = length;
            start = left + 1;
        }

        // Even-length palindrome
        left = center;
        right = center + 1;

        while (left >= 0 && right < len &&
               s[left] == s[right])
        {
            left--;
            right++;
        }

        length = right - left - 1;

        if (length > maxLength)
        {
            maxLength = length;
            start = left + 1;
        }
    }

    char* result = (char*)malloc((maxLength + 1) * sizeof(char));

    if (result == NULL) return NULL;

    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';

    return result;
}
