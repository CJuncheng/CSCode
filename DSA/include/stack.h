/******************************************************************************************
 * Data Structures in C++
 * Juncheng Chen, j.c.chen.cn9@gmail.com
 * March 30, 2022
 ******************************************************************************************/
#pragma once

#include "vector.h"
#include <cmath>
#include <sstream>
using namespace std;
template <typename T>
class Stack : public Vector<T>
{ 
    public: //size(), empty()以及其他开放接口，均可直接沿用
        void push(T const &e) { Vector<T>::insert(Vector<T>::size(), e); } //入栈：等效于新元素作为向量的末元素插入
        T pop(void) { return Vector<T>::remove(Vector<T>::size() - 1); }    //出栈：等效于删除向量末元素
        T &top(void) { return (*this)[Vector<T>::size() - 1]; }              //取顶：直接返回向量末元素
};

// ====================== 4.3 栈的应用 ======================
// 4.3.1 逆序输出 -> 进制转换
// 递归实现
void convert(Stack<char> &S, int64_t n, int32_t base) //十进制正整数n到base进制的转换（递归版）, 1 < base <= 16
{
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    if (0 < n) //在尚有余数之前，反复地
    {
        S.push(digit[n % base]); //逆向记录当前最低位，再
        convert (S, n / base, base); // 通过递归得到所有更高位
    }
} //新进制下由高到低的各数位，自顶而下保存于栈中
// 迭代实现
void convert_(Stack<char> &S, int64_t n, int32_t base) //十进制正整数n到base进制的转换（迭代版）
{
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0) 
    {
        int32_t remainder = (int)(n % base);
        S.push(digit[remainder]);
        n /= base;
    }
} //新进制下由高到低的各数位，自顶而下保存于栈中
// 4.3.2 递归嵌套 -> 括号匹配
// 迭代实现
bool paren (const char exp[], size_t lo, size_t hi)
{
    Stack<char> S;
    for (size_t i = lo; i <= hi; ++i)
    {
        switch (exp[i])
        {
            case '(': case '[': case '{': S.push (exp[i]); break;
            case ')': if ( (S.empty() )||('(' != S.pop() ) ) return false; break;
            case ']': if ( (S.empty() )||('[' != S.pop() ) ) return false; break;
            case '}': if ( (S.empty() )||('{' != S.pop() ) ) return false; break;
            default: break;
        }
    }
    return S.empty();
}
// 4.3.3 延迟缓冲 -> 中缀表达式 4.3.4 逆波兰表达式
//习题 4-6
// 输出一个浮点数并压入栈中
float readNumber(char *&S, Stack<float> &opnd)
{
    opnd.push(0); //初始化为 0
    char c = *S;
    bool is_decimal = false; //是否处理的是小数部分
    float decimal_base = 0.1;
    while (*S)
    {
        if (isdigit(*S))
        {
            float val = opnd.pop();
            int digit = int(*S) - 0x30;

            if (!is_decimal) //处理非小数部分， x = x*10 + y
                opnd.push(val * 10 + digit);
            else
            { //处理小数部分，x=x+y*decimal_base
                opnd.push(val + digit * decimal_base);
                decimal_base *= 0.1; // 当有小数时，计算下一个数位的基数
            }
            S++;
        }
        else if (*S == '.')
        {
            is_decimal = true;
            decimal_base = 0.1;
            S++;
        }
        else
            break;
    }
    return opnd.top();
}

float calcu(char op, float opnd)
{ //实施一元计算
    if (op == '!')
    {
        float ret = 1;
        for (int i = (int)opnd; i > 1; i--)
            ret *= i;
        return ret;
    }
    return -1;
}

float calcu(float pOpnd1, char op, float pOpnd2)
{ //实施二元计算，结果入栈
    switch (op)
    {
    case '+':
        return pOpnd1 + pOpnd2;
        break;
    case '-':
        return pOpnd1 - pOpnd2;
        break;
    case '*':
        return pOpnd1 * pOpnd2;
        break;
    case '/':
        return pOpnd1 / pOpnd2;
        break;
    case '^':
        return pow(pOpnd1, pOpnd2);
        break;
    }
    return -1;
}

void append(string &RPN, char op)
{ //读入操作数，并将其接至 PRN 末尾
    RPN = RPN + op;
}

void append(string &RPN, float opnd)
{ //读入操作数，并将其接至 PRN 末尾
    std::ostringstream ss;
    ss << opnd;
    RPN = RPN + ss.str();
}

void append(string &RPN, double opnd)
{ //读入操作数，并将其接至 PRN 末尾
    std::ostringstream ss;
    ss << opnd;
    RPN = RPN + ss.str();
}
#define N_OPTR 9 //运算符总数
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator; //运算符集合
//加，减，乘，除，乘方，阶乘，左括号，右括号，起始符与终止符
const char pri[N_OPTR][N_OPTR] = { //运算符优先等级[栈顶][当前]
    /*          |------------当前运算符-----------| */
    /*          +     -     *     /     ^     !     (     )     \0 */
    /* -- + */ '>',  '>',  '<',  '<',  '<',  '<',  '<',  '>',  '>',    
    /* |  - */ '>',  '>',  '<',  '<',  '<',  '<',  '<',  '>',  '>',    
    /* 栈 * */ '>',  '>',  '>',  '>',  '<',  '<',  '<',  '>',  '>',    
    /* 顶 / */ '>',  '>',  '>',  '>',  '<',  '<',  '<',  '>',  '>',    
    /* 运 ^ */ '>',  '>',  '>',  '>',  '>',  '<',  '<',  '>',  '>',    
    /* 算 ! */ '>',  '>',  '>',  '>',  '>',  '>',  ' ',  '>',  '>',    
    /* 符 ( */ '<',  '<',  '<',  '<',  '<',  '<',  '<',  '=',  ' ',    
    /* |  ) */ ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',    
    /* --\0 */ '<',  '<',  '<',  '<',  '<',  '<',  '<',  ' ',  '='    
};
int op2index(char op) {
    switch(op){
        case '+': return 0; break;
        case '-': return 1; break;
        case '*': return 2; break;
        case '/': return 3; break;
        case '^': return 4; break;
        case '!': return 5; break;
        case '(': return 6; break;
        case ')': return 7; break;
        case '\0': return 8; break;
        default: return -1; break;
    }
}
char orderBetween(char op1, char op2)
{ //视其与栈顶运算符之间优先级高低分别处理
    int index1 = op2index(op1);
    int index2 = op2index(op2);
    return pri[index1][index2];
}
float evaluate(char *S, std::string &RPN)
{                      //对已剔除空白符的表达式求值，并转换为逆波兰式 RPN
    Stack<float> opnd; //运算数栈
    Stack<char> optr;  //运算符栈

    optr.push('\0'); //尾哨兵 '\0' 也作为头哨兵首先入栈

    while (!optr.empty())
    { //在运算符栈非空之前，逐个处理表达式中各字符
        if (isdigit(*S))
        { //若当前字符为操作数，则
            readNumber(S, opnd);
            append(RPN, opnd.top()); //读入操作数，并将其接至 PRN 末尾
        }
        else
        { //若当前字符为运算符
            switch (orderBetween(optr.top(), *S))
            {         //视其与栈顶运算符之间优先级高低分别处理
            case '<': //栈顶运算符低优先级时
                optr.push(*S);
                S++; //计算推迟，当前运算符进栈
                break;
            case '=': //优先级相等，（当前运算符为右括号或尾部哨兵\0)时
                optr.pop();
                S++; //脱括号并接收下一个字符
                break;
            case '>':
            { //栈顶运算符高优先级时，可实施相应的计算，并将结果重新入栈
                char op = optr.pop();
                append(RPN, op); //栈顶运算符出栈并续接至 RPN 末尾
                if ('!' == op)
                { //! 为一元操作符
                    float pOpnd = opnd.pop();
                    opnd.push(calcu(op, pOpnd)); //实施一元计算，结果入栈
                }
                else
                { //其它都为二元操作符
                    float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop();
                    opnd.push(calcu(pOpnd1, op, pOpnd2)); //实施二元计算，结果入栈
                }
                break;
            }
            default:
                exit(-1); //逢语法错误，不做处理直接退出
                break;
            } // switch
        }
    } // while
    return opnd.pop(); //弹出并返回最后的计算结果
}
