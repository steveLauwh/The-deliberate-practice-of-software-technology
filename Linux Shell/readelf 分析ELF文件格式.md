## readelf 分析 ELF 文件格式

ELF(Executable and Linking Format) 是一种对象文件的格式，用于定义不同类型的对象文件(Object files)中都放了什么东西、以及都以什么样的格式去放这些东西。

参数说明
-a ：–all 全部 Equivalent to: -h -l -S -s -r -d -V -A -I
-h ：–file-header 文件头 Display the ELF file header
-l ：–program-headers 程序 Display the program headers
-S ：–section-headers 段头 Display the sections’ header
