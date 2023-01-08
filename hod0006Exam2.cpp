/*
Midterm 2 - Programming:
Hash Table with Linear Probing and Mid-Square Hash Function
by Hiram Dominguez
*/
#include <iostream>
#include <cmath>
using namespace std;

class midHashTable {
private:
    const int tableSize{ 10 };
    int squaredKey, extractedBits, lowBitsToRemove;
    int R = ceil(log2(tableSize));

    int getHashMidSquare(int key) {
        squaredKey = key * key;

        lowBitsToRemove = ((32 - R) / 2);
        extractedBits = squaredKey >> lowBitsToRemove;
        extractedBits = extractedBits & (0xFFFFFFFF >> (32 - R));

        return extractedBits % tableSize;
    }
public:
    midHashTable() {
        const int tableSize = 10;
        int table[tableSize];
    }

    bool HashInsert(int table[], int item) {
        int bucket{};
        bucket = getHashMidSquare(item);
        int bucketsProbed = 0;
        while (bucketsProbed < tableSize) {
            if (table[bucket] == NULL) {
                table[bucket] = item;
                cout << "Inserted!" << endl;
                return true;
            }

            bucket = (bucket + 1) % tableSize;
            ++bucketsProbed;
        }

        return false;
    }

    int HashSearch(int table[], int key) {
        int bucket{};
        int bucketProbed = 0;
        bucket = getHashMidSquare(key);
        while ((table[bucket] != NULL) && (bucketProbed < tableSize)) {
            if (table[bucket] != NULL && table[bucket] == key) {
                return table[bucket];
            }

            bucket = (bucket + 1) % tableSize;
            ++bucketProbed;
        }
        return NULL;
    }

    void HashRemove(int table[], int key) {
        int bucket = 0;
        int bucketProbed = 0;

        while ((table[bucket] != NULL) && bucketProbed < tableSize) {
            if (table[bucket] != NULL && table[bucket] == key){
                    cout << "REMOVED" << endl;
            }

            bucket = (bucket + 1) % tableSize;

            ++bucketProbed;
        }
    }
};

int main(){
    midHashTable Hashman;
    int selection;
    int num;
    int arr[10];

    cout << "WELCOME TO HASH THING" << endl;
    cout << "Type an option:\n 1.Insert\n 2.Search\n 3.Remove" << endl;
    cin >> selection;

    switch (selection) {
    case 1:
        cout << "Put in any number: " << endl;
        cin >> num;
        Hashman.HashInsert(arr, num);
        break;
    case 2:
        cout << "Put in any number: " << endl;
        Hashman.HashSearch(arr, num);
        cin >> num;
        break;
    case 3:
        cout << "Put in any number: " << endl;
        Hashman.HashRemove(arr, num);
        cin >> num;
        break;
    default:
        cout << "Please select something" << endl;
    }
    return 0;
}