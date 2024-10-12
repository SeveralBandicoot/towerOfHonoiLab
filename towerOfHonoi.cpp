/* Towers of Hanoi - using Stacks

@AJ Enrique Arguello (10/1/24)

* Objective: Students will simulate the Tower of Hanoi Puzzle
With 4 Blocks (characters - A, B, C & D) and 3 character Stacks T1, T2 & T3
Create 3 character stacks T1, T2 and T3. Fill T1 with the characters A, B, C & D (leaving the
other 2 Towers T2 & T3 empty). Display the Board
T1 A B C D
T2
T3
Prompt the user to enter a source T and a destination T.
Move the last character from source to destination – Students MUST use Stacks

Ex) if the user entered 1 and then 2 the display should show
T1 A B C
T2 D
T3

Ex) entering 1-3 would then move the B character to the T3
T1 A B
T2 D
T3 C
Continue prompting the user until the A B C D characters are moved to Tower 3 in order
The only rule is that letters can NEVER be out of alphabetical order.
A B is allowed but not B A, A C is allowed but not C A, B C but not C B,...


*/

#include <iostream>
#include <stack>

using namespace std;

void Board(); // prototype for board function 
void tower(int &start, int &end, stack<char> &T1, stack<char> &T2, stack<char> &T3); // prototype for tower function 
stack<char> T1; // tower 1 stack
stack<char> T2; // tower 2 stack
stack<char> T3; // tower 3 stack

int main() {
    bool pzleComplete = false; // bool puzzle complete variable set to false 
    char a = 'A', b = 'B', c = 'C', d = 'D'; // characters a, b, c, d
    int srce, dest; // int variables for source and destination 

    // pushes characters into T1 in the order (A B C D)
    T1.push(a);  
    T1.push(b);
    T1.push(c);
    T1.push(d);  

    // loops until the puzzle is completed
    while (!pzleComplete) { 
        Board(); // display current board 

        // prompts the user for source and destination inputs
        cout << "Enter your source tower (1, 2, 3): ";
        cin >> srce;
        cout << "Enter your destination tower (1, 2, 3): ";
        cin >> dest;

        // move the character between the towers
        tower(srce, dest, T1, T2, T3);

        // checks if T3 contains the complete puzzle in order: A B C D
        if (T3.size() == 4 && T3.top() == 'D') {
            stack<char> temp = T3;
            temp.pop();
            if (temp.top() == 'C') {
                temp.pop();
                if (temp.top() == 'B') {
                    temp.pop();
                    if (temp.top() == 'A') {
                        pzleComplete = true;
                    }
                }
            }
        }
    }

    // displays the final board 
    cout << "\nCongrats! You completed the puzzle!\n";
    Board();

    return 0;
}

// function to display the contents of the stack from bottom to top
void displayStack(stack<char> s) {
    stack<char> tempStack;
    // transfers elements to temporary stack to reverse the order
    while (!s.empty()) {
        tempStack.push(s.top());
        s.pop();
    }
    // prints from the temporary stack
    while (!tempStack.empty()) {
        cout << "\t" << tempStack.top();
        tempStack.pop();
    }
}

// function to display the current board state
void Board() {
    cout << "\nT1 "; // displays all the tiles on Tower 1
    displayStack(T1);
    cout << "\n\nT2 "; // displays all the tiles on Tower 2
    displayStack(T2);
    cout << "\n\nT3 "; // displays all the tiles on Tower 3
    displayStack(T3);
    cout << "\n\n";
}

// function moves blocks from one tower to another
void tower(int &start, int &end, stack<char> &T1, stack<char> &T2, stack<char> &T3) {
    stack<char> *source = nullptr, *destination = nullptr; // pointers for source and destination stacks

    // assigns source and destination based on user input
    if (start == 1) source = &T1;
    else if (start == 2) source = &T2;
    else if (start == 3) source = &T3;

    if (end == 1) destination = &T1;
    else if (end == 2) destination = &T2;
    else if (end == 3) destination = &T3;

    // ensures valid source and destination, checks if the source tower is not empty
    if (source && destination && !source->empty()) {
        char topElement = source->top();

        if (destination->empty() || topElement > destination->top()) { // checks if destination is empty or in the incorrect order  
            source->pop(); // removes element from the source
            destination->push(topElement); // moves the top element to the destination stack
        } else { 
            cout << "Invalid move! You can only place larger letters on smaller ones.\n";
        }
    } else {
        cout << "Invalid move! The source tower is empty or input is incorrect.\n";
    }
}

