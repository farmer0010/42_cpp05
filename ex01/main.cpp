#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\n--- Test 1: Valid Signing (Success) ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 10);
        Form       taxForm("Tax Form", 20, 50);

        std::cout << alice << std::endl;
        std::cout << taxForm << std::endl;

        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Low Grade Signing (Failure) ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        Form       secretDoc("Secret Doc", 10, 10);

        std::cout << bob << std::endl;
        std::cout << secretDoc << std::endl;

        bob.signForm(secretDoc);
        std::cout << secretDoc << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Invalid Form Construction (Too High) ---" << std::endl;
    try {
        Form badForm("Bad", 0, 10);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Invalid Form Construction (Too Low) ---" << std::endl;
    try {
        Form badForm("Bad", 151, 10);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
