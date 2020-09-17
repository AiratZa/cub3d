NAME = cub3D


# %.o: %.c
#     $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


# $(NAME): $(OBJ)
#     $(CC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

MLX	= libmlx.a
MLX_DYLIB_PATH = ./mlx_linux
# -Wall -Wextra -Werror
CFLAGS			= -O3 
LIBS			= -L$(MLX_DYLIB_PATH) -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRCS			= ./utils/quick_sort.c ./utils/images_colors.c ./utils/load_textures.c ./utils/ft_exit.c ./utils/initial_settings.c ./utils/initial_settings_2.c \
				./sprites_handler/sprites_handler_main.c ./sprites_handler/init_sprite_settings.c	main.c\
				./parser/error_messages.c ./parser/main.c ./parser/map_border_checker.c ./parser/my_tests.c ./parser/map_parser.c\
				 ./parser/param_parse_main.c ./parser/rgb_param_parse.c ./parser/struct_funcs.c ./parser/utils.c\
				 get_next_line/get_next_line_utils.c get_next_line/get_next_line.c\
				 ./engine/main_loop.c ./engine/keys_handler.c ./engine/make_screenshot.c ./engine/keys_status_handler.c ./engine/main_calculation.c ./engine/draw_walls_n_background.c\
				./utils/free_vars.c ./utils/clear_imgs_n_close_window.c

OBJS			= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make bonus -C libft
	# gcc -I./libft/ *.c *.o -L./libft/ -lft
	gcc ${CFLAGS} -I$(MLX_DYLIB_PATH) -I/usr/include -I./libft/ -o ${NAME} ${OBJS} ${LIBS} -L./libft/ -lft -g

all: $(NAME)

# $(MLX):
# 	@make -C $(MLX_DYLIB_PATH)
# 	@mv $(MLX_DYLIB_PATH)/$(MLX) .

clean:
		@make fclean -C libft
		@rm $(OBJS)

# fclean: clean
# 		@rm $(NAME)

# re:
# 	fclean $(NAME)

%.o: %.c
	gcc $^ -o $@ -g -c
	# @echo "-- $@ is compiled"
	
# .PHONY:	all clean fclean re

cor_map:
	@echo "\n========= #1 =========="
	@./cub3D ./maps/cor/1.cub
	@echo "\n========= #2 =========="
	@./cub3D ./maps/cor/2.cub
	@echo "\n========= #3 =========="
	@./cub3D ./maps/cor/3.cub
	@echo "\n========= #4 =========="
	@./cub3D ./maps/cor/4.cub
	@echo "\n========= #5 =========="
	@./cub3D ./maps/cor/5.cub
	@echo "\n========= #6 =========="
	@./cub3D ./maps/cor/6.cub
	@echo "\n========= #7 =========="
	@./cub3D ./maps/cor/7.cub
	@echo "\n========= #8 =========="
	@./cub3D ./maps/cor/8.cub
	@echo "\n========= #9 =========="
	@./cub3D ./maps/cor/9.cub
	@echo "\n========= #10 =========="
	@./cub3D ./maps/cor/10.cub
	@echo "\n========= #11 =========="
	@./cub3D ./maps/cor/11.cub

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