cmake_minimum_required(VERSION 3.9)
project(NEW_FDF C)

set(CMAKE_C_STANDARD 99)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

include_directories(minilibx gnl/libft gnl)
include_directories(inc libft/includes minilibx) # header directories
link_directories(minilibx gnl/libft) # library directories

set(SOURCE_FILES main.c gnl/get_next_line.c ft_foo.c fdf.h
		ft_make_mlx.c ft_del_mlx.c ft_list_foo.c ft_read_file.c
		ft_point.c ft_atoi_base.c ft_draw.c ft_matrix_transform.c
		ft_brazenhaim.c ft_color.c ft_event.c) # sources

set(CMAKE_FRAMEWORK "-framework OpenGL" "-framework AppKit")

add_executable(NEW_FDF ${SOURCE_FILES}) # compilation
target_link_libraries(NEW_FDF -lft  -lmlx ${CMAKE_FRAMEWORK}) # linkage