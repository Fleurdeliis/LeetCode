#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int size = time.size();
        int correct = 0;
        double x[60];
        for (int i = 0; i < 60; i++) {
            x[i] = 0;
        }
        for (int i = 0; i < size; i++) {
            time[i] %= 60;
            x[time[i]]++;
        }

        for (int i = 1; i < 60; i++) {
            for (int j = i + 1; j < 60; j++) {
                if ((i + j) % 60 == 0)
                    correct += x[i] * x[j];
            }
        }

        correct += (int)(x[0] * (x[0] - 1) / 2);
        correct += (int)(x[30] * (x[30] - 1) / 2);

        return correct;
    }

};