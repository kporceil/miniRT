NAME := miniRT

override SRCDIR := srcs/

override BUILDDIR := .build/$(MODE)/

override FLAGFILE := .build/.compile_flags

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

MAIN := main

BASENAME := $(MAIN) \
			$(addprefix tuples/, point vector add substract negate scalar magnitude normalize dot_product cross_product mult) \
			$(addprefix color/, color add substract scalar mult) \
			$(addprefix canvas/, canva write_pixel ppm_to_canva ppm_header ppm_io) \
			$(addprefix gnl/, get_next_line get_next_line_utils) \
			$(addprefix matrix/, create compare mult identity transposing determinant submatrix minors cofactor is_invertible invert translation scaling rotation shearing view_transformation shape_set_matrix orientation) \
			$(addprefix ray/, create position intersect hit transform precompute) \
			$(addprefix spheres/, create intersect) \
			$(addprefix light/, normal reflect point_light material phong shade_hit color_at map_normal compute_tbn) \
			$(addprefix world/, create intersect free_world) \
			$(addprefix camera/, create ray_for_pixel render move) \
			$(addprefix shadow/, is_shadowed) \
			$(addprefix plane/, plane intersect) \
			$(addprefix cylinders/, create intersect intersect_caps) \
			$(addprefix cones/, create intersect intersect_caps) \
			$(addprefix patterns/, pattern_at pattern_at_object ring_at check_at gradient_at stripe_at) \
			$(addprefix reflect/, reflected_color) \
			$(addprefix render_mlx/, init_mlx exit_mlx loop_mlx display_mlx hooks canva_to_mlx_image) \
			$(addprefix refraction/, find_nx init_list add_or_delete_list refractive_color schlick) \
			$(addprefix cube/, cube intersect) \
			$(addprefix groups/, create intersect add_shape group_set_matrix group_set_material free copy delete_index) \
			$(addprefix scenes_parsing/, parse_line parse_file parse_light parse_ambient parse_camera parse_sphere parse_plane parse_cube parse_cube_texture parse_cylinder parse_cone parse_point parse_vector parse_color new_light_node free_light_list new_shape_node free_shape_list get_shape_id parse_normalized_vector count_possible_intersections parse_model parse_texture check_world_health) \
			$(addprefix mapping/, uv_pattern_at spherical_map planar_map cylindrical_map cubic_map_front cubic_map_back cubic_map_left cubic_map_right cubic_map_up cubic_map_down face_from_point uv_image uv_checker texture_map uv_align_check cube_pattern conical_map) \
			$(addprefix triangles/, create intersect) \
			$(addprefix bounding_box/, create add_point bounds_of add contains_point contains_box transform parent_space_bounds_of intersect split_bounds partition_children divide) \
			$(addprefix vectors/, create get_header free add delete_index) \
			$(addprefix uid/, generate_uid) \
			$(addprefix obj_parser/, obj_parser parse_obj_line free add_vertice add_face change_group parsed_to_group add_vertice_normal add_smooth_polygon add_polygon) \
			$(addprefix smooth_triangles/, create) \

DIR := $(addprefix $(DEPDIR), $(sort $(filter-out ./, $(dir $(BASENAME)))))    \
       $(addprefix $(OBJDIR), $(sort $(filter-out ./, $(dir $(BASENAME)))))

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

override LIBFT := libft/libft.a

override MLX := minilibx-linux/libmlx.a

override LDFLAGS := -lmlx -lXext -lX11 -lft -lcmocka -lm

override LDLIBS := -L libft/ -L minilibx-linux/

override FILTERED_SRCS := $(strip $(foreach f,$(SRCS),$(if $(or $(findstring test,$(f)),$(findstring tmp,$(f))),,$(f)))) $(strip $(foreach f,$(addprefix includes/, $(shell ls includes/)),$(if $(or $(findstring test,$(f)),$(findstring tmp,$(f))),,$(f))))

CC := cc

CFLAGS := -Wall -Wextra -Werror -Wunreachable-code

ifeq (debug, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -g3
endif

ifeq (opti, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -O3 -march=native -flto -funroll-loops -finline-functions -fomit-frame-pointer -fno-math-errno -funsafe-math-optimizations -fno-signed-zeros -DNDEBUG -pipe
endif

ifeq (gprof, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -pg
endif

ifeq (asan, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -fsanitize=address -g3 -O1
endif

ifeq (msan, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -fsanitize=memory -g3 -O1
#-Wstrict-prototypes
endif

ifeq (lsan, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -fsanitize=leak -g3 -O1
endif

CPPFLAGS := -Iincludes -Ilibft/includes -Iminilibx-linux/

DEPSFLAGS := -MD -MP -MF

MAKEFLAGS += --no-print-directory

.DEFAULT_GOAL = all

-include $(DEPS)

CURRENT_FLAGS := $(MODE)$(CC)$(CFLAGS)$(CPPFLAGS)$(LDFLAGS)$(LDLIBS)$(TEST)

ifneq ($(MODE),)
ifneq ($(shell cat $(FLAGFILE) 2>/dev/null), $(CURRENT_FLAGS))
$(shell mkdir -p $(BUILDDIR) && echo '$(CURRENT_FLAGS)' > $(FLAGFILE))
endif
endif

.PHONY: json
json:
	@compiledb $(MAKE) MODE="$(MODE)"

.PHONY: all
all:
	@$(MAKE) MODE="default" TEST="$(TEST)" $(NAME)
#-j$(nproc) 
.PHONY: debug
debug:
	@$(MAKE) -j$(nproc) MODE="debug" TEST="$(TEST)" $(NAME)

.PHONY: asan
asan:
	@$(MAKE) -j$(nproc) MODE="asan" TEST="$(TEST)" $(NAME)

.PHONY: lsan
lsan:
	@$(MAKE) -j$(nproc) MODE="lsan" TEST="$(TEST)" $(NAME)

.PHONY: msan
msan:
	@$(MAKE) -j$(nproc) MODE="msan" TEST="$(TEST)" $(NAME)

.PHONY: gprof
gprof:
	@$(MAKE) -j$(nproc) MODE="gprof" TEST="$(TEST)" $(NAME)

.PHONY: opti
opti:
	@$(MAKE) -j$(nproc) MODE="opti" TEST="$(TEST)" $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(FLAGFILE)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LDLIBS) $(LDFLAGS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@

$(LIBFT): force
	@$(MAKE) -j$(nproc) MODE="$(MODE)" -C libft/

$(MLX): force
	@$(MAKE) -C minilibx-linux/

$(FLAGFILE): | $(BUILDDIR)
	@echo '$(CURRENT_FLAGS)' > $@

.PHONY: force
force:

$(DIR):
	mkdir -p $@

.PHONY: clean
clean:
	@$(MAKE) -j$(nproc) clean -C minilibx-linux/
	@$(MAKE) -j$(nproc) MODE="$(MODE)" clean -C libft/
	rm -rf $(BUILDDIR)

.PHONY: fclean
fclean: clean
	@$(MAKE) -j$(nproc) MODE="$(MODE)" fclean -C libft/
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	@$(MAKE) $@ -C $(dir $(LIBFT))
	@norminette $(FILTERED_SRCS)
