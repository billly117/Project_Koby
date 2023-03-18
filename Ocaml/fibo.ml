let rec fibo x =
match x with
|1 | 2 -> 1
| n -> fibo(n-1) + fibo(n-2);;

let res = fibo 8 in print_int res