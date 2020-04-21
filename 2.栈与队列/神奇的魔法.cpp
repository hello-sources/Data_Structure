#include<iostream>
#include<stack>
using namespace std;
int n;          //输入个数
int f[100];     //保存出队序列 
stack<int> stk;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>f[i];
    int B=1,A=1;   //出队序列指针
    bool flag=1;
    while(B<=n){
        if(f[B]==A){  //直接比较未入栈序列首部与当前序列首部 
            A++;
            B++;
        }
        else if(!stk.empty() && stk.top()==f[B]){       //比较栈顶和首部
            stk.pop();
            B++;
        } 
        else if(A<=n){                            //若A还有剩余的元素 
            stk.push(A++);        
        }
        else{
            flag=0;break;
        } 
    } 
    if(flag) cout<<"yes";
    else     cout<<"no";
    return 0;
}
