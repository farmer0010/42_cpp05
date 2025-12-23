#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- 테스트 1: 정상적인 관료 생성 및 승진/강등 ---" << std::endl;
    try {
        Bureaucrat chulsoo("Chulsoo", 2);
        std::cout << chulsoo << std::endl;

        std::cout << ">> 승진 시도 (2 -> 1)" << std::endl;
        chulsoo.incrementGrade();
        std::cout << chulsoo << std::endl;

        std::cout << ">> 강등 시도 (1 -> 2)" << std::endl;
        chulsoo.decrementGrade();
        std::cout << chulsoo << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "예외 발생: " << e.what() << std::endl;
    }

    std::cout << "\n--- 테스트 2: 잘못된 등급으로 생성 시도 (0등급) ---" << std::endl;
    try {
        Bureaucrat badGuy("BadGuy", 0);
        std::cout << "이 메시지는 절대 출력되면 안 됩니다." << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "예외 잡음: " << e.what() << std::endl;
    }

    std::cout << "\n--- 테스트 3: 잘못된 등급으로 생성 시도 (151등급) ---" << std::endl;
    try {
        Bureaucrat lazyGuy("LazyGuy", 151);
        std::cout << "이 메시지는 절대 출력되면 안 됩니다." << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "예외 잡음: " << e.what() << std::endl;
    }

    std::cout << "\n--- 테스트 4: 한계 돌파 시도 (1등급에서 승진) ---" << std::endl;
    try {
        Bureaucrat president("President", 1);
        std::cout << president << std::endl;

        std::cout << ">> 무리하게 승진 시도!" << std::endl;
        president.incrementGrade();
        std::cout << "이 메시지는 출력되면 안 됩니다." << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "예외 잡음: " << e.what() << std::endl;
    }

    return 0;
}
