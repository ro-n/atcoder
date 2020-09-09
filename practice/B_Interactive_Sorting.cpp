#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)

#define NMAX 26

using namespace std;

typedef pair<int, int> pii;

int N, Q;
string balls;
vector<pii> relations; // (x < y)

void insertBall(int first, int last, char ball) {
    int mid = first + (last - first) / 2;
    printf("? %c %c\n", balls[mid], ball);
    fflush(stdout);
    string ans;
    cin >> ans;
    if (ans == ">") {
        if (last - first == 1) balls.insert(first, 1, ball);
        else insertBall(first, mid, ball);
    } else if (ans == "<") {
        if (last - first <= 2) {
            balls.insert(last, 1, ball);
        } else {
            insertBall(mid + 1, last, ball);
        }
    }
}

void n26() {
    balls = 'A';
    for (char ball = 'B'; ball <= 'Z'; ++ball) {
        insertBall(0, balls.size(), ball);
    }
    cout << "! " << balls << endl;
}

bool relational(int pae[]) {
    for (pii rel: relations) {
        if (pae[rel.first] >= pae[rel.second]) {
            return false;
        }
    }
    return true;
}

void n5() {
    while (true) {
        int query_i;
        int query_j;
        int d_min = INT_MAX;
        int q = 0;

        int p[NMAX][NMAX];
        REP(i, N) REP(j, N) p[i][j] = 0;
        int a[NMAX];
        REP(k, N) a[k] = k;

        do {
            if (relational(a)) {
                ++q;
                REP(i, N) REP(j, N) {
                    if (a[i] < a[j]) ++p[i][j];
                }
            }
        } while (next_permutation(a, a + N));

        if (q == 1) { break; }
        REP(i, N) REP(j, N) {
            int d = abs(2 * p[i][j] - q);
            if (d_min > d) {
                d_min = d;
                query_i = i;
                query_j = j;
            }
        }
        printf("? %c %c\n", 'A' + query_i, 'A' + query_j);
        fflush(stdout);
        string ans;
        cin >> ans;
        if (ans == "<") {
            relations.push_back(pii(query_i, query_j));
        } else if (ans == ">") {
            relations.push_back(pii(query_j, query_i));
        }
    }
    int a[NMAX];
    REP(i, N) a[i] = i;
    do {
        if (relational(a)) {
            vector<pii> v;
            REP(i, N) v.push_back(pii(a[i], i));
            sort(v.begin(), v.end());
            cout << "! ";
            REP(i, N) printf("%c", 'A' + v[i].second);
            cout << endl;
            break;
        }
    } while (next_permutation(a, a + N));
}


int main() {
    cin >> N >> Q;
    if (N == 26) {
        n26();
    } else if (N == 5) {
        n5();
    }
    return 0;
}