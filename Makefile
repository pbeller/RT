include config.mk

NAME = $(CONFIG_NAME)
OUTPUT_TYPE = $(CONFIG_OUTPUT_TYPE)
CC_FLAGS_EXTRA = $(CONFIG_CC_FLAGS_EXTRA)
CC_FLAGS_EXTRA_POST = $(CONFIG_CC_FLAGS_EXTRA_POST)

LIB_TOWEL_PATH = ./libs/libtowel
LIB_TOWEL_INCLUDES = -I $(LIB_TOWEL_PATH)/includes
LIB_TOWEL_LD = $(LIB_TOWEL_PATH)/libtowel.a

C_DIR = srcs
O_DIR = .tmp/objects

CC_FLAGS = -g -Wall -Wextra -Werror
CC_HEADERS = -I ./includes -I ./srcs/libft/includes
CC_DEBUG =

C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep ".*\.c$$" | grep -v "\.spec\.c")
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)

H_FILES = $(shell find includes -type f -follow -print | grep ".*\.h$$")
O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

COL_GRAY = \033[1;30m
COL_RESET = \033[0;0m
COL_RED = \033[0;31m
COL_GREEN = \033[0;32m
CC_OPTIONS = $(CC_FLAGS) $(CC_HEADERS) $(CC_FLAGS_EXTRA)

DEBUG_FILE_NAME = .debug.out

MAKE_PATHS = $(dir $(wildcard ./libs/*/))
MAKE = make -s

all:
	@$(foreach lib, $(MAKE_PATHS), $(MAKE) -C $(lib);)
	@$(MAKE) $(NAME)

$(NAME): $(O_FILES)
	@echo ""
	@echo "[info] compile $(OUTPUT_TYPE) ..."

ifeq ($(OUTPUT_TYPE), lib)
	@ar rcs $@ $^
endif
ifeq ($(OUTPUT_TYPE), exec)
	gcc $(CC_OPTIONS) $(CONFIG_EXTRA_LIBS) $(CONFIG_EXTRA_H) $(LIB_TOWEL_INCLUDES) $(CC_DEBUG) $^ -o $@  $(CC_FLAGS_EXTRA_POST) $(LIB_TOWEL_LD)
endif
ifeq ($(OUTPUT_TYPE), so)
	@gcc $(CC_OPTIONS) $(LIB_TOWEL_INCLUDES) $(CC_DEBUG) $^ -shared -o $@  $(CC_FLAGS_EXTRA_POST) $(LIB_TOWEL_LD)
endif
	@echo "$(COL_GREEN)$(NAME)$(COL_RESET)"
	$(POST_COMPILATION_CMD)

$(O_DIR)%.o: $(C_DIR)%.c $(H_FILES)
	@mkdir -p $(O_DIRS) $(O_DIR)
	@gcc $(CC_OPTIONS) $(CONFIG_EXTRA_H) $(LIB_TOWEL_INCLUDES) $(CC_DEBUG) -o $@ -c $< \
		&& printf "."

clean: _clean
	@$(foreach lib, $(MAKE_PATHS), $(MAKE) -C $(lib) clean;)

fclean: _fclean
	@$(foreach lib, $(MAKE_PATHS), $(MAKE) -C $(lib) fclean;)

_clean:
	$(info [info] $@ ...)
	@rm -rf .tmp

_fclean: _clean
	$(info [info] $@ ...)
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re:
	@$(MAKE) fclean
	@$(MAKE) all

check:
	$(CONFIG_CHECK_CMD)

check_ongoing:
	$(CONFIG_CHECK_ONGOING_CMD)

norm:
	find srcs includes -name "*.h" -o -name "*.c" -follow | xargs norminette

valgrind:
	valgrind --leak-check=full ./$(NAME) $(args)

log:
	touch $(DEBUG_FILE_NAME)
	tail -f $(DEBUG_FILE_NAME)

rendu:
	rm -rf /tmp/$(NAME)_rendu
	sh "$(shell git rev-parse --show-toplevel)/common/tools/prepare_rendu.sh" `pwd` /tmp/$(NAME)_rendu $(vogo)

run: all
	$(CONFIG_RUN_CMD)

obj:
	sh "$(shell git rev-parse --show-toplevel)/common/tools/c_obj_generator/create_object.sh" $(obj) `pwd`

mgr:
	sh "$(shell git rev-parse --show-toplevel)/common/tools/c_obj_generator/create_object_mgr.sh" $(obj) `pwd`

.PHONY: init_libs all clean fclean re
