#include <iostream>
#include <vector>
#include <string>

typedef void(*function)();

void forEach(std::string txt, void(*func)(char));
void forEach(std::vector<int> arr, void(*func)(int));
void forEach(std::vector<std::string> arr, void(*func)(std::string));
void runCode(function cb);

int main() {
    
    std::vector<int> numbers = {10,39,21,38};
    std::vector<std::string> names = {"Gab", "Rose", "Kyle"};
    
    forEach("Hello", [](char c) -> void {
        std::cout << c << std::endl;
    });
    
    forEach(numbers, [](int x) -> void {
        int z = x + 10;
        std::cout << z << std::endl;
    });
    
    forEach(names, [](std::string name) -> void {
        std::cout << name << std::endl;
    });

    return 0;
}

//string
void forEach(std::string txt, void(*func)(char)) {
    for(int i = 0; i < txt.length(); i++) {
        func(txt[i]);
    }
}

//vector int
void forEach(std::vector<int> arr, void(*func)(int)) {
    for(int i = 0; i < arr.size(); i++) {
        func(arr[i]);
    }
}

//vector string
void forEach(std::vector<std::string> arr, void(*func)(std::string)) {
    for(int i = 0; i < arr.size(); i++) {
        func(arr[i]);
    }
}

//Typedef Function
void runCode(function cb){
    cb();
}