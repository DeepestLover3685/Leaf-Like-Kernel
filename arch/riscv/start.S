.globl _start           # 将_start声明为全局符号，使得linker（链接器）可以访问
.section .text          # 切换或指定接下来代码放在哪个段（section）中，这里是 .text 段，也就是“代码段”。

_start:
    la sp, stack_top    # 设置栈指针
    call start          # 跳转到main()函数
1:  j 1b                # 死循环防止返回

