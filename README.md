# **LeetCode Solutions**

This repository contains my solutions to various **LeetCode** problems.  
Solutions are written in **C++**, organized by problem number/title, and each problem folder usually includes:

- Source code (`.cpp`) with a `main()` for quick testing
- A short per-problem `README.md` (problem statement, examples, approach, and complexity)
- (Sometimes) a `Makefile` and helper headers (e.g., a custom `Vector.h`)

## **📁 Repository Structure**

```text
.
├─ 1_twoSum/
├─ 2_addTwoNumbers/
├─ 3_longestSubstringWithoutRepeatingCharacters/
├─ 4_medianOf2SortedList/
├─ 9_palindromeNumber/
.
.
.
├─ 121_bestTimeToBuyAndSellStock/
.
.
.
└─ README.md ← (this file)
```

## **⚙️ Build & Run**

### Using `make` 

```bash
cd <problem_folder>
make           # builds the program (target name can be 'program' or the problem)
./program      # or ./<target_name>
```

After having done with testing, do house keeping:

```bash
make clean
```
