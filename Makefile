# ================================================
# 工具链与编译选项
# ================================================
CROSS = riscv64-unknown-elf-
CXX = $(CROSS)g++					# C++编译器指定
CC = $(CROSS)g++					# 备用的C编译器
AS = $(CROSS)as						# 汇编器

OBJDUMP = $(CROSS)objdump			# 反编译工具
OBJCOPY = $(CROSS)objcopy			# 二进制提取工具

CFLAGS = -march=rv64imac -mabi=lp64 -mcmodel=medany -nostdlib -static			# 编译器参数
LDFLAGS = -T linker.ld



# ================================================
# 构建路径和子模块
# ================================================
START_DIR = arch/riscv
MAIN_DIR = src/arch/kernel
BUILD_DIR = build

SRC = $(START_DIR)/start.S $(MAIN_DIR)/entry.cpp
TARGET = $(BUILD_DIR)/LLKernel.elf



# ================================================
# 构建目标规则
# ================================================
all: $(TARGET)

$(TARGET): $(SRC) linker.ld			# 如果 entry.cpp、start.S、或者 linker.ld 有任何改动，就需要重新生成 $(TARGET)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC)



# ================================================
# 辅助命令
# ================================================
# 生成反汇编文件，make dump
dump:
	$(OBJDUMP) -D $(TARGET) > LLKernel.dump

# 启动qemu，make qemu
qemu: $(TARGET)
	qemu-system-riscv64 -nographic -machine virt -bios none -kernel $(TARGET)

# 清理文件，make clean
clean:
	@for dir in $(SUBDIRS); do $(MAKE) -C $$dir clean; done
	rm -f $(BUILD_DIR)/*.elf


