#include <iostream>

class AbstractDisplay{
public:
    virtual void open() = 0;
    virtual void print() = 0;
    virtual void close() = 0;
    void Display() {
        open();
        print();
        close();
    } 
};

class ballpointPen : public AbstractDisplay {
    virtual void open() {
        std::cout << "打开圆珠笔笔套." << std::endl;
    }

    virtual void print(){
        std::cout << "我正在使用我的圆珠笔写字." << std::endl;
    }

    virtual void close(){
        std::cout << "套上圆珠笔笔套." << std::endl;
    }
};

class fountainPen : public AbstractDisplay{
    virtual void open() {
        std::cout << "打开钢笔笔套." << std::endl;
    }

    virtual void print(){
        std::cout << "我正在使用我的钢笔写字." << std::endl;
    }

    virtual void close(){
        std::cout << "套上钢笔笔套." << std::endl;
    }
};

int main(int argc,char** argv) 
{
    AbstractDisplay* pen = new fountainPen;
    pen->Display();
    delete pen;
    pen = new ballpointPen;
    pen->Display();
    return 0;
}