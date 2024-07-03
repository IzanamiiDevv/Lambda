#include <iostream>
#include <functional>

typedef std::function<void(char)> fn;
typedef std::function<fn(char)> ffn;
typedef std::function<ffn(char)> fffn;

struct Password{
    std::string passcode;
    void(*set)(Password* buffer, std::string pass);
    fffn(*open)(Password* buffer);
};

Password PasswordInit() {
    Password buff;
    buff.set = [](Password* buffer, std::string pass)->void {
        buffer->passcode = pass;
    };
    
    buff.open = [](Password* buffer) -> fffn {
        return [buffer](char pass) -> ffn {
            return [buffer, pass](char pass2) -> fn {
                return [buffer, pass, pass2](char pass3) -> void {
                    char temp[3] = {pass, pass2, pass3};
                    std::string p;
                    for(char n : temp) p += n;
                    if(p == buffer->passcode) {
                        std::cout << "Success";
                    }else {
                        std::cout << "Failed";
                    };
                };
            };
        };
    };
    
    return buff;
}

int main() {
    Password test = PasswordInit();
    
    test.set(&test, "757");
    test.open(&test)('7')('5')('7');
    return 0;
}
