# Parser::parse()

使用 --draw 选项与 --math 选项时，必须同时提供 --output 选项。

同时提供的选项，顺序可以是任意的。

对于不合法的命令行参数，程序应异常退出（退出码非 0）。

所有 - 开头的命令行参数都被视为选项；换而言之，输入、提示词、问题、文件名这些内容都不会以 - 开头。

```bash
./hw7 --chat "Hello, how are you?"

./hw7 --draw "An apple" -o apple.png
./hw7 -o apple.png --draw "An apple"
./hw7 --output apple.png --draw "An apple"

./hw7 --math "Answer of 1 + 1" -o answer.png
./hw7 -o answer.png --math "Answer of 1 + 1"
./hw7 --output answer.png --math "Answer of 1 + 1"
```

Fail tests:

```bash
./hw7 ---chat "Hello, how are you?"   # ---chat
./hw7 --chatt "Hello, how are you?"   # --chatt
./hw7 --chat "Hello, how are you?" --draw   # --draw
./hw7 --chat "Hello, how are you?" "hi"   # hi
./hw7 --chat "Hello, how are you?" -o chat.txt  # -o

./hw7 --draw -o apple.png "An apple"   # -o
./hw7 -o apple.png --draw "An apple" --chat  # --chat
./hw7 --output --draw "An apple" apple.png   # --draw
./hw7 --output "An apple" --draw apple.png   # invalid path "An apple"

./hw7 --math -o answer.png "Answer of 1 + 1"   # -o
./hw7 -o answer.png --math "Answer of 1 + 1" --chat  # --chat
./hw7 --output --math "Answer of 1 + 1" answer.png   # --math
./hw7 --output "Answer of 1 + 1" --math answer.png   # invalid path "Answer of 1 + 1"
```
