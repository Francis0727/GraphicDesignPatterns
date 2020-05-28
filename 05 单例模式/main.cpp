#include <iostream>
#include <thread>
#include <mutex>

class salesItem{
public:
    static salesItem* getInstance() {
        if (m_instance == NULL){
            std::mutex mutex1;
            std::lock_guard<std::mutex> guard(mutex1);
            if (m_instance == NULL){
                m_instance = new salesItem();
                static Destruct c1;
            }
        }
        return m_instance;
    }

    class Destruct {
    public:
        ~Destruct() {
            if (m_instance != NULL){
                delete m_instance;
                m_instance = NULL;
                std::cout << "m_instance have been released..." 
<< std::endl;
            }
        }
    };
private:
    salesItem() = default;
private:
    static salesItem* m_instance;
};

// 定义静态成员变量
salesItem* salesItem::m_instance = NULL;

void thread(){
    salesItem* pt = salesItem::getInstance();
    return ;
}

int main() {
    std::thread Thread1(thread);
    std::thread Thread2(thread);
    Thread1.join();
    Thread2.join();

    return 0;
}
