int main()
{
    int *ptr = (int*) ~0x00;  // a pointer to the end of memory

    *ptr = 5;
}
