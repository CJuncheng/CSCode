#include <vector>
#include <iostream>
#include <numeric>
#include <thread>
#include <future>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Order {
    int s;
    int t;
    int a;
};

bool compareOrder(const Order& o1, const Order& o2) {
    return o1.s < o2.s;
}

int maximizeEarnings(const std::vector<Order>& orders) {
    int n = orders.size();
    std::vector<int> dp(n, 0);
    dp[0] = orders[0].a;

    for (int i = 1; i < n; i++) {
        int maxEarnings = orders[i].a;

        for (int j = 0; j < i; j++) {
            if (orders[i].s >= (orders[j].s + orders[j].t)) {
                maxEarnings = std::max(maxEarnings, orders[i].a + dp[j]);
            }
        }

        dp[i] = std::max(maxEarnings, dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Order> orders(n);

    for (int i = 0; i < n; i++) {
        std::cin >> orders[i].s;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> orders[i].t;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> orders[i].a;
    }

    // 按照下单时刻进行排序
    std::sort(orders.begin(), orders.end(), compareOrder);

    int maxEarnings = maximizeEarnings(orders);
    std::cout << maxEarnings << std::endl;

    return 0;
}