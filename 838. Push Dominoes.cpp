// 这个是自己操作的
class Solution {
public:
    string pushDominoes(string dominoes) {
    char last[1] = "";
    int n = dominoes.size();
    string res = "";
    for (int i = 0, j = 0; j < n; j++) {
        if (dominoes[j] == '.') continue;
        if (dominoes[j] == 'L') {
            if (last[0] == 'R') {               
                res += string((j - i) / 2 , 'R') + string((j - i) % 2 , '.') + string((j - i) / 2 , 'L')+'L';
            }
            else {
                res += string((j - i + 1),'L');
            }
            last[0] = 'L';
        }
        else if (dominoes[j] == 'R') {
            if (last[0] == 'R') {
                                res += string((j - i + 1),'R');             
            }
            else {
                res += string((j - i),'.') + 'R';
            }
            last[0] = 'R';
        }
        i = j + 1;
    }
    if (last[0] == 'R') {
        res += string((n - res.size()),'R');
    }
    else {
        res += string((n - res.size()),'.');
    }
    return res;     
    }
};


// 这个是模拟行为，比较费时。每次都需要遍历一遍
class Solution {
public:
    string pushDominoes(string dominoes) {
        // 多米诺骨牌推倒，好有趣的样子
        if (dominoes.length() <= 1) {
            return dominoes;
        }
        bool is_end = false;
        int len = dominoes.length();
        string old_str = dominoes;
        string new_str = dominoes;
        while (!is_end) {
            is_end = true;
            if (old_str[0] == '.') {
                new_str[0] = (old_str[1] == 'L' ? 'L' : '.');
            }
            for (int i = 1; i < len - 1; ++i) {
                if (old_str[i] == '.') {
                    if (old_str[i - 1] != 'R' || old_str[i + 1] != 'L') {
                        if (old_str[i - 1] == 'R') {
                            new_str[i] = 'R';
                            is_end = false;
                        }
                        else if (old_str[i + 1] == 'L') {
                            new_str[i] = 'L';
                            is_end = false;
                        }
                    }

                }
            }
            if (old_str[len - 1] == '.') {
                new_str[len - 1] = (old_str[len - 2] == 'R' ? 'R' : new_str[len - 1]);
            }
            old_str = new_str;
        }
        return old_str;// old_str和new_str时一样的
    }
};