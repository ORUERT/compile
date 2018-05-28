//
// Created by oruret on 2018/4/9.
//

/*
 * 词法记号类
 */

#include "string.h"
#include "cifa.cpp"
using namespace std;

class Token{
public:
    Tag tag;
    Token (Tag t);
    virtual string toString();
    virtual ~Token();
};

/*
 * 标识符记号类
 */
class Id:public Token{
public:
    string name;
    Id (string n);
    virtual string toString();
};

