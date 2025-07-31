#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << "  ";
    mstack.pop();
    std::cout << mstack.size() << "  ";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << "  ";
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);

    std::cout << std::endl << "Testing with std::list:" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << "  ";
    lst.pop_back();
    std::cout << lst.size() << "  ";
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << "  ";
        ++lit;
    }
    std::cout << std::endl;
    std::list<int> l(lst);
    return 0;
}