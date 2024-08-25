class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
    
    void value(int &a, int &b, int c, int d) {
        int a_new = a * d + b * c;
        int b_new = b * d;
        int gcds = gcd(abs(a_new), b_new);  // Use abs() to handle negative values correctly
        a = a_new / gcds;
        b = b_new / gcds;
    }
    
    string fractionAddition(string expression) {
        int n = expression.size();
        vector<int> num_store;
        
        int i = 0;
        while (i < n) {
            int sign = 1;
            if (expression[i] == '-') {
                sign = -1;
                i++;
            } else if (expression[i] == '+') {
                i++;
            }
            
            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num_store.push_back(sign * num);
            
            i++; // skip the '/' character
            
            num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num_store.push_back(num);
        }
        
        int a = num_store[0]; // numerator of the first fraction
        int b = num_store[1]; // denominator of the first fraction
        
        for (int i = 2; i < num_store.size(); i += 2) {
            int c = num_store[i];
            int d = num_store[i + 1];
            value(a, b, c, d);
        }
        
        return to_string(a) + "/" + to_string(b);
    }
};
