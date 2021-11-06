#include <stdio.h>
#include <stdlib.h>
int *twoSum( int *nums, int numsSize, int target, int *returnSize );



int
main(void)
{
    int i, j;
    int numsSize = 4;
    int target = 9;
    int nums[] = {2, 7, 11, 15};
    int *returnSize = 0;
    int *arr = NULL;

    /*for ( i = 0; i < numsSize; i++ )
    {
        scanf( "%d,", &nums[i] );
    }*/

    arr = twoSum( nums, numsSize, target, returnSize);

    printf("[%d, %d]\n", arr[0], arr[1]);
    return 0;

}

int *twoSum( int *nums, int numsSize, int target, int *returnSize )
{
    int i, j;
    int mapTempSize = 0;
    int *arr = NULL;


    struct
    {
        int key;
        int value;
    } map[numsSize];
    map[0].key = nums[0];
    map[0].value = 0;

    arr = (int *) malloc( 2*sizeof( int ) );
    if ( arr == NULL )
        return arr;

    for ( i = 1; i < numsSize; i++ )
    {
        if (target - nums[i] >= 0 )
        {
            for ( j = 0, mapTempSize++; j < mapTempSize; j++ )
            {
                if ( ( target - nums[i] ) == map[j].key )
                {
                    arr[0] = i;
                    arr[1] = map[j].value;
                    return arr; 
                }                
            }
            map[j].key = nums[i];
            map[j].value = i;

        }
    }
    return arr;
}