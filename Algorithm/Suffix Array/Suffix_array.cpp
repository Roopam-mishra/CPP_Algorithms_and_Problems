
// Code By : Nikhil  Chopra
struct suffix{
    int index;
    int rank[2];
};

string s;  // We will be building suffix array on this string

bool cmp(struct suffix &a,struct suffix &b){
    if(a.rank[0] == b.rank[0]) return a.rank[1] < b.rank[1];
    return a.rank[0] < b.rank[0];
}

vector<int> buildsuffixarr(){
    int n = s.size();
    n++;  // By incrementing this last char will work as null char 
    struct suffix suffixarr[n];
    for(int i=0;i<n;i++){
        suffixarr[i].index = i;
        suffixarr[i].rank[0] = s[i] - 'a';
        if(i<n-1) suffixarr[i].rank[1] = s[i+1] - 'a';
        else suffixarr[i].rank[1] = -1;
    }
    sort( suffixarr , suffixarr+n , cmp);
    int ind[n];
    for (int k = 4; k < 2*n; k *= 2) { 
        int rank = 0; 
        int prev_rank = suffixarr[0].rank[0]; 
        suffixarr[0].rank[0] = rank; 
        ind[suffixarr[0].index] = 0; 
        for (int i = 1; i < n; i++) { 
            if (suffixarr[i].rank[0] == prev_rank and suffixarr[i].rank[1] == suffixarr[i-1].rank[1]){ 
                prev_rank = suffixarr[i].rank[0]; 
                suffixarr[i].rank[0] = rank; 
            } 
            else{ 
                prev_rank = suffixarr[i].rank[0]; 
                suffixarr[i].rank[0] = ++rank; 
            } 
            ind[suffixarr[i].index] = i; 
        } 
        for (int i = 0; i < n; i++) { 
            int nextindex = suffixarr[i].index + k/2; 
            suffixarr[i].rank[1] = (nextindex < n)? suffixarr[ind[nextindex]].rank[0]: -1; 
        } 
        sort(suffixarr, suffixarr+n, cmp); 
    }  
    vector<int> suffixArr(n); 
    for (int i = 0; i < n; i++) suffixArr[i] = suffixarr[i].index;
    return  suffixArr; 
}
