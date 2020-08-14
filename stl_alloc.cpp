// file: 2jjalloc.cpp

#include "stl_alloc.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class X {
public:
    int a;
    char b;
public:
    X(int m_a, char m_b) : a(m_a), b(m_b){};
    ~X() { std:cout << "destory X" << std::endl ;};
};

#ifdef DEBUG

int main() {
    // int ia[5] = {0, 1, 2, 3, 4};
    int i;

    // vector<int, JJ::allocator<int> > iv(ia, ia + 5);

    // iv.push_back(5);
    // iv.push_back(6);
    // iv.push_back(7);
    // iv.erase(iv.begin());

    // for (i = 0; i < iv.size(); i++) {
    //     cout << iv[i] << ' ';
    // }

    // cout << endl;

    vector<X, JJ::allocator<X> > xv;
    xv.reserve(16);
    xv.push_back(X(1, 'a'));
    xv.push_back(X(2, 'b'));
    xv.push_back(X(3, 'c'));

    for (i = 0; i < xv.size(); i++) {
        cout << xv[i].a << ' ';
    }

    // vector<std::string, JJ::allocator<std::string> > sv;
    // sv.reserve(16);
    // sv.push_back(std::move(std::string("a")));
    // sv.push_back("b");
    // sv.push_back("c");

    // for (i = 0; i < sv.size(); i++) {
    //     cout << sv[i] << ' ';
    // }

}

#endif