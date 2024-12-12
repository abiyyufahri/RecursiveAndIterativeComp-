#include <iostream>

using namespace std;

long long minStep(string s);
int main(int argc, char* argv[]) {
    if (argc > 1) {
        cout << minStep(argv[1]) << endl;
    } else {
        cout << "No input provided." << endl;
    }
    return 0;
}


long long minStep(string s) {
    long long total_step = 0;
    int n1 = 0;
    int n = 0;

    for (int pos = s.length() -1; pos >= 0; --pos) {
        if (s[pos] == '1') {
            total_step += n - n1;
            n1++;
        }
        n++;
    }

    if (n1 == 0) {
        return 0;
    }

    return total_step;
}



