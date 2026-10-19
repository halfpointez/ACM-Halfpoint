#!/usr/bin/env bash
# 对拍脚本（Linux / WSL / Git Bash 通用）
# 用法: bash stress.sh <sol.cpp> <brute.cpp> <gen.cpp> [轮数]
# 说明: gen 会收到种子 1..轮数; 失败时输入存为 ./bad_case.txt, 用同一种子可复现
set -uo pipefail

if [ $# -lt 3 ]; then
    echo "用法: bash stress.sh <sol.cpp> <brute.cpp> <gen.cpp> [轮数]"
    exit 1
fi

SOL="$1"; BRUTE="$2"; GEN="$3"; MAX="${4:-1000}"
CXX="${CXX:-g++}"
FLAGS="-O2 -std=c++17 -Wall -Wextra"

TMP="$(mktemp -d)" || exit 1
trap 'rm -rf "$TMP"' EXIT

echo "[stress] 编译 $SOL / $BRUTE / $GEN ..."
"$CXX" $FLAGS -o "$TMP/sol"   "$SOL"   || exit 1
"$CXX" $FLAGS -o "$TMP/brute" "$BRUTE" || exit 1
"$CXX" $FLAGS -o "$TMP/gen"   "$GEN"   || exit 1

for ((i = 1; i <= MAX; i++)); do
    "$TMP/gen" "$i" > "$TMP/in.txt"
    "$TMP/sol"   < "$TMP/in.txt" > "$TMP/out_sol.txt"
    "$TMP/brute" < "$TMP/in.txt" > "$TMP/out_brute.txt"
    if ! cmp -s "$TMP/out_sol.txt" "$TMP/out_brute.txt"; then
        echo "[stress] ✗ 第 $i 轮 (种子 $i) 不一致!"
        cp "$TMP/in.txt" ./bad_case.txt
        echo "已存下失败数据: ./bad_case.txt (重跑: ./gen $i)"
        echo "--- 暴力输出 ---"; head -c 500 "$TMP/out_brute.txt"; echo
        echo "--- 你的输出 ---"; head -c 500 "$TMP/out_sol.txt";   echo
        exit 1
    fi
done
echo "[stress] ✓ 全部 $MAX 轮通过"
