OUTPUT_ARCH(riscv)              /*输出文件的指定架构*/
ENTRY(_start)                   /*指定程序入口点（start.S中的_start）*/

MEMORY                          /*定义内存的起始位置和长度*/
{
  ram(wxa!ri) : ORIGIN = 0x80000000, LENGTH = 128M
}

SECTIONS {
  .text : {
		PROVIDE(_text_start = .);
		*(.text .text.*)
		PROVIDE(_text_end = .);
	} >ram

  .rodata : {
		PROVIDE(_rodata_start = .);
		*(.rodata .rodata.*)
		PROVIDE(_rodata_end = .);
	} >ram

  .data : {
		. = ALIGN(4096);            /*内存对齐到4096字节边界*/

		PROVIDE(_data_start = .);
		*(.sdata .sdata.*)
		*(.data .data.*)
		PROVIDE(_data_end = .);
	} >ram

  .bss : {
		PROVIDE(_bss_start = .);
		*(.bss .bss.*)
		PROVIDE(_bss_end = .);
	} >ram

  /*定义内存的起始、结束位置变量*/
  PROVIDE(_memory_start = ORIGIN(ram));
	PROVIDE(_memory_end = ORIGIN(ram) + LENGTH(ram));

  /*定义堆的起始、结束位置变量*/
	PROVIDE(_heap_start = _bss_end);
	PROVIDE(_heap_size = _memory_end - _heap_start);
}