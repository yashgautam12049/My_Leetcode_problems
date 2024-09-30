class MyCircularDeque {
public:
int K;
int front;
int rear;
int current_count;
vector<int>deq;
    MyCircularDeque(int k) {
        K=k;
        deq=vector<int>(K,0);
        front=0;
        rear=K-1;
        current_count=0;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return 0;
        }
        front=(front+K-1)%K;
        deq[front]=value;
        current_count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return 0;
        }
        rear=(rear+1)%K;
        deq[rear]=value;
        current_count++;
        return 1;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return 0;
        }
        front=(front+1)%K;
        current_count--;
        return 1;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return 0;
        }
        rear=(rear-1+K)%K;
        current_count--;
        return 1;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return deq[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return deq[rear];
    }
    
    bool isEmpty() {
        if(current_count==0){
            return 1;
        }
        return 0;
    }
    
    bool isFull() {
        if(current_count==K){
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */