var a_res, b_res: int
var d_min = 1.0

for b in 2..1_000_000:
    if b mod 7 != 0:
        let a = 3 * b div 7
        var d = float((3 * b - 7 * a) / (7 * b))
        if d < d_min:
            d_min = d
            (a_res, b_res) = (a, b)
echo $a_res, "/", $b_res
