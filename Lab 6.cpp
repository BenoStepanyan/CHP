#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

class RunLengthEncoder {
public:
    string encode(const string& input) {
        ostringstream encoded;
        int n = input.size();

        for (int i = 0; i < n; i++) {
            int count = 1;
            while (i + 1 < n && input[i] == input[i + 1]) {
                count++;
                i++;
            }
            encoded << input[i] << count;
        }
        return encoded.str();
    }

};

int main() {
    RunLengthEncoder rle;
    string input;
    cout<<"Naxadasutyun: ";
    getline(cin,input);
    string encoded = rle.encode(input);

    cout << "Encoded: " << encoded << endl;

    return 0;
}
