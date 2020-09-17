# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 21:00:48 by gdrake            #+#    #+#              #
#    Updated: 2020/09/17 22:28:07 by gdrake           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX	= libmlx.dylib


CFLAGS = -O3

MLX_LIB_DIR = ./mlx_sources/minilibx_mms_20200219/
MLX_LIB			= -I$(MLX_LIB_DIR) -L$(MLX_LIB_DIR) -lmlx -framework OpenGL -framework AppKit -lm

LIBFT_DIR = ./libft
LIBFT = -L$(LIBFT_DIR)  -lft

SRCS = ./utils/quick_sort.c ./utils/images_colors.c ./utils/load_textures.c ./utils/ft_exit.c ./utils/initial_settings.c ./utils/initial_settings_2.c \
				./sprites_handler/sprites_handler_main.c ./sprites_handler/init_sprite_settings.c	main.c\
				./parser/main.c ./parser/map_border_checker.c ./tmp/my_tests.c ./parser/map_parser.c ./parser/texture_parse.c ./parser/convert_map_to_rect.c ./parser/more_map_checks.c\
				 ./parser/param_parse_main.c ./parser/rgb_param_parse.c ./parser/struct_funcs.c ./parser/utils.c\
				 get_next_line/get_next_line_utils.c get_next_line/get_next_line.c\
				 ./engine/main_loop.c ./engine/keys_handler.c ./engine/make_screenshot.c ./engine/keys_status_handler.c ./engine/main_calculation.c ./engine/draw_walls_n_background.c\
				./utils/free_vars.c ./utils/clear_imgs_n_close_window.c

OBJS			= $(SRCS:.c=.o)

$(NAME): $(MLX) $(OBJS)
	make bonus -C libft
	gcc ${CFLAGS}  -I$(LIBFT_DIR) $(LIBFT) ${OBJS} ${MLX_LIB}  -o ${NAME}

all: $(NAME)

$(MLX):
	make -C $(MLX_LIB_DIR)
	rm -./rf libmlx.dylib
	cp $(MLX_LIB_DIR)libmlx.dylib ./


clean:
	make clean -C $(MLX_LIB_DIR)
	make fclean -C ./libft
	@rm $(OBJS)
	@rm -rf *.o

fclean: clean
	@rm libmlx.dylib
	@rm $(NAME)

re:
	fclean $(NAME)

%.o: %.c
	gcc $^ -o $@ -c

FOR_NORM = ./engine/ ./get_next_line/ ./includes/ ./libft/ ./parser/ ./sprites_handler/ ./utils/ ./main.c

norme:
	norminette $(FOR_NORM)

incor_map:
	incor_map_1
	incor_map_2
	incor_map_3
	incor_map_4
	incor_map_5
	incor_map_6
	incor_map_7

incor_map_1:
	@echo "\n========= #1 =========="
	@./cub3D ./maps/incorcor/1.cub

incor_map_2:
	@echo "\n========= #2 =========="
	@./cub3D ./maps/incorcor/2.cub
incor_map_3:
	@echo "\n========= #3 =========="
	@./cub3D ./maps/incorcor/3.cub
incor_map_4:
	@echo "\n========= #4 =========="
	@./cub3D ./maps/incorcor/4.cub
incor_map_5:
	@echo "\n========= #5 =========="
	@./cub3D ./maps/incorcor/5.cub
incor_map_6:
	@echo "\n========= #6 =========="
	@./cub3D ./maps/incorcor/6.cub
incor_map_7:
	@echo "\n========= #7 =========="
	@./cub3D ./maps/incorcor/7.cub

.PHONY:	all clean fclean re