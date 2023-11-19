#include <iostream>
#include <string>

int Execute(const std::string s) {
    return system(s.c_str());
}

// 1 - name of solve that you want to debug (good/fast) | main
// 2 - name of solve that fully works (bad/slow)        | stupid
// 3 - name of test generator                           | gen
// 4 - count of tests                                   | 100

int main(const int argc, const char** argv) {
    if (argc != 5) {
        std::cerr << "You gave wrong amount of arguments (" << argc - 1 << "), expected 4";
        return 1;
    }

    // PREPARING
    std::string name_working_solve = argv[1],
                name_debug_solve = argv[2],
                name_generator = argv[3];
    const int cnt_tests = atoi(argv[4]);
    Execute("mkdir outputs_working");
    Execute("mkdir outputs_debug");
    Execute("mkdir tests");

    // COMPILING
    Execute("g++ " + name_working_solve + ".cpp -o" + name_working_solve);
    Execute("g++ " + name_debug_solve + ".cpp -o" + name_debug_solve);
    Execute("g++ " + name_generator + ".cpp -o" + name_generator);

    // GENERATING & TESTING
    for (int i = 0; i < cnt_tests; i++) {
        Execute(name_generator + ".exe " + std::to_string(i + 1) + " > " + "tests\\test" + std::to_string(i) + ".txt");
        Execute(name_working_solve + ".exe " + " < " + "tests\\test" + std::to_string(i) + ".txt > outputs_working\\output" + std::to_string(i) + ".txt");
        Execute(name_debug_solve + ".exe " + " < " + "tests\\test" + std::to_string(i) + ".txt > outputs_debug\\output" + std::to_string(i) + ".txt");
        const int res = Execute("comp outputs_working\\output" + std::to_string(i) + ".txt outputs_debug\\output" + std::to_string(i) + ".txt /M");
        if (res != 0) {
            std::cout << "Failed at test " << i << std::endl;
            return 2; 
        }
    }

    // RESULTING
    std::cout << "All tests passed!" << std::endl;
    return 0;
}