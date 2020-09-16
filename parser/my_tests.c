#include "cub3d.h"

void test(t_map *map, t_params *p)
{
    int i;

    i = 0;
    printf("=================================================================\n\n");
    while (i < map->y_size)
    {
        printf("%3d |%s|\n", i, (map->arr_ptr[i])->line);
        i++;
    }
    printf("\n=================================================================\n");

    printf("R %d %d\n", p->r_width, p->r_height);
    printf("%s == %s\n", "NO", p->NO);
    printf("%s == %s\n", "SO", p->SO);
    printf("%s == %s\n", "WE", p->WE);
    printf("%s == %s\n", "EA", p->EA);
    printf("%s  == %s\n", "S", p->S);

    printf("F %3d, %3d, %3d\n", p->f_r, p->f_g, p->f_b);
    printf("C %3d, %3d, %3d\n", p->c_r, p->c_g, p->c_b);
}