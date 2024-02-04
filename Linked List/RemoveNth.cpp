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

node* remove(node* head , int k){
    node* fast = head;    
    node* slow = head;    


    for( int i=0; i < k; i++){
        fast = fast->next;
    }

    if(fast == NULL){
        node* delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }

    while(fast->next!= NULL){
        fast = fast->next;
        slow = slow->next;
    }

    node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;

}



int main(){
    vector<int> arr = {12, 23 , 24, 25 ,26 , 34 , 38, 46};
    node* head = convertToLL(arr);
    print(remove(head,3));
}