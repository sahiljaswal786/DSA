#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data ;
    node* next;

    public:
    node (int data1 , node* next1){
        data = data1;
        next = next1;
    }

    public:
    node (int data1 ){
        data = data1;
        next = nullptr;
    }

};

node* convertToLL(vector<int>& arr){
    node* head = new node (arr[0]);
    node* mover = head;
    for (int i = 1 ; i < arr.size() ; i++){
        node* temp = new node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(node * head){
    node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void print(node* head){
    node* temp = head;
    while (temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}


node* sortLL(node* head){
    if(head == NULL || head->next ==NULL) return NULL;

    node* zerohead = new node(-1);
    node* onehead = new node(-1);
    node* twohead = new node(-1);

    node* zero = zerohead;
    node* one = onehead;
    node* two = twohead;

    node* temp = head;

    while(temp ){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        } else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }else {
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    zero->next = (onehead->next) ? (onehead->next) : (twohead->next);
    one->next = twohead->next;
    two=nullptr;

    node* newHead = zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;

    return newHead;

} 



int main(){
    vector<int> arr = {1, 1, 0, 2, 0, 1, 2, 0, 2};
    node* head = convertToLL(arr);
    print(sortLL(head));
}