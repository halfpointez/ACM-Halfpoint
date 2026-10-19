# 对拍

对拍就是：用一份显然对但很慢的程序，在随机小数据上陪你比输出。不一致就说明你写错了，把当时那组数据留下慢慢查。

三个文件放在一起：

- `sol.cpp`：你的程序
- `brute.cpp`：暴力，照着题意最笨地写，别动脑优化
- `gen.cpp`：数据生成器，种子从 `argv[1]` 拿（同一种子永远出同一组数据）

然后跑：

```bash
bash stress.sh sol.cpp brute.cpp gen.cpp 500
```

全过就打 ✓；不一致会停下来打印两份输出，把出错数据存到 `bad_case.txt`。

先跑一遍示例感受下（Windows 上用 Git Bash 或 WSL 跑）：

```bash
bash stress.sh example_lower_bound/sol.cpp example_lower_bound/brute.cpp example_lower_bound/gen.cpp 300
```

换新题：复制 `template_gen.cpp`、`template_brute.cpp` 去改，`stress.sh` 不用动。写 gen 记住三件事：数据小（n 从 10 以内起步）、值域小（容易撞出重复）、偶尔掺边界（全相等 / 最小值 / 越界）。

一个坑：brute 别和 sol 共用同一段逻辑，两边一起错的话，对拍永远看不出来。

（拷到 Linux 上如果脚本报 `$'\r'` 之类的错，`sed -i 's/\r$//' stress.sh` 修一下。）
