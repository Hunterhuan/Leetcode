class Solution {
public:
    bool isNum(const char& c) {
        return (c >= '0' && c <= '9');
    }
    bool isX(const char& c) {
        return (c == 'x');
    }
    int solveEquation_helper_get_next_num(const string& equation, int& index) {
        bool negative = false;
        if (equation[index] == '-') {
            negative = true;
            index++;
            if (isX(equation[index])) {
                return -1;
            }
        }
        else if (equation[index] == '+') {
            index++;
            if (isX(equation[index])) {
                return 1;
            }
        }
        else if (!isNum(equation[index])) {
            return 1;
        }
        else if (equation[index] == 0) {
            return 0;
        }
        int result = 0;
        while (index < equation.size() && isNum(equation[index])) {
            result*=10;
            result+=equation[index]-'0';
            
            index++;
        }
        if (negative) result *= -1;
        return result;
    }
    void solveEquation_helper_fill_both_sides(int& num_x, int& RHS, const string& equation) {
        //input: twp integers all set to 0, pass-by-reference; equation containing the information
        //output: two integer parameters modified as: (num_x)*x = (RHS).
        int coefficient;
        int i;
        //working on LHS
        for (i = 0; i < equation.size(); i++) {
            if (equation[i] == '=') {
                break;
            }
            //i is updated inside the below function
            coefficient = solveEquation_helper_get_next_num(equation, i);   
            if (isX(equation[i])) {
                num_x += coefficient;
            }
            else {
                RHS -= coefficient;
                i--;
            }
        }
        i++;
        //working on RHS
        for (; i < equation.size(); i++) {
            //i is updated inside the below function
            coefficient = solveEquation_helper_get_next_num(equation, i);   
            if (isX(equation[i])) {
                num_x -= coefficient;
            }
            else {
                RHS += coefficient;
                i--;
            }
        }
    }
    string solveEquation(string equation) {
        int num_x = 0, RHS = 0;
        //filling the variables: (num_x)*x = (RHS).
        solveEquation_helper_fill_both_sides(num_x, RHS, equation);
        
        if (num_x == 0) {
            if (RHS == 0) {
                return "Infinite solutions";
            }
            else {
                return "No solution";
            }
        }
        string result = "x=";
        result += to_string(RHS/num_x);
        return result;
    }
};