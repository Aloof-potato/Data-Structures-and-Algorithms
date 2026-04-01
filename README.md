# Data-Structures-and-Algorithms (Hello Algo Replica)

声明：本项目为个人学习《Hello 算法》的实战代码库（Replica）。

- 原版项目：[krahets/hello-algo](https://github.com/krahets/hello-algo)
- 核心目的：脱离原版环境，从零构建 C++ 工程目录与 CMake 自动化编译系统，纯手写复刻所有核心数据结构与算法，作为个人的基础沉淀。
- 学习打卡：[DAILY_CHECKIN.md](./DAILY_CHECKIN.md)

## 项目模式

- 根目录 `common/` 存放公共头文件。
- 每个 `chapter_*` 目录放多个独立 `.cpp`。
- 每个 `.cpp` 约定独立 `main()`，对应一个可执行文件。

## CMake 规则

- 根 `CMakeLists.txt` 自动扫描并 `add_subdirectory(chapter_*)`。
- 章节 `CMakeLists.txt` 自动扫描本目录 `*.cpp`。
- 仅当 `.cpp` 中检测到 `main()` 才会生成目标，空骨架文件会被自动跳过。
- 目标命名：`<chapter_name>_<file_name_without_ext>`。
- 输出路径：`build/bin/<chapter_name>/`。

## 常用命令（Windows + MinGW）

```bash
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=D:/mingw64/bin/g++.exe
cmake --build build
```

编译单个文件目标（示例）：

```bash
cmake --build build --target chapter_tree_binary_tree
```

运行示例：

```bash
./build/bin/chapter_tree/chapter_tree_binary_tree.exe
```

## 模板与脚本

- `templates/main/main_basic.cpp`：最小 main 模板
- `templates/main/main_with_common.cpp`：含 `common/common.h` 模板
- `templates/main/main_io.cpp`：带输入读取模板
- `templates/chapter_cmakelists_template.txt`：章节 CMake 模板
- `scripts/new_demo.ps1`：快速创建新 demo 文件

示例：

```powershell
./scripts/new_demo.ps1 -Chapter chapter_tree -Name binary_tree -Template with_common
```
