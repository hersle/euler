package main

import "fmt"

func main() {
	var a_res, b_res int
	d_min := 1.0
	for b := 2; b <= 1000000; b++ {
		if b % 7 != 0 {
			a := 3 * b / 7
			d := 3.0 * (float64(b) - 7 * float64(a)) / (7 * float64(b))
			if d < d_min {
				d_min, a_res, b_res = d, a, b
			}
		}
	}
	fmt.Println(a_res, b_res)
}
