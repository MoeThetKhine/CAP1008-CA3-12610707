int findNumbers(int* nums, int numsSize)
{
    int count = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int productID = nums[i];
        int digits = 0;

        while (productID > 0)
        {
            digits++;
            productID /= 10;
        }

        if (digits % 2 == 0)
        {
            count++;
        }
    }

    return count;
}
