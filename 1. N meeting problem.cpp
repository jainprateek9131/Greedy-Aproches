struct meeting {
    int start;
    int end;
    int pos; 
}; 
bool comparator(struct meeting m1, meeting m2) 
{ 
    if (m1.end < m2.end) return true; 
    else if(m1.end > m2.end) return false; 
    else if(m1.pos < m2.pos) return true; 
    return false; 
} 
void maxMeetings(int s[], int e[], int n) {
    struct meeting meet[n]; 
    for(int i = 0;i<n;i++) {
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i+1; 
    }
    
    sort(meet, meet+n, comparator); 
    
    vector<int> answer;
    
    int limit = meet[0].end; 
    answer.push_back(meet[0].pos); 
    
    for(int i = 1;i<n;i++) {
        if(meet[i].start > limit) {
            limit = meet[i].end; 
            answer.push_back(meet[i].pos); 
        }
    }
    for(int i = 0;i<answer.size();i++) {
        cout << answer[i] << " "; 
    }
    
}
// ANOTHER METHOD
static bool cmp(pair<int,int>m1, pair<int,int>m2){
       return(m1.second<m2.second);
   }
   int maxMeetings(int start[], int end[], int n)
   {
       // Your code here
       vector<pair<int, int>>meet;
       int i;
       for(i=0;i<n;i++){
           meet.push_back({start[i], end[i]});
       }
       sort(meet.begin(),meet.end(),cmp);
       pair<int,int>recent=meet[0];
       int count = 1;
       for(i=1;i<n;i++){
           if(meet[i].first>recent.second){
               count+=1;
               recent=meet[i];
           }
       }
       return count;
   }
