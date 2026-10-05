#include <stdio.h>

int heap[100], n = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int level(int i)
{
    int l = 0;

    while (i > 0)
    {
        i = (i - 1) / 2;
        l++;
    }

    return l;
}

void insert(int x)
{
    int i = n;
    heap[n++] = x;

    if (i == 0)
        return;

    int p = (i - 1) / 2;

    /* MIN level */
    if (level(i) % 2 == 0)
    {
        if (heap[i] > heap[p])
        {
            swap(&heap[i], &heap[p]);
            i = p;

            while (i >= 3)
            {
                int gp = (i - 3) / 4;

                if (heap[i] > heap[gp])
                {
                    swap(&heap[i], &heap[gp]);
                    i = gp;
                }
                else
                    break;
            }
        }
        else
        {
            while (i >= 3)
            {
                int gp = (i - 3) / 4;

                if (heap[i] < heap[gp])
                {
                    swap(&heap[i], &heap[gp]);
                    i = gp;
                }
                else
                    break;
            }
        }
    }

    /* MAX level */
    else
    {
        if (heap[i] < heap[p])
        {
            swap(&heap[i], &heap[p]);
            i = p;

            while (i >= 3)
            {
                int gp = (i - 3) / 4;

                if (heap[i] < heap[gp])
                {
                    swap(&heap[i], &heap[gp]);
                    i = gp;
                }
                else
                    break;
            }
        }
        else
        {
            while (i >= 3)
            {
                int gp = (i - 3) / 4;

                if (heap[i] > heap[gp])
                {
                    swap(&heap[i], &heap[gp]);
                    i = gp;
                }
                else
                    break;
            }
        }
    }
}

void search(int key)
{
    for (int i = 0; i < n; i++)
    {
        if (heap[i] == key)
        {
            printf("Key found\n");
            return;
        }
    }

    printf("Key not found\n");
}

int main()
{
    int m, x, key;

    printf("Enter number of elements: ");
    scanf("%d", &m);

    printf("Enter elements: ");

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        insert(x);
    }

    printf("Min-Max Heap: ");

    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\nEnter key to search: ");
    scanf("%d", &key);

    search(key);

    return 0;
}