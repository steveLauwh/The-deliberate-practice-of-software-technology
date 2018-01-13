## Sublime Text 3 + PlantUML + Graphviz 用代码生成 UML 图

在 Sublime Text 3 上使用 PlantUML 插件，写 PlantUML 脚本，通过快捷键生成图片。

### 需要工具

* Sublime Text 3 ：文本编辑器

* PlantUML 插件 ：[sublime_diagram_plugin](https://github.com/jvantuyl/sublime_diagram_plugin)

* Graphviz ：开源的图片渲染库。安装了这个库才能在 Windows 下实现把 PlantUML 脚本转换为图片

### windows 平台下安装方法

第一步：安装 Sublime Text 3 文本编辑器

第二步：git https://github.com/jvantuyl/sublime_diagram_plugin.git，把源文件夹放到 Sublime 的 Data\Packages 目录下

第三步：安装 Graphviz，需要配置环境变量，配置如下：

在系统变量中添加：

变量名：GRAPHVIZ_DOT 

变量值：C:\Program Files\Graphviz2.38\bin\dot.exe (graphviz 安装路径位置)

添加 `C:\Program Files\Graphviz2.38\bin;` 到系统变量 path 中

### 使用

例子：

```
@startuml
Alice -> Bob: Authentication Request
Bob --> Alice: Authentication Response
Alice -> Bob: Another authentication Request
Alice <-- Bob: another authentication Response
@enduml
```
复制到 Sublime，并保存文件，使用快捷键 Alt+M，就可以生成图片。

### 注意事项

问题：安装 PlantUML 插件时，出现 unable to load diagram plugin,check console for details. 把例子粘过来 Alt+M 时显示 nothing to process. 

解决办法：原因是下载的插件里无法加载文件：Diagram.sublime-settings，其中第三行将编码方式"charset": null 改为 "charset": "UTF-8"，关掉 Sublime Text 3 重启即可。

