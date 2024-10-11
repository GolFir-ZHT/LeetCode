#!/bin/bash

# 检查是否传入文件名参数
if [ -z "$1" ]; then
    echo "请提供要编译的 C++ 文件名"
    exit 1
fi

# 获取文件名并去除扩展名
filename=$(basename -- "$1")
filename_without_ext="${filename%.*}"

# 如果提供了第二个参数，使用它作为输出目录，否则使用当前目录
if [ -n "$2" ]; then
    output_dir="$2"
    # 如果目录不存在，创建它
    mkdir -p "$output_dir"
else
    output_dir="."
fi

# 编译 C++ 代码，并将可执行文件输出到指定目录
g++ -o "$output_dir/$filename_without_ext" "$1"

# 检查编译是否成功
if [ $? -eq 0 ]; then
    echo "编译成功，生成的可执行文件为: $output_dir/$filename_without_ext"
    
    # 运行生成的可执行文件
    echo "正在执行程序..."
    "$output_dir/$filename_without_ext"
else
    echo "编译失败"
fi
