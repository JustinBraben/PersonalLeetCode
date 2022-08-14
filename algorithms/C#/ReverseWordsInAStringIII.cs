public class Solution {
    public string ReverseWords(string s) {
        String[] w = s.Split(' ');
        StringBuilder ans = new StringBuilder("");
        
        for(int i = 0; i < w.Length; i++){
            w[i] = Reverse(w[i]);
        }
        
        for(int i = 0; i < w.Length; i++){
            if (i == w.Length -1){
                ans.Append(w[i]);
            } else {
                ans.Append(w[i]).Append(" ");
            }
        }
        return ans.ToString();
    }
    
    public String Reverse(String s){
        char[] charArray = s.ToCharArray();
        Array.Reverse( charArray );
        return new string( charArray );
    }
}