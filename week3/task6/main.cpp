#include <string>
#include <algorithm>

class ReversibleString{
    public:
        ReversibleString(){}
        ReversibleString(const std::string& v) {
            val = v;
        }

        void Reverse() {
           std::reverse(begin(val), end(val));
        }

        std::string ToString() const {
            return val;
        }
    private:
        std::string val;
};