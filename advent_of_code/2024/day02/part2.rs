use std::io;

fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: i32 = n.trim().parse().unwrap();

    let mut res = 0;

    for _i in 0..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let line = line.trim().split(" ");

        let mut arr: Vec<i32> = Vec::new();

        for part in line {
            let num: i32 = part.parse().unwrap();
            arr.push(num);
        }

        for i in 0..arr.len() {
            let mut rising = false;
            let mut falling = false;
            let mut larger = 0;
            let mut p = 0;
            let mut q = 1;
            while q < arr.len() {
                if q == i {
                    q += 1;
                }
                if p == i {
                    p += 1;
                }
                if p == q {
                    q += 1;
                }
                if q == arr.len() {
                    break;
                }
                // println!("{p} {q}");
                if arr[p] <= arr[q] {
                    rising = true;
                }
                if arr[p] >= arr[q] {
                    falling = true;
                }
                if (arr[p] - arr[q]).abs() > 3 {
                    larger += 1;
                }
                p += 1;
                q += 1;
            }
            if !(rising && falling) && larger == 0 {
                res += 1;
                break;
            }
        }
    }

    println!("{res}");
}
