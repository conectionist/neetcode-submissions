class MedianFinder {
private:
    priority_queue<int> lowerHalf;
    priority_queue<int, vector<int>, greater<int>> upperHalf;

public:
    MedianFinder() {
        
    }

    void moveFromLowerToUpper()
    {
        upperHalf.push(lowerHalf.top());
        lowerHalf.pop();
    }

    void moveFromUpperToLower()
    {
        lowerHalf.push(upperHalf.top());
        upperHalf.pop();
    }
    
    void addNum(int num) {
        lowerHalf.push(num);
        moveFromLowerToUpper();

        if(lowerHalf.size() < upperHalf.size())
            moveFromUpperToLower();
    }
    
    double findMedian() {
        if(lowerHalf.size() > upperHalf.size())
            return lowerHalf.top();

        return (lowerHalf.top() + upperHalf.top())/2.0;
    }
};
