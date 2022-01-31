#pragma once
#include "date.h"
#include <string>
#include <memory>
#include "token.h"

class Node{
public:
    virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const std::string& event) const override;
};

class LogicalOperationNode: public Node {
public:
    LogicalOperationNode(enum LogicalOperation op,const std::shared_ptr<Node> left, const std::shared_ptr<Node> right);
    bool Evaluate(const Date& date, const std::string& event) const override;

private:
    enum LogicalOperation _op;
    const std::shared_ptr<Node> _left;
    const std::shared_ptr<Node> _right;
};

class EventComparisonNode: public Node {
public:
    EventComparisonNode(enum Comparison cmp, const std::string& event);
    bool Evaluate(const Date& date, const std::string& event) const override;

private:
    enum Comparison _cmp;
    const std::string _event;
};

class DateComparisonNode: public Node {
public:
    DateComparisonNode(enum Comparison cmp, const Date& date);
    bool Evaluate(const Date& date, const std::string& event) const override;

private:
    enum Comparison _cmp;
    const Date _date;
};