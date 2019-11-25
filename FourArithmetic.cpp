#include<iostream>
#include"Stack.h"
#include<cstring>
#define max 256
using namespace std;

char op[7] = {'+','-','*','/','(',')','#'}; //定义运算符数组

char priority[7][7]={
    {'>','>','<','<','<','>','>'},    //用来进行比较运算符优先级的矩阵
    {'>','>','<','<','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'<','<','<','<','<','=','$'},
    {'>','>','>','>','$','>','>'},
    {'<','<','<','<','<','$','='}    
};
/*
获取运算符函数
如果是运算符，返回对应序号
若为数字，返回-1
其余返回-2
*/
int GetOp(char x){
    int i;
    if(x>='0'&&x<='9')
    return -1;
    else
    {
        for(i=0; i<7; i++){
            if (x==op[i])
            {
                return i;
                break;
            }
        }
    }
    if(i == 7)
    return -2;
    
}

/*比较运算符优先级函数
输入两个运算符对应的序号，根据查表得到优先级
若‘$’ 表示 数组最后一位 返回‘\0’
*/
char compare(int m, int n){
    char P = priority[m][n];
    if(P == '$'){
        return '\0';
    }
    else
    {
        return P;
    }
}

/*
运算函数
根据op 得序号得具体运算，进行运算
*/
int Execute(int a, int op, int b){
    int result;
    switch (op)
    {
    case 0:
        result = a+b;
        break;
    case 1:
        result = a-b;
        break;
    case 2:
        result = a*b;
        break;
    case 3:
        result = a/b;
        break;
    }
    return result;
}

//检查表达式是否正确
int Deduction(char s[], int len){
    if(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/')
    return 1;
    if(s[len-1]=='+'||s[len-1]=='-'||s[len-1]=='*'||s[len-1]=='/')
    return 1;
    for(int i =0; i<len-1;i++){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            if(s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='*'||s[i+1]=='/')
            return 1;
        }
        else if(s[i]=='('){
            if(s[i+1]==')')
            return 1;
        }
        else if(s[i]==')'){
            if(s[i+1]=='(')
            return 1;
        }       
    }
    int left=0;
    int right =0;
    for(int i = len-1; i>=0; i--){
        if(s[i]==')')
        right++;
        else if(s[i]=='(')
        left++;
    }
    if(left!=right){
        return 1;
    }
    //检查括号是否匹配，用栈来匹配
    Stack<char> a(100);
    a.Push('#');
    int i =0;
    while(i<len){  //碰到左括号 入栈
        if(s[i]=='('){
            a.Push(s[i]);
            i++;
        }
        else if(s[i]==')'&&a.GetTop()>0){ //碰到右括号并栈不空，则出栈
            a.Pop();
            i++;
        }
        else if(s[i]==')'&&a.GetTop()==0) //碰到右括号并栈空，则返回1
            return 1;
        else 
            i++;
    }
    if(a.GetTop()!=0)
        return 1;

    return 0;
}

int main()
{
	int result;
	char str[1024];
	while(gets(str)) //循环输入
	{
		int cst,len = strlen(str);
		cst = Deduction(str,len); //检查表达式是否正确
		if(cst == 1)
		{
			cout << "error" << endl;
			continue;
		} 
		Stack<int> Num(100),Opr(100); //定义 运算符栈 和 操作数栈
	    Opr.Push(6); //先在运算符栈中压入#符号
	    int temp = 0;
	    char *ch = str;
	    for(int i=0;i<=len;i++)
	    {
			if(*ch == '\0')                            //到达表达式末尾，将最后一位变为# 
			{
				*ch = '#';
			}
			if( GetOp(*ch) == -1)                //字符串中的当前元素为一个数字
	    	{
	    		while(GetOp(*ch) == -1)           
	        	{
	    		   temp = temp*10 + *ch-'0';
	    		   ch++;
			    }
			    Num.Push(temp);                        //将得到的数字压入操作数栈 
			    temp = 0;                              //将临时值再次置0 
			}
			else if(GetOp(*ch) != -2)
			{
				char flag = compare(Opr.GetTop(), GetOp(*ch) );  //比较运算符的优先级 
				if(flag == '>')
				{
					while( (compare( Opr.GetTop(), GetOp(*ch) )) == '>')
				    {
					    int m,n;
					    n = Num.GetTop();                               
					    Num.Pop();
					    m = Num.GetTop();
					    Num.Pop();
					    if(n == 0 && Opr.GetTop() == 3)
					    {
					    	cst = 1;
					    	break;
						}
					    int res; 
					    res = Execute(m,Opr.GetTop(),n);                //执行运算得到结果 
					    Opr.Pop();
					    Num.Push(res);
				    }
				    if((compare( Opr.GetTop(), GetOp(*ch) )) == '=')
				    {
				    	Opr.Pop();
				    	ch++;
					}
					else if((compare( Opr.GetTop(), GetOp(*ch) )) == '<')
					{
						Opr.Push(GetOp(*ch)); 
				        ch++;
					}
				    
				}
				else if(flag == '<')
				{

				Opr.Push(GetOp(*ch));               //栈内的运算符优先级低 
				  ch++;	
				}
				else if(flag == '=')
				{
					Opr.Pop();
					ch++;
				}
			}
			else 
			ch++;
		}
		if(cst == 1)
		{
			cout << "error" << endl;
			continue;
		}
		result = Num.GetTop();
		cout << result << endl; 

	}
	return 0;
}