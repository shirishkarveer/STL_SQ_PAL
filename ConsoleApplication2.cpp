// Determine if a string is a palindrome
// Use a queue and a stack to solve the problem

#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)//KEEP LOOKING AT FRONT OF QUE AND TOP OF STACK
{                                       //TAKE THOSE ELEMENTS AND COMPARE THEM
    std::stack<char> stk;
    std::queue<char> q;

    // add all the string characters that are alpha to the back of the queue  in uppercase
    // push all the string characters that are alpha on the stack

    for (char c : s)//USING RANGE BASED FOR LOOP TO ITERATE OVER STRING S that is passed into
        if (std::isalpha(c)) {   //for each char check if it is alpha char , 
            c = std::toupper(c);    //if it is CONV it to UPPER CASE
            q.push(c);             //set up the DS
            stk.push(c);           ////set up the DS
        }

    char c1{};      //VAR C1 = read char into
    char c2{};      //same as above

    // while the queue is not empty
    //      compare and remove the character at the top of the stack 
    //      and the chacterter at the front of the queue
    //      if they are not the same - return false since it can't be a palindrome
    // if you complete the loop then the string must be a palindrome so return true
    while (!q.empty()) {        //can use stack as well here coz both have same # of elems
        c1 = q.front();         //assign front of Q to c1
        q.pop();                //then get rid of char from Q
        c2 = stk.top();         //assign top of Q to c2
        stk.pop();              //popping that c2 out from stack
        if (c1 != c2)           //then compare the 2 chars
            return false;       //if not same return false
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}