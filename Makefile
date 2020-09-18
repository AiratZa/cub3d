# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 21:00:48 by gdrake            #+#    #+#              #
#    Updated: 2020/09/18 18:44:19 by gdrake           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -O3

MLX_LIB_DIR = ./mlx_sources/minilibx_mms_20200219/
MLX_LIB			= -I$(MLX_LIB_DIR) -L$(MLX_LIB_DIR) -lmlx -framework OpenGL -framework AppKit -lm
MLX	= $(MLX_LIB_DIR)libmlx.dylib

LIBFT_DIR = ./libft
LIBFT = -L$(LIBFT_DIR)  -lft

SRCS = main.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c\
	./utils/free_vars.c ./utils/clear_imgs_n_close_window.c ./utils/quick_sort.c ./utils/images_colors.c ./utils/load_textures.c ./utils/ft_exit.c ./utils/initial_settings.c ./utils/initial_settings_2.c\
	./parser/main.c ./parser/map_border_checker.c ./parser/map_parser.c ./parser/texture_parse.c ./parser/convert_map_to_rect.c ./parser/more_map_checks.c\
	./parser/param_parse_main.c ./parser/rgb_param_parse.c ./parser/struct_funcs.c ./parser/utils.c\
	./sprites_handler/sprites_handler_main.c ./sprites_handler/init_sprite_settings.c\
	./engine/main_loop.c ./engine/keys_handler.c ./engine/make_screenshot.c ./engine/keys_status_handler.c ./engine/main_calculation.c ./engine/draw_walls_n_background.c

OBJS			= $(SRCS:.c=.o)

all: $(NAME)

make_libft:
	@echo "....... libft is compiling"
	@make bonus -C libft

$(NAME): $(MLX) $(OBJS) make_libft
	@gcc ${CFLAGS}  -I$(LIBFT_DIR) $(LIBFT) ${OBJS} ${MLX_LIB}  -o ${NAME}
	@echo "||||||||| cub3D is compiled! |||||||||\n"
	@echo "༼ つ ◕_◕  GOOD LUCK, HAVE FUN! ༼ つ ◕_◕ \n"


$(MLX):
	@echo "....... libmlx.dylib is compiling\n"
	@make -C $(MLX_LIB_DIR)
	@echo "....... libmlx.dylib is compiled ^_^\n"
	@rm -rf ./libmlx.dylib
	@echo "....... Deleted libmlx.dylib from core dir\n"
	@cp $(MLX_LIB_DIR)libmlx.dylib ./
	@echo "....... New libmlx.dylib copied to core dir\n"

clean:
	@make clean -C $(MLX_LIB_DIR)
	@make fclean -C ./libft
	@rm $(OBJS)

fclean: clean
	@rm libmlx.dylib
	@rm $(NAME)

re:
	fclean $(NAME)

%.o: %.c
	@gcc $^ -o $@ -c


FOR_NORM = ./engine/ ./get_next_line/ ./includes/ ./libft/ ./parser/ ./sprites_handler/ ./utils/ ./main.c

norme:
	norminette $(FOR_NORM)

.PHONY:	all clean fclean re