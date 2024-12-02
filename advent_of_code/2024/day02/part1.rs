use std::cmp;
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

        let mut rising = false;
        let mut falling = false;
        let mut diff = 0;

        for i in 0..arr.len() - 1 {
            if arr[i] <= arr[i + 1] {
                rising = true;
            }
            if arr[i] >= arr[i + 1] {
                falling = true;
            }
            diff = cmp::max((arr[i] - arr[i + 1]).abs(), diff);
        }

        // println!("{rising} {falling} {diff}");

        if !(rising && falling) && diff <= 3 {
            res += 1;
        }
    }

    println!("{res}");
}
