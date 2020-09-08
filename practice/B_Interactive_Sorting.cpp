#include <cstdio>
#include <string>

using namespace std;

int partition(string &s, int low, int high) {
    char pivot = s[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        printf("? %c %c\n", s[j], pivot);
        fflush(stdout);
        char ans;
        scanf(" %c", &ans);
        if (ans == '<') {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i+1], s[high]);
    return i + 1;
}

void quickSort(string &s, int low, int high) {
    if (low < high) {
        int mid = partition(s, low, high);
        quickSort(s, low, mid - 1);
        quickSort(s, mid + 1, high);
    }
}

int main() {
    int N, Q, i, j;
    scanf("%d%d", &N, &Q);
    string s;
    for (i = 0; i < N; i++) s += (char)('A' + i);

    quickSort(s, 0, s.length() - 1);

    printf("! %s\n", s.c_str());
    fflush(stdout);

    return 0;
}

