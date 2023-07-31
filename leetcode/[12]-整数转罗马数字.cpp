string intToRoman(int num) {
    map<int,string> temp;
    temp[1] = "I";
    temp[4] = "IV";
    temp[5] = "V";
    temp[9] = "IX";
    temp[10] = "X";
    temp[40] = "XL";
    temp[50] = "L";
    temp[90] = "XC";
    temp[100] = "C";
    temp[400] = "CD";
    temp[500] = "D";
    temp[900] = "CM";
    temp[1000] = "M";
    int nums[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    int ind = 12;
    string res= "";
    while(num != 0){
        if(num >= nums[ind]){
            num -= nums[ind];
            res += temp[nums[ind]];
        }else{
            ind--;
        }
    }
    return res;
}