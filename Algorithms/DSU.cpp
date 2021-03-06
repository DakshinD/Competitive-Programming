struct DSU {
    int dsu[100001];
    int sizes[100001];

    void make_set(int n) {
        for (int i = 0; i < n; i++) {
            dsu[i] = i;
            sizes[i] = 1;
        }
    }

    int find(int a) {
        if (dsu[a] == a) return a;
        return (dsu[a] = find(dsu[a]));
    }

//weighted union function
    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sizes[a] < sizes[b])
                swap(a, b);
            dsu[b] = a;
            sizes[a] += sizes[b];
        }
    }


    bool isSameSet(int a, int b){
        int x = find(a);
        int y = find(b);
        return x == y;
    }

};
