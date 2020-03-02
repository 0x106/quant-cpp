
#include "../src/vector.h"

int test_constructors()
{
    int success = 1;
    {
        Quant::Vector<float> v;
    }

    {
        Quant::Vector<float> v(1);
        if (v.data().size() != 1)
            success = 0;
    }

    {
        std::vector<float> data;
        data.push_back(3);
        data.push_back(5);
        data.push_back(7);

        Quant::Vector<float> v(data);

        if (!(v.data()[0] == 3) || !(v.data()[1] == 5) || !(v.data()[2] == 7))
            success = 0;
    }

    {
        Quant::Vector<float> v({3, 5, 7});
        if (!(v.data()[0] == 3) || !(v.data()[1] == 5) || !(v.data()[2] == 7))
            success = 0;
    }

    return success;
}

int test_copy()
{
    int success = 1;
    {
        Quant::Vector<float> v({3, 5, 7});
        if (!(v.data()[0] == 3) || !(v.data()[1] == 5) || !(v.data()[2] == 7))
            success = 0;

        Quant::Vector<float> q(v);

        if (!(q.data()[0] == 3) || !(q.data()[1] == 5) || !(q.data()[2] == 7))
            success = 0;

        Quant::Vector<float> p = q;

        if (!(p.data()[0] == 3) || !(p.data()[1] == 5) || !(p.data()[2] == 7))
            success = 0;
    }
    return success;
}

int test_move()
{
    int success = 0;
    return success;
}

int test_operator_add()
{
    int success = 1;
    {
        Quant::Vector<float> v({3, 5, 7});
        Quant::Vector<float> q({11, 13, 17});

        Quant::Vector<float> p = v + q;

        if (!(p.data()[0] == 14) || !(p.data()[1] == 18) || !(p.data()[2] == 24))
            success = 0;
    }
    return success;
}

int test_operator_subtract()
{
    int success = 1;
    {
        Quant::Vector<float> v({3, 5, 7});
        Quant::Vector<float> q({11, 13, 17});

        Quant::Vector<float> p = v - q;

        if (!(p.data()[0] == -8) || !(p.data()[1] == -8) || !(p.data()[2] == -10))
            success = 0;
    }
    return success;
}

int test_operator_scalar_multiply()
{
    int success = 0;
    return success;
}

int test_operator_scalar_divide()
{
    int success = 0;
    return success;
}

int main(int argc, char **argv)
{

    std::cout << "test_constructors: " << (test_constructors() == 1 ? "passed." : "failed.") << std::endl;
    std::cout << "test_copy: " << (test_copy() == 1 ? "passed." : "failed.") << std::endl;
    std::cout << "test_move: " << (test_move() == 1 ? "passed." : "failed.") << std::endl;
    std::cout << "test_operator_add: " << (test_operator_add() == 1 ? "passed." : "failed.") << std::endl;
    std::cout << "test_operator_subtract: " << (test_operator_subtract() == 1 ? "passed." : "failed.") << std::endl;
    std::cout << "test_operator_scalar_multiply: " << (test_operator_scalar_multiply() == 1 ? "passed." : "failed.") << std::endl;
    std::cout << "test_operator_scalar_divide: " << (test_operator_scalar_divide() == 1 ? "passed." : "failed.") << std::endl;

    return 0;
}