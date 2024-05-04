/*class Solution {
public:
    string removeOccurrences(string s, string part) {
      int i=0;
        int n=s.size();
        int n1=part.size();
        while(i<n){
         if(s.substr(i,n1)==part){
         s.erase(i,n1);
            n=n-n1;
         }
            else{
            i++;
            }
        }
        return s;
    }
};
*/
class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t found = s.find(part);
        while (found != string::npos) {
            s.erase(found, part.size());
            found = s.find(part);
        }
        return s;
    }
};
