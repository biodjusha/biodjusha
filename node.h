#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED


#include <memory>
#include "date.h"


using namespace std;

enum class Comparison{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
    };

enum class LogicalOperation{
   Or,
   And,
};

class Node{
public:
    virtual bool Evaluate(const Date& d, const string& e)const=0;
};

class DateComparisonNode:public Node{
public:
    DateComparisonNode(Comparison& c, const Date& d);
    bool Evaluate(const Date& d, const string& e)const override;
private:
     const Comparison comp;
     const Date date;

};

class EventComparisonNode:public Node{
public:
    EventComparisonNode (Comparison& c, const string& e);
    bool Evaluate(const Date& d, const string& e)const override;
private:
    const Comparison comp;
    const string event;
};

class LogicalOperationNode:public Node{
public:
    LogicalOperationNode (LogicalOperation new_op, shared_ptr<Node> new_left, shared_ptr<Node> new_right);
    bool Evaluate(const Date& d, const string& e)const override;
private:
    shared_ptr<Node> left, right;
    LogicalOperation op;
};

class EmptyNode:public Node{
public:
    bool Evaluate(const Date& d, const string& e)const override;
};
#endif // NODE_H_INCLUDED
