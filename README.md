# 软件设计实践 作业 7 - 多文件工程

这是一个简陋的 C++ 程序，它可以让你在命令行中调用百度翻译、ChatGPT、OpenAI 绘图以及 WolframAlpha 数学计算。

接受的参数格式：
- `--chat prompt`：调用 ChatGPT，`prompt` 是向 ChatGPT 输入的内容。结果打印到标准输出。
- `--translate prompt`：调用百度翻译，`prompt` 是向百度翻译输入的内容。结果打印到标准输出。
- `--draw prompt`：调用 OpenAI 绘图，`prompt` 是向 OpenAI 绘图输入的内容。
- `--math prompt`：调用 WolframAlpha，`prompt` 是向 WolframAlpha 输入的内容。
- `--output file` 或 `-o file`：使用 `--draw` 和 `--math` 时**必须**提供的选项。指定结果保存的文件，**只支持 PNG 文件**。

同时提供的选项，顺序可以是任意的。所有以 - 开头的内容都会被视为选项，因此 `prompt` 和 `file` 都不能以 - 开头。`file` 参数必须以 `.png` 结尾。

使用示例：

```bash
$ ./hw7 --chat "Hi, how are you?"
I am fine.  # 来自 ChatGPT 的回复（以 UTF-8 编码）

$ ./hw7 --translate "Hi, how are you?"
嗨，你好吗？  # 来自百度翻译的回复（以 UTF-8 编码）

$ ./hw7 --draw "An apple" -o apple.png
# 生成了来自 OpenAI 的画作，存放在 apple.png 文件中

$ ./hw7 --math "Answer of 1 + 1" -o answer.png
# 生成了来自 WolframAlpha 的响应图片，存放在 answer.png 文件中

$ ./hw7 -o answer.png --math "Answer of 1 + 1"
# 同上
```

