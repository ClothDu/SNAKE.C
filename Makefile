# Diretórios
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
DEBUG_DIR := $(BUILD_DIR)/Debug
RELEASE_DIR := $(BUILD_DIR)/Release

# Compilador e flags
CC := gcc
CFLAGS := -I$(INC_DIR) -I/ucrt64/include -I/ucrt64/include/pdcurses -Wall
DEBUG_FLAGS := -g
RELEASE_FLAGS := -O2


# Bibliotecas
LIBS := -lpdcurses


# Fontes e objetos
SRC_PATTERN := *.c
SRCS := $(wildcard $(SRC_DIR)/$(SRC_PATTERN))
OBJS_DEBUG := $(patsubst $(SRC_DIR)/%.c, $(DEBUG_DIR)/%.o, $(SRCS))
OBJS_RELEASE := $(patsubst $(SRC_DIR)/%.c, $(RELEASE_DIR)/%.o, $(SRCS))

# Executáveis
EXEC_DEBUG := $(DEBUG_DIR)/outDebug.exe
EXEC_RELEASE := $(RELEASE_DIR)/outRelease.exe

# Alvo padrão
all: debug

# ========================
#       Debug Build
# ========================
debug: $(DEBUG_DIR) $(EXEC_DEBUG)

$(DEBUG_DIR):
	@mkdir -p $(DEBUG_DIR)

$(EXEC_DEBUG): $(OBJS_DEBUG)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $@ $^ $(LIBS)

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c -o $@ $<

# ========================
#       Release Build
# ========================
release: $(RELEASE_DIR) $(EXEC_RELEASE)

$(RELEASE_DIR):
	@mkdir -p $(RELEASE_DIR)

$(EXEC_RELEASE): $(OBJS_RELEASE)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -o $@ $^ $(LIBS)

$(RELEASE_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -c -o $@ $<

# ========================
#         Clean
# ========================
clean:
	@echo "Limpando arquivos de build..."
	@rm -rf $(BUILD_DIR)

# ========================
#         Run
# ========================
run: $(EXEC_DEBUG)
	@echo "Executando o jogo Snake..."
	@$(EXEC_DEBUG)

.PHONY: all debug release clean run
