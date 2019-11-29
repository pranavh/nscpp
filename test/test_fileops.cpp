#include<iostream>
#include "../src/fileops.cpp"

namespace t_fileops
{
    void test_iscomment() {
        std::cout << "Testing iscomment()" << std::endl;
        std::cout << "iscomment(\'x\'): " << nscpp::iscomment('x') << std::endl;
        std::cout << "iscomment(\'%\'): " << nscpp::iscomment('%') << std::endl;
        std::cout << "iscomment(\'#\'): " << nscpp::iscomment('#') << std::endl;
    }

    void test_dlmread() {
        std::cout << "Testing dlmread()" << std::endl;
        std::vector<std::vector<double>> data=nscpp::dlmread("./test_assets/dlmread.dat");
        int nrows = data.size();
        int ncols = data[0].size();

        std::cout << "Data size: " << nrows << "x" << ncols << std::endl;
        std::cout << "Data: " << std::endl;
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
            {
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }

    }

    void test_dlmread1d() {
        std::vector<double> data;

        std::cout << "Testing dlmread1d()" << std::endl;
        data = nscpp::dlmread1d("./test_assets/dlmread1d.dat", ',');
        int nelem = data.size();

        std::cout << "Data size: " << nelem << std::endl;
        std::cout << "Data: " << std::endl;
        for (int i = 0; i < nelem; i++)
        {
            std::cout << data[i] << "\t";
        }
        std::cout << std::endl;
    }

    void test_dlmwrite() {
        std::vector<std::vector<double>> v = { {1.2, 1.3, 1.4, 1.5}, {2.2, 2.3, 2.4, 2.5}, {3.2, 3.3, 3.4, 3.5} };

        std::cout << "Testing dlmwrite()" << std::endl;
        nscpp::dlmwrite("./test_assets/dlmwrite.dat", v);

        std::cout << "Testing dlmwrite_1d()" << std::endl;
        nscpp::dlmwrite("./test_assets/dlmwrite_1d.dat", v[0], ',');
    }

    int do_test() {
        std::cout << "Testing fileops.cpp" << std::endl;
        std::cout << "-------------------" << std::endl << std::endl;
        test_iscomment();
        test_dlmread1d();
        test_dlmread();
        test_dlmwrite();
        std::cout << std::endl << std::endl << "-------------------" << std::endl;
        std::cout << "Finished testing fileops.cpp" << std::endl;
    }
} // namespace t_fileops