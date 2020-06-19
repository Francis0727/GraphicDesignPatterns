#include <iostream>
#include <map>
#include <stack>

using namespace std;

// 对于a + b - c + d这类的字符串，其每一个字符都是一个Expression对象。
// 注: 对于运算符，实例中不会做特殊的处理
class Expression {
public:
    virtual int interpreter(map<char, int> var)=0;
    virtual ~Expression(){}
};

// 变量表达式
// 功能: 获取字符对应的数值
class VarExpression: public Expression {
private:
    char key;
public:
    VarExpression(const char& key){
        this->key = key;
    }
    
    int interpreter(map<char, int> var) override {
        return var[key];
    }
};

// 符号表达式
// 功能: 存放运算符两侧的字符。例如a + b，则会保存a和b
class SymbolExpression : public Expression {
    // 运算符左右两个参数
protected:
    Expression* left;
    Expression* right;
public:
    SymbolExpression( Expression* left,  Expression* right):
        left(left),right(right){
        
    }
};

// 符号表达式进行加法运算
class AddExpression : public SymbolExpression {  
public:
    AddExpression(Expression* left, Expression* right):
        SymbolExpression(left,right){
        
    }
    int interpreter(map<char, int> var) override {
        return left->interpreter(var) + right->interpreter(var);
    }
};

// 符号表达式减法运算
class SubExpression : public SymbolExpression {
public:
    SubExpression(Expression* left, Expression* right):
        SymbolExpression(left,right){
        
    }

    int interpreter(map<char, int> var) override {
        return left->interpreter(var) - right->interpreter(var);
    }
};



Expression*  analyse(string expStr) {
    stack<Expression*> expStack;
    Expression* left = nullptr;
    Expression* right = nullptr;
	// 若检测到当前字符为为操作运算符，则操作符后的字符必为操作数。
	// 因此,将左侧操作数从stack中弹出，然后使用左右操作数构建一个操作表达式
    for(int i=0; i<expStr.size(); i++){
        switch(expStr[i]){
            case '+':
                // 加法运算
                left = expStack.top();
                right = new VarExpression(expStr[++i]);
                expStack.push(new AddExpression(left, right));
                break;
            case '-':
                // 减法运算
                left = expStack.top();
                right = new VarExpression(expStr[++i]);
                expStack.push(new SubExpression(left, right));
                break;
            default:
                // 变量表达式
                expStack.push(new VarExpression(expStr[i]));
        }
    }
   
    Expression* expression = expStack.top();
    return expression;
}

void release(Expression* expression){
    //释放表达式树的节点内存...
}

int main(int argc, const char * argv[]) {
    // expStr为需解析的字符串，并为字符串中的字符设定初值
    string expStr = "a+b-c+d-e";
    map<char, int> var;
    var.insert(make_pair('a',5));
    var.insert(make_pair('b',2));
    var.insert(make_pair('c',1));
    var.insert(make_pair('d',6));
    var.insert(make_pair('e',10));

    // 对字字符串解析(解析AddExpression和SubExpression对象，存储在stack中)
    Expression* expression= analyse(expStr);
    // 计算表达的值(注: 会递归调用interpreter函数)
    int result=expression->interpreter(var);
    
    std::cout << result << std::endl;
    release(expression);
    
    return 0;
}
