#include "stdio.h"
#include "string.h"

int main(void)
{
    //char json[100] = "{\"S01\":\"1\", \"S02\":\"2\", \"S03\":\"3\", \"S04\":\"4\", \"S05\":\"5\", \"S06\":\"6\"}";
    char json[100] = "{\"S01\":\"1\", \"S03\":\"3\", \"S04\":\"4\", \"S06\":\"6\"}";
    if (json == NULL)
    {
        return -1;
    }

    int i, j;
    int len;
    char data[6][2][10];
    memset(data, 0, 6*2*10);

    char *p = NULL;
    char *q = NULL;

    p = strtok(json, ",");
    for (i=0; i<6; i++)
    {
        if (p != NULL)
        {
            q = strstr(p, ":");
            if (q != NULL)
            {
                strncpy(data[i][0], p+2, 3);
                len = strlen(q);
                if (q[len-1] == '}')
                {
                    strncpy(data[i][1], q+2, strlen(q)-3-1);
                }
                else
                {
                    strncpy(data[i][1], q+2, strlen(q)-3);
                }
            }
            else
            {
                printf("json format error\n");
            }
        }

        p = strtok(NULL, ",");
    }

    printf("data:\n");
    for (i=0; i<6; i++)
    {
        for (j=0; j<2; j++)
        {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
