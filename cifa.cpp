//
// Created by oruret on 2018/4/9.
//
/*
 * 类别      词法记号         含义
 * 特殊      err              错误记号
 *           end             文件结束
 * 标识符    id               标识符
 * 常量      num              数字
 *           ch               字符
 *           str              字符串
 * 关键字    kw_int            int
 *           kw_char            char
 *           kw_void            void
 *           kw_extern          extern
 *           kw_if              if
 *           kw_else            else
 *           kw_switch          switch
 *           kw_case            case
 *           kw_default         default
 * 界符      kw_while            while
 *           kw_for             for
 *           kw_do              do
 *           kw_break           break
 *           kw_continue        continue
 *           kw_return          return
 *           add                +
 *           sub                -
 *           mul                *
 *           div                /
 *           mod                %
 *           inc                ++
 *           dec                --
 *           not                !
 *           lea                &
 *           and                &&
 *           or                 ||
 *           assign             =
 *           gt                 >
 *           ge                 >=
 *           lt                 <
 *           le                 <=
 *           equ                ==
 *           nequ               !=
 *           comma              ,
 *           colon              :
 *           semicon            ;
 *           lparen             (
 *           rparen             )
 *           lbrack             [
 *           rbrack             ]
 *           lbrac              {
 *           rbrac              }
 */
#include <stdio.h>
#include <string.h>

#define BUFLEN 80
int lineLen = 0;
int readPos = -1;
char line[BUFLEN];
int lineNum = -1;
int colNum = 0;
char ch = -1;
char lastch = -1;
char scan(FILE * file){
    if(!file){
        return -1;
    }
    if(readPos == lineLen - 1){
        lineLen = fread(line,1,BUFLEN,file);
        if(lineLen == 0){
            lineLen = 1;
            line[0] = -1;
        }
        readPos = -1;
    }
    readPos ++;
    ch = line[readPos];

    if(lastch == '\n'){
        lineNum ++;
        colNum = 0;
    }

    if(ch == -1) {
        fclose(file);
        file = NULL;
    }else if(ch != '\n'){
        colNum ++;
    }

    lastch = ch;
    return ch;
}

/*
 * 词法记号标签
 */

enum Tag{
    ERR,
    END,
    ID,
    KW_INT,KW_CHAR,KW_VOID,
    KW_EXTERN,
    NUM,CH,STR,
    NOT,LEA,
    ADD,SUB,MUL,DIV,MOD,
    INC,DEC,
    GT,GE,LT,LE,EQU,NEQU,
    AND,OR,
    LPAREN,RPAREN,
    LBRACK,RBRACK,
    LBRACE,RBRACE,
    COMMA,COLON,SEMICON,
    ASSIGN,
    KW_IF,KW_ELSE,
    KW_SWITCH,KW_CASE,KW_DEAFULT,
    KW_WHILE,KW_DO,KW_FOR,
    KW_BREAK,KW_CONTINUE,KW_RETURN
};
