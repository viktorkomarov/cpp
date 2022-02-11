#include <vector>
#include <stdexcept>
#include <iostream>

template<typename T>
class Deque{
public:
    bool Empty() const {return front_items_.empty() && back_items_.empty();}
    size_t Size() const {return front_items_.size() + back_items_.size();}

    T& operator[](size_t index) {
        return access(index);
    }

    const T& operator[](size_t index) const {
        return access(index);
    }

    T& At(size_t index) {
        if (index >= Size()) throw std::out_of_range("");
        return access(index);
    }

    const T& At(size_t index) const {
        if (index >= Size()) throw std::out_of_range("");
        return access(index);
    }

    T& Front() {
        if (front_items_.empty()) {
            return back_items_.front();
        }

        return front_items_.back();
    }

    const T& Front() const {
        if (front_items_.empty()) {
            return back_items_.front();
        }
        
        return front_items_.back();
    }

    T& Back() {
        if(back_items_.empty()) {
            return front_items_.front();
        }
        return back_items_.back();
    }

   const T& Back() const {
        if(back_items_.empty()) {
            return front_items_.front();
        }
        return back_items_.back();
    }

    void PushFront(T t) {front_items_.push_back(t);}

    void PushBack(T t) {back_items_.push_back(t);}
private:
    std::vector<T> front_items_;
    std::vector<T> back_items_;

    T& access(size_t index) {
        if (index < front_items_.size()) {
            return front_items_[front_items_.size()-index - 1];
        }
        return back_items_[index - front_items_.size()];
    }

    const T& access(size_t index) const {
        if (index < front_items_.size()) {
            return front_items_[front_items_.size()-index - 1];
        }
        return back_items_[index - front_items_.size()];
    }
};

// int main()
// {
//     Deque<int> deq;
//     for(int i = 0; i < 10; ++i) deq.Pu

//     std::cout<< deq[0] <<std::endl;
//     std::cout<< deq[1] <<std::endl;
//     std::cout<< deq[2] <<std::endl;
//     std::cout<< deq[3] <<std::endl;
// }