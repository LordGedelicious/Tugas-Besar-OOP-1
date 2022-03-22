#ifndef __BASE_EXCEPTION_HPP__
#define __BASE_EXCEPTION_HPP__

#include <iostream>
using namespace std;

// ini masih disatuin dlu di satu file, nanti baru dipisah pisah
class BaseException {
public:
    virtual void printMessage() = 0;
};

class ItemNotFoundException : public BaseException {
    private:
        int id;
        string name;
    public:
        ItemNotFoundException(string name);
        ItemNotFoundException(int id);
        void printMessage() override;
};

#endif