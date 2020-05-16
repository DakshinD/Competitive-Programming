struct segmentTree{
    int originalValues[100001];
    int segSum[100001]; //this array will be our segtree when calculating range sum queries
    int segMin[100001]; //this array will be our segtree when calculating range minimum queries
    int lazy[100001]; //this array stores values for our lazy propagation updates

    void createSegTree(int currentNode, int left, int right){
        lazy[currentNode] = 0;
        if(left == right){
            segSum[currentNode] = segMin[currentNode] = originalValues[currentNode];
            return;
        }

        int mid = (left + right)/2;
        createSegTree(2*currentNode+1, left, mid); //this goes down the left path
        createSegTree(2*currentNode+2, mid + 1, right); //this goes down our right path

        segSum[currentNode] = segSum[2*currentNode+1]+segSum[2*currentNode+2];
        segMin[currentNode] = min(segMin[2*currentNode+1], segMin[2*currentNode+2]);
    }

    void lazyUpdate(int currentNode, int left, int right){

        if(lazy[currentNode] > 0){
            segSum[currentNode] += (right - left + 1) * lazy[currentNode];
            segMin[currentNode] += lazy[currentNode];

            if(left != right){ //if we aren't updating a single node but rather a range
                lazy[2*currentNode+1] += lazy[currentNode];
                lazy[2*currentNode+2] += lazy[currentNode];
            }

            lazy[currentNode] = 0; //we rest this node's delta since we have already transferred the update down the subtree
        }
    }

    void update(int rangeLeft, int rangeRight, int value, int node, int left, int right){
        if(right < left){
            return;
        }
        lazyUpdate(node, left, right); //make sure we update the segTree before changing values
        if(rangeRight < left || rangeLeft > right){
            return;
        }
        if(rangeLeft <= left && right <= rangeRight){ //if the range we are looking for is contained totally inside, just update
            lazy[node] += value;
            lazyUpdate(node, left, right);
            return;
        }

        int mid = (left + right)/2;
        update(rangeLeft, rangeRight, value, 2*node+1, left, mid);
        update(rangeLeft, rangeRight, value, 2*node+2, mid+1, right);

        segSum[node] = segSum[2*node+1] + segSum[2*node+2];
        segMin[node] = min(segMin[2*node+1], segMin[2*node+2]);
    }

    int sumQuery(int rangeLeft, int rangeRight, int node, int left, int right){
        if(right < left){
            return 0;
        }

        if(rangeRight < left && rangeLeft > right){ // 2 cases where our range is out of bounds of this node
            return 0;
        }

        if(rangeLeft <= left && right <= rangeRight){ // if our range totally overlaps with this node's range
            return segSum[node];
        }

        int mid = (left + right)/2;
        int sum = 0;
        sum += sumQuery(rangeLeft, rangeRight, 2*node+1, left, mid);
        sum += sumQuery(rangeLeft, rangeRight, 2*node+2, mid+1, right);
        return sum;
    }

    int minQuery(int rangeLeft, int rangeRight, int node, int left, int right){
        if(right < left){
            return INT_MAX;
        }

        if(rangeRight < left && rangeLeft > right){ // 2 cases where the given range is outside and not overlapping
            return INT_MAX;
        }

        if(rangeLeft <= left && right <= rangeRight){ // if our range totally overlaps with this node's range
            return segMin[node];
        }

        int mid = (left + right)/2;
        int maxVal = INT_MAX;
        maxVal = min(maxVal, minQuery(rangeLeft, rangeRight, 2*node+1, left, mid));
        maxVal = min(maxVal, minQuery(rangeLeft, rangeRight, 2*node+2, mid+1, right));
        return maxVal;
    }

    
};
