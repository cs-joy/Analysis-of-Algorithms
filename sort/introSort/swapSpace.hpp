namespace swapSpace
{
    void swaping(int* x, int* y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;

        return;
    }
}