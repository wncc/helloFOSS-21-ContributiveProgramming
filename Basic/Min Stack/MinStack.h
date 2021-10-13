#define MAXSIZE 1000
class MinStack{
    private:
        int* arr;
        int size;
        int min_elem;
    public:
        MinStack();
        void push(int val);
        int pop(); 
        int top();
        int getMin();
}
