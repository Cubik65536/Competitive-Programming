#include<bits/stdc++.h>

using namespace std;

int main() {
    string dir;
    string instruction;

    while(true) {
        cin >> instruction;
        if (instruction == "99999") {
            break;
        }

        int direction = ((int) (instruction[0] - '0')) + ((int) (instruction[1] - '0'));

        if (direction == 0) {
            cout << dir << " " << (instruction.substr(2, 3)) << endl;
        } else if (direction % 2 == 0) {
            dir = "right";
            cout << dir << " " << (instruction.substr(2, 3)) << endl;
        } else {
            dir = "left";
            cout << dir << " " << (instruction.substr(2, 3)) << endl;
        }
    }
    
    return 0;
}
