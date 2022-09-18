#include <iostream>;
#include <vector>
#include "map";

using namespace std;

int main(){

    int T;
    cin >> T;

    while (T--){
        int N, X, operationNo=0, xorOperation, maxOcurance = 1;
        vector<int> arr;

        cin >> N >> X;
        map<int, int> counter, operations;
        map<int, int>::iterator itr;

        for(int i = 0; i < N; i++){
            int arrNumber;
            cin >> arrNumber;

            itr = counter.find(arrNumber);
            if (itr != counter.end()){
                counter[arrNumber]++;
            }
            else{
                counter[arrNumber] = 1;
            }

            operations[arrNumber] = 0;
        }

        for(auto it = counter.cbegin(); it != counter.cend(); it++){
            if (X == 0){
                break;
            }

            xorOperation  = it->first ^ X;


            itr = counter.find(xorOperation);
            if (itr != counter.end()){
                counter[xorOperation]++;
            }

            itr = operations.find(xorOperation);
            if (itr != operations.end()){
                operations[xorOperation]++;
            }


        }

        for(auto it = counter.cbegin(); it != counter.cend(); it++){
            if (it->second >= maxOcurance){
                arr.push_back(it->first);
                maxOcurance = it->second;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            if (i == 0){
                operationNo = operations[arr.at(i)];
            }
            else{
                if (operations[arr.at(i)] < operationNo){
                    operationNo = operations[arr.at(i)];
                }
            }

        }

        cout << maxOcurance << " " << operationNo << "\n";

    }
}