class MedianFinder {
private:
    priority_queue<int> max_pq;
    priority_queue<int,vector<int>,greater<int>> min_pq;
    int n;
public:
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if(!n){
            max_pq.push(num);
        }
        else if(n & 1){
            if(num >= max_pq.top()){
                min_pq.push(num);
            }
            else{
                int max_last_top = max_pq.top();
                max_pq.pop();
                min_pq.push(max_last_top);
                max_pq.push(num);
            }
        }
        else{
            if(num > min_pq.top()){
                int min_last_top = min_pq.top();
                min_pq.pop();
                max_pq.push(min_last_top);
                min_pq.push(num);
            }
            else{
                max_pq.push(num);
            }
        }
        n++;
    }
    
    double findMedian() {
        double median;
        if(n & 1){
            median = max_pq.top();
        }
        else{
            median = double(max_pq.top() + min_pq.top()) / 2;
        }

        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */