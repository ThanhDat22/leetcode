
# Add Two Numbers (Linked List)

## Problem Statement

You are given two **linked lists** that represent two non-negative numbers.  

- The digits are stored in **reverse order** (the ones place comes first).  
- Each node contains a single digit.  
- Add the two numbers and return the result as a new linked list.

You can assume:

- The two numbers do not have leading zeros, except for the number 0 itself.

---

## Example 1

**Input:**  

```plaintext
l1 = [2,4,3]  
l2 = [5,6,4]
```

**Output:**  

```plaintext
[7,0,8]
```

**Explanation:**  
342 + 465 = 807  

---

## Example 2

**Input:**  

```plaintext
l1 = [0]  
l2 = [0]
```

**Output:**  

```plaintext
[0]
```

---

## Example 3

**Input:**  

```plaintext
l1 = [9,9,9,9,9,9,9]  
l2 = [9,9,9,9]
```

**Output:**  

```plaintext
[8,9,9,9,0,0,0,1]
```

---

## Constraints

- The length of each linked list is between **1** and **100**.  
- Each node's value is between **0** and **9**.  
- The two numbers represented by the lists do not have leading zeros.

---

## Definition for singly-linked list

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```

---

## Code Template (C++)

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Your solution here
    }
};
```

## **Program Running**

### Compile Code

```ssh
make
```

### Run Code with all test case

```ssh
make test
```

### Run Code with single test case

In command line, type make test<number> which is number from 1 to 10. For example:

```ssh
make test1
```

### Run Code with user input number

```ssh
run
```

1. Enter the number of digits for the first number. For example, if the number is 15, input 2 prest enter.
2. Enter the digits of first number in reverse order. For example, if the number is 15, input 5, press enter, and input 1, press enter.
3. Repeat step 1 and 2 for the second number.

## TAKE AWAY

✅ 1. Two Pointer Technique
📌 Concept:
Two pointers (l1 and l2) are used to:

Traverse two linked lists simultaneously.

Keep track of digits being added.

📌 Why it’s used here:
The problem involves processing two lists simultaneously.

The two-pointer technique simplifies the logic of adding corresponding digits.

📌 Key Techniques:
✅ Parallel traversal of linked lists
✅ Synchronizing pointer movement
✅ Handling unequal list lengths

✅ 2. Dummy Node Technique
📌 Concept:
A dummy node is a placeholder node used to simplify linked list creation.

It eliminates edge cases for handling the head node separately.

📌 Why it’s used here:
The dummy node simplifies handling the first node creation.

Avoids writing special code for the head node case.

📌 Key Technique:
✅ Initialize a dummy node
✅ Return dummy->next as the result