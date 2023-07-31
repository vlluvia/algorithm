int romanToInt(string s) {
    map<char, int> temp;
    temp['I'] = 1;
    temp['V'] = 5;
    temp['X'] = 10;
    temp['L'] = 50;
    temp['C'] = 100;
    temp['D'] = 500;
    temp['M'] = 1000;
    int sum = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'I' && i+1<s.size() && s[i+1] =='V'){
            sum += 4;i++;
        }else if(s[i] == 'I' && i+1<s.size() && s[i+1] =='X'){
            sum += 9; i++;
        }else if(s[i] == 'X' && i+1<s.size() && s[i+1] =='L'){
            sum += 40; i++;
        }else if(s[i] == 'X' && i+1<s.size() && s[i+1] =='C'){
            sum += 90; i++;
        }else if(s[i] == 'C' && i+1<s.size() && s[i+1] =='D'){
            sum += 400; i++;
        }else if(s[i] == 'C' && i+1<s.size() && s[i+1] =='M'){
            sum += 900; i++;
        }else{
            sum += temp[s[i]];
        }
    }
    return sum;
}