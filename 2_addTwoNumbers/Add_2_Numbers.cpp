#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); //
        ListNode* current = dummy;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            sum = sum % 10;
            
            current->next = new ListNode(sum);
            current = current->next;
        }
        
        return dummy->next;
    }
};

// Function prototypes
void printList(ListNode*);
void print_sum(ListNode*);
ListNode* createList(int[], size_t);


ListNode* createList(int arr[], size_t size) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head; // Save original head

    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }

    cout << endl;

    print_sum(head); // Pass the original head to print the sum

    cout << "----------------------------------------\n" << endl;
}

void print_sum(ListNode* head) {
    long long sum = 0;
    long long place = 1;

    while (head != nullptr) {
        sum += head->val * place;
        place *= 10;
        head = head->next;
    }

    cout << "Sum = " << sum << endl;
}

void run_test_case(int case_num) {
    Solution solution;
    ListNode* l1;
    ListNode* l2;
    ListNode* result;

    if (case_num == 1) {
        int arr1[] = {2, 4, 3};
        int arr2[] = {5, 6, 4};
        l1 = createList(arr1, 3);
        l2 = createList(arr2, 3);
    } else if (case_num == 2) {
        int arr1[] = {0};
        int arr2[] = {0};
        l1 = createList(arr1, 1);
        l2 = createList(arr2, 1);
    } else if (case_num == 3) {
        int arr1[] = {9, 9, 9, 9, 9, 9, 9};
        int arr2[] = {9, 9, 9, 9};
        l1 = createList(arr1, 7);
        l2 = createList(arr2, 4);
    } else if (case_num == 4) {
        int arr1[] = {1, 2};
        int arr2[] = {9};
        l1 = createList(arr1, 2);
        l2 = createList(arr2, 1);
    } else if (case_num == 5) {
        int arr1[] = {5};
        int arr2[] = {7};
        l1 = createList(arr1, 1);
        l2 = createList(arr2, 1);
    } else if (case_num == 6) {
        int arr1[] = {9, 9, 9, 9, 9, 9, 9};
        int arr2[] = {9, 9, 9, 9, 9, 9, 9};
        l1 = createList(arr1, 7);
        l2 = createList(arr2, 7);
    } else if (case_num == 7) {
        int arr1[] = {2, 9, 6};
        int arr2[] = {8, 1, 4};
        l1 = createList(arr1, 3);
        l2 = createList(arr2, 3);
    } else if (case_num == 8) {
        int arr1[] = {0, 1, 2};
        int arr2[] = {0, 0, 3};
        l1 = createList(arr1, 3);
        l2 = createList(arr2, 3);
    } else if (case_num == 9) {
        int arr1[] = {5, 6, 4};
        int arr2[] = {5, 4, 6};
        l1 = createList(arr1, 3);
        l2 = createList(arr2, 3);
    } else if (case_num == 10) {
        int arr1[] = {9, 9};
        int arr2[] = {1};
        l1 = createList(arr1, 2);
        l2 = createList(arr2, 1);
    } else {
        cout << "Invalid test case number!" << endl;
        return;
    }

    result = solution.addTwoNumbers(l1, l2);
    printList(result);
}

void run_user_input_case() {
    Solution solution;
    
    int n1;
    cout << "Enter the number of digits for the first number: ";
    cin >> n1;
    
    int arr1[n1];
    cout << "Enter the digits of the first number (in reverse order): ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    
    int n2;
    cout << "Enter the number of digits for the second number: ";
    cin >> n2;
    
    int arr2[n2];
    cout << "Enter the digits of the second number (in reverse order): ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    
    ListNode* l1 = createList(arr1, n1);
    ListNode* l2 = createList(arr2, n2);
    
    // Add the two numbers
    ListNode* result = solution.addTwoNumbers(l1, l2);
    
    cout << "\nResult as linked list: ";
    printList(result);
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        int test_case = atoi(argv[1]);
        run_test_case(test_case);
    } else if (argc == 1) {
        run_user_input_case();
    } else {
        cout << "Usage:\n";
        cout << "  ./add_two_numbers <test_case_number>   # To run a specific test case\n";
        cout << "  ./add_two_numbers                     # To provide manual input\n";
        return 1;
    }

    return 0;
}
