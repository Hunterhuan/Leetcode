// 没想到需要什么地方用stack的
class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        int cnt = 0;
        m_prices.push_back(price);
        m_record.push_back(1);

        for(int i = m_prices.size()-1; i >= 0; )
        {
            if(m_prices[i] > price) break;
            cnt += m_record[i];
            i -= m_record[i];
        }

        m_record.back() = cnt;
        return cnt;
    }

private:
    vector<int> m_record; // 记录上一天的 span
    vector<int> m_prices; // 记录每天的价格
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */






// 妙，想通了。其实就是stack
class StockSpanner {
public:
    StockSpanner() {

    }

    stack<pair<int, int>> s;
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top().first <= price) {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */