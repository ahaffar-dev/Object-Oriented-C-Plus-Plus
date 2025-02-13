#include <iostream>
#include <string>

using namespace std;

void printMem(int* arr, int size) {
    printf("Each int is worth %lu bytes\n", sizeof(arr[0]));
    for (int i = 0; i < size; i++) {
        printf("Value :%i at Memory Location: %p\n", arr[i], arr + i);
    }
}

void printMem(string arr[], int size) {
    cout << "Each string is stored at memory locations:\n";
    for (int i = 0; i < size; i++) {
        cout << "Value: \"" << arr[i] << "\" at Memory Location: " << static_cast<const void*>(arr[i].c_str()) << endl;

    }
}

int main() {
    // Array of integers
    int intArray[5] = { 1, 2, 3, 4, 5 };
    printMem(intArray, 5);

    // Change last value and print it
    intArray[4] = 500;
    cout << "Last value in array: " << intArray[4] << endl;

    // Calculate memory difference
    int* firstAddr = &intArray[0];
    int* secondAddr = &intArray[1];
    int addressDifference = (char*)secondAddr - (char*)firstAddr;
    cout << "Memory Address Difference: " << addressDifference << " bytes" << endl;

    // Array of strings with "hello" in different languages
    string greetings[5] = { "Hello", "Hola", "Bonjour","Salams","Ciao"};
    printMem(greetings, 5);

    // Calculate memory difference for strings
    char* firstStrAddr = (char*)greetings[0].c_str();
    char* secondStrAddr = (char*)greetings[1].c_str();
    int stringAddressDifference = secondStrAddr - firstStrAddr;

    cout << "Memory Address Difference for strings: " << stringAddressDifference << " bytes" << endl;

    return 0;
}