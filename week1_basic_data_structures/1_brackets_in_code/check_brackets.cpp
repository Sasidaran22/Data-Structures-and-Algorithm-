
  
#include <iostream>
#include <stack>
#include <string>

using namespace std;


struct Bracket {
    Bracket(char type, int pos):
        type(type),
        pos(pos)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']') {
            return true;
        }
        if (type == '{' && c == '}') {
            return true;
        }
        if (type == '(' && c == ')') {
            return true;
        }
        return false;
    }

    char type;
    int pos;
};

void print_stack(stack<Bracket> st) {
    char c;
    while (st.size()) {
        c = st.top().type;
        cout << c;
        st.pop();
    }
    cout << endl;
}

int main() {
    std::string text;
    getline(std::cin, text);
    int fpos = -1;

    std::stack <Bracket> opening_brackets_stack;
    for (int pos = 0; pos < text.length(); ++pos) {
        char next = text[pos];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket *b = new Bracket(next, pos + 1);
            opening_brackets_stack.push(*b);
        }

        if (next == ')' || next == ']' || next == '}') {
        
            if (opening_brackets_stack.size() == 0) {
                fpos = pos + 1;
                break;
            } else if (opening_brackets_stack.top().Matchc(next)) {
            
                opening_brackets_stack.pop();
            } else {
                fpos = pos + 1;
                break;
            }
        }
    }

    // Printing answer, write your code here
    if (opening_brackets_stack.size() == 0 && fpos == -1) {
        cout << "Success" << endl;
    } else {
        if (opening_brackets_stack.size() && fpos == -1) {
            fpos = opening_brackets_stack.top().pos;
        }
        cout << fpos << endl;
    }

    return 0;}
