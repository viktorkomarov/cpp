#pragma once
#include "node.h"


bool EmptyNode::Evaluate(const Date &date, const std::string &event) const{
    return true;
}

LogicalOperationNode::LogicalOperationNode(enum LogicalOperation op, const std::shared_ptr<Node> left,
                                           const std::shared_ptr<Node> right): _op(op), _left(left), _right(right){};

bool LogicalOperationNode::Evaluate(const Date &date, const std::string &event) const {
    switch (_op) {
        case LogicalOperation::And:
            return _left->Evaluate(date, event) && _right->Evaluate(date, event);
        case LogicalOperation::Or:
            return _left->Evaluate(date, event) || _right->Evaluate(date, event);
        default:
            return false;
    }
}

EventComparisonNode::EventComparisonNode(enum Comparison cmp, const std::string &event):
        _cmp(cmp), _event(event){};

bool EventComparisonNode::Evaluate(const Date &date, const std::string &event) const {
    switch (_cmp) {
        case Comparison::Less:
            return event < _event;
        case Comparison::Greater:
            return event > _event;
        case Comparison::LessOrEqual:
            return event <= _event;
        case Comparison::GreaterOrEqual:
            return event >= _event;
        case Comparison::Equal:
            return event == _event;
        case Comparison::NotEqual:
            return _event != event;
        default:
            return false;
    }
}

DateComparisonNode::DateComparisonNode(enum Comparison cmp, const Date &date) :_cmp(cmp), _date(date)
        {};

bool DateComparisonNode::Evaluate(const Date &date, const std::string &event) const {
    switch (_cmp) {
        case Comparison::Less:
            return date < _date;
        case Comparison::Greater:
            return !(_date == date) &&  _date < date;
        case Comparison::LessOrEqual:
            return date < _date || _date == date;
        case Comparison::GreaterOrEqual:
            return _date == date ||  _date < date;
        case Comparison::Equal:
            return _date == date;
        case Comparison::NotEqual:
            return !(_date == date);
        default:
            return false;
    }
}