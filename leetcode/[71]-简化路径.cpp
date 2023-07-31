class Solution {
public String simplifyPath(String path) {
        Stack<String> res = new Stack<String>();
        String[] data = path.split("/");

        for(String s: data){
            if(s.equals("..")){
                if (!res.isEmpty() ) {
                    res.pop();
                }
            }else if(!s.equals("") && !s.equals(".")){
                res.push(s);
            }
        }

        if ( res.isEmpty() ) {
            return "/";
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < res.size(); i++) {
            ans.append( "/" + res.get(i) );
        }
        return ans.toString();
    }
}