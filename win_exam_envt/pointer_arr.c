
int main(int argc, char *argv[])
{
    //int a[4] = {2, 1, 6, 8};
    //cout << *(a + 1) << endl;
    //cout << (&a) << endl;
    //int (*b)[4] = &a;

    struct Test
    {
        struct Test* child[4];
    };

    struct Test a;
    a.child = {NULL};
    

    return 0;
}