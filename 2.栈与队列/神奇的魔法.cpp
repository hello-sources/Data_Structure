#include<iostream>
#include<stack>
using namespace std;
int n;          //�������
int f[100];     //����������� 
stack<int> stk;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>f[i];
    int B=1,A=1;   //��������ָ��
    bool flag=1;
    while(B<=n){
        if(f[B]==A){  //ֱ�ӱȽ�δ��ջ�����ײ��뵱ǰ�����ײ� 
            A++;
            B++;
        }
        else if(!stk.empty() && stk.top()==f[B]){       //�Ƚ�ջ�����ײ�
            stk.pop();
            B++;
        } 
        else if(A<=n){                            //��A����ʣ���Ԫ�� 
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
