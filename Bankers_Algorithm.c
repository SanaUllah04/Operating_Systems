#include <stdio.h>

int main() {
    int n = 5, m = 3, ind = 0, i, j, k, y, flag = 0;
    int alloc[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int max[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int avail[3] = {3, 3, 2}, f[n], ans[n], need[n][m];
    
    for (k = 0; k < n; k++) f[k] = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int safe = 1;
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j]) safe = 0;
                if (safe) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    
    for (i = 0; i < n; i++) if (f[i] == 0) { flag = 1; break; }

    if (flag) printf("The system is not safe");
    else {
        printf("Safe Sequence: ");
        for (i = 0; i < n - 1; i++) printf("P%d -> ", ans[i]);
        printf("P%d", ans[n - 1]);
    }
    return 0;
}
