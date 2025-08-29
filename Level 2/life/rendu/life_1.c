#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac != 4)
        return 1;
    int weight = atoi(av[1]);
    int height = atoi(av[2]);
    int iterators = atoi(av[3]);
    int x = 1;
    int y = 1;
    char c;
    int print = 0;
    int arr[2][height + 2][weight + 2];
    for(int i =0;i < 2; i++)
    {
        for(int j = 0; j < height + 2; j++)
        {
            for(int k = 0; k < weight + 2;k++)
                arr[i][j][k] = 0;
        }
    }
    while(read(0, &c, 1) >0)
    {
        if (c == 'w' && y > 1)
            y--;
        else if (c == 'a' && x > 1)
            x--;
        else if (c == 'd' && x < weight)
            x++;
        else if (c == 's' && y < height)
            y++;
        else if (c == 'x')
                print = !print;
        if (print)
            arr[0][y][x] = 1;

    }
    for(int iter = 0 ; iter < iterators; iter++)
    {
        for(int j =1; j <= height ; j++)
        {
            for(int k = 1; k <= weight ;k++)
            {
                int n = 0;
                for(int h = -1; h <= 1 ; h++)
                {
                    for(int w = -1; w <= 1; w++)
                    {
                        if (!(w == 0 && h == 0))
                            n+= arr[iter%2][h + j][w + k];
                    }
                }
                if (arr[iter%2][j][k] == 1)
                {
                    if (n == 2 || n == 3)
                        arr[(iter + 1)%2][j][k] = 1;
                    else
                        arr[(iter + 1)%2][j][k] = 0;
                }
                else
                {
                    if (n == 3)
                        arr[(iter + 1)%2][j][k] = 1;
                    else
                        arr[(iter + 1)%2][j][k] = 0;
                }
            }
        }
    }
    for(int i = 1; i <=height ;i++)
    {
        for(int j = 1; j <= weight; j++)
        {
            if (arr[iterators% 2][i][j] == 0)
                putchar(' ');
            else
                putchar('O');
        }
        putchar('\n');
    }
}
