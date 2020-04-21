using namespace std;
#include <iostream>

class Node{
public :
    int data;
    Node *next;
    Node(int _data){
        data=_data;
        next=NULL;
    }
};

class LinkList{
public:
    Node *head;
    LinkList(){
        head=NULL;
    }
    void insert(Node *node,int index){
        if(index<0){
            return;
        }
        if(head==NULL){
            head=node;
            head->next=NULL;
            return;
        }
        if(index==0){
            node->next=head;
            head=node;
            return;
        }
        Node *current_node=head;
        int count=0;
        while(current_node->next!=NULL&&count<index-1){
            count++;
            current_node=current_node->next;
        }
        if(count==index-1){
            node->next=current_node->next;
            current_node->next=node;
            return;
        }
        return;
    }

    void delete_node(int index) {
        if (head == NULL) {
            return;
        }
        Node *current_node = head;
        int count = 0;
        if (index == 0) {
            head = head->next;
            delete current_node;
            return;
        }
        while (current_node->next != NULL && count < index -1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1 && current_node->next != NULL) {
            Node *delete_node = current_node->next;
            current_node->next = delete_node->next;
            delete delete_node;
        }
    }

    int search(int index){
        if(index<0){
            return -1;
        }
        Node *current_node=head;
        int count=0;
        while(current_node->next!=NULL&&count<index){
            current_node=current_node->next;
            count++;
        }
        if(count==index&&current_node!=NULL){
            return current_node->data;
        }
        return -2;
    }

    void show(){
        Node *current_node=head;
        while(current_node!=NULL){
            //cout<<current_node->data<<" ";
            current_node=current_node->next;
        }
        cout<<endl;
    }

    int getLenth(){
        int len=0;
        Node *current_node=head;
        while(current_node!=NULL){
            len++;
            current_node=current_node->next;
        }
        return len;
    }

};

int main(){
    int N,M;
    cin>>N>>M;
    LinkList *linklist=new LinkList();
    //int *key=new int[M];
    for(int i=1;i<=N;i++){
        Node *node=new Node(i);
        linklist->insert(node,i-1);
    }
    //linklist->show();
    for(int j=0;j<M;j++){
        int i;
        cin>>i;
        linklist->delete_node(i-1);
        //linklist->show();
    }
    int count=N-M;
    cout<<linklist->search((count+1)/2-1)<<endl;
    return 0;
}
