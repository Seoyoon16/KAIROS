#include <iostream>
#include <string> // <cstring>를 <string>으로 수정해야 합니다.

class Johnson {
public:
    int age;
    std::string name; // string을 std::string으로 수정해야 합니다.
};

int main() {
    Johnson* js = new Johnson;
    js->age = 10; // (* js).age = 10;
    js->name = "Johnson"; // (* js).name = "Johnson";

    std::cout << js->age << std::endl;
    std::cout << js->name << std::endl;

    delete js; // 동적 할당된 메모리를 해제해야 합니다.

    return 0;
}

// main() 함수는 프로그램의 진입점입니다. 이 함수에서는 Johnson 클래스의 객체를 동적으로 할당하고, 멤버 변수에 값을 할당합니다.

// 먼저 Johnson* js = new Johnson;를 통해 Johnson 클래스의 객체를 동적으로 할당합니다. js는 Johnson 객체를 가리키는 포인터입니다.

// 다음으로 js->age = 10;와 js->name = "Johnson";를 사용하여 js 포인터가 가리키는 Johnson 객체의 age와 name 멤버 변수에 값을 할당합니다. -> 연산자는 포인터를 통해 멤버에 접근할 때 사용됩니다.

// 그 다음에는 std::cout을 사용하여 js->age와 js->name을 출력합니다. std::cout은 표준 출력 스트림을 나타내는 객체이며, << 연산자를 사용하여 값을 출력합니다.

// js->age와 js->name은 각각 int와 std::string 타입이므로, std::cout을 통해 출력할 수 있습니다.

// 마지막으로 delete js;를 사용하여 동적으로 할당된 메모리를 해제합니다. delete 연산자를 사용하여 동적으로 할당된 객체를 메모리에서 제거할 수 있습니다.

// 프로그램의 실행이 종료되기 전에 return 0;을 사용하여 정상적으로 종료되었음을 나타냅니다.

// 이렇게 코드를 실행하면 "10Johnson"이라는 출력 결과가 나타날 것입니다.