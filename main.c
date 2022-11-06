#include "Set.h"

int compare(void *a, void *b)
{
    int a_num = *(int *)a;
    int b_num = *(int*)b;
    return b_num - a_num;
}

int main() {
    Set *s = set_new(compare);
    int numbers[100];

    for(int i = 0; i < 100; i++)
    {
        numbers[i] = i;

        if(numbers[i] % 2 == 0)
        {
            set_add(s, numbers+i);
        }
        else
        {
            numbers[i] = i * -1;
            set_add(s, numbers+i);
        }
    }

    int add1 = 17;
    int add2 = -6;
    int add3 = -100;
    int add4 = 99;

    set_add(s, &add1);
    set_add(s, &add2);
    set_add(s, &add3);
    set_add(s, &add4);

    int target = 54;
    if(set_contains(s, &target))
        printf("It works!\n");

//    set_remove(s, &target);
//
//    if(set_contains(s, &target))
//        printf("It does NOT work!\n");




    return 0;
}
