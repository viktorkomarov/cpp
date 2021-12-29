#include <vector>
#include <algorithm>

class FunctionPart{
public:
    FunctionPart(char ops, double arg) {
        operation = ops;
        val = arg;
    }
    double Apply(double src) const {
        if (operation == '-') {
            return src - val;
        } else if(operation == '+') {
            return src + val;
        }

        return src;
    }
    void Invert() {
        if (operation == '-') {
            operation = '+';
        } else if(operation == '+') {
            operation = '-';
        }
    }
private:
    char operation;
    double val;
};

class Function{
public:
    void AddPart(char operation, double v){
        operations.push_back({operation, v});
    }
    double Apply(double source) const{
        for(const auto& part : operations) {
            source = part.Apply(source);
        }
        return source;
    }
    void Invert() {
        for(auto& part : operations) part.Invert();
        std::reverse(begin(operations), end(operations));
    }
private:
    std::vector<FunctionPart> operations;
};
