#include <iostream>
#include <string>
#include <set>

using namespace std;

// Function prototype
size_t length_of_longest_substring(string&); // Find the length of the longest substring without repeating characters

int main() {
    string s; // Declare a string variable to hold the input

    cout << "Enter a string: "; // Prompt the user for input
    getline(cin, s); // Read the input string

    size_t length = length_of_longest_substring(s); // Call the function to find the length of the longest substring without repeating characters

    cout << "Length of the longest substring without repeating characters: " << length << endl; // Output the result

    return 0;
}

// Function definition

/** Find the length of the longest substring without repeating characters.
    @param s: The input string to be processed.
    @return size_t: The length of the longest substring without repeating characters. 
 */
size_t length_of_longest_substring(string& s) {
    set<char> seen; // Set to store characters in the current substring
    size_t max_length = 0; // Variable to store the maximum length of substring found
    size_t start = 0; // Start index of the current substring
    
    // Iterate through the string using two pointers: start and end
    for (size_t end = 0; end < s.length(); ++end) { 
        // If the character at the end pointer is already in the set, move the start pointer to the right
        while (seen.find(s[end]) != seen.end()) {
            seen.erase(s[start]); // Remove the character at the start pointer from the set
            ++start; // Move the start pointer to the right
        }
        seen.insert(s[end]); // Add the character at the end pointer to the set
        
        size_t current_length = end - start + 1; // Calculate the current length of the substring
        
        // Update the maximum length if the current length is greater     
        max_length = max(max_length, current_length);
    }
    
    // Return the maximum length of substring found
    return max_length; 
}