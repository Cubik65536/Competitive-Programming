#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string books;
    cin >> books;

    int l_count = count(books.begin(), books.end(), 'L');
    int m_count = count(books.begin(), books.end(), 'M');

    int l_not_in_place = 0;
    for (int i = 0; i < l_count; i++) {
        if (books[i] != 'L') l_not_in_place++;
    }

    int m_not_in_place = 0;
    for (int i = l_count; i < l_count + m_count; i++) {
        if (books[i] != 'M') m_not_in_place++;
    }

    int m_in_l = 0;
    for (int i = 0; i < l_count; i++) {
        if (books[i] == 'M') m_in_l++;
    }

    int l_in_m = 0;
    for (int i = l_count; i < l_count + m_count; i++) {
        if (books[i] == 'L') l_in_m++;
    }

    cout << l_not_in_place + m_not_in_place - min(m_in_l, l_in_m) << endl;
    
    return 0;
}
