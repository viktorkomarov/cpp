#include <set>
#include <deque>
#include <string>
#include "test_runner.h"

template <class T>
class ObjectPool {
public:
    T* Allocate()
    {
        T *obj = moveIfCan();
        if (obj != nullptr) {
            return obj;
        }
        obj = new T;
        active.insert(obj);
        return obj;
    }
    T* TryAllocate(){
        return moveIfCan();
    }

    void Deallocate(T* object){
        if (active.count(object) == 0) throw std::invalid_argument("not found");
        active.erase(object);
        released.push_back(object);
    }

    ~ObjectPool(){
        for(auto obj : active) {
            delete obj;
        }

        for (size_t i = 0; i < released.size(); ++i)
        {
            delete released[i];
        }
    }


private:
    std::deque<T*> released;
    std::set<T*> active;

    T* moveIfCan() {
        if (released.size() == 0) {
            return nullptr;
        }
        auto obj = released.front();
        released.pop_front();
        active.insert(obj);
        return obj;
    }
};

void TestObjectPool() {
    ObjectPool<std::string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    pool.Deallocate(p1);
}
/*
int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}*/