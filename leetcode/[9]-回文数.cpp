bool isPalindrome(int x) {
    string res = to_string(x);
    string temp = res;
    reverse(temp.begin(),temp.end());
    return res == temp;
}