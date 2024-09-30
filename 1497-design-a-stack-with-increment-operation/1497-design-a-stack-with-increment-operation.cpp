class CustomStack {
public:
int front;
int rear;
vector<int>stack;
int initial=0; //initial element
int k;
    CustomStack(int maxSize) {
        stack=vector<int>(maxSize);
        front=0;
        rear=-1;
        k=maxSize;
    }
    
    void push(int x) {
        if(initial<k){
            rear++;
            initial++;
        stack[rear]=x;
        }
    }
    
    int pop() {
        if(initial==0){
            return -1;
        }
        int ans=stack[rear];
        rear--;
        initial--;
        return ans;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,initial);i++){
            stack[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */