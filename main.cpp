#include <iostream>
#include <vector>

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }
}

long long directAccess(const int arr[], int size) {
    const int middle = size / 2;
    (void)arr[middle];
    return 1;
}

long long oneLoop(const int arr[], int size) {
    long long counter = 0;
    for (int i = 0; i < size; ++i) {
        (void)arr[i];
        ++counter;
    }
    return counter;
}

long long divideBy2(int size) {
    long long counter = 0;
    while (size > 1) {
        size /= 2;
        ++counter;
    }
    return counter;
}

long long insideLoopD2(int size) {
    long long counter = 0;
    for (int i = 0; i < size; ++i) {
        int temporary = size;
        while (temporary > 1) {
            temporary /= 2;
            ++counter;
        }
    }
    return counter;
}

long long nestedLoop(int size) {
    long long counter = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ++counter;
        }
    }
    return counter;
}

int main() {
    const int inputSizes[] = {10, 100, 500, 2000};

    std::cout << "n\tdirectAccess\toneLoop\tdivideBy2\tinsideLoopD2\tnestedLoop\n";
    for (int size : inputSizes) {
        std::vector<int> values(size);
        fillArray(values.data(), size);

        std::cout << size << '\t'
                  << directAccess(values.data(), size) << "\t\t"
                  << oneLoop(values.data(), size) << "\t\t"
                  << divideBy2(size) << "\t\t"
                  << insideLoopD2(size) << "\t\t"
                  << nestedLoop(size) << '\n';
    }
}