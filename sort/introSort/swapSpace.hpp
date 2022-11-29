

namespace swapSpace
{
    void swapp(int* x, int* y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;

        return;
    }
}