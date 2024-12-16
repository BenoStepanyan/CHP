#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


struct LZ77Triple {
    int length;
    int distance;
    char nextChar;

    LZ77Triple(int len, int dist, char next)
        : length(len), distance(dist), nextChar(next) {}
};


vector<LZ77Triple> compress(const string& input, int windowSize = 10, int bufferSize = 5) {
    vector<LZ77Triple> output;
    int n = input.length();
    int i = 0;

    
    while (i < n) {
        int matchLength = 0;
        int matchDistance = 0;

        for (int j = max(0, i - windowSize); j < i; ++j) {
            int k = 0;
          
            while (k < bufferSize && (i + k) < n && input[j + k] == input[i + k]) {
                k++;
            }

            
            if (k > matchLength) {
                matchLength = k;
                matchDistance = i - j;
            }
        }

        
        char nextChar = (matchLength > 0 && i + matchLength < n) ? input[i + matchLength] : '\0';

        
        output.push_back(LZ77Triple(matchLength, matchDistance, nextChar));

      
        i += (matchLength > 0 ? matchLength : 1);
    }

    return output;
}


void printCompressedData(const vector<LZ77Triple>& compressed) {
    for (const auto& triple : compressed) {
        cout << "(" << triple.length << ", " << triple.distance << ", '" << triple.nextChar << "') ";
    }
    cout << endl;
}

int main() {
    string input = "ABABABABA";  // Test input string
    cout << "Input String: " << input << endl;

   
    vector<LZ77Triple> compressedData = compress(input);

    cout << "Compressed Data (Length, Distance, Next Character):" << endl;
    printCompressedData(compressedData);

    return 0;
}
