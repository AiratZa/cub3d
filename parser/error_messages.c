#include "cub3d.h"



// void error_exit_with_message_incorrect_char_in_map(char c, int x, int y)
// {
//     printf("Error\n");
//     printf("Incorrect char in map == %c\n", c);
//     printf("Position in map:\nx_pos = %d\ny_pos = %d\n", x, y);
//     exit(1);
// }

void error_exit_with_message_incorrect_border_in_map(int x, int y)
{
    printf("Error\n");
    printf("In one of the side of point map:\nx_pos = %d\ny_pos = %d\n", x, y);
    printf("dont or cant exist correct border\n");
    exit(1);
}