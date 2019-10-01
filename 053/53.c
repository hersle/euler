//               r!     
// C(n, r) = -----------
//           (n-r)! * r!
//
//                     n!                   n!         
// C(n, r+1) = ------------------- = -----------------
//             (n-(r+1))! * (r+1)!   (n-r-1)! * (r+1)!
//
//                     n!                n!           1                 n-r
// C(n, r+1) = ------------------- = ----------- * -------- = C(n, r) * ---
//             (n-r)!                (n-r)! * r!     r+1                r+1
//             ------ * r! * (r+1)                   --- 
//              n-r                                  n-r
//
// +---------------------------+
// |                       n-r |
// | C(n, r+1) = C(n, r) * --- |
// |                       r+1 |
// +---------------------------+
#include <stdio.h>

int main()
{
    int count = 0;
    int n, r, ncr;
    for (n = 1; n <= 100; n++) {
        r = 0;
        ncr = 1;  // C(n, r) = C(n, 0) = 1
        while (r <= n / 2) {  // C(n, r) is symmetric. Only check to n/2
            ncr = ncr * (n - r) / (r + 1);
            r++;
            if (ncr > 1000000) {
                printf("C(%d, r) > 1000000 when r in [%d, %d]\n", n, r, n - r);
                count += n - 2 * r + 1;
                break;
            }
        }
    }

    printf("count = %d\n", count);
    return 0;
}
