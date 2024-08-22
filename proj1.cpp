#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct User {
    int userID;
    int balance;
};
bool compare(const User& a, const User& b) {
    if (a.balance == b.balance)
        return a.userID < b.userID; 
    return a.balance < b.balance;
}

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> userMap; 

    vector<User> users(N);
    for (int i = 0; i < N; ++i) {
        int userID, balance;
        cin >> userID >> balance;
        userMap[userID] = balance; 
        users[i] = {userID, balance}; 
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int fromUserID, toUserID, amount;
        cin >> fromUserID >> toUserID >> amount;

        if (userMap[fromUserID] >= amount) {
            userMap[fromUserID] -= amount;
            userMap[toUserID] += amount;
            cout << "Success" << endl;
        } else {
            cout << "Failure" << endl;
        }
    }
    for (int i = 0; i < N; ++i) {
        users[i].balance = userMap[users[i].userID];
    }
    sort(users.begin(), users.end(), compare);
    cout << endl;
    for (const auto& user : users) {
        cout << user.userID << " " << user.balance << endl;
    }

    return 0;
}
