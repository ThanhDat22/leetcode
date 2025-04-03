# **🔤 Problem: Longest Substring Without Repeating Characters**

You are given a string s.
Your task is to find the longest part of the string where no letter or symbol repeats.

- A substring means the letters must be next to each other in order.
- You must return the length (number of letters) of that part.

## 🔍 What does that mean?

You need to look through the string and find the longest piece where each letter is different.

## 🧪 Examples

1. Input: "abcabcbb"
Output: 3
Why? → "abc" is the longest part where no letter repeats.

2. Input: "bbbbb"
Output: 1
Why? → "b" is the only letter that doesn’t repeat in a substring.

3. Input: "pwwkew"
Output: 3
Why? → "wke" is a part where no letter repeats. "pwke" is not allowed because it skips letters (not a substring).

## Idea

Solving this problem using sliding window technique. It moves two pointers (start and end) to keep track of a window (a part of the string) where all characters are different.

A set is used to remember the characters were seen.

1. Start with two pointers: start and end both at 0.
2. Use a set to keep track of characters in the current substring.
3. Move end one step at a time.
    - If the character is not in the set → Add it and update the longest length.
    - If the character is in the set → Remove characters from the left (start) until it's gone.
4. Repeat until you finish the string.
