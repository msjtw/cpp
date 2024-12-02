use std::io;

fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).expect("");
    let n: i32 = n.trim().parse().expect("");

    let mut arr1: Vec<i32> = Vec::new();
    let mut arr2: Vec<i32> = Vec::new();

    for _i in 0..n {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("");
        let line = line.trim().split("   ");
        let line = line.collect::<Vec<&str>>();
        let a: i32 = line[0].parse().expect("");
        let b: i32 = line[1].parse().expect("");
        arr1.push(a);
        arr2.push(b);
    }

    arr1.sort();
    arr2.sort();

    let mut res: i32 = 0;

    for i in 0..arr1.len() {
        res += (arr1[i] - arr2[i]).abs();
    }

    println!("{res}");
}
